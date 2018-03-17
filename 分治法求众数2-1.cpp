#include<iostream>
#include<fstream>
using namespace std;

//������м�������ȵ����ҽ���
void split(int a[], int n, int &l, int &r)
{
	int mid = n / 2;
	for (l = 0; l < n; l++)
	{
		//���a[mid]��ߵ�һ����a[mid]��ȵ�Ԫ���±� l
		if (a[l] == a[mid]) break;
	}
	for (r = n; r > 0; r--)
	{
		//���a[mid]�ұߵ�һ����a[mid]��ȵ�Ԫ���±� r
		if (a[r] == a[mid]) break;
	}
}

void GetMaxCnt(int &mid, int &maxCnt, int a[], int n)
{
	int l, r; //���ұ߽�
	split(a,n,l,r); //��һ�ηָ�
	int num = n / 2;
	int cnt = r - l; //�м�Ԫ�ص�����

	//update
	if (cnt > maxCnt)
	{
		maxCnt = cnt;
		mid = a[num];
	}

	//��߸�������maxCntʱ��Ѱ
	if (l + 1 > maxCnt)
		GetMaxCnt(mid,maxCnt,a,l+1);
	//��Ѱ�ұ�
	if (n - r > maxCnt)
		GetMaxCnt(mid, maxCnt, &a[r], n - r);
}

int main()
{
	//��input.txt
	ifstream infile("input.txt", ios::in);
	int amount;
	infile >> amount; //�ַ�������
	int *p;
	p = new int[amount];
	for (int i = 0; i < amount; i++)
	{
		infile >> p[i];
		cout << p[i] << " ";
	}
	cout << endl;
	infile.close();
	int num = 0;
	int maxCnt = 0;
	GetMaxCnt(num,maxCnt,p,amount);

	//��output.txt
	ofstream outfile("output.txt");
	cout << num << endl << maxCnt << endl;
    outfile <<num << endl<<maxCnt<<endl;
	outfile.close();
	return 0;
}
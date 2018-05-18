#include<iostream>
#include<fstream>
using namespace std;
#define N 1000
int n;//S��С
int c;//�Ӽ�Ŀ��ֵ
int r=0;//ʣ��Ԫ��������
int set[N];//set[N]�洢S����Ԫ�� �������Դ洢N��   
int x[N] = { 0 };//����x[N]����ʾa[N]Ԫ���Ƿ�ѡ�񣬳�ʼΪ0����Ϊ1���ʾѡ��   
int sum = 0;//��ǰ��ѡԪ��֮�� 

bool Sum_Subset(int i)
{
	if (sum == c)
		return true; //�ҵ����н�
	if (i > n)
		return false; //δ�ҵ����н�
	r -= set[i];
	if (sum + set[i] <= c)//����������
	{
		x[i] = 1; 
		sum += set[i];
		if (Sum_Subset(i + 1)) //�����������
			return true;
		sum -= set[i]; //����
	}
	if (sum + r >= c) //���������� ��ǰ�ͣ�ʣ����>Ŀ��ֵ   
	{
		x[i] = 0;
		if (Sum_Subset(i + 1)) //�����������
			return true;
	}
	r += set[i];
	return false;
}

int main()
{
	//��input.txt
	ifstream infile("input.txt", ios::in);
	infile >> n >> c;
	cout << "�Ӽ�Ԫ�ظ�����" << n <<"  ��Ŀ��ֵ��"<<c<< endl<<endl;
	cout << n <<"��Ԫ��Ϊ:"<<endl;
	for (int i = 0; i < n; i++)
	{
		infile >> set[i];
		cout << set[i] << " ";
		r += set[i];
	}
	cout << endl << endl;
	infile.close();

	//��output.txt
	ofstream outfile("output.txt");
	if (!Sum_Subset(0)) //�޽�
	{
		cout << "No Solution!" << endl;
		outfile << "No Solution!" << endl;
	}
	else
	{
		cout << "��Ϊ��" << endl;
		for (int i = 0; i < n; i++)
		{
			if (x[i] == 1)
			{
				cout << set[i] << " ";
				outfile << set[i] << " ";
			}
		}
		cout << endl<<endl;
	}
	outfile.close();
	return 0;
}
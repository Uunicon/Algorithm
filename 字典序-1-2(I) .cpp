#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	int f(int, int);
	int g(string);

	//��input.txt
	ifstream infile("input.txt", ios::in);
	int amount;
	infile >> amount; //�ַ�������
	string *p;
	p = new string[amount];
	for (int i = 0; i < amount; i++)
		infile >> p[i];
	infile.close();

	//��output.txt
	ofstream outfile("output.txt");
	for (int i = 0; i < amount; i++)
	{
		outfile << g(p[i]) << endl;
	}
	outfile.close();
	return 0;
}

int f(int i, int k)  
//�����i���ַ����Ȳ�����k�������ַ�������
{
	int j;
	int sum = 0;
	if (k == 1)   //�ַ�������Ϊ1 ����1��
		return 1;
	else
	{
		for (j = i + 1; j <= 26; j++) 
			sum += f(j, k - 1);    //j=i+1 �����ַ��� ���ȼ�һ
	}                              //�ݹ� ��k=1��ʼ
	return sum;
}//f(int i, int k)

int g(string a)
//�����ַ����ı��
{
	int i, j, n, length, head, next;
	int k = a.size(); //�ַ�������
	int sum = 0;

	//����Ϊk-1���ַ�������
	for (i = 1; i < k; i++)
		for (j = 1; j <= 26; j++)
			sum += f(j, i);

	//a��head ����Ϊk���ַ�������
	head = a[0] - 'a' + 1;  //����ĸ���
	for (i = 1; i < head; i++)
		sum += f(i, k);

	//��head��ͷ����Ϊk���ַ�������
	next = head;//��¼��һ����ĸ���
	for (i = 1; i < k; i++)
	{
		n = a[i] - 'a' + 1; //��i����ĸ���
		length = k - i;
		for (j = next + 1; j < n; j++)
			sum += f(j, length);
		next = n;
	}
	return sum + 1;//��������
}
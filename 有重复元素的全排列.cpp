#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int finish(char list[], int k, int i)
{//��i��Ԫ���Ƿ���ǰ��Ԫ��[k...i-1]�г��ֹ�  
	if (i>k)
	{
		for (int j = k; j<i; j++)
			if (list[j] == list[i])
				return 0;
	}
	return 1;
}

void Swap(char &a, char &b)
{//��������Ԫ��
	char temp = a;
	a = b;
	b = temp;
}

void Perm(char list[], int k, int m, int &count,string *s)
{//����list[k:m]����������
	if (k == m)//��ʣһ��Ԫ��
	{
		for (int i = 0; i <= m; i++)
		{
			cout << list[i];
			s[count] = s[count]+list[i];
		}//end for
		cout << endl;
		count++;
	}
	else //���ж��Ԫ�ش�����
		for (int i = k; i <= m; i++)
		{
			if (finish(list, k, i)) //�ж��Ƿ��ظ�
			{
				Swap(list[k], list[i]);
				Perm(list, k + 1, m, count,s);
				Swap(list[i], list[k]);
			}//end if
		}//end for
}// end Perm

int main()
{

	//��input.txt
	ifstream infile("input.txt", ios::in);
	int num;//�ַ�����
	infile >> num; 
	int amount = 1;
	int count=0;
	char *p = new char[num];
	cout << "�ַ���Ϊ��";
	for (int i = 0; i < num; i++)
	{
		infile >> p[i];
		cout << p[i];
		amount = amount*(i + 1); //����num�׳ˣ����ڴ���ַ���
	}
	string *s = new string[amount];
	cout << endl;
	infile.close();

	cout << "ȫ����Ϊ��" << endl;
	//��output.txt
	ofstream outfile("output.txt");
	Perm(p,0,num-1,count,s);
	for (int i = 0; i < count; i++)
	{
		outfile << s[i] <<endl;
	}
	cout << "����Ϊ��";
	cout << count << endl;
	outfile << count << endl;
	return 0;
}


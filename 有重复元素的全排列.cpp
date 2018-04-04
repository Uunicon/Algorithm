#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int finish(char list[], int k, int i)
{//第i个元素是否在前面元素[k...i-1]中出现过  
	if (i>k)
	{
		for (int j = k; j<i; j++)
			if (list[j] == list[i])
				return 0;
	}
	return 1;
}

void Swap(char &a, char &b)
{//交换两个元素
	char temp = a;
	a = b;
	b = temp;
}

void Perm(char list[], int k, int m, int &count,string *s)
{//产生list[k:m]的所有排列
	if (k == m)//仅剩一个元素
	{
		for (int i = 0; i <= m; i++)
		{
			cout << list[i];
			s[count] = s[count]+list[i];
		}//end for
		cout << endl;
		count++;
	}
	else //还有多个元素待排列
		for (int i = k; i <= m; i++)
		{
			if (finish(list, k, i)) //判断是否重复
			{
				Swap(list[k], list[i]);
				Perm(list, k + 1, m, count,s);
				Swap(list[i], list[k]);
			}//end if
		}//end for
}// end Perm

int main()
{

	//打开input.txt
	ifstream infile("input.txt", ios::in);
	int num;//字符数量
	infile >> num; 
	int amount = 1;
	int count=0;
	char *p = new char[num];
	cout << "字符串为：";
	for (int i = 0; i < num; i++)
	{
		infile >> p[i];
		cout << p[i];
		amount = amount*(i + 1); //计算num阶乘，用于存放字符串
	}
	string *s = new string[amount];
	cout << endl;
	infile.close();

	cout << "全排列为：" << endl;
	//打开output.txt
	ofstream outfile("output.txt");
	Perm(p,0,num-1,count,s);
	for (int i = 0; i < count; i++)
	{
		outfile << s[i] <<endl;
	}
	cout << "数量为：";
	cout << count << endl;
	outfile << count << endl;
	return 0;
}


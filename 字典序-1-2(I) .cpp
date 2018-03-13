#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	int f(int, int);
	int g(string);

	//打开input.txt
	ifstream infile("input.txt", ios::in);
	int amount;
	infile >> amount; //字符串数量
	string *p;
	p = new string[amount];
	for (int i = 0; i < amount; i++)
		infile >> p[i];
	infile.close();

	//打开output.txt
	ofstream outfile("output.txt");
	for (int i = 0; i < amount; i++)
	{
		outfile << g(p[i]) << endl;
	}
	outfile.close();
	return 0;
}

int f(int i, int k)  
//计算第i个字符长度不超过k的升序字符串个数
{
	int j;
	int sum = 0;
	if (k == 1)   //字符串长度为1 仅有1个
		return 1;
	else
	{
		for (j = i + 1; j <= 26; j++) 
			sum += f(j, k - 1);    //j=i+1 升序字符串 长度减一
	}                              //递归 从k=1开始
	return sum;
}//f(int i, int k)

int g(string a)
//计算字符串的标号
{
	int i, j, n, length, head, next;
	int k = a.size(); //字符串长度
	int sum = 0;

	//长度为k-1的字符串数量
	for (i = 1; i < k; i++)
		for (j = 1; j <= 26; j++)
			sum += f(j, i);

	//a到head 长度为k的字符串数量
	head = a[0] - 'a' + 1;  //首字母序号
	for (i = 1; i < head; i++)
		sum += f(i, k);

	//以head开头长度为k的字符串数量
	next = head;//记录下一个字母序号
	for (i = 1; i < k; i++)
	{
		n = a[i] - 'a' + 1; //第i个字母序号
		length = k - i;
		for (j = next + 1; j < n; j++)
			sum += f(j, length);
		next = n;
	}
	return sum + 1;//加上自身
}
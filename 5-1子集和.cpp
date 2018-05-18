#include<iostream>
#include<fstream>
using namespace std;
#define N 1000
int n;//S大小
int c;//子集目标值
int r=0;//剩余元素数量和
int set[N];//set[N]存储S集合元素 ，最多可以存储N个   
int x[N] = { 0 };//设置x[N]来表示a[N]元素是否选择，初始为0，若为1则表示选择   
int sum = 0;//当前所选元素之和 

bool Sum_Subset(int i)
{
	if (sum == c)
		return true; //找到可行解
	if (i > n)
		return false; //未找到可行解
	r -= set[i];
	if (sum + set[i] <= c)//搜索左子树
	{
		x[i] = 1; 
		sum += set[i];
		if (Sum_Subset(i + 1)) //往纵深方向搜索
			return true;
		sum -= set[i]; //回溯
	}
	if (sum + r >= c) //搜索右子树 当前和＋剩余量>目标值   
	{
		x[i] = 0;
		if (Sum_Subset(i + 1)) //往纵深方向搜索
			return true;
	}
	r += set[i];
	return false;
}

int main()
{
	//打开input.txt
	ifstream infile("input.txt", ios::in);
	infile >> n >> c;
	cout << "子集元素个数：" << n <<"  和目标值："<<c<< endl<<endl;
	cout << n <<"个元素为:"<<endl;
	for (int i = 0; i < n; i++)
	{
		infile >> set[i];
		cout << set[i] << " ";
		r += set[i];
	}
	cout << endl << endl;
	infile.close();

	//打开output.txt
	ofstream outfile("output.txt");
	if (!Sum_Subset(0)) //无解
	{
		cout << "No Solution!" << endl;
		outfile << "No Solution!" << endl;
	}
	else
	{
		cout << "解为：" << endl;
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
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int mini(int a, int b, int c)
{
	int mini = a;
	if (b < mini)mini = b;
	if (c < mini)mini = c;
	return mini;
}


//m:字符串A长度
//n:字符串B长度
int Edit_Dist(string A,string B)
{
	int m = A.length();
	int n = B.length();
	char ca, cb;

	int **p; //p[m][n]
	p = new int*[m];
	for (int i = 0; i <= m; i++)
		p[i] = new int[n];
	for (int i = 0; i <= m; i++) //p[i][0] = i delete;
		p[i][0] = i;
	for (int j = 0; j <= n; j++) //p[0][j] = j insert;
		p[0][j] = j;
	for(int i = 1;i <= m; i++)
	{
		ca = A[i - 1];
		for (int l = 1; l <= n; l++)
		{
			cb = B[l - 1];
			if (ca == cb)
				p[i][l] = p[i - 1][l - 1];
			else
				p[i][l] = mini(p[i-1][l-1]+1,p[i-1][l]+1,p[i][l-1]+1);
		}//end for
	}//end for
	return p[m][n];
}


int main()
{
	string A, B;
	//打开input.txt
	ifstream infile("input.txt", ios::in);
	infile >> A >> B;
	infile.close();

	cout << "字符串A为：" << A << endl;
	cout << "字符串B为：" << B << endl;
	cout <<"编辑距离为："<< Edit_Dist(A, B);
	cout << endl;
	//打开output.txt
	ofstream outfile("output.txt");
	outfile << Edit_Dist(A, B) << endl;
	outfile.close();
	return 0;
}
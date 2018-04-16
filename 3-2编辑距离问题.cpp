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


//m:�ַ���A����
//n:�ַ���B����
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
	//��input.txt
	ifstream infile("input.txt", ios::in);
	infile >> A >> B;
	infile.close();

	cout << "�ַ���AΪ��" << A << endl;
	cout << "�ַ���BΪ��" << B << endl;
	cout <<"�༭����Ϊ��"<< Edit_Dist(A, B);
	cout << endl;
	//��output.txt
	ofstream outfile("output.txt");
	outfile << Edit_Dist(A, B) << endl;
	outfile.close();
	return 0;
}
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int set(int);
	int a, s;
	//打开input.txt
	ifstream infile("input.txt", ios::in);
	infile >> a; //字符串数量
	s = set(a);
	cout << s << endl;
	infile.close();

	//打开output.txt
	ofstream outfile("output.txt");
	outfile << s << endl;
    outfile.close();
	return 0;
}

//半数集数量计算
int set(int n)
{
	int sum ;
	if (n == 1) return 1;
	else
		for (int i = 1; i <= n / 2; i++) //不超过一半
			sum += set(i);
	return sum;
}
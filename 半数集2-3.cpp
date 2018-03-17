#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int set(int);
	int a, s;
	//��input.txt
	ifstream infile("input.txt", ios::in);
	infile >> a; //�ַ�������
	s = set(a);
	cout << s << endl;
	infile.close();

	//��output.txt
	ofstream outfile("output.txt");
	outfile << s << endl;
    outfile.close();
	return 0;
}

//��������������
int set(int n)
{
	int sum ;
	if (n == 1) return 1;
	else
		for (int i = 1; i <= n / 2; i++) //������һ��
			sum += set(i);
	return sum;
}
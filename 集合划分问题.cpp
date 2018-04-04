#include <iostream>
#include<fstream>
using namespace std;

int Stirling(int i, int j)
{
	if ((j == i) || (j == 1))
		return 1;
	else if (j == 2)
		return pow(2, (i - 1) * 1.0) - 1; //S(n,2)
	else
		return Stirling(i - 1, j - 1) + j * Stirling(i - 1, j);
}

int main()
{
	//��input.txt
	ifstream infile("input.txt", ios::in);
	int n, k, a;
	infile >> n >> k;
	cout <<" "<<n<<" ��Ԫ�صļ���" << " " << k <<" ����"<< endl;
	a = Stirling(n, k);
	infile.close();

	//��output.txt
	ofstream outfile("output.txt");
	cout << "�� "<<a<<" �ֻ��ַ���" << endl;
	outfile << a << endl;
	outfile.close();
	return 0;
}

#include <iostream>
#include<fstream>
using namespace std;

//统计个数重新赋值
void Sortcolor(int a[], int n)
{
	int i;
	if (n <= 1) return;//若n小于1，不用排序
	int red = 0, white = 0, blue = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 0)++red;
		else if (a[i] == 1)++white;
		else ++blue;
	}
	for (i = 0; i < red; i++)
		a[i] = 0;
	for (i = 0; i < white; i++)
		a[red + i] = 1;
	for (i = 0; i < blue; i++)
		a[red+white + i] = 2;
}

void Sortcolor_2(int a[], int n)
{
	int i;
	if (n <= 1) return;//若n小于1，不用排序
	int begin = -1, end = n , current = 0;
	while (current<end)
	{
		if (a[current] < 1)
			swap(a[current++], a[++begin]);
		else if (a[current] > 1)
			swap(a[current], a[--end]);
		else
			current++;
	}
}

void swap(int &a, int&b)
{
	int temp;
	temp = a; a = b; b = temp;
}
int main()
{
	int  n,i;
	cin >> n;
	int *p = new int[n];
	for (i = 0; i < n; i++)
		cin >> p[i];
	Sortcolor_2(p, n);
	for (i = 0; i < n; i++)
		cout << p[i]<<" ";
	cout << endl;
	return 0;
}
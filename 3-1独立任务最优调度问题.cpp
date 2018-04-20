#include <iostream>
#include<fstream>
#include<string>

#define INFINITY 65535
using namespace std;


//A完成第K个任务的时间为x，B完成的时间为F[k][x]
//F[k][x]=min{F[k-1][x]+b[x],F[k-1][x-a[k]]}   k由b完成 ，k由a完成
int Ind_task_opt_scheduling(int **F,int a_sum_t,int *A,int *B,int *timek,int n)
{
	int sumA = A[0]; //记录每增加一次任务 由A全部完成的时间
	//k=0 
	for (int i = 0; i <= a_sum_t; i++)
		F[0][i] = B[0];
	//初始化
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= a_sum_t; j++)
			F[i][j] = INFINITY;
	F[0][sumA] = B[0] < A[0] ? B[0] : A[0];
	timek[0] = F[0][sumA] < A[0] ? F[0][sumA] : A[0];
	//k>=1
	for (int k = 1; k < n; k++)
	{
		timek[k] = INFINITY;
		sumA += A[k];
		for(int x = 0; x <= sumA; x++)
		{
			if (x < A[k])
				F[k][x] = F[k - 1][x] + B[k];
			else //F[k][x]=min{F[k-1][x]+b[x],F[k-1][x-a[k]]} 
				F[k][x] = (F[k - 1][x] + B[k]) < F[k - 1][x - A[k]] ? F[k - 1][x] + B[k] : F[k - 1][x - A[k]];
			int temp;
			//max(x,F[k][x])
			temp = x > F[k][x] ? x : F[k][x];
			//min(timek,temp)
			timek[k] = timek[k] < temp ? timek[k] : temp;
		}
	}
	return timek[n-1];
}

int main()
{
	int amnt;//任务数量
	int a_sum_t=0;//所有任务a完成的时间
	int time;
	//打开input.txt
	ifstream infile("input.txt", ios::in);
	infile >> amnt;
	cout << "任务数量：" << amnt << endl;
	int *pa = new int[amnt];
	int *pb = new int[amnt];
	int *timek = new int[amnt];
	int i;
	cout << "A机器所需时间：";
	for (i = 0; i < amnt; i++)
	{
		infile >> pa[i];
		a_sum_t += pa[i];
		cout << pa[i] << " ";
	}
	cout << endl;
	cout << "B机器所需时间：";
	for (i = 0; i < amnt; i++)
	{
		infile >> pb[i];
		cout << pb[i] << " ";
	}
	cout << endl;
	infile.close();

	int **m; //m[amnt][a_sum_t]
	m = new int*[amnt];
	for (int i = 0; i <= amnt; i++)
		m[i] = new int[a_sum_t];

	time = Ind_task_opt_scheduling(m,a_sum_t,pa,pb,timek,amnt);
	//打开output.txt
	ofstream outfile("output.txt");

	outfile  <<time<< endl;
	cout <<"最短时间为："<< time << endl;
	outfile.close();
	return 0;

}
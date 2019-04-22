// 19dichotomization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const double eps = 1e-5;
const double PI = acos(-1.0);
double f(double x)
{
	return x * x;
}
double calSqrt()
{
	double left = 1,right = 2,mid;
	while (right - left > eps)
	{
		mid = (left + right) / 2;
		if (f(mid) > 2)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	return mid;
}
//////////////////////////////////////////////////////////////////////////
double f1(double R,double h)
{
	double alpha = 2 * acos((R - h)/R);
	double L = 2 * sqrt(R*R-(R-h)*(R-h));
	double S1 = alpha *R*R/2 - L*(R-h)/2;
	double S2 = PI*R*R/2;
	return S1/S2;
} 
double solve(double R, double r) // take in water problem
{
	double left = 0,right = R,mid;
	while (right - left > eps)
	{
		mid = (left + right)/2;
		if (f1(R,mid)>r)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	return mid; //return surface height

}
//////////////////////////////////////////////////////////////////////////
int wss[100];
int wooden_shed_solution(int n,int wss[], int K)
{
	int left = 0, right = wss[n-1], mid; //mid:max length	
	while (left < right)
	{
		int k = 0;
		mid = (left+right)/2;
		for (int i = 0; i<n; i++)
		{
			k += (wss[i] / mid);
		}
		if (k < K)
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	return left -1;
}

int main(int argc, char* argv[])
{
//	double ans = 0;
//	ans = calSqrt();
// 	printf("%.5lf\n",ans);

//	double R,r;
//	scanf("%lf%lf",&R,&r);
// 	printf("%.4f\n",solve(R,r));
	
	int n = 3;
	int K = 7;
	wss[0] = 10;
	wss[1] = 24;
	wss[2] = 15;
	sort(wss,wss+n);
	int ans = wooden_shed_solution(n, wss, K);
	printf("%d\n",ans);
	return 0;
}

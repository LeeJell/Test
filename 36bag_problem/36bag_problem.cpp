// 36bag_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100;
const int maxv = 1000;
int w[maxn], c[maxn], dp[maxv];
#define max(a,b) (((a)>(b))?(a):(b))
int main(int argc, char* argv[])
{
	int n, V;
	scanf("%d%d", &n, &V);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int v = 0; v <= V; v++)
	{
		dp[v] = 0;
	}
	for (i = 1; i <=n; i++) //backward 01 bag
	{
		for (v = V; v >= w[i]; v--)
		{
			dp[v] = max(dp[v], dp[v-w[i]] + c[i]);
		}
	}
//	for (i = 1; i <=n; i++)	//forward complete bag
//	{
//		for (v = w[i]; v >= V; v++)
//		{
//			dp[v] = max(dp[v], dp[v-w[i]] + c[i]);
//		}
// 	}
	int maxvvv = 0;
	for (v = 0; v <= V; v++)
	{
		if (dp[v] > maxvvv)
		{
			maxvvv = dp[v];
		}
	}
	printf("%d\n", maxvvv);
	return 0;
}

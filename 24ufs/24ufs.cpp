// 24ufs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
const int N = 110;
int father[N];
bool isRoot[N];
void init(int nodenum)
{
	for (int i = 1; i < nodenum; i++)
	{
		father[i] = i;
		isRoot[i] = false;
	}
}
int findfather(int x)
{
	if (x == father[x])
	{
		return x;
	}
	else
	{
		x = findfather(father[x]);
		return x;
	}
}
int opt_findfather(int x)
{
	if (x == father[x])
	{
		return x;
	}
	else
	{
		int v = opt_findfather(father[x]);
		father[x] = v;
		return v;
	}
}
int Union(int a, int b)
{
	int faA = findfather(a);
	int faB = findfather(b);
	if (faA == faB)
	{
		return faA;
	}
	else
	{
		father[faB] = faA;
		return faA;
	}

}
int main(int argc, char* argv[])
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	init(n);
	for (int i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		Union(a,b);
	}
	for (i = 1; i<= n; i++)
	{
		isRoot[opt_findfather(i)] = true;
	}
	//	Root[findfather()]++; //int Root[x], the elements of the set
	int ans = 0;
	for (i = 1; i<= n; i++)
	{
		ans += isRoot[i+1];
	}
	printf("%d\n",ans);
	return 0;
}

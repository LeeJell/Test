// 18simple_greed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
using namespace std;
struct mooncake {
	double store;
	double sell;
	double price;
}cake[1010];
bool cmp(mooncake a,mooncake b)
{
	return a.price>b.price;
}

const int maxn = 110;
struct Interval {
	int x,y;
}I[maxn];
bool cmp1(Interval a, Interval b)
{
	if (a.x != b.x) return a.x > b.x;
	else return a.y <b.y;
}

int main(int argc, char* argv[])
{
	/////////////////////mooncake problem/////////////////////
/*	int n;
	double D;
	scanf("%d%lf",&n,&D);
	for (int i=0; i<n; i++)
	{
		scanf("%lf",&cake[i].store);
	}
	for (i=0; i<n; i++)
	{
		scanf("%lf",&cake[i].sell);
		cake[i].price = cake[i].sell/cake[i].store;
	}
	sort(cake, cake+n, cmp);
	double ans = 0;
	for (i = 0; i<n; i++)
	{
		if (cake[i].store <= D)
		{
			D -= cake[i].store;
			ans += cake[i].sell;
		}
		else
		{
			ans += D*cake[i].price;
			break;
		}
	}
	printf("%.2f\n",ans);
	/////////////////////mooncake problem/////////////////////
*/
	
/*	//////////////minnumbershow//////////////////////
	int counter[10];
	for (int i=0;i<10;i++)
	{
		scanf("%d",&counter[i]);
	}
	for (i=1;i<10;i++)
	{
		if (counter[i]!=0)
		{
			counter[i]--;
			printf("%d",i);
			break;
		}
	}
	for (i=0;i<10;i++)
	{
		while(counter[i]!=0)
		{
			counter[i]--;
			printf("%d",i);
		}
	}
	//////////////minnumbershow//////////////////////
*/
	
	/////////////区间不相交/////////////////////////////////////////////
	int n;
	while (scanf("%d", &n), n!=0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &I[i].x, &I[i].y);
		}
	
		sort(I, I+n, cmp1);		//区间排序
		int ans = 1, lastX = I[0].x;
		for (i = 1; i<n; i++)
		{
			if (I[i].y <= lastX)
			{
				lastX = I[i].x;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	printf("Hello World!\n");
	return 0;
}


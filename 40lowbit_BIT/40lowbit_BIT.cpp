// 40lowbit_BIT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 100010;
#define lowbit(i) ((i)&(-i))

int c[maxn];

struct Node {
	int val;
	int pos;
}temp[maxn];
int A[maxn]; //discretization
int getSum(int x) //O(logN)
{
	int sum = 0;
	for (int i = x; i > 0; i-=lowbit(i))
	{
		sum +=c[i];
	}
	return sum;
}

void update(int x, int v) //O(logN)
{
	for (int i = x; i <= maxn; i+=lowbit(i))
	{
		c[i] += v;
	}
}
//int main(int argc, char* argv[])
//{
//	int n, x;
//	scanf("%d", &n);
//	memset(c,0, sizeof(c));
//	for (int i = 0;i < n; i++)
//	{
//		scanf("%d", &x);
//		update(x, 1);
//		printf("%d\n", getSum(x - 1));
//	}
//	return 0;
//}
bool cmp(Node a, Node b)
{
	return a.val < b.val;
}

int findKthElement(int K)
{
	int l = 1, r = maxn, mid;
	while (l < r)
	{
		mid = (l + r)/2;
		if (getSum(mid) >= K)
		{
			r = mid;
		}
		else l = mid + 1;
	}
	return l;
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp[i].val);
		temp[i].pos = i;
	}
	std::sort(temp, temp + n, cmp);
	for (i = 0; i < n; i++)
	{
		if (i == 0 || temp[i].val != temp[i - 1].val)
		{
			A[temp[i].pos] = i + 1;
		}
		else
		{
			A[temp[i].pos] = A[temp[i - 1].pos];
		}
	}
	for (i = 0; i < n; i++)
	{
		update(A[i], 1);
		printf("%d\n", getSum(A[i] - 1));
	}
	return 0;
}

int cc[maxn][maxn];
void updatecc(int x, int y, int v)
{
	for (int i = x; i < maxn; i +=lowbit(i))
	{
		for (int j = y; j < maxn; j +=lowbit(j))
		{
			c[i][j] += v;
		}
	}
}
int getSumcc(int x, int y)
{
	int sum = 0;
	 for (int i = x; i > 0; i-=lowbit(i))
	 {
		 for (int j = y; j > 0; j -= lowbit(j))
		 {
			 sum += c[i][j];
		 }
	 }
	 return sum;
}

int ccc[maxn]; //Interval update, single point query
int getSumccc(int x) //O(logN)
{
	int sum = 0;

	for (int i = x; i <= maxn; i+=lowbit(i))
	{
		sum += c[i];
	}
	return sum;
}

void updateccc(int x, int v) //O(logN)
{
	for (int i = x; i > 0; i-=lowbit(i))
	{
		c[i] += v;
	}
}
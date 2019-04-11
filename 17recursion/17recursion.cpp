// 17recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
const int maxn = 11;
int n ,P[maxn],hashTable[maxn] = {false};
int count = 0;
void generateP(int index)		//全排列123、132/213/231、/312、321
{
	if(index == n+1)
	{
		for(int i = 1; i<= n; i++)
		{
			printf("%d",P[i]);
		}		
		printf("\n");
		return;
	}
	for (int x = 1; x<=n; x++)
	{
		if (hashTable[x] == false)
		{
			P[index] = x;
			hashTable[x] = true;
			generateP(index+1);
			hashTable[x] = false;
		}
	}
}
void n_queen_vs(int index)
{
	if(index == n+1)
	{
		bool flag = true;
		for(int i = 1; i<= n; i++)
		{
			for (int j = i+1; j<=n; j++)
			{
				if(abs(i-j) == abs(P[i]-P[j]))	//two queens在同一对角线上
				{
					flag = false;
					break;
				}
			}
		}		
		if(flag) 
		{
			
			count++;
			for(int i = 1; i<= n; i++)
			{
				printf("%d",P[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int x = 1; x<=n; x++)
	{
		if (hashTable[x] == false)
		{
			P[index] = x;
			hashTable[x] = true;
			n_queen_vs(index+1);
			hashTable[x] = false;
		}
	}

}
void n_queen_op(int index)
{
	if (index == n+1)
	{
		count++;
		for(int i = 1; i<= n; i++)
		{
			printf("%d",P[i]);
		}
		printf("\n");
		return;
	}
	for (int x=1; x<=n; x++)
	{
		if(hashTable[x] == false)
		{
			bool flag = true;
			for (int pre =1; pre <index; pre++)
			{
				if(abs(index-pre) == abs(x-P[pre]))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				P[index] = x;
				hashTable[x] = true;
				n_queen_op(index + 1);
				hashTable[x] = false;
			}
		}
	}

}
int main(int argc, char* argv[])
{
	n = 4;
	n_queen_op(1);
	printf("valid solution num:%d\n",count);
	count = 0;
	return 0;
}


// 20merger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
const int maxn = 100;
void merge(int A[],int L1,int R1,int L2,int R2)
{
	int i = L1,j = L2;
	int temp[maxn],index = 0;
	while (i<=R1&&j<=R2)
	{
		if (A[i]<=A[j])
		{
			temp[index++] = A[i++];
		}
		else
		{
			temp[index++] = A[j++];
		}
	}
	while(i<=R1) temp[index++] = A[i++];
	while(j<=R2) temp[index++] = A[j++];
	for (i = 0;i<index;i++)
	{
		A[L1 +i] = temp[i];
	}
}
void mergeSort(int A[],int left,int right)
{
	if (left<right)
	{	
		int mid = (left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
	}
}

void mergeSort_non_recur(int A[],int n)
{
	for (int step = 2; step/2<=n; step *= 2)		//divide into groups every 2^n
	{
		for (int i = 0;i<n;i+=step)
		{
			int mid = i+step/2 -1;
			if (mid+1<=n)
			{
				merge(A,i,mid,mid+1,min(i+step-1,n));
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int Partition(int A[],int left,int right)
{
	//int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
	//std::swap(A[p],A[left]);
	int temp = A[left];
	while(left < right)
	{
		while(left<right&&A[right]>temp) right--;
		A[left] = A[right];
		while(left<right&&A[left]<=temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

void quickSort(int A[],int left,int right) //O(nlogn)
{
	if (left<right)
	{
		int pos = Partition(A,left,right);
		quickSort(A,left,pos-1);
		quickSort(A,pos+1,right);
	}
}


//////////////////////////////////////////////////////////////////////////
int randSelect(int A[],int left, int right, int K)
{
	if(left==right) return A[left];
	int p =Partition(A,left,right);
	int M = p-left+1;
	if (K<M)
	{
		return randSelect(A,left,p-1,K);
	}
	else
	{
		return randSelect(A,p+1,right,K);
	}
}

int main(int argc, char* argv[])
{
	int A[]={5,2,1,3,7,6,10,4,9,8};
	//mergeSort(A,0,8);
	//mergeSort_non_recur(A,10);

	srand((unsigned)time(NULL));
	for (int i=0;i<10;i++)
	{
		printf("%d ",rand()%(10-1+1)+1); //range:[1,10] rand()%(b-a+1)+a max:32767
	}
	std::cout<<std::endl;
	quickSort(A,0,9);
	for (i=0;i<10;i++)
	{
		printf("%d",A[i]);
	}
	return 0;
}

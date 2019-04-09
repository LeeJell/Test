// 16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int minnum=0,k=0;
	int a[5]={3,1,5,2,4};
//	for (int i=0;i<5;i++)		//选择排序:找到最大或最小值，之后进行交换
//	{
//		minnum = a[i];
//		for (int j=i+1;j<5;j++)
//		{
//			if(minnum > a[j])
//			{
//				minnum = a[j];
//				k=j;
//			}
//
//		}
//		a[k] = a[i];
//		a[i] = minnum;
//  	}

	/////////////
//	for (int i=1;i<=4;i++)			//冒泡排序
//	{
//		for(int j=0;j<5-i;j++)
//		{
//			if (a[j]>a[j+1])
//			{
//				int temp = a[j];
//				a[j] = a[j+1];
//				a[j+1] = temp;
//			}
//		}
//	}

	///////////
	for (int i = 1; i < 5; i++)		//插入排序
	{
		int temp = a[i],j=i;
		while (j>0&&temp<a[j-1])
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
	}
	

	for (i = 0; i < 5; i++)
	{
		cout<<a[i]<<endl;
	}

	printf("Hello World!\n");
	return 0;
}


// 38KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cstdio>
using namespace std;
#define MAXN 1010
int next[MAXN];
int nextval[MAXN];
void getNext(char s[], int len)
{
	int j = -1;
	next[0] = -1;
	for (int i = 1; i < len; i++)
	{
		while (j != -1 && s[i] != s[j+1])
		{
			j = next[j];
		}
		if (s[i] == s[j + 1])
		{
			j++;
		}
		next[i] = j;
	}
}
bool KMP(char text[], char pattern[])
{
	int n =strlen(text), m = strlen(pattern);
	getNext(pattern, m);
	int j = -1;
	for (int i = 0; i < n; i++)
	{
		while (j != -1 && text[i] != pattern[j + 1])
		{
			j = next[j];
		}
		if (text[i] == pattern[j + 1])
		{
			j++;
		}
		if (j == m -1)
		{
			return true;
		}

	}
	return false;
}
void getNextval(char s[], int len)
{
	int j = 1;
	nextval[0] = -1;
	for (int i =1; i < len; i++)
	{
		while (j != -1 && s[i] != s[j + 1])
		{
			j = nextval[j];
		}
		if (s[i] == s[j + 1])
		{
			j++;
		}
		if (j == -1 || s[i+1]!=s[j+1])
		{
			nextval[i] = j;
		}
		else
		{
			nextval[i] = nextval[j];
		}
	}
}
int KMP_count(char text[], char pattern[])
{
	int ans = 0;
	int n =strlen(text), m = strlen(pattern);
	getNext(pattern, m);
	int j = -1;
	for (int i = 0; i < n; i++)
	{
		while (j != -1 && text[i] != pattern[j + 1])
		{
			j = next[j];
		}
		if (text[i] == pattern[j + 1])
		{
			j++;
		}
		if (j == m -1)
		{
			ans++;
			j = next[j];
		}

	}
	return ans;
}
int main(int argc, char* argv[])
{
	return 0;
}

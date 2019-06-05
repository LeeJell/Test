// 34critical_path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct node {
	int w;
	int v;
};
const int n = 10;
int inDegree[n];
vector<node> G[n];
int ve[n],vl[n];
stack<int> topOrder;
bool topologicalSort()
{
	int num = 0;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		//printf("%d", u);
		q.pop();
		topOrder.push(u);
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v;
			inDegree[v]--;
			if (inDegree[v] == 0)
			{
				q.push(v);
			}
			if(ve[u] + G[u][i].w > ve[v])
			{
				ve[v] = ve[u] + G[u][i].w;
			}
		}
		//G[u].clear();
		num++;
	}
	if (num == n)
	{
		return true;
	}
	else
		return false;
}

int CriticalPath()
{
	memset(ve, 0, sizeof(ve));
	if(topologicalSort() == false)
	{
		return -1;
	}

	int maxLength = 0;
	for (int i =0; i < n; i++)
	{
		if (ve[i] > maxLength)
		{
			maxLength = ve[i];
		}
	}
	fill(vl, vl+n, maxLength);

//	fill(vl, vl+n, ve[n-1]);
	while (!topOrder.empty())
	{
		int u = topOrder.top();
		topOrder.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v;
			if (vl[v]-G[u][i].w < vl[u])
			{
				vl[u] = vl[v] - G[u][i].w;
			}
		}
	}
	for (int u = 0; u < n; u++)
	{
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v;
			int w = G[u][i].w;
			int e = ve[u], l = vl[v] - w;
			if (e == l)
			{
				printf("%d->%d\n",u ,v);
			}
		}
	}
	return ve[n-1];
}
int main(int argc, char* argv[])
{
	return 0;
}

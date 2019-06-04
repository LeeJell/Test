// 29bellman_ford.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 0X3fffffff;
struct Node{
	int v, dis;
	Node(int _v,int _dis):v(_v),dis(_dis){}
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];
bool Bellman(int s)
{
	fill(d, d +MAXV, INF);
	d[s] = 0;
	for (int i = 0;i < n-1; i++)
	{
		for (int u = 0; u < n; u++)
		{
			for (int j = 0; j < Adj[u].size(); j++)
			{
				int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;
				if (d[u] + dis < d[v])
				{
					d[v] = d[u] +dis;
				}

			}
		}
	}
	for (int u = 0; u < n; u++)
	{
		for (int j = 0; j <Adj[u].size(); j++)
		{
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if (d[u] + dis < d[v])
			{
				return false;
			} 
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
//SPFA Alogrithm
bool SPFA(int s)
{
	memset(inq, false, sizeof(inq));
	memset(num, 0, sizeof(num));
	fill(d,d+MAXV,INF);
	queue<int> Q;
	Q.push(s);
	inq[s] = true;
	num[s]++;
	d[s] = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for (int j = 0; j < Adj[u].size(); j++)
		{
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if (d[u] + dis < d[v])
			{
				d[v] = d[u] + dis;
				if (!inq[v])
				{
					Q.push(v);
					inq[v] = true;
					num[v]++;
					if (num[v] >= n)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
}
int main(int argc, char* argv[])
{

	return 0;
}

// 31prim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;
//////////////////////////////////////////////////////////////////////////
//adjacent matrix
int n ,G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
int prim()
{
	fill(d, d+MAXV, INF);
	d[0] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
		{
			return -1;
		}
		vis[u] = true;
		ans += d[u];
		for (int v = 0; v < n; v++)
		{
			if (vis[v] ==false && G[u][v] != INF && G[u][v] < d[v])
			{
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}
//////////////////////////////////////////////////////////////////////////
//adjacency list
struct Node {
	int v, dis;
};
vector<Node> Adj1[MAXV];
int m;
int dis[MAXV];
bool visable[MAXV] = {false};
int prim_list()
{
	fill(dis, dis + MAXV, INF);
	dis[0] = 0;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < m; j++)
		{
			if (visable[j] ==false && dis[j] < MIN)
			{
				u = j;
				MIN = dis[j];
			}
		}
		if (u == -1)
		{
			return -1;
		}
		visable[u] = true;
		ans += dis[u];
		for (j = 0; j <Adj1[u].size(); j++)
		{
			int v = Adj1[u][j].v;
			if (visable[v] ==false && Adj1[u][j].dis < d[v])
			{
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}
int main(int argc, char* argv[])
{
	return 0;
}

// 26graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

struct testNode{
	int v, w;
	testNode(int _v, int _w):v(_v),w(_w) {}	//constructor
};
//adj[1].push_back(testNode(3,4));
//////////////////////////////////////////////////////////////////////////
// adjacent matrix 
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void DFS(int u, int depth)
{
	vis[u] = true;
	for (int v = 0; v < n; v++)
	{
		if (vis[v] ==false && G[u][v] != INF)
		{
			DFS(v, depth + 1);
		}
	}
}
void DFSTrave()
{
	for (int u = 0; u < n; u++)
	{
		if (vis[u] == false)
		{
			DFS(u, 1);
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//Adjacency list
vector<int> Adj[MAXV];
//int n;
//bool vis[MAXV] = {false};
void DFS_list(int u, int depth)
{
	vis[u] = true;
	for (int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i];
		if (vis[v] == false)
		{
			DFS_list(v, depth+1);
		}
	}
}
void DFSTrave_list()
{
	for (int u = 0; u < n; u++)
	{
		if (vis[u] == false)
		{
			DFS_list(u, 1);
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//BFS
bool inq[MAXV] = {false};
void BFS(int u)
{
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++)
		{
			if (inq[v] ==false && G[u][v] !=INF)
			{
				q.push(v);
				inq[v] = true;
			}
		}
	}
}
void BFSTrave()
{
	for (int u = 0; u < n; u++)
	{
		if (inq[u] == false)
		{
			BFS(u);
		}
	}
}
//////////////////////////////////////////////////////////////////////////

// int n;
// bool inq[MAXV] = {false};

struct Node {
	int v;
	int layer;
};
vector<Node> Adj1[MAXV];
void BFS_list(int s)
{
	queue<Node> q;
	Node start;
	start.v = s;
	start.layer = 0;
	q.push(start);
	inq[start.v] = true;
	while (!q.empty())
	{
		Node topNode = q.front();
		q.pop();
		int u =topNode.v;
		for (int i = 0; i < Adj1[u].size(); i++)
		{
			Node next = Adj1[u][i];
			next.layer = topNode.layer + 1;
			if (inq[next.v] == false)
			{
				q.push(next);
				inq[next.v] = true;
			}
		}
	}
}
void BFSTrave_list()
{
	for (int u = 0; u < n; u++)
	{
		if (inq[u] == false)
		{
			BFS(u);
		}
	}
}

void problem_BFS_list(int s,int L)
{
	int numForward = 0;
	queue<Node> q;
	Node start;
	start.v = s;
	start.layer = 0;
	q.push(start);
	inq[start.v] = true;
	while (!q.empty())
	{
		Node topNode = q.front();
		q.pop();
		int u =topNode.v;
		for (int i = 0; i < Adj1[u].size(); i++)
		{
			Node next = Adj1[u][i];
			next.layer = topNode.layer + 1;
			if (inq[next.v] == false && next.layer <= L)
			{
				q.push(next);
				inq[next.v] = true;
				numForward++;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////
const int maxn =2010;
// const int INF = 1000000000;

map<int, string> intToString;
map<string, int> stringToInt;
map<string ,int> Gang;
//int G[maxn][maxn] = {0};
int weight[maxn] = {0};
//int n;
int k, numPerson = 0;
//bool vis[maxn] = {false};
//struct Gang {
//	string head;
int numMember;
//}arrayGang[maxn];
// int numGang = 0;
//bool cmp(Gang a, Gang b)
//{
//	return a.head <b.head;
// }
void problem_DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
	numMember++;
	vis[nowVisit] = true;
	if (weight[nowVisit] > weight[head])
	{
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++)
	{
		if (G[nowVisit][i]> 0)
		{
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if (vis[i] ==false)
			{
				problem_DFS(i,head, numMember, totalValue);
			}
		}
	}
}
void problem_DFSTrave()
{
	for (int i = 0; i < numMember; i++)
	{
		if (vis[i] == false)
		{
			int head = i, numMember = 0, totalValue = 0;
			problem_DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k)
			{
				Gang[intToString[head]] = numMember;
			}
		}
	}
}
int change(string str)
{
	if (stringToInt.find(str) != stringToInt.end())
	{
		return stringToInt[str];
	}
	else
	{
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}
int main(int argc, char* argv[])
{
//	int w;
//	string str1, str2;
//	cin>>n>>k;
//	for (int i = 0; i<n; i++)
//	{
//		cin >> str1 >> str2 >> w;
//		int id1 = change(str1);
//		int id2 = change(str2);
//		weight[id1] += w;
//		weight[id2] += w;
//		G[id1][id2] += w;
//		G[id2][id1] += w;
//	}
//	problem_DFSTrave();
//	cout<<Gang.size()<<endl;
//	map<string, int>::iterator it;
//	for (it =Gang.begin(); it!=Gang.end(); it++)
//	{
//		cout<<it->first<<" "<<it->second<<endl;
// 	}

	//////////////////////////////////////////////////////////////////////////
	Node user;
	int n, L, numFollow, idFollow;
	scanf("%d%d", n, &L);
	for (int i = 1; i<=n; i++)
	{
		user.v = i;
		scanf("%d", &numFollow);
		for (int j = 0; j < numFollow; j++)
		{
			scanf("%d", &idFollow);
			Adj1[idFollow].push_back(user);
		}
	}
	int numQuery, s;
	scanf("%d", &numQuery);
	for (int i = 0; i < numQuery; i++)
	{
		memset(inq, false, sizeof(inq));
		scanf("%d\n", &s);
		int numForward = problem_BFS_list(s,L);
		printf("%d\n", numForward);
	}
	return 0;
}

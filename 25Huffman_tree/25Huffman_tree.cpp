// 25Huffman_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <queue.h>
using namespace std;
priority_queue<long, vector<long>, greater<long>> q;//small top heap
int main(int argc, char* argv[])
{
	int n;
	long long temp, x, y, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%ld",&temp);
		q.push(temp);
	}
	while (q.size() > 1)
	{
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x + y);
		ans += x+y;
	}
	printf("%lld\n", ans);
	return 0;
}

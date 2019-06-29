// 35dynamic_planning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
#define max(a,b) (((a) > (b))?(a):(b))
#define min(a,b) (((a) < (b))?(a):(b))
/////////////////////////////////////////////////////////////////////////
//Fibonacci sequence optimal solution
//const int MAXV = 100;
//int dp[MAXV];
//
//int F(int n)		//O(2^n) -> O(n)
//{
//	if (n == 0 || n == 1)
//	{
//		return 1;
//	}
//	if (dn[n] != 1)
//	{
//		return dp[n];
//	}
//	else
//	{
//		dp[n] = F(n-1) + F(n-2);
//		return dp[n];
//	}
// }


//////////////////////////////////////////////////////////////////////////
//number_tower problem
//const int maxn = 1000;
//int f[maxn][maxn], dp[maxn][maxn];
//int main(int argc, char* argv[])
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			scanf("%d",&f[i][j]);
//		}
//	}
//	for (int j = 1;j <= n; j++)
//	{
//		dp[n][j] = f[n][j];
//	}
//	for (i = n-1; i >= 1; i--)
//	{
//		for (j = 1; j <=i; j++)
//		{
//			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) +f[i][j];
//		}
//	}
//	printf("%d\n", dp[1][1]);
//	return 0;
// }

//////////////////////////////////////////////////////////////////////////
//max continuous subseq sum
//const int maxn = 10010;
//int A[maxn], dp[maxn];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	dp[0] = A[0];
//	for (i = 1; i < n; i++)
//	{
//		dp[i] = max(A[i], dp[i-1] +A[i]);
//	}
//	int k = 0;
//	for (i = 1; i < n; i++)
//	{
//		if (dp[i] > dp[k])
//		{
//			k = i;
//		}
//	}
//	printf("%d\n", dp[k]);
//	return 0;
// }

//////////////////////////////////////////////////////////////////////////
///LIS
//const int N = 100;
//int A[N], dp[N];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	int ans = -1;
//	for (i = 1; i <= n; i++) //tail subscript
//	{
//		dp[i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			if (A[i] >= A[j] && (dp[j] + 1 > dp[i]))
//			{
//				dp[i] = dp[j] + 1;
//			}
//		}
//		ans = max(ans, dp[i]);
//	}
//	printf("%d", ans);
//	return 0;
// }
//////////////////////////////////////////////////////////////////////////
///LCS
//const int N = 100;
//char A[N],B[N];
//int dp[N][N];
//int main()
//{
//	gets(A+1);
//	gets(B+1);
//	int lenA = strlen(A+1);
//	int lenB = strlen(B+1);
//	for (int z = 0; z < lenA; z++)
//	{
//		dp[z][0] = 0;
//	}
//	for (z = 0; z <= lenB; z++)
//	{
//		dp[0][z] = 0;
//	}
//
//	for (int i = 1; i <= lenA; i++)
//	{
//		for (int j = 1; j <=lenB; j++)
//		{
//			if (A[i] == B[j])
//			{
//				dp[i][j] = dp[i-1][j-1] + 1;
//			}
//			else
//			{
//				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//			}
//		}
//	}
//	printf("%d\n",dp[lenA][lenB]);
//	return 0;
// }
//////////////////////////////////////////////////////////////////////////
///Longest return substring   //O(n^2)
//const int maxn = 1010;
//char S[maxn];
//int dp[maxn][maxn];
//int Manacher(char *st, int len)
//{
//	int mx = 0, ans = 0, po = 0;
//	for (int i = 1; i <=len; i++)
//	{
//		if (mx > i)
//		{
//			Len[i] = min(mx - i, len[2 * po - i]);
//		}
//		else
//		{
//			Len[i] = 1;
//		}
//		while (st[i -len[i]] == st[i + len[i]])
//		{
//			len[i]++;
//		}
//		if (len(i) + i > mx)
//		{
//			mx = len[i] + i;
//			po = i;
//		}
//		ans = max(ans, Len[i]);
//	}
//	return ans - 1;
//}
//int main()
//{
//	gets(S);
//	int len = strlen(S),ans = 1;
//	memset(dp, 0, sizeof(dp));
//	for (int i = 0; i < len; i++)
//	{
//		dp[i][i] = 1;
//		if (i < len - 1)
//		{
//			if (S[i] == S[i+1])
//			{
//				dp[i][i+1] =1;
//				ans = 2;
//			}
//		}
//	}
//	for (int L = 3; L<= len; L++)
//	{
//		for (int i =0; i +L-1 < len; i++)
//		{
//			int j = i + L -1;
//			if (S[i] ==S[j] && dp[i +1][j-1] == 1)
//			{
//				dp[i][j] = 1;
//				ans = L;
//			}
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
// }
//const int mx = 10000;
//char ss[mx + 5], s[(mx << 1) + 5];
//int len[(mx << 1) + 5];
//void debug()
//{
//	int i;
//	for (i = 1; s[i]; ++i) printf("%c ", s[i]);
//	puts("");
//	for (i = 1; s[i]; ++i) printf("%d ", len[i]);
//	puts("");
//}
// 
//int main()
//{
//	int right, mid, i, maxlen;
//	while (gets(ss))
//	{
//		memset(s, 0, sizeof(s));
//		s[0] = '$';
//		for (i = 0; ss[i]; ++i) s[(i << 1) + 1] = '#', s[(i << 1) + 2] = ss[i];
//		s[(i << 1) + 1] = '#';
//		memset(len, 0, sizeof(len));
//		maxlen = right = mid = 0;
//		for (i = 1; s[i]; ++i)
//		{
//			len[i] = (i < right ? min(len[(mid << 1) - i], right - i) : 1);
//			while (s[i + len[i]] == s[i - len[i]]) ++len[i];
//			maxlen = max(maxlen, len[i]);
//			if (right < i + len[i]) mid = i, right = i + len[i];
//		}
//		printf("%d\n", maxlen - 1);
//		debug();
//	}
//	return 0;
// }
//////////////////////////////////////////////////////////////////////////
///DAG
int DP(int i)
{
	if(dp[i] > 0) return dp[i];
	for (int j = 0; j < n; j++)
	{
		if (G[i][j] != INF)
		{
			int temp = DP(j)+ G[i][j];
			if (temp > dp[j])
			{
				dp[i] = temp;
				choice[i] = j;
			}
		}
	}
	return dp[i];
}
void printPath(int i)
{
	printf("%d", i);
	while (choice[i] != -1)
	{
		i = choice[i];
		printf("->%d", i);
	}
}
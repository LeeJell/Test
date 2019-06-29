// 37string_hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
//const int MOD = 100000007;
// const int P = 10000019;
//vector<int> ans;
//long long hashFunc(string str)
//{
//	long long H = 0;
//	for (int i = 0; i < str.length(); i++)
//	{
//		H = (H*P + str[i] - 'a') % MOD;
//	}
//	return H;
//}
//
//int main(int argc, char* argv[])
//{
//	string str;
//	while (getline(cin, str), str != "#")
//	{
//		long long id = hashFunc(str);
//		ans.push_back(id);
//	}
//	sort(ans.begin(), ans.end());
//	int count = 0;
//	for (int i = 0; i < ans.size(); i++)
//	{
//		if (i == 0 || ans[i] != ans[i-1])
//		{
//			count++;
//		}
//	}
//	cout<<count<<endl;
//	return 0;
// }
const int MOD = 100000007;
const int P = 10000019;
const int MAXN = 1010;
long powP[MAXN], H1[MAXN] = {0}, H2[MAXN] = {0};
vector<pair<int, int> > pr1, pr2;
void init(int len)
{
	powP[0] = 1;
	for (int i = 1; i <=len; i++)
	{
		powP[i] = (powP[i-1]*P) % MOD;
	}
}
void calH(long H[], string &str)
{
	H[0] = str[0];
	for (int i = 1; i < str.length(); i++)
	{
		H[i] = (H[i - 1] * P +str[i])%MOD;
	}
}
int calSingleSubH(long H[], int i, int j)
{
	if(i == 0)
		return H[j];
	return ((H[j] - H[i - 1]* powP[j - i + 1])%MOD + MOD)%MOD;
}
//void calSubH(long H[], int len, vector<pair<int, int> >&pr)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = i; j < len; j++)
//		{
//			int hashValue = calSingleSubH(H, i , j);
//			pr.push_back(make_pair(hashValue, j - i + 1));
//		}
//	}
//}
//
//int getMax()
//{
//	int ans = 0;
//	for (int i = 0; i < pr1.size(); i++)
//	{
//		if (pr1[i].first == pr2[i].first)
//		{
//			ans = max(ans, pr1[i].second);
//		}
//	}
//	return ans;
//}
//int main()
//{
//	string str1,str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	init(max(str1.length(), str2.length()));
//	calH(H1, str1);
//	calH(H2, str2);
//	calSubH(H1,str1.length(), pr1);
//	calSubH(H2,str2.length(), pr2);
//	printf("ans = %d\n", getMax());
//	return 0;
// }

//////////////////////////////////////////////////////////////////////////
int binarySearch(int l, int r, int len, int i, int isEven)
{
	while (l < r)
	{
		int mid = l - (l-r)/2;
		int H1L = i - mid + isEven, H1R = i;
		int H2L = len - l - (i + mid), H2R = len - l - (i + isEven);
		int hashL = calSingleSubH(H1, H1L, H1R);
		int hashR = calSingleSubH(H2, H2L, H2R);
		if (hashL != hashR)
		{
			r = mid;
		}
		else
		{
			l = mid + l;
		}
	}
	return l - 1;
}
int main()
{
	init(MAXN);
	string str;
	getline(cin, str);
	calH(H1, str);
	reverse(str.begin(),str.end());
	calH(H2, str);
	int ans = 0;
	for (int i = 0; i <str.length(); i++)
	{
		int maxLen = min(i, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen,str.length(), i, 0);
		ans = max(ans, k * 2 + 1);
	}
	for ( i = 0; i < str.length(); i++)
	{
		int maxLen = min(i+1, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 1);
		ans = max(ans, k*2);
	}
	printf("%d\n", ans);
	return 0;
}
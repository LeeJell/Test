// 42fraction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

struct Fraction {
	int up, down;
};

int gcd(int a, int b)
{
	return !b?a:gcd(b, a%b);
}
Fraction reduction(Fraction result)
{
	if (result.down < 0)
	{
		result.up = result.up;
		result.down = -result.down;
	}
	if (result.up == 0)
	{
		result.down = 1;
	}
	else
	{
		int d = gcd(abs(result.up), abs(result.down));
		result.up/=d;
		result.down/=d;
	}
	return result;
}
Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up*f2.down + f2.up*f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

void showResult(Fraction r)
{
	r = reduction(r);
	if (r.down == 1)
	{
		printf("%lld",r.up);
	}
	else if (abs(r.up) > r.down)
	{
		printf("%d %d/%d",r.up/r.down, abs(r.up)%r.down, r.down);
	}
	else
	{
		printf("%d%d",r.up, r.down);
	}
	
}
Fraction minu(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up*f2.down - f2.up*f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up*f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up*f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}


//////////////////////////////////////////////////////////////////////////
//Prime number
bool isPrime(int n)
{
	if(n <= 1) return false;
	int sqr = (int) sqrt(1.0* n);
	for (int i = 2; i <= sqr; i++)  ///i * i <= n;
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] ={0};
void FindPrime()
{
//	for (int i = 1; i <maxn; i++)
//	{
//		if (isPrime(i) == true)
//		{
//			prime[pNum++] = i;
//			p[i] = true;
//		}
// 	}
	for (int i = 2; i < maxn; i++) //O(nloglogn)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			for (int j = i + i; j < maxn; j+=i)
			{
				p[j] = true;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//Prime factorization
struct factor {
	int x,cnt;
}fac[10];

int main(int argc, char* argv[])
{
	FindPrime();
	int n, num = 0;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1 = 1");
	}
	else
	{
		printf("%d=", n);
		int sqr = (int) sqrt(1.0 * n);
		for (int i = 0; i < pNum && prime[i] <= sqr; i++)
		{
			if (n % prime[i] == 0)
			{
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (n % prime[i] == 0)
				{
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if (n == 1)
			{
				break;
			}
		}
		if (n != 1)
		{
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for (i = 0; i < num; i++)
		{
			if(i > 0) printf("*");
			printf("%d",fac[i].x);
			if (fac[i].cnt > 1)
			{
				printf("^%d", fac[i].cnt);
			}
		}
	}
	return 0;
}

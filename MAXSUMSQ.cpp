#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;

void max_sum(vector<ll>  arr,int n)
{
	ll rmx = -INF;
ll mn = 0; ll mnct = 1;
 ll rct =0;
 int sum;
for(int i=sum=0;i<n;i++)
{
	sum += arr[i];
			
	if( sum - mn > rmx) rmx = sum-mn ,  rct = mnct;
	else if( sum - mn == rmx ) rct += mnct;
 
	if( sum < mn ) mn = sum ,  mnct = 1;
	else if( sum == mn ) mnct++;
}
	printf("%lld %lld\n",rmx,rct);
}

int main()
{
	int n =0;
	scanf("%d",&n);
	while(n--)
	{
		int t =0;
		cin>>t;
		vector<ll> vec;
		for(int i =0;i<t;i++)
		{
			ll y =0;
			scanf("%lld",&y);
			vec.PB(y);
		}
		max_sum(vec, t);
	}
	return 0;
}
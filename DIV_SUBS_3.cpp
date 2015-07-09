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
#define INF 1<<20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;

vector<int>arr;

int main()
{
	int tc =0;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		
		for(int i =0;i<n;i++)
		{
			ll t =0;
			scanf("%lld",&t);
			arr.PB(t);
		}
		int sz =arr.size();
		ll k = 1<<sz;
		bool bt =true;
		for(ll  i =1;i<=k;i++)
		{
			ll y =i;
			ll sum =0;
			ll t =0;vector<int>ind;
			while(y!=0)
			{
				if(y&1)
				{
				sum+=(arr[n-t-1]);
				ind.PB(n-t-1);
				}
				t++;
				y>>=1;
			}
			if(sum%n ==0 )
			{
				sort(ind.begin(),ind.end());
				cout<<ind.size()<<endl;
				for(int i =0;i<ind.size();i++)
				{
				cout<<ind[i]+1;
				if(i!=ind.size()-1)
				cout<<" ";
				}
				cout<<endl;
				bt =false;
				break;
			}
		}
		if(bt)
		cout<<"-1"<<endl;
		arr.clear();
	}
	return 0;
}
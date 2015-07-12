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
#define MOD 1000000007
#define ll long long 
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		ll num = 0;
		cin>>num;
		ll z = ceil(log2(num));
		ll start =0; ll end = pow(2,z);
		if(num != start && num != end)
		{
			ll t = 1;
			ll dup =end;
			ll mid = (dup + start)/2;

			while(mid != num)
			{
				if(num > mid)
				{
					start = mid;
				}
				else if(num < mid)
				{
					dup = mid;
				}
				mid = (dup + start)/2;
				t++;
			}
			cout<<end<<" "<<t<<endl;
		}
		else 
		cout<<end<<" "<<0<<endl;
	}
	return 0;
}
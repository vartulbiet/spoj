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
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int y =0;
		cin>>y;
		vector<int>a,b;
		REP(i,1,y)
		{
			int u =0;
			cin>>u;
			a.PB(u);
		}
		REP(i,1,y)
		{
			int u =0;
			cin>>u;
			b.PB(u);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll ans =0;
		REP(i,0,(y-1))
		{
			ans +=(a[i]*b[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
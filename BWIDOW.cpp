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
		int x = 0;
		cin>>x;
		int ur = 0,index;
		vector<pair<int,int> >rings;
		for(int i =0 ;i < x; i++)
		{
			int a,b;
			cin>>a>>b;
			if(a>ur)
			{
				ur =a;
				index = i;
			}
			rings.PB(MP(a,b));
		}
		bool bt =true;
		for(int i =0 ;i < x && bt; i++)
		{
			if(i!=index)
			{
				if(rings[i].second >= ur)
					bt =false;
			}
		}
		if(bt)
			cout<<index+1<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
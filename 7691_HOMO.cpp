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
int main()
{
	int n =0;
	scanf("%d",&n);
	map<ll,int>mymap;
		int het =0;
		int hom =0;
	while(n--)
	{
		char s[7];
		ll x;
		scanf("%6s",&s);
		scanf("%lld",&x);
		if(s[0] == 'i')
		{
			//cout<<"000"<<endl;
			mymap[x]++;
			if(mymap[x] == 2)
				hom++;
			if(mymap[x] == 1)
				het++;
		}
		else
		{
			if(mymap[x]>0)
			{
				mymap[x] -- ;
				if(mymap[x] == 1)
					hom--;
				if(mymap[x] == 0)
					het--;
			}
		}
		//cout<<hom<<"     "<<het<<endl;
		if ( hom >= 1 && het >= 2 ) {
            printf( "both\n" );
        }
        else if ( hom >= 1 ) {
            printf( "homo\n" );
        }
        else if ( het >= 2 ) {
            printf( "hetero\n" );
        }
        else {
            printf( "neither\n" );
        }
	}
	return 0;
}
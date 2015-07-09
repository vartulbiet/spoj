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
static short table[6100+1][6100+1];

int main()
{
	int n =0;
	scanf("%d",&n);

	while(n--)
	{
		char s[6102];
		scanf("%s",s);
		//cout<<s<<endl;
		int x =strlen(s);
		memset(table, 0 , sizeof(table));
		for(int i = 1 ;i<x;i++)
		{
			for(int j = 0,k= i;k<x;k++,j++)
			{
				table[j][k] = min(table[j][k-1],table[j+1][k])+1;
				if(s[j] == s[k])
				{
					table[j][k] = table[j+1][k-1];
				}
			}
		}
		printf("%d\n",table[0][x-1]);
	}
	return 0;
}
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
	int m =0;
	scanf("%d",&m);
	char a[5005],b[5005];
	
	scanf("%s",a);
	for(int i =0;i<m;i++)
		b[i] = a[m-i-1];
	//cout<<a<<b;
short int table[2][5005];
	for(int i =0;i<=m;i++)
	{
		for(int j =0;j<=m;j++)
		{
			if(i==0 ||j==0)
				table[1][j] =0;
			else if(a[i-1] == b[j-1])
			{
				table[1][j] = table[0][j-1]+1;
			}
			else
				table[1][j] =max(table[0][j],table[1][j-1]);
		//	cout<<table[1][j]<<" ";
		}
		//cout<<endl;
		for(int j= 0;j<=m;j++)
			table[0][j] = table[1][j];
	}
	printf("%d\n",m-table[1][m]);
	return 0;
}
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
using namespace std;
struct node
{
	int o;
	int n;
	int w;
};
int a,b;
void KNAPSACK(vector<node>&vec, int n)
{
	vector< vector<node> >matrix;
	for(int i = 0; i < n+1 ;i++)
	{
		vector<node>temp;
		for(int j = 0; j < n+1; j++)
		{	
			struct node t;
			t.o = x;
			t.n = y;
			t.w = z;
			temp.PB(t);
		}
		matrix.PB(temp);
	}
	for(int i = 1; i< n+1 ;i++)
		matrix[i][0] = vec[i-1];
	int min_weight =0;
	for(int i = 1 ;i < n+1 ;i++)
	{
		struct node val = vec[i-1];
		for(int j = 1 ; j < n+1 ; j++)
		{
			if(matrix[i][j].o < val.o || matrix[i][j].n < val.n)
			{
				matrix[i][j].o +=val.o;
				matrix[i][j].n +=val.n;
				matrix[i][j].w +=val.w;
			}
		}
	}
}
int main()
{
	int test = 0;
	cin>>test;
	while(test--)
	{
		cin>>a>>b;
		int c;
		cin>>c;
		vector<node >vec;
		for(int i = 0 ; i < c; i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			struct node t;
			t.o = x;
			t.n = y;
			t.w = z;
			vec.PB(t);
		}
		KNAPSACK(vec,c);
	}	
	return 0;
}
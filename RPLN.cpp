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
void init_tree(int*arr,int st,int end,int*seg,int node)
{
	if(st>end)
		return;
	else if(st == end)
	{
		seg[node] = arr[st];
	}
	else
	{
		init_tree(arr,st,(st+end)>>1,seg,2*node);
		init_tree(arr,((st+end)>>1)+1,end,seg,2*node+1);
		seg[node] = min(seg[2*node],seg[2*node+1]);
	}
}

int*create_segment_tree(int*arr,int init,int end)
{
	int sz = end+1;
	int  h =  ceil(log2(sz));
	int size = 2*pow(2,h) - 1;
	int* seg = (int*)malloc(sizeof(int)*size);
	init_tree(arr,init,end,seg,1);
	return seg;
}
int query(int*seg,int node,int st,int end,int x,int y)
{
	if(x>y || st>y || end<x)
	{
		return 1<<30;
	}
	else if(st>=x && end<=y)
	{
		return seg[node];
	}
	else
	{
		return seg[node]  =  min(query(seg,2*node,st,(st+end)>>1,x,y) , query(seg,2*node+1,((st+end)>>1)+1,end,x,y));
	}
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	int tt = 1;
	while(n--)
	{
		cout<<"Scenario #"<<tt++<<":"<<endl;
		cout<<endl;
		int m,q;
		scanf("%d%d",&m,&q);
		int*arr = (int*)malloc(sizeof(int)*m);
		for(int i =0;i<m;i++)
		{
			int u =0;
			scanf("%d",&u);
			arr[i] = u;
		}
		int*tree = create_segment_tree(arr,0,m-1);
		for(int i =0;i<q;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",query(tree,1,0,m-1,a-1,b-1));
		}
	}
	return 0;
}
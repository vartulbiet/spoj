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
int arr[100005];

struct node
{
	vector<int>hold;
};
struct node seg[4*100005];

void merge(int node)
{
	int l = 2*node;
	int r = 2*node+1;
	int i = 0,j =0;
	while(i<seg[l].hold.size() && j<seg[r].hold.size())
	{
		if(seg[l].hold[i] > seg[r].hold[j])
		{
			seg[node].hold.PB(seg[r].hold[j]);
			j++;
		}
		else
		{
			seg[node].hold.PB(seg[r].hold[j]);
			i++;
		}
	}
	while(i<seg[l].hold.size())
	{
		seg[node].hold.PB(seg[l].hold[i]);
		i++;
	}
	while(j<seg[r].hold.size())
	{
		seg[node].hold.PB(seg[r].hold[j]);
		j++;
	}
}
void make_tree(int i, int j,int node)
{
	if(i>j)
		return;
	if(i == j)
	{
		seg[node].hold.PB(arr[i]);
	}
	else
	{
		make_tree(i,(i+j)/2,2*node);
		make_tree((i+j)/2 + 1,j,2*node+1);
		merge(node);
	}
}

void init_tree(int n)
{
	make_tree(0,n-1,1);
}

int do_query(int i,int j,int r1,int r2,int node,int element)
{
	if(r1>r2 || i>r2 || j<r1)
		return -1;
	if(i==j)
	{
		return seg[node].hold[element-1];
	}
	else
	{
		if(seg[2*node].hold.size()>=element)
		{
			return do_query(i,((i+j)>>1),r1,r2,2*node,element);
		}
		else
		{
			return do_query(((i+j)>>1)+1,j,r1,r2,2*node+1,element - seg[2*node].hold.size());
		}
	}
}
int main()
{
	int n =0;
	int q =0;
	cin>>n>>q;
	for(int i =0;i<n;i++)
	{
		int u =0;
		cin>>u;
		arr[i] = u;
	}
	init_tree(n);
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		cout<<do_query(0,n-1,x-1,y-1,1,z)<<endl;
	}
	return 0;
}
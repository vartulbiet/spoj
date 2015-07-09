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
#define s 30005
char arr[s];

struct node
{
	int left;
	int right;
};
struct node seg[4*s];
void init(int i,int j,int node){
	if(i == j)
	{
		if(arr[i]=='(')
		{
			seg[node].left = 0;
			seg[node].right = 1;
		}
		else if(arr[i]==')')
		{
			seg[node].left = 1;
			seg[node].right = 0;
		}
	}
	else
	{
		int mid = (i+j)>>1;
		init(i,mid,2*node);
		init(mid + 1,j,1+2*node);
		int mint = min(seg[2*node].right,seg[2*node+1].left);

			seg[node].left = seg[2*node].left - mint + seg[2*node+1].left;
			seg[node].right = seg[2*node+1].right - mint + seg[2*node].right;

	}
}
void update(int i,int j, int index,int node)
{
	if(i == j)
	{
		if(arr[i] == '(')
		{
			arr[i] = ')';
			seg[node].right--;
			seg[node].left++;
			
		}
		else{
			arr[i] = '(';
			seg[node].left--;
			seg[node].right++;
		}
	}
	else
	{
		int mid = (i+j)>>1;
		update(i,mid,index,2*node);
		update(mid + 1,j,index,1+2*node);
		int mint = min(seg[2*node].right,seg[2*node+1].left);

			seg[node].left = seg[2*node].left - mint + seg[2*node+1].left;
			seg[node].right = seg[2*node+1].right - mint + seg[2*node].right;
	}
}
void build_tree(int sz)
{
	init(0,sz-1,1);
}
int main()
{
	
	int n =10;
	int tt =1;
	while(n--)
	{
		int x = 0;
		printf("Test %d:\n", tt++);
		scanf("%d", &x);
		scanf("%s",arr);
		build_tree(x);
		int q =0;
		scanf("%d", &q);
		while(q--)
		{
			int a =0;
			scanf("%d", &a);
			if(a == 0)
			{
				int ans = !seg[1].left && !seg[1].right;
                if (ans) puts("YES");
                else puts("NO");
			}
			else
			update(0,x-1,a-1,1);
		}
	}
	   
	return 0;
}
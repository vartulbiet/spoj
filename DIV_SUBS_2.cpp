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
vector<int>arr;
vector<bool>visited;
int n;
int ans;
int summ;
bool bt;
vector<int>give;
void recursion(int count,ll sum)
{
	if(sum%n == 0)
	{
	ans = count;summ =sum;
	bt =false;
	for(int i =0;i<visited.size();i++)
	{
		if(visited[i])
		give.PB(i);
	}
	return;
	}
	for(int i =0;i<n && bt;i++)
	{
		if(!visited[i])
		{
			sum+=arr[i];
			visited[i] = true;
			recursion(count+1,sum);
			if(!bt)
			return;
			visited[i] = false;
			sum -=arr[i];
		}
	}
}
int main()
{
	int tc =0;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		ans =0;summ =0;bt =true;
		for(int i =0;i<n;i++)
		{
			int t =0;
			scanf("%d",&t);
			arr.PB(t);
			visited.PB(false);
		}
		for(int  i= 0;i<n && bt;i++)
		{
			visited[i] = true;
			recursion(1,arr[i]);
			if(!bt)
			break;
			visited[i ]=  false;
		}
		cout<<ans<<endl;
		int y =0;
		for(int i =0;i<n;i++)
		{
			if(visited[i])
			{
			if(y!=0)
			cout<<" ";
			y++;
			cout<<i+1;
			}
		}
		cout<<endl;
		ans =0;
		arr.clear();
		visited.clear();
		give.clear();
	}
	return 0;
}
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
typedef make_pair MP
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
int ans = 0;
vector<ii >arr;
int n =0;
void recurse(curr_index,curr_sum)
{
	if(curr_index == n)
	return;
	if(curr_index ==n-1)
	{
		
		return;
	}
	//taking length
	curr_sum +=arr[curr_index].first;
	if(curr_index -1>=0)
		curr_sum += 
	else
		
	//taking breadth
	curr_sum +=arr[curr_index].first;
}
int main()
{
	cin>>n;
	
	for(int i =0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		arr.PB(MP(x,y));
	}
	recurse(arr);
	return 0;
}
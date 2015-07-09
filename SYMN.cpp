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
	vi arr;
	for(int i =0;i<n;i++)
	{
		int y =0;
		cin>>y;
		arr.PB(y);
	}
	int j = n-1;
	bool bt =true;
	for(int i =0;i<n && j>i;i++)
	{
		if(arr[i] != arr[j--])
			bt =false;
	}
	if(bt)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
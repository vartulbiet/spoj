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
	cin>>n;
	int mad = n-1;
	vector<int>arr;
	while(n--)
	{
		int y =0;
		cin>>y;
		arr.PB( y);
	}
	bool bt =true;
	int maxx =0;
	for(int i =0;i<arr.size() && bt;i++)
	{
		if(arr[i] >mad)
			bt =false;
		maxx = max(maxx,arr[i]);
	}
	if(!bt)
	cout<<"-1"<<endl;
	else if(maxx ==0)
	cout<<"0"<<endl;
	else
	{
		int c =0;int d =0;
		for(int i =0;i<arr.size();i++)
		{
			if(arr[i] == maxx -1)
			c++;
			if(arr[i] == maxx)
			d++;
		}
		if(d == arr.size())
		cout<<maxx+1<<endl;
		else if(c == maxx)
		cout<<c<<endl;
		else
		cout<<"-1"<<endl;
	}
	return 0;
}
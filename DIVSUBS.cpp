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
 int table[1005][1005];
int counti[1005][1005];
char backTrace[1005][1005];
vector<int>arr;
int n;
ll sum;
void subset_sum()
{
	for(int  i =0;i<1005;i++)
	{
		for(int j =0;j<1005;j++)
		{
		table[i][j] = 0;
		counti[i][j]=0;
		backTrace[i][j] ='-';
		}
		table[i][0] =1;
	}
	for(int i =1;i<=n;i++)
	{
		for(int j =0;j<=sum;j++)
		{
			table[i][j] =table[i-1][j];
			counti[i][j] = counti[i-1][j];
			backTrace[i][j] = '^';
			if(j>=arr[i-1])
			{
				if(table[i-1][j-arr[i-1]] ==1)
				{
					table[i][j] =1;
					counti[i][j] = 1+counti[i-1][j-arr[i-1]];
					backTrace[i][j] = '|';
				}
			}
		}
	}
	int ind = 0;int k =n;
	for(int i =1;i<sum;i++)
	{
		if(table[n][i] == 1 && (i%n ==0))
		{
		cout<<counti[n][i]<<endl;
		ind =i;
		break;
		}
	}
	char ch = backTrace[k][ind];
	vector<int>anss;
	while(k>0 && ind >0)
	{
			if(ch =='|')
			{
				anss.PB(k);
				k--;
				ind = ind - arr[k]; 
				//cout<<" "<<ind<<endl;
				if(ind<0 || k<0)
				break;
				ch = backTrace[k][ind];
			}
			else if(ch =='^')
			{
				k--;
				//cout<<"~"<<ind<<endl;
				if(k<0)
				break;
				ch = backTrace[k][ind];
			}
			else
			break;
	}
	sort(anss.begin(),anss.end());
	for(int i =0;i<anss.size();i++)
	cout<<anss[i]<<" ";
	cout<<endl;
}
int main()
{
	int tc =0;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		for(int i =0;i<n;i++)
		{
			ll y =0;
			cin>>y;
			arr.PB(y);
		}
		for(int i =0;i<n;i++)
		sum+=arr[i];
		sort(arr.begin(),arr.end());
		subset_sum();
		arr.clear();
	}
	return 0;
}
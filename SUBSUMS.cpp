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
typedef vector<int> vi;
typedef pair<int, int> ii;
int get_sum(int num,int*arr,int st,int end)
{
	int sum = 0;
	//cout<<num;
	while(num!=0)
	{
		if(num & 1)
		{
			sum +=arr[end];
		}
		end--;
		num = num>>1;
	}
	return sum;
}

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int uu = n/2;
	int*arr = (int*)malloc(sizeof(int)*n);
	
	for(int i =0;i<n;i++)
		cin>>arr[i];
	
	int x = 0;
	x = pow(2,uu)-1;
	int y = x;
	vector<int>dum;
	vector<int>sum;
	while(true)
	{
		sum.PB(get_sum(x,arr,0,uu-1));
		if(x == 0)
			break;
		x = (x-1)&y;
	}
	x = pow(2,n-uu)-1;
	y =x;
	while(true)
	{
		dum.PB(get_sum(x,arr,uu,n-1));
		if(x == 0)
			break;
		x = (x-1)&y;
	}
	sort(sum.begin(),sum.end());
	ll res = 0;
	  for(int i=0;i<dum.size();i++)
    {
        vector<int>::iterator low=lower_bound(sum.begin(),sum.end(),a-dum[i]);
         vector<int>::iterator high=upper_bound(sum.begin(),sum.end(),b-dum[i]);
        res+=(high-sum.begin())-(low-sum.begin());
    }
	cout<<res<<endl;
	return 0;
}
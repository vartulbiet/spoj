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
struct node
{
	int a,b,c;
};
void LIS(vector<pair < pair<int,int>,int> >arr)
{
	vector<int>temp;
	//for(int i =0;i<arr.size();i++)
	//	cout<<arr[i].first.first<<" "<<arr[i].first.second<<" "<<arr[i].second<<endl;
	//cout<<endl;
	for(int i =0;i<arr.size();i++)
		temp.PB(arr[i].second);
	for(int i =0;i<arr.size();i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[j].first.first<arr[i].first.first && arr[j].first.second<arr[i].first.second)
				temp[i] = max(temp[i],temp[j]+arr[i].second);
		}
	}
	int ans =0;
	for(int i =0;i<arr.size();i++)
		ans = max(ans,temp[i]);
	cout<<ans<<endl;
}
int main()
{
	int n  =0;
	cin>>n;
	while(n!=0)
	{
		vector<pair< pair<int,int>,int> >vec;
		for(int i =0;i<n;i++)
		{
			struct node x;
			cin>>x.a>>x.b>>x.c;
			pair< pair<int,int>,int> p = MP(MP(x.a,x.b),x.c);
			vec.PB(p);
			struct node y;
			y.a =x.b;y.b =x.a;y.c =x.c;p = MP(MP(y.a,y.b),y.c);vec.PB(p);
			y.a =x.c;y.b =x.a;y.c =x.b;p = MP(MP(y.a,y.b),y.c);vec.PB(p);
			y.a =x.a;y.b =x.c;y.c =x.b;p = MP(MP(y.a,y.b),y.c);vec.PB(p);
			y.a =x.b;y.b =x.c;y.c =x.a;p = MP(MP(y.a,y.b),y.c);vec.PB(p);
			y.a =x.c;y.b =x.b;y.c =x.a;p = MP(MP(y.a,y.b),y.c);vec.PB(p);
		}
		sort(vec.begin(),vec.end());
		LIS(vec);
		cin>>n;
	}
	return 0;
}
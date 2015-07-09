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
map<string,bool>mymap;
int lis;
vector<int>arr;
int n;
string s;
void LIS()
{
	 n = s.size();
	for(int i=0;i<n;i++)
	arr.PB(1);
	lis =0;
	for(int i =0;i<n;i++)
	{
		for(int j =i+1;j<n;j++)
		{
			if(s[i]<=s[j] && arr[i]+1>arr[j])
			arr[j] =arr[i]+1;
			lis = max(lis,arr[j]);
		}
	}
}
void recursion(string t,int ans,int last)
{
	if(ans==0)
	{
		reverse(t.begin(),t.end());
		mymap[t] = true;
	}
	else
	{
	for(int i =0;i<n;i++)
	{
		string y = t;
		
		//cout<<last<<" "<<i<<" "<<y<<ans<<endl;
		if(arr[i] == ans && ((y.size()>0 && y[y.size()-1] >=s[i] && last>i) ||(y.size()==0)))
		{
		y.PB(s[i]);
		//cout<<y<<endl;
		recursion(y,ans-1,i);
		}
	}
	}
}
int main()
{
	int k =0;
	cin>>k;
	while(k--)
	{
		cin>>s;
		LIS();
		string h;
		recursion(h,lis,-1);
		for(std::map<string,bool>::iterator it =mymap.begin();it!=mymap.end();it++)
		cout<<it->first<<endl;
		cout<<endl;
		arr.erase(arr.begin(),arr.end());
		mymap.erase(mymap.begin(),mymap.end());
	}
	return 0;
}

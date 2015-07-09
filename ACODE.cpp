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
vector<ull>arr;
int getInt(string s)
{
	int a = (s[0]-'0')*10;
	int b = (s[1] - '0');
	return a+b;
}

ll solve(string s,int x)
{
	if(s.size() == 1 && s[0]=='0')
		return 0;
	if(s.size() == 1 && s[0]!='0')
		return 1;
	if(s.size() == 2 && getInt(s)<=26 && getInt(s)>0 && s[0]!='0' &&s[1]!='0')
		return 2;
	if(s.size() == 2 &&getInt(s)==0)
		return 0;
	if(s.size() == 2)
		return 1;
	else if(s.size()>2)
	{
		string temp =s.substr(0,2);
		int y = getInt(temp);
		if(y>0 && y<=26 && temp[0]!='0' && temp[1]!='0')
		{
			if(arr[x] == -1)
			{
				ull u = solve(s.substr(1,s.size()-1),x+1);
				ull v = solve(s.substr(2,s.size()-2),x+2);
				arr[x] = u+v;
			}
			return arr[x];
		}
		else if( y>0 && y<=26 && temp[0] =='0')
			return 0;
		else if(y>0 && y<=26 && temp[1] =='0')
		{
			return solve(s.substr(2,s.size()-2),x+2);
		}
		else if(temp[1] == '0')
			return 0;
		else 
		{
			if(arr[x] == -1)
			{
				ull u = solve(s.substr(1,s.size()-1),x+1);
				arr[x] = u;
			}
			return arr[x];
		}
	}
}

int main()
{
	string s;
	cin>>s;
	while(s!="0")
	{
		int n = s.size();
		for(int i =0;i<n;i++)
			arr.PB(-1);
		ull ans = solve(s,0);
		if(s[0] == '0')
			ans =0;
		cout<<ans<<endl;
		cin>>s;
		arr.erase(arr.begin(),arr.end());
	}
	return 0;
}
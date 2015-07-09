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
bool _check(string s)
{
	for(int i =0;i<s.size();i++)
		if(s[i] == '-')
			return false;
	return true;
}
int main()
{
	string s;
	cin>>s;int tc =1;
	while(_check(s))
	{
		//cout<<s<<endl;
		stack<char>st;
		for(int i =0;i<s.size();i++)
		{
			if(s[i] == '{')
				st.push(s[i]);
			else
			{
				char x = ' ';
				if(st.size()!=0)
				 x =st.top();
				if(x == '{')
					st.pop();
				else
					st.push(s[i]);
			}
		}
		int ans =0;

	while(!st.empty())
	{
		char a = st.top();
		st.pop();
		char b = st.top();
		st.pop();
		if(a == b)
			ans++;
		else if(b == '{' && a =='}');
		else
			ans= ans+2;
	}
	cout<<tc++<<". "<<ans<<endl;
	cin>>s;
}
	return 0;
}
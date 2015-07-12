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
#define MOD 1000000007
#define ll long long 
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		stack<char>vec;
		string answer;
		for(int i =0 ; i < s.size(); i++)
		{
			if(s[i] == ')')
			{
				char t = vec.top();
				vec.pop();
				answer.push_back(t);
			}
			else if(s[i] == '*' || s[i] == '^' || s[i] == '+' || s[i] == '-' || s[i] == '/' )
				vec.push(s[i]);
			else if(s[i] !='(')
				answer.push_back(s[i]);
		}
		cout<<answer<<endl;
	}
	return 0;
}
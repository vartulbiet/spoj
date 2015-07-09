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
int main()
{
	int n =0;
	cin>>n;
	while(n != 0)
	{
		vector<int>arr(n);
		for(int i =0;i<n;i++)
		{
			int u =0;
			cin>>u;
			arr[i] = u;
		}
		int curr = 0;
		stack<int>st;
		bool bt =true;
		for(int i =0;i<n && bt;)
		{
			int x = arr[i];
			if(x == curr+1)
			{
				i++;
				curr =x;
				//cout<<curr<<endl;
			}
			else
			{
				if(!st.empty())
				{
					int u = st.top();
					if( u == curr+1)
					{
						st.pop();
						curr = u;
						//cout<<curr<<endl;
					}
					else
					{
						st.push(x);
						i++;
						//cout<<curr<<endl;
					}
				}
				else
				{
					st.push(x);
					i++;
					//cout<<curr<<endl;
				}
			}
		}
		while(!st.empty() && bt)
		{
			int c = st.top();
			if(c == curr+1)
			{
				st.pop();
				curr = c;
				//cout<<curr<<endl;
			}
			else
				bt = false;
		}
		if(bt)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		cin>>n;
	}
	return  0;
}
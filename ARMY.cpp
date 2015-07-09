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
	int n = 0;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		priority_queue<int>gq,mq;
		for(int i =0;i<a;i++)
		{
			int y = 0;
			cin>>y;
			gq.push(-y);
		}
		for(int i =0;i<b;i++)
		{
			int y = 0;
			cin>>y;
			mq.push(-y);
		}
		while(!mq.empty() && !gq.empty())
		{
			int x = mq.top();
			int y = gq.top();
			if(-x>-y)
			{
				gq.pop();
			}
			else
			{
				mq.pop();
			}
		}
		if(mq.empty())
		{
			cout<<"Godzilla"<<endl;
		}
		else
			cout<<"MechaGodzilla"<<endl;
	}
	return  0;
}
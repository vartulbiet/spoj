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

bool floyd_warshall(vector< vector<double> > vec)
{
	for(int i=0;i<vec.size();i++)
	{
		for(int j =0;j<vec.size();j++)
		{
			for(int k =0;k<vec.size();k++)
			{
				vec[j][k] = max(vec[j][k],vec[j][i]*vec[i][k]);
			}
		}
	}
	        		
		for(int i  = 0 ; i < vec.size(); i++)
		{
				if(vec[i][i] > 1.0)
					return false;
		}
		return true;
}
int main()
{
	int n =0;
	cin>>n;
	int test = 1;
	while(n!=0)
	{
		map<string,int>mymap;
		int j =0;
		for(int i =0 ;i < n ; i++)
		{
			string d;
			cin>>d;
			mymap[d] = j++;
		}
		int m =0;
		cin>>m;
		
		vector<vector<double> >graph;

		for(int i  = 0 ; i < n; i++)
		{
			vector<double>temp;
			for(int j  = 0 ; j < n; j++)
				temp.PB(0.0);
			graph.PB(temp);
		}
		for(int i =0 ; i< m ;i++)
		{
			string a,c;
			double b;
			cin>>a>>b>>c;
			graph[mymap[a]][mymap[c]] = b;
		}
		bool uu = floyd_warshall(graph);


		  if(!uu)
            cout<<"Case "<<test<<": Yes\n";
        else
            cout<<"Case "<<test<<": No\n";
		cin>>n;
		test++;
	}
	return 0;
}
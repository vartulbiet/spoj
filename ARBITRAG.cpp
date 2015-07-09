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
void floyd_warshall(vector< vector<double> > vec)
{
	bool bt = true;
	for(int i=0;i<vec.size();i++)
	{
		for(int j =0;j<vec.size();j++)
		{
			for(int k =0;k<vec.size();k++)
			{
				if(vec[j][k] == 0)
					vec[j][k] = (vec[j][i]*vec[i][k]);
				else if(vec[j][k] != (vec[j][i]*vec[i][k]))
				{
					bt = false;
					cout<<j<<" "<<k<<" "<<vec[j][k]<<" "<< (vec[j][i]*vec[i][k])<<endl;
				}
			}
		}
	}
	for(int i=0;i<vec.size();i++)
	{
		for(int j =0;j<vec.size();j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	if(bt)
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		map<string,int>mymap;
		int j =0;
		while(n--)
		{
			string d;
			cin>>d;
			mymap[d] = j++;
		}
		int m =0;
		cin>>m;
		
		vector<vector<double> >graph;
		for(int i =0;i<mymap.size();i++)
		{
			vector<double>temp;
			for(int j =0;j<mymap.size();j++)
			temp.PB(0.00);
			graph.PB(temp);
		}
		for(int i =0;i<graph.size();i++)
		{
			for(int j =0;j<graph[i].size();j++)
			graph[i][j] =0.00;
			graph[i][i] = 1.00;
		}
		for(int i =0;i<m;i++)
		{
			string a;
			double b;
			string c;
			cin>>a>>b>>c;
			graph[mymap[a]][mymap[c]] = b*100000;
			graph[mymap[c]][mymap[a]] = 100000.00/(double)b;		
		}
		floyd_warshall(graph);
		cin>>n;
	}
	return 0;
}
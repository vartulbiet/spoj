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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<pair<int,int> >vec;
vector<double>nodes;
vector<vector<double> >graph;
vector<bool>mst;
ll m;
double dist(int a,int b, int x,int y)
{
	//cout<<a<<b<<x<<y<<"   "<<sqrt(pow(abs((a-x)),2 )+ pow(abs((b-y)),2))<<endl;
	return m*((sqrt((labs((a-x)*(a-x)) )+ (labs((b-y)*(b-y)))))); 
}
void print_graph(int n)
{
	for(int i =0 ;i < n; i++)
	{
		vector<double>temp;
		for(int j =0; j < n; j++)
			cout<<dist(vec[i].first, vec[i].second, vec[j].first, vec[j].second)<<" ";
		cout<<endl;
	}
}
void create_graph(int n)
{
	for(int i =0 ;i < n; i++)
	{
		vector<double>temp;
		for(int j =0; j < n; j++)
			temp.PB(dist(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
		graph.PB(temp);
	}
	//print_graph(n);
}

int getMIN(int n)
{
	double value = INF;
	int index = 0;
	for(int i =0 ; i< n ; i++)
	{
		if(mst[i] == false && value > nodes[i])
		{
			value = nodes[i];
			index = i;
		}
	}
	return index;
}
void apply_prims(int n)
{
	for(int i =0 ;i < n-1; i++)
	{
		int  mint = getMIN(n);
		mst[mint] = true;
		for(int j = 0 ;j < n ; j++)
		if(nodes[j] > graph[mint][j] && mst[j] ==false)
		{
			nodes[j] = graph[mint][j];
			//cout<<nodes[j]<<"~~"<<j<<endl;
		}
	}
}
int main()
{
	int test = 0;
	cin>>test;
	int k =1;
	while(test--)
	{
		nodes.clear();
		vec.clear();
		graph.clear();
		mst.clear();
		ll n;
		cin>>n>>m;
		for(int i =0; i < n ; i++)
		{
			int x,y;
			cin>>x>>y;
			vec.PB(MP(x,y));
			nodes.PB(INF);
			mst.PB(false);
		}
		nodes[0] = 0;
		create_graph(n);
		apply_prims(n);
		ll cost = 0;
		for(int i =0 ;i < n ;i++)
		{
			cost += ceil(nodes[i]);
			cost= cost%MOD;
		}

		cout<<"Scenario #"<<k++<<": "<<cost<<endl;
	}
	return 0;
}
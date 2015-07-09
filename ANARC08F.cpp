#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull long long int  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
#define M 1000000009
using namespace std;
int graph[105][105];
map<string,int>mymap;
void init_graph()
{
	for(int i =0 ;i <105; i++)
	{
		for(int j = 0 ; j < 105; j++)
			graph[i][j] = INF;
	}
	mymap.erase(mymap.begin(),mymap.end());
}
void print_g()
{
	int n =  mymap.size();
	for(int i =0 ; i<n ; i++)
	{
		for(int j = 0; j < n ;j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	for(std::map<string,int>::iterator it = mymap.begin();it!=mymap.end(); it++)
		cout<<it->first<<endl;
}
void floyd_Warshall()
{
	int n =  mymap.size();
	for(int i =0 ;i < n ; i++)
	{
		for(int j =0 ;j < n ; j++)
		{
			for(int k =0 ;k < n ; k++)
			{
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
}
int gtNumber(string b)
{
	//cout<<b<<" "<<b.size()<<endl;
	int v = 0;
	int x = b.size()-4;
	int number = 0;
	for(int i = x-1;i >=0; i--)
	{
		char x = b[2+i];
		int u = x -'0';
		number += (u*(pow(10,v++)));
	}
	return number;
}
void make_graph(int x)
{
	init_graph();
	int i = 0;
	while(x--)
	{
		string a,b,c;
		cin>>a>>b>>c;
		int cost = gtNumber(b);
		if(mymap.find(a) ==mymap.end())
		mymap[a] = i++;

		if(mymap.find(c) ==mymap.end())
		mymap[c] = i++;
		if(b[0] =='-')
			graph[mymap[a]][mymap[c]] = min(cost,graph[mymap[a]][mymap[c]]);
		else if(b[b.size()-1] == '-')
			graph[mymap[c]][mymap[a]] = min(cost,graph[mymap[c]][mymap[a]] );
			else
			{
				graph[mymap[a]][mymap[c]] = min(cost,graph[mymap[a]][mymap[c]]);
				graph[mymap[c]][mymap[a]] = min(cost,graph[mymap[c]][mymap[a]]);
			}
	}
	print_g();
}

int main()
{
	int n,c,r;
	int z = 1;
	cin>>n>>c>>r;

	bool bt =true;
	while(bt)
	{
		vector<string>l;
		while(c>-1)
		{
			string x;
			cin>>x;
			l.PB(x);
			c--;
		}
		make_graph(r);
		floyd_Warshall();
		int ans = 0;
		for(int i = 1; i < l.size() ; i++)
		{
			ans+=graph[mymap[l[0]]][mymap[l[i]]];
			ans+=graph[mymap[l[i]]][mymap[l[0]]];
		}
		cout<<z++<<". "<<ans<<endl;
	cin>>n>>c>>r;
		if(n ==0 && c ==0 && r==0)
			bt =false;
	}
	return 0;
}
#include<iostream>
#include<vector>
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
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define MP make_pair
#define INF 1<<30
using namespace std;
vector<list<int> >graph;
bool DFS(int s,bool*seen,int*match)
{
	for(int i =0;i<graph[s].size();i++)
	{
		int j = graph[s][i];
		if(!seen[j])
		{
			seen[j] = true;
			if(match[j] ==-1 || DFS(match[j],seen,match))
			{
				match[j] = s;
				return true;
			}
		}
	}
	return false;
}
void MBM(int m,int n)
{
	int*match = (int*)malloc(sizeof(int)*m);
	for(int i = 0 ; i<m ;i++)
		match[i ] =-1;
	int result =0;
	for(int i =0;i<m;i++)
	{
		bool*seen = (bool*)malloc(sizeof(bool)*n);
		for(int i = 0 ;i <n; i++)
			seen[i] =false;
		if(DFS(i,seen,match))
		result++;
	}
	cout<<result<<endl;
}
int main()
{
	
 	int a,b,c;
 	cin>>a>>b>>c;
 	list<int>s;
 	for(int i = 0 ;i <a;i++)
 		graph.PB(s);
 	for(int i = 0 ; i<c;i++)
 	{
 		int x,y;
 		cin>>x>>y;
 		graph[x-1].PB(y-1);
 	}
 
     MBM(a,b);
 
    return 0;
}
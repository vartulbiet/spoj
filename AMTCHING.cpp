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

bool DFS(int s,bool** graph,bool*seen,int*match)
{
	for(int i =0;i<N;i++)
	{
		if(!seen[i] && graph[s][i] == 1)
		{
			seen[i] = true;
			if(match[i] ==-1 || DFS(match[i],graph,seen,match))
			{
				match[i] = s;
				return true;
			}
		}
	}
	return false;
}
void MBM(bool **graph)
{
	int match[M];
	memset(match,-1,sizeof(match));
	int result =0;
	for(int i =0;i<M;i++)
	{
		bool seen[N];
		memset(seen,0,sizeof(seen));
		if(DFS(i,graph,seen,match))
		result++;
	}
	cout<<result<<endl;
}
int main()
{
	
 	int a,b,c;
 	cin>>a>>b>>c;
 	int**graph = (int**)malloc(sizeof(int*)*m);
 	for(int i = 0; i<m; i++)
 	{
 		int*graph[i]  = (int*)malloc(sizeof(int)*n);
 	}
 	for(int i = 0 ; i<c;i++)
 	{
 		int x,y;
 		cin>>x>>y;
 		graph[x-1][y-1] = 1;
 	}
     MBM(bpGraph);
 
    return 0;
}
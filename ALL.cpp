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
vector<vector<int> >graph;
map<int,bool>mymap;
int solve(int x,int y,int d)
{
	int count  = x+y;
	int tochange = 0;
	std::set<int> myset;
	std::set<int>::iterator it;
	std::set<int> myset2;
	std::set<int>::iterator it2;

	for (int i=0; i<x; i++) myset.insert(i); 

	for (int i=0; i<y; i++) myset.insert(x+i); 

	while(myset.size()>0 &&myset2.size()>0)
	{


		for (it=myset.begin(); it!=myset.end(); ++it)
		{
			if(mymap[*it] || graph[*it].size() == 0)
			{
				mymap[*it] = true;
				myset.erase(*it);
			}
		}
			if(myset.size()==0 || myset2.size()==0)
		{
			tochange++;
			break;
		}
		else
		tochange++;

		for (it2=myset2.begin(); it2!=myset2.end(); ++it2)
		{
			if(mymap[*it2] || graph[*it2].size() == 0)
			{
				mymap[*it2] = true;
				myset.erase(*it2);
			}
		}
				if(myset.size()==0 || myset2.size()==0)
		{
			tochange++;
			break;
		}
		else
			tochange++;
	}
	return tochange;
}
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	while(x!=0 && y!= 0 && z!=0)
	{
		for(int i =0 ;i <(x+y);i++)
		{
			vector<int>temp;
			graph[i] =temp;
			mymap[i] = true;
		}
		for(int i =0; i < z; i++)
		{
			int a,b;
			cin>>a>>b;
			graph[a-1].PB(b-1);
			mymap[a-1] = false;
		}
		cout<<solve(x,y,z)+2<<endl;
		cin>>x>>y>>z;
	}
	return 0;
}
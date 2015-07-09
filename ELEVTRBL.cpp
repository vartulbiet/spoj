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
#define INF 1<<25
#define M 100000009
#define MP make_pair
using namespace std;
 vector<bool>arr;
int BFS(int floor, int start,int down, int u, int d,queue<pair<int,int> >q )
{
		while(!q.empty())
		{
			int x = q.front().first;
			//cout<<" "<<x<<endl;
		
			if(x == down)
				return q.front().second;

			if((x+u)<=floor && arr[x+u] ==false)
			{
				
				arr[x+u] =true;
				q.push(MP(x+u,q.front().second+1));
				//cout<<x+u<<"++"<<endl;
			}
			if((x-d)>=0  && arr[x-d] ==false)
			{
				
				arr[x-d] = true;
				q.push(MP(x-d,q.front().second+1));
				//cout<<x-d<<"__"<<endl;
			}
				q.pop();
		}
		return -1;
}
int main()
{
	int floor,start,dest,up,down;
	cin>>floor>>start>>dest>>up>>down;
	for(int i =0; i<floor ; i++)
	{
		arr.PB(false);
	}
	arr[start-1] = 0;
	queue<pair<int,int> >q;
	q.push(MP(start-1,0));
	//cout<<floor-1<<start-1<<dest-1<<up<<down<<endl;
	int uu = BFS(floor-1,start-1,dest-1,up,down,q);
	if(uu != -1)
	cout<<uu<<endl;
else
	cout<<"use the stairs"<<endl;
	return 0;
}
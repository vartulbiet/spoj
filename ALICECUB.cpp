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
int graph[16][16];
void init()
{
	memset(graph,0,sizeof(graph));
	graph[0][1] =1;graph[0][2] =1;graph[0][4] =1;graph[0][8] =1;
	graph[1][0] =1;graph[1][3] =1;graph[1][5] =1;graph[1][9] =1;
	graph[2][0] =1;graph[2][3] =1;graph[2][6] =1;graph[2][10] =1;
	graph[3][1] =1;graph[3][2] =1;graph[3][7] =1;graph[3][11] =1;
	graph[4][0] =1;graph[4][5] =1;graph[4][6] =1;graph[4][12] =1;
	graph[5][1] =1;graph[5][4] =1;graph[5][7] =1;graph[5][13] =1;
	graph[6][2] =1;graph[6][4] =1;graph[6][7] =1;graph[6][14] =1;
	graph[7][3] =1;graph[7][5] =1;graph[7][6] =1;graph[7][15] =1;
	graph[8][0] =1;graph[8][9] =1;graph[8][10] =1;graph[8][12] =1;
	graph[9][1] =1;graph[9][8] =1;graph[9][11] =1;graph[9][13] =1;
	graph[10][2] =1;graph[10][8] =1;graph[10][11] =1;graph[10][14] =1;
	graph[11][3] =1;graph[11][9] =1;graph[11][10] =1;graph[11][15] =1;
	graph[12][4] =1;graph[12][8] =1;graph[12][13] =1;graph[12][14] =1;
	graph[13][5] =1;graph[13][7] =1;graph[13][9] =1;graph[13][15] =1;
	graph[14][6] =1;graph[14][10] =1;graph[14][12] =1;graph[14][15] =1;
	graph[15][7] =1;graph[15][11] =1;graph[15][13] =1;graph[15][14] =1;
}
map<vector<int>,int>mymap;
void BFS()
{
	queue<vector<int> >q;
	
	vector<int>dest;

	for(int i =0;i<8;i++)
		dest.PB(0);
	for(int i =0;i<8;i++)
		dest.PB(1);

	mymap[dest] = 0;

	q.push(dest);

	while(!q.empty())
	{
		vector<int>x = q.front();
		int st = mymap[x];
		q.pop();
		for(int i =0;i<16 ;i++)
		{
			for(int j =0;j<16;j++)
			{
				if(graph[i][j] == 1 && (x[i] + x[j] == 1) && i<j)
				{ 
					swap(x[i],x[j]);
					if(mymap.find(x) == mymap.end())
					{
						mymap[x] = st+1;	
						if( st+1<=2)
							q.push(x);
						
					}
					swap(x[i],x[j]);
				}
			}
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	init();
	int tc =1;
	BFS();
	//for(std::map<vector<int>,int>::iterator it = mymap.begin();it!=mymap.end();it++)
	//	cout<<it->second<<" ";
	//cout<<"hi"<<endl;
	while(n--)
	{
		vector<int>arr;
		for(int i =0;i<16;i++)
		{
			int u =0;cin>>u;
			arr.PB(u);
		}
		cout<<"Case #"<<tc++<<": ";
		if(mymap.find(arr) == mymap.end())
			cout<<"more"<<endl;
		else
			cout<<mymap[arr]<<endl;
	}
	return 0;
}
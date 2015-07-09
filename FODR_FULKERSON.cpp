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
#define V 10
bool bfs(int rgraph[V][V],int s,int t,int parent[]){
    bool visited[V];
    memset(visited,0,sizeof(visited));

    queue<int>q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v =0;v<V;v++)
        {
            if(visited[v] == false && rgraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
void dfs(int rGraph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
void min_cut(int graph[V][V],int s,int t)
{
    int rgraph[V][V];
    for(int i =0;i<V;i++)
    {
        for(int j =0;j<V;j++)
            rgraph[i][j] = graph[i][j];
    }
    int parent[V];

    while(bfs(rgraph,s,t,parent))
    {
        int path_flow = INF;
         cout<<"hi"<<endl;
        for(int v = t;v!=s;v= parent[v]){
        int u = parent[v];
        path_flow = min(path_flow,rgraph[u][v]);
        }

        for(int v =t;v!=s;v=parent[v])
        {
            int u = parent[v];
            rgraph[u][v] -=path_flow;
            rgraph[v][u] +=path_flow;
        }
    }
    for(int i =0;i<V;i++)
    {
        for(int j =0;j<V;j++)
            cout<<rgraph[i][j]<<"  "  ;
        cout<<endl;
    }
     bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rgraph, s, visited);
 
    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (visited[i] && !visited[j] && graph[i][j])
              cout << i << " - " << j << endl;
 
    return;
}
int main()
{
    int graph[V][V] = { {0, 1, 1, 1, 0, 0,0,0,0,0},
                        {1, 0, 0, 0, 1, 0,0,0,0,0},
                        {1, 0, 0, 0, 1, 1,0,0,0,0},
                        {1, 0, 0, 0, 0, 1,0,0,0,0},
                        {0, 1, 1, 0, 0, 0,1,1,0,0},
                        {0, 0, 1, 1, 0, 0,0,1,1,0},
                        {0, 0, 0, 0, 1, 0,0,0,0,1},
                        {0, 0, 0, 0, 1, 1,0,0,0,1},
                        {0, 0, 0, 0, 0, 1,0,0,0,1},
                        {0, 0, 0, 0, 0, 0,1,1,1,0},
                      };
 
    min_cut(graph, 0, 9);
 
    return 0;
}
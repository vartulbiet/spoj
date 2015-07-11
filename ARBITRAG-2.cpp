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
int main(){
    for(int test = 1; ; test++){
        int n;
        scanf("%d",&n);
        if(n == 0)
            return 0;
        map<string , int> m;
        string s , source , dest;
        for(int i = 0 ; i < n ; i++){
            cin>>s;
            m[s] = i;
        }
        int table;
        cin>>table;
        double dist[50][50] , cost ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                dist[i][j] = 0.0;
            } 
        }

        for(int i = 0 ; i < table ; i++){
            cin>>source>>cost>>dest;
            int x , y;
            x = m[source];
            y = m[dest];
            dist[x][y] = cost;
        }
        //floyd warshall
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                        dist[i][j] = max(dist[i][j] , dist[i][k] * dist[k][j]);
                 		for(int i  = 0 ; i < n; i++)
		{
			vector<double>temp;
			for(int j  = 0 ; j < n; j++)
				cout<<dist[i][j]<<"  ";
			cout<<endl;
		}
        int flag = 0;
        for(int i = 0 ; i < n ; i++){
                if(dist[i][i] > 1.0 ){
                    flag = 1;
                    break;
                }
        }
        if(flag)
            cout<<"Case "<<test<<": Yes\n";
        else
            cout<<"Case "<<test<<": No\n";
    }
}
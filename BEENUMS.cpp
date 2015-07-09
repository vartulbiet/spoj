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
int main()
{
	int x = 0;
	cin>>x;
	while(x != -1)
	{
		if(x % 2 != 0)
		{
			if((x-1)%3 == 0)
			{
				int y = (x-1)/3;
				int a = sqrt(y);
				if(a*(a+1)==y)
					cout<<"Y"<<endl;
				else
					cout<<"N"<<endl;
			}
			else
				cout<<"N"<<endl;
		}
		else
			cout<<"N"<<endl;
		cin>>x;
	}
	return 0;
}
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
	string s;
	printf("Ready\n");
	while(getline(cin,s))
	{
		//cout<<s<<endl;
		if(s[0] ==' ' && s[1] ==' ')
			break;
		if((s[0] == 'p' && s[1] =='q') || (s[0] == 'q' && s[1] =='p')|| (s[0] == 'b' && s[1] =='d') ||(s[0] == 'd' && s[1] =='b'))
			cout<<"Mirrored pair"<<endl;
		else
			cout<<"Ordinary pair"<<endl;
	}
	return 0;
}
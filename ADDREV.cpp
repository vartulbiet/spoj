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
#define INF 1<<20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
int toNum(string s)
{
	int num =0;
	int index =0;
	for(int i =s.size()-1;i>=0;i--)
	{
		num += ( (s[i]-'0') * pow((double)10,index++));
	}
	return num;
}
string rev(int n)
{
	string s;
	while(n!=0)
	{
		s.PB((n%10)+'0');
		n= n/10;
	}
	//reverse(s.begin(),s.end());
	//cout<<s<<endl;
	return s;
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		cout<<toNum(rev(toNum(rev(x))+toNum(rev(y))))<<endl;
	}
	return 0;
}
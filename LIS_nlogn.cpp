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
int get_index(vector<int>temp,int k)
{
	for(int i =0;i<temp.size();i++)
	{
		if(temp[i]>k)
			return i;
	}
}
void LIS(vector<int>arr)
{
	vector<int>temp(arr.size());
	int len = 1;
	temp.PB(arr[0]);
	for(int i =1;i<arr.size();i++)
	{
		cout<<arr[i]<<endl;
		if(arr[i]<temp[0])
			temp[0] = arr[i];
		else if(temp[len-1]<arr[i])
			temp[len++] = arr[i];
		else temp[get_index(temp,arr[i])] = arr[i];
	}
	cout<<len;
}
int main()
{
	int n =0;
	cin>>n;
	vector<int>arr(n);
	int  i =0;
	while(n--)
	{
		cin>>arr[i++];
	}
	LIS(arr);
	return 0;
}
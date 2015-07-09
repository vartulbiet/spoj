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
int getsum(vector<ll>arr,int k,int neg)
{
	if(k>neg)
	{
		int j =0;
		for(int i =0;i<neg;i++)
		{
			if(arr[j] <0)
			{
			arr[j]*=-1;
			j++;
			//cout<<"";
			}
		}
		 k -=neg;
		 sort(arr.begin(),arr.end());
		 int index =0;
		 
		 for(int  i =arr.size();i>=0;i--)
		 if(arr[i] <= 0)
		 {
		 index = i;
		 break;
		 }
		 while(k!=0)
		 {
			arr[index]*=-1;
			k--;
		 }
	}
	else if( k<=neg)
	{
		for(int i =0;i<k;i++)
		arr[i] *= -1;
	}
	//cout<<endl;
	//for(int i =0;i<arr.size();i++)
	//cout<<arr[i]<<"  ";
	//cout<<endl;
	int sum =0;
	for(int i =0;i<arr.size();i++)
	sum+=arr[i];
	return sum;
}
int main()
{
	int tc =0;
	cin>>tc;
	while(tc--)
	{
		int count  = 0, k = 0;
		cin>>count>>k;
		vector<ll>arr;
		int neg =0;
		while(count--)
		{
			ll y =0;
			cin>>y;
			if(y<0)
			neg++;
			arr.PB(y);
		}
		sort(arr.begin(),arr.end());
		cout<<getsum(arr,k,neg)<<endl;
	}
	return 0;
}
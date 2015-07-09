#include <iostream>
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	int s =0;
	while(n--)
	{
		int y =0;
		cin>>y;
		y>0?s+=y:s+=0;
	}
	cout<<s<<endl;
	return 0;
}
#include <cstring>
#include <iostream>
#include<math.h>
#include <string>
using namespace std;

int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		string s;
		unsigned long long int a=0;
		unsigned long long int b=0;
		cin>>s>>b;
		a=s[s.length()-1]-'0';
		if(a==0&&b==0){
			cout<<"0"<<endl;
			continue;
		}
		if(b==0){
			cout<<"1"<<endl;
			continue;
		}
		if(a==0){
			cout<<"0"<<endl;
			continue;
		}
		if(b%4==0){
			b=4;
		}
		else
		{
			b=b%4;
		}
		unsigned long long int ans=(pow(a,b));
		cout<<ans%10<<endl;
	}
	return 0;
}
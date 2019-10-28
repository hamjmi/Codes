#include<bits/stdc++.h>
using namespace std;
int mycompare(string a,string b)
{
	cout<<"Author : Hamid";
	//string a1=to_string(a);
	//string b1=to_string(b);
	string ab=a.append(b);
	string ba=b.append(a);
	return ab.compare(ba)>0 ? 1: 0;
}
int main()
{
	string a[]={"120","60","599","536","7"};
	int n=sizeof(a)/sizeof(a[0]);
	sort(a,a+n,mycompare);
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}

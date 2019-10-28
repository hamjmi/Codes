#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,l1,l2;
	string s1,s2;
	map<char,int> a;
	cin>>t;
	while(t--)
	{
	    cin>>s1>>s2;
	    //if(s1==NULL || s2==NULL)
	      //  cout<<"\nNO";
	    //else
	    //{
	    l1=s1.length();
	    l2=s2.length();
	    if(l1==l2)
	    {
	        a.clear();
	        for(int i=0;i<l1;i++)
	        {
	            a[s1[i]]++;
	        }
	        int ch=0;
	        for(int i=0;i<l1;i++)
	        {
	            if(a.find(s2[i])!=a.end())
	            {
	                if(a[s2[i]]>=1)
	                    a[s2[i]]--;
	                else
	                {
	                    ch=1;
	                    break;
	                }
	            }
	            else
	            {
	                ch=1;
	                break;
	            }
	        }
	        if(ch==0)
	            cout<<"\nYES";
	        else
	            cout<<"\nNO";
	    }
	    else
	    {
	        cout<<"\nNO";
	    }
	   // }
	}
	return 0;
}

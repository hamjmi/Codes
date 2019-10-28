#include<bits/stdc++.h>
using namespace std;
#define max 100
#define temp 0
#define perm 1
#define nil -1
#define infinity 9999
int n=9;
int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
int status[9];
int pre[9];
int pathLen[9];
int min_temp();
void dij(int s);
void findpath(int s,int v);
int main()
{
	int s,v;
	cout<<"\nEnter the source vertex..";
	cin>>s;
	dij(s);
	while(1)
	{
		cout<<"\nEnter Destination Vertex(-1 to quit)...";
		cin>>v;
		if(v==-1)
			break;
		if(v>=n || v<0)
			cout<<"\nDoesn't Exit...";
		else if(v==s)
			cout<<"\nSource and Destination are same...";
		else if(pathLen[v]==9999)
			cout<<"\nThere is no path..";
		else
			findpath(s,v);
	}
}
int min_temp()
{
	int min=infinity;
	int k=nil;
	for(int i=0;i<n;i++)
	{
		if(status[i]==temp && pathLen[i]<min)
		{
			min=pathLen[i];
			k=i;
		}
	}
	return k;
}
void dij(int s)
{
	int i,current;
	for(i=0;i<n;i++)
	{
		status[i]=temp;
		pathLen[i]=infinity;
		pre[i]=nil;
	}
	pathLen[s]=0;
	while(1)
	{
		current=min_temp();
		if(current==nil)
			return;
		status[current]=perm;
		for(i=0;i<n;i++)
		{
			if(graph[current][i]!=0 && status[i]==temp)
			{
				if(pathLen[current]+graph[current][i]<pathLen[i])
				{
					pathLen[i]=pathLen[current]+graph[current][i];
					pre[i]=current;
				}
			}
		}
	}
}
void findpath(int s,int v)
{
	int i,u;
	int path[max];
	int d=0;
	int count=0;
	cout<<"\nShortest Path... : ";
	while(v!=s)
	{
		count++;
		path[count]=v;
		//cout<<v<<"->";
		u=pre[v];
		d+=graph[u][v];
		v=u;
	}
	count++;
	path[count]=s;
	//cout<<s<<"->";
	//cout<<"\nShortest Path... : ";
	for(i=count;i>0;i--)
	{
		cout<<path[count]<<"->";
	}
	cout<<"\nShortest Distance : "<<d;
}

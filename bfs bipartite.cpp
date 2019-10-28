#include<bits/stdc++.h>
using namespace std;
#define N 9


bool bipartite(int g[N][N],int src)
{
	int color[N];
	memset(color,-1,sizeof(color));
	color[src]=1;
	
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(g[u][u]==1)
			return false;
		for(int i=0;i<N;i++)
		{
			if(g[u][i]==1 && color[i]==-1)
			{
				color[i]=1-color[u];
				q.push(i);
			}
			else if(g[u][i]==1 && color[i]==color[u])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int g[N][N]={{0,1,0,1,1,0,0,0,0},
	     {0,0,1,0,1,0,0,0,0},
		 {0,0,0,0,0,1,0,0,0},
		 {0,0,0,0,1,0,1,0,0},
		 {0,0,0,0,0,1,0,1,0},
		 {0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,1,0,0,1,0},
		 {0,0,0,0,0,1,0,0,1},
		 {0,0,0,0,0,0,0,0,0}};
	bipartite(g,0)? cout<<"Yes.." : cout<<"No...";

}

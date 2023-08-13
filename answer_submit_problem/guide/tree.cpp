#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,u,v;
vector<int>g[N];
int dis[N];
int dfs(int st)
{
	queue<int>q;
	int x;
	memset(dis,0,sizeof(dis));
	q.push(st);dis[st]=1;
	while(q.size())
	{
		x=q.front();q.pop();
		for(int y:g[x])
			if(!dis[y])dis[y]=dis[x]+1,q.push(y);
	}
	return x;
}
int main()
{
	freopen("guide9.in","r",stdin);
	freopen("guide9.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
	}
	int x=dfs(1);
	int y=dfs(x);
	int len=1;
	int y_=y;
	while(y!=x)
	{
		len++;
		for(int z:g[y])
			if(dis[y]>dis[z]){y=z;break;}
	}
	cout<<len<<endl;
	y=y_;
	cout<<y<<endl;
	while(y!=x)
	{
		len++;
		for(int z:g[y])
			if(dis[y]>dis[z]){y=z;cout<<z<<endl;break;}
	}
	return 0;
}
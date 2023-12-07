/**
 * @file flows.h
 * This file contains @struct Maxflow_Mincut and @struct MCMF.
*/
#ifndef YMH_HEADS
#include "heads.h"
#endif

/*------------------------------Maxflow_Mincut------------------------------*/
struct Maxflow_Mincut
{
	private:
	int S,T,nodec;
	struct E
	{
		int v;
		ll cap;
		int rid;
		bool israw;
		E(int v,ll cap=0,int rid=0,bool raw=0):v(v),cap(cap),rid(rid),israw(raw){}
	};
	vector<E>*g;
	int *dep,*nxt;
	vector<vector<E>::iterator>edges;
	bool bfs()
	{
		queue<int>q;
		q.push(S);
		memset(dep+1,-1,sizeof(int)*nodec);
		dep[S]=0;
		while(nempty(q))
		{
			int x=q.front();q.pop();
			for(E e:g[x])
				if(e.cap&&!~dep[e.v])
					dep[e.v]=dep[x]+1,q.push(e.v);
		}
		return ~dep[T];
	}
	ll dfs(int x)
	{
		if(x==T)return LLONG_MAX;
		for(;nxt[x]<g[x].size();nxt[x]++)
		{
			E &e=g[x][nxt[x]];
			if(!e.cap||dep[e.v]<=dep[x])continue;
			edges.PB(&e);
			ll f=dfs(e.v);
			if(f)return min(f,e.cap);
			edges.PPB();
		}
		return 0;
	}
	public:
	Maxflow_Mincut(){}
	Maxflow_Mincut(int node_count,int sink,int terminal)
	{
		S=sink,T=terminal,nodec=node_count;
		g=new vector<E>[node_count+1]();
		dep=new int[node_count+1](),nxt=new int[node_count+1]();
	}
	void add(int u,int v,ll w)
	{
		g[u].PB(v,w,g[v].size(),1);
		g[v].PB(u,0,g[u].size()-1,0);
	}
	ll Maxflow()
	{
		ll maxflow=0;
		while(bfs())
		{
			memset(nxt+1,0,sizeof(int)*nodec);
			ll flow=0;
			while(1)
			{
				flow=dfs(S);
				if(!flow)break;
				maxflow+=flow;
				for(auto e:edges)
				{
					e->cap-=flow;
					g[e->v][e->rid].cap+=flow;
				}
				edges.clear();
			}
		}
		return maxflow;
	}
	pair<ll,vector<PII> >Mincut()
	{
		ll mf=Maxflow();
		vector<PII>mincut;
		for(int i=1;i<=nodec;i++)
			if(~dep[i])
			{
				for(E j:g[i])
					if(!~dep[j.v]&&j.israw)
						mincut.PB(i,j.v);
			}
		return {mf,mincut};
	}
};

/*------------------------------MCMF------------------------------*/
struct MCMF
{
	private:
	int S,T,ndc;
	struct E
	{
		int v;
		ll cap,cost;
		int rid;
		E(int v,ll cap,ll cost,int rid):v(v),cap(cap),cost(cost),rid(rid){}
	};
	vector<E>*g;
	int *dep,*nxt;
	bool bfs()
	{
		queue<int>q;
		q.push(S);
		memset(dep+1,-1,ndc<<2);
		dep[S]=0;
		while(nempty(q))
		{
			int x=q.front();q.pop();
			for(E e:g[x])
				if(e.cap&&!~dep[e.v])
					dep[e.v]=dep[x]+1,q.push(e.v);
		}
		return ~dep[T];
	}
	bool spfa()
	{
		memset(dis+1,0x3f,ndc<<3);
		dis[S]=0;
		queue<int>q;
		q.push(S);
		while(nempty(q))
		{
			int x=q.front();q.pop();
			for(int i=0;i<g[x].size();i++)
			{
				E e=g[x][i];
				if(e.cap&&dis[e.v]>dis[x]+e.cost)
					dis[e.v]=dis[x]+e.cost,q.push(e.v),pv[e.v]=x,pe[e.v]=i;
			}
		}
		return dis[T]<1e16;
	}
	ll getflow()
	{
		ll res=LLONG_MAX;
		for(int i=T;i!=S;i=pv[i])
			res=min(res,g[pv[i]][pe[i]].cap);
		return res;
	}
	int *pe,*pv;
	ll *dis;
	public:
	MCMF(){}
	MCMF(int nc,int sink,int terminal)
	{
		ndc=nc,S=sink,T=terminal;
		g=new vector<E>[nc+1]();
		dep=new int[nc+1]();
		nxt=new int[nc+1]();
		pe=new int[nc+1]();
		pv=new int[nc+1]();
		dis=new ll[nc+1]();
	}
	~MCMF()
	{
		delete[]g;
		delete[]dep;
		delete[]nxt;
		delete[]pe;
		delete[]pv;
		delete[]dis;
	}
	void add(int u,int v,ll w,ll c)
	{
		g[u].PB(E(v,w,c,g[v].size()));
		g[v].PB(E(u,0,-c,g[u].size()-1));
	}
	PII flow(ll tryInc=LLONG_MAX)
	{
		ll maxflow=0,mincost=0;
		while(bfs())
		{
			memset(nxt+1,0,ndc<<2);
			ll flow=0;
			while(1)
			{
				if(!spfa())break;
				flow=min(tryInc,getflow());
				maxflow+=flow;
				mincost+=dis[T]*flow;
				for(int i=T;i!=S;i=pv[i])
					g[pv[i]][pe[i]].cap-=flow,
					g[g[pv[i]][pe[i]].v][g[pv[i]][pe[i]].rid].cap+=flow;
				if(flow>=tryInc)return MP(maxflow,mincost);
			}
		}
		return MP(maxflow,mincost);
	}
};
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'//交互题删掉
#define FastIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FileIO(Name) freopen(Name ".in","r",stdin);\
freopen(Name ".out","w",stdout)
#define Fix(Dec) cout<<fixed<<setprecision(Dec)
#define sp_el(i,n) " \n"[i==n]
#define put_ret(Msg) return cout<<Msg<<endl,void()
#define nonEmp(x) !x.empty()
#define PB emplace_back
#define PPB pop_back
#define MP make_pair
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
using namespace std;

void Init()
{
	FastIO;
}
const int N=100005;
int Q;
struct Splay
{
	int v[N],sz[N],ch[N][2],fa[N],rt,Tot;
	int node(int V)
	{
		v[++Tot]=V,sz[Tot]=1;
		return Tot;
	}
	int choffa(int x)
	{
		return ch[fa[x]][1]==x;
	}
	void pushup(int x)
	{
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	}
	void rotate(int x)
	{
		int f=fa[x],g=fa[f],c=choffa(x);
		if(g)ch[g][choffa(f)]=x,fa[x]=g;
		else rt=x,fa[x]=0;
		ch[f][c]=ch[x][!c],fa[ch[x][!c]]=f,ch[x][!c]=f,fa[f]=x;
		pushup(f);
		pushup(x);
	}
	void splay(int x,int tg=0)
	{
		while(fa[x]!=tg)
		{
			if(fa[fa[x]]!=tg)rotate(choffa(x)==choffa(fa[x])?fa[x]:x);
			rotate(x);
		}
		if(!tg)rt=x;
	}
	void toroot(int V)
	{
		int u=rt,lst=-1;
		while(u)
		{
			if(v[u]<=V)
			{
				lst=u;
				if(ch[u][1])u=ch[u][1];
				else break;
			}
			else
			{
				if(ch[u][0])u=ch[u][0];
				else break;
			}
		}
		splay(u);
		splay(lst);
		u=ch[rt][1];
		while(ch[u][0])u=ch[u][0];
		splay(u,rt);
	}
	void init()
	{
		Tot=0;
		rt=node(INT_MIN);
		node(INT_MAX);
		fa[2]=1,ch[1][1]=2;
		pushup(1);
	}
	void dfs(int x)
	{
		if(ch[x][0])dfs(ch[x][0]);
		cerr<<v[x]<<" ";
		if(ch[x][1])dfs(ch[x][1]);
	}
	void insert(int x)
	{
		toroot(x);
		// dfs(rt);
		// cerr<<endl;
		int s=node(x);
		fa[s]=ch[rt][1],ch[ch[rt][1]][0]=s;
		pushup(ch[rt][1]),pushup(rt);
		// for(int i=1;i<=Tot;i++)cerr<<v[i]<<" "<<fa[i]<<" "<<
		// (choffa(i)?'r':'l')<<endl;
		// dfs(rt);
		// cerr<<endl<<endl;
	}
	void erase(int x)
	{
		toroot(x-1);
		ch[rt][1]=ch[ch[rt][1]][1],fa[ch[rt][1]]=rt;
		pushup(rt);
	}
	int kth(int k)
	{
		k++;
		int u=rt;
		while(u)
		{
			if(sz[ch[u][0]]+1==k)return splay(u),v[u];
			if(sz[ch[u][0]]<k)k-=sz[ch[u][0]]+1,u=ch[u][1];
			else u=ch[u][0];
		}
	}
	int rnk(int x)
	{
		toroot(x-1);
		return sz[ch[rt][0]]+1;
	}
	int pre(int x)
	{
		toroot(x-1);
		// for(int i=1;i<=Tot;i++)cerr<<v[i]<<" "<<fa[i]<<" "<<
		// (choffa(i)?'r':'l')<<endl;
		return v[rt];
	}
	int nxt(int x)
	{
		toroot(x);
		int u=ch[rt][1];
		while(ch[u][0])u=ch[u][0];
		return v[u];
	}
}tree;
void Solve()
{
	tree.init();
	cin>>Q;
	while(Q--)
	{
		int op,x;
		cin>>op>>x;
		switch(op)
		{
			case 1:tree.insert(x);break;
			case 2:tree.erase(x);break;
			case 3:cout<<tree.rnk(x)<<endl;break;
			case 4:cout<<tree.kth(x)<<endl;break;
			case 5:cout<<tree.pre(x)<<endl;break;
			case 6:cout<<tree.nxt(x)<<endl;break;
		}
	}
}
void QingKong()
{

}

int main()
{
#ifdef LOCAL
ll STE=clock();
#endif
	Init();
	int T=1;
	//cin>>T;
	while(T--)
	{
		Solve();
		QingKong();//多测不清空，抱灵两行泪
	}
#ifdef LOCAL
ll ETE=clock();
cerr<<"\n\n-----------------------\nProgram done in "<<ETE-STE<<" ms";
#endif
	return 0;
}
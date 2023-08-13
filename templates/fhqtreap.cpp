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
mt19937 rnd(time(NULL));
struct Treap
{
	struct Node
	{
		int val,p,sz;
		Node *lc,*rc;
	}Pool[N],*root;
	int Tot;
	Node *node(int v)
	{
		++Tot;
		Node *nd=Pool+Tot;
		nd->val=v;
		nd->p=rnd();
		nd->sz=1;
		nd->lc=nd->rc=NULL;
		return nd;
	}
	int getsz(Node *x)
	{
		if(!x)return 0;
		return x->sz;
	}
	void pushup(Node *x)
	{
		if(!x)return;
		x->sz=getsz(x->lc)+getsz(x->rc)+1;
	}
	void split_v(Node *rt,Node *&r1,Node *&r2,int V)
	{
		if(!rt)
		{
			r1=r2=NULL;
			return;
		}
		if(rt->val<=V)r1=rt,split_v(rt->rc,r1->rc,r2,V),pushup(r1);
		else r2=rt,split_v(rt->lc,r1,r2->lc,V),pushup(r2);
	}
	void split_s(Node *rt,Node *&r1,Node *&r2,int S)
	{
		if(!rt)
		{
			r1=r2=NULL;
			return;
		}
		if(getsz(rt->lc)+1<=S)
			r1=rt,split_s(rt->rc,r1->rc,r2,S-getsz(rt->lc)-1),pushup(r1);
		else r2=rt,split_s(rt->lc,r1,r2->lc,S),pushup(r2);
	}
	void merge(Node *&rt,Node *r1,Node *r2)
	{
		if(!r1){rt=r2;return;}
		if(!r2){rt=r1;return;}
		if(r1->p>r2->p)
			rt=r1,merge(rt->rc,r1->rc,r2);
		else rt=r2,merge(rt->lc,r1,r2->lc);
		pushup(rt);
	}
	void init()
	{
		root=NULL;
		Tot=0;
	}
	void dfs(Node *rt)
	{
		if(!rt)return;
		dfs(rt->lc);
		cerr<<(rt->val)<<endl;
		dfs(rt->rc);
	}
	void insert(int x)
	{
		Node *p(NULL),*q(NULL),*r(NULL),*v=node(x);
		split_v(root,p,q,x-1);
		merge(r,v,q);
		merge(root,p,r);
	}
	void erase(int x)
	{
		Node *p(NULL),*q(NULL),*r(NULL),*s(NULL);
		split_v(root,p,q,x-1);
		split_v(q,r,s,x);
		merge(r,r->lc,r->rc);
		merge(q,r,s);
		merge(root,p,q);
	}
	int rnk(int x)
	{
		Node *p(NULL),*q(NULL);
		split_v(root,p,q,x-1);
		int res=getsz(p)+1;
		merge(root,p,q);
		return res;
	}
	int kth(int k)
	{
		Node *p(NULL),*q(NULL),*r(NULL),*s(NULL);
		split_s(root,p,q,k-1);
		split_s(q,r,s,1);
		int res=r->val;
		merge(q,r,s);
		merge(root,p,q);
		return res;
	}
	int pre(int x)
	{
		Node *p(NULL),*q(NULL),*r(NULL),*s(NULL);
		split_v(root,p,q,x-1);
		split_s(p,r,s,p->sz-1);
		int res=s->val;
		merge(p,r,s);
		merge(root,p,q);
		return res;
	}
	int nxt(int x)
	{
		Node *p(NULL),*q(NULL),*r(NULL),*s(NULL);
		split_v(root,p,q,x);
		split_s(q,r,s,1);
		int res=r->val;
		merge(q,r,s);
		merge(root,p,q);
		return res;
	}
}tree;
int Q;
void Solve()
{
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
//		cerr<<"Operation "<<Q<<" done\n";
//		tree.dfs(tree.root);
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
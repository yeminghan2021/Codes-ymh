#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
#ifdef DEBUG
#define msg(Msg) cerr<<Msg<<endl
#define debug(Var) cerr<<#Var<<"="<<Var<<endl
#else
#define msg(Msg)
#define debug(Var)
#endif

void Init()
{
	FastIO;
}
void Solve()
{
	
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
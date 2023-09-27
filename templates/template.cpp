#include<bits/stdc++.h>
using namespace std;
namespace YMH
{
#define ll long long
#define endl '\n'//交互题删掉
#define FastIO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FileIO(Name) freopen(Name ".in","r",stdin);freopen(Name ".out","w",stdout)
#define Fix(Dec) cout<<fixed<<setprecision(Dec)
#define sp_el(i,n) " \n"[i==n]
#define put_ret(Msg) return cout<<Msg<<endl,void()
#define nempty(x) !x.empty()
#define PB emplace_back
#define PPB pop_back
#define MP make_pair
#define ALL(Name) Name.begin(),Name.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
#define fi first
#define se second
template<typename Type>
using PQ_min=priority_queue<Type,vector<Type>,greater<Type> >;
template<typename Type>
using PQ_max=priority_queue<Type>;
#ifdef DEBUG
#include "templates/debug.h"
#else
#define dbg(...) 114514
#define msg(...) 1919810
#endif

void Init()
{
	FastIO;
}
void Solve(int CASE)
{
	
}
void QingKong()
{

}
}
int main()
{
	YMH::Init();
	int ___=1;
	//cin>>___;
	for(int __=1;__<=___;__++)
	{
		YMH::Solve(__);
		YMH::QingKong();//多测不清空，抱灵两行泪
	}
#ifdef LOCAL
	cerr<<"\n\nPROGRAM DONE";
#endif
	return 0;
}
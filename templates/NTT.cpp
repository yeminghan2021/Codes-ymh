#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define PB emplace_back
#define PPB pop_back

#define Tmpl template<typename _T>
Tmpl
_T gcd(_T a,_T b)
{
	if(a<b)swap(a,b);
	return b?gcd(b,a%b):a;
}
Tmpl
_T lcm(_T a,_T b){return a*b/gcd(a,b);}
Tmpl
_T pw(_T ds,ll zs)
{
	if(!zs)return 1;
	_T t=pw(ds,zs>>1);t*=t;
	if(zs&1)return t*ds;
	return t;
}
template<ll MOD,typename _T=ll>
struct ModInt
{
	_T val;
	ModInt(_T v=0){val=v%MOD;}
	_T V(){return val;}
	static _T Mod(){return MOD;}
	ModInt operator=(const _T v){return (*this)=ModInt(v);}
	ModInt operator==(const ModInt B)const{return val==B.val;}
	ModInt operator!=(const ModInt B)const{return val!=B.val;}
	ModInt operator+(const ModInt B)const{return (val+B.val)%MOD;}
	ModInt operator-(const ModInt B)const{return (val-B.val+MOD)%MOD;}
	ModInt operator*(const ModInt B)const{return val*B.val%MOD;}
	ModInt operator+(const _T B)const{return (val+B)%MOD;}
	ModInt operator-(const _T B)const{return (val-B+MOD)%MOD;}
	ModInt operator*(const _T B)const{return val*B%MOD;}
	ModInt operator+=(const ModInt B){return (*this)=(*this)+B;}
	ModInt operator-=(const ModInt B){return (*this)=(*this)-B;}
	ModInt operator*=(const ModInt B){return (*this)=(*this)*B;}
};
template<ll MOD,typename _T=ll>
ModInt<MOD,_T> inv(ModInt<MOD,_T> x){return pw(x,MOD-2);}
template<ll MOD,typename _T=ll>
ModInt<MOD,_T> operator/(const ModInt<MOD,_T> A,const ModInt<MOD,_T> B)
{return A.val*inv(B).val%MOD;}
template<ll MOD,typename _T=ll>
ModInt<MOD,_T> operator/(const ModInt<MOD,_T> A,const _T B)
{return A.val*inv(ModInt<MOD,_T>(B)).val%MOD;}
template<ll MOD,typename _T=ll>
ModInt<MOD,_T> operator/=(ModInt<MOD,_T> &A,const ModInt<MOD,_T> B)
{return A=A/B;}
template<ll MOD,typename _T=ll>
istream& operator>>(istream &in,ModInt<MOD,_T> &A)
{
	in>>A.val;A.val%=MOD;
	return in;
}
template<ll MOD,typename _T=ll>
ostream& operator<<(ostream &out,const ModInt<MOD,_T> A)
{
	out<<A.val;
	return out;
}
typedef ModInt<998244353>      M998;
typedef ModInt<1000000007>     M197;
using MI= /*Be careful with the modulo!*/ M998;

/*-----------------Convolution-----------------*/
typedef vector<MI> Poly;
namespace Conv
{
const MI G=3,GI=inv(G);
const ll MD=MI::Mod();
MI o[25];
void init()
{
	for(int i=0;i<=23;i++)o[i]=pw(G,(MD^1)>>i);
}
void NTT(Poly &poly)
{
	int _n=poly.size();
	Poly _p(_n);
	for(int i=0;i<_n;i++)
	{
		int v=0;
		for(int wu=_n>>1,wv=1;wu;wu>>=1,wv<<=1)
			if(wu&i)v|=wv;
		_p[v]=poly[i];
	}
	poly=_p;
	for(int i=2;i<=_n;i<<=1)
	{
		int hf=i>>1;
		MI NowO=o[__builtin_ctz(i)];
		for(int j=0;j<_n;j+=i)
		{
			MI O(1);
			for(int k=j;k<j+hf;k++)
			{
				MI u=poly[k],v=O*poly[k+hf];
				poly[k]=u+v,poly[k+hf]=u-v;
				O=O*NowO;
			}
		}
	}
}
void INTT(Poly &poly)
{
	NTT(poly);
	reverse(poly.begin()+1,poly.end());
}
void convolution(Poly &x,Poly &y)//x*=y;
{
	init();
	int _n=x.size(),_m=y.size(),_t=_n+_m-1,__t=_n+_m-1;
	while((_t&(-_t))!=_t)_t+=_t&(-_t);
	while(_n<_t)_n++,x.PB(0);
	while(_m<_t)_m++,y.PB(0);
	NTT(x);
	NTT(y);
	for(int i=0;i<_t;i++)x[i]=x[i]*y[i];
	INTT(x);
	MI tinv=inv(MI(_t));
	for(MI &i:x)i*=tinv;
	while(x.size()>__t)x.PPB();
}
}

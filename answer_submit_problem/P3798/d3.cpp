#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
using MI= /*Be careful with the modulo!*/ M197;
int main(){
    ll ans=0,t=4;
    for(int i=2;i<=17;i++)ans+=t-4,t=t*2+pw(2,i+1);
    cout<<ans<<endl;
	ans=0,t=0;
    for(int i=2;i<=17;i++)ans+=t,t=t*2+pw(2,i+1);
    cout<<ans<<endl;
    return 0;
}
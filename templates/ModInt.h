#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll


/*----------------ModInt----------------*/
#define TmplT template<typename _T>
TmplT
_T pw(_T ds,ll zs)
{
	if(!zs)return (_T)1;
	_T t=pw(ds,zs>>1);t*=t;
	if(zs&1)return t*ds;
	return t;
}
#define T_MOD_TYP template<ll MOD,typename _T=ll>
T_MOD_TYP
struct ModInt
{
	_T val;
	ModInt(_T v=0){val=(v%MOD+MOD)%MOD;}
	_T V(){return val;}
	static _T Mod(){return MOD;}
	ModInt operator=(const _T v){return this->val=(v%MOD+MOD)%MOD;}
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
T_MOD_TYP
ModInt<MOD,_T> inv(ModInt<MOD,_T> x){return pw(x,MOD-2);}
T_MOD_TYP
ModInt<MOD,_T> operator/(const ModInt<MOD,_T> A,const ModInt<MOD,_T> B)
{return A.val*inv(B).val%MOD;}
T_MOD_TYP
ModInt<MOD,_T> operator/(const ModInt<MOD,_T> A,const _T B)
{return A.val*inv(ModInt<MOD,_T>(B)).val%MOD;}
T_MOD_TYP
ModInt<MOD,_T> operator/=(ModInt<MOD,_T> &A,const ModInt<MOD,_T> B)
{return A=A/B;}
T_MOD_TYP
ModInt<MOD,_T> operator/=(ModInt<MOD,_T> &A,const _T B)
{return A=A/B;}
T_MOD_TYP
istream& operator>>(istream &in,ModInt<MOD,_T> &A)
{
	in>>A.val;A.val%=MOD;
	return in;
}
T_MOD_TYP
ostream& operator<<(ostream &out,const ModInt<MOD,_T> A)
{
	out<<A.val;
	return out;
}
typedef ModInt<998244353>      M998;
typedef ModInt<1000000007>     M197;
using MI=M998;
MI operator "" _M(unsigned ll V){return MI(V);}
#undef T_MOD_TYP
#undef TmplT


/*----------------ModInt_variable----------------*/
#define TmplT template<typename _T>
TmplT
_T gcd(_T a,_T b)
{
	if(a<b)swap(a,b);
	return b?gcd(b,a%b):a;
}
TmplT
_T lcm(_T a,_T b){return a*b/gcd(a,b);}
TmplT
_T pw(_T ds,ll zs)
{
	if(!zs)return 1;
	_T t=pw(ds,zs>>1);t*=t;
	if(zs&1)return t*ds;
	return t;
}
#define TmplTll template<typename _T=ll>
TmplTll
struct ModInt_variable
{
	static _T MOD;
	static void SetMod(_T Mod)
	{
		MOD=Mod;
	}
	static void InMod()
	{
		cin>>MOD;
	}
	_T val;
	ModInt_variable(_T v=0){val=v%MOD;}
	_T V(){return val;}
	static _T Mod(){return MOD;}
	ModInt_variable operator+(const ModInt_variable B)const{return (val+B.val)%MOD;}
	ModInt_variable operator-(const ModInt_variable B)const{return (val-B.val+MOD)%MOD;}
	ModInt_variable operator*(const ModInt_variable B)const{return val*B.val%MOD;}
	ModInt_variable operator+(const _T B)const{return (val+B)%MOD;}
	ModInt_variable operator-(const _T B)const{return (val-B+MOD)%MOD;}
	ModInt_variable operator*(const _T B)const{return val*B%MOD;}
	ModInt_variable operator+=(const ModInt_variable B){return (*this)=(*this)+B;}
	ModInt_variable operator-=(const ModInt_variable B){return (*this)=(*this)-B;}
	ModInt_variable operator*=(const ModInt_variable B){return (*this)=(*this)*B;}
};
TmplT
_T ModInt_variable<_T> ::MOD=-1;
TmplTll
ModInt_variable<_T> inv(ModInt_variable<_T> x)
{return pw(x,ModInt_variable<_T>::MOD-2);}
TmplTll
ModInt_variable<_T> operator/(const ModInt_variable<_T> A,const ModInt_variable<_T> B)
{return A*inv(B)%ModInt_variable<_T>::MOD;}
TmplTll
ModInt_variable<_T> operator/(const ModInt_variable<_T> A,const _T B)
{return A*inv(ModInt_variable<_T>(B))%ModInt_variable<_T>::MOD;}
TmplTll
ModInt_variable<_T> operator/=(ModInt_variable<_T> A,const ModInt_variable<_T> B)
{return A=A/B;}
TmplTll
istream& operator>>(istream &in,ModInt_variable<_T> &A)
{
	in>>A.val;A.val%=ModInt_variable<_T>::MOD;
	return in;
}
TmplTll
ostream& operator<<(ostream &out,const ModInt_variable<_T> A)
{
	out<<A.val;
	return out;
}
typedef ModInt_variable<> M_Var;
typedef ModInt_variable<int> M_VarI;
using MIV=M_Var;
#undef TmplT
#undef TmplTll



int main()
{
	
	return 0;
}
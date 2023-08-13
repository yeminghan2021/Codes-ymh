#include<bits/stdc++.h>
using namespace std;
#define endl '\n'//交互题删掉
#define FIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define sp_el(i,n) " \n"[i==n]//空格换行
/*-------------------------basic template---------------------------*/
/*--------defines & constants--------*/
const int Size=/*array size*/114514;

#define ll long long
#define ull unsigned ll
#define Tmpl template<typename _T>
const ll M998=998244353,M197=1000000007;
const ll MOD=/*modulo number*/M998;
/*--------gcd & lcm & power--------*/
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
/*--------Integer with modulo--------*/
struct ModInt
{
	ll val;
	ModInt(ll v=0){val=v%MOD;}
	operator ll(){return val;}
	ModInt operator=(const ll v){return (*this)=ModInt(v);}
	ModInt operator+(const ModInt B)const{return (val+B.val)%MOD;}
	ModInt operator+=(const ModInt B){return (*this)=(*this)+B;}
	ModInt operator-(const ModInt B)const{return (val-B.val+MOD)%MOD;}
	ModInt operator-=(const ModInt B){return (*this)=(*this)-B;}
	ModInt operator*(const ModInt B)const{return val*B.val%MOD;}
	ModInt operator*=(const ModInt B){return (*this)=(*this)*B;}
};
ModInt inv(ModInt x){return pw(x,MOD-2);}
ModInt operator/(const ModInt A,const ModInt B)
{return (A*inv(B)).val%MOD;}
ModInt operator/=(ModInt A,const ModInt B){return A=A/B;}
istream& operator>>(istream &in,ModInt &A)
{
	in>>A.val;A.val%=MOD;
	return in;
}
ostream& operator<<(ostream &out,const ModInt A)
{
	out<<A.val;
	return out;
}
typedef ModInt MI;

/*--------Big Integer--------*/
struct BigInt
{
	vector<ll>num;
	/*----giving value----*/
	BigInt(const ll llval=0)
	{
		ll temp=llval;
		while(temp)num.push_back(temp%10),temp/=10;
	}
	BigInt operator=(const ll llval)
	{
		(*this)=BigInt(llval);
		return *this;
	}
	BigInt operator=(const string strval)
	{
		for(int i=strval.size()-1;~i;--i)
			num.push_back(strval[i]-'0');
		return *this;
	}
	/*----comparing operators----*/
	bool operator==(const BigInt B)const
	{
		if(num.size()!=B.num.size())return 0;
		for(int i=num.size()-1;~i;--i)
			if(num[i]!=B.num[i])return 0;
		return 1;
	}
	bool operator<(const BigInt B)const
	{
		if(num.size()!=B.num.size())return num.size()<B.num.size();
		for(int i=num.size()-1;~i;--i)
			if(num[i]!=B.num[i])return num[i]<B.num[i];
		return 0;
	}
	bool operator>(const BigInt B)const{return B<(*this);}
	bool operator<=(const BigInt B)const{return !(B<(*this));}
	bool operator>=(const BigInt B)const{return !(B<(*this));}
	/*----calculating operators----*/
	BigInt pop_zero(){while(!num.back())num.pop_back();return *this;}
	BigInt operator+(const BigInt B)const
	{
		BigInt C;//result
		int temp=0;
		int n=max(num.size(),B.num.size());
		for(int i=0;i<n;i++)
		{
			if(i<num.size())temp+=num[i];
			if(i<B.num.size())temp+=B.num[i];
			C.num.push_back(temp%10);
			temp/=10;
		}
		if(temp)C.num.push_back(temp);
		return C;
	}
	BigInt operator+=(const BigInt B){return (*this)=(*this)+B;}
	BigInt operator-(const BigInt B)const
	{
		BigInt C;//result
		int temp=0;
		int n=max(num.size(),B.num.size());
		for(int i=0;i<n;i++)
		{
			if(i<num.size())temp+=num[i];
			if(i<B.num.size())temp+=B.num[i];
			C.num.push_back((temp+10)%10);
			temp=(temp>=0?0:-1);
		}
		C.pop_zero();
		return C;
	}
	BigInt operator-=(const BigInt B){return (*this)=(*this)-B;}
	BigInt operator*(const BigInt B)const//龟速乘，FFT乘法见Fast_Mul
	{
		BigInt C;
		int Lena=num.size(),Lenb=B.num.size();
		for(int i=0;i<=Lena+Lenb;i++)C.num.push_back(0);
		for(int i=0;i<Lena;i++)
			for(int j=0;j<Lenb;j++)
				C.num[i+j]+=num[i]*B.num[j];
		for(int i=0;i<Lena+Lenb;i++)
			C.num[i+1]+=C.num[i]/10,C.num[i]%=10;
		C.pop_zero();
		return C;
	}
	BigInt operator*=(const BigInt B){return (*this)=(*this)*B;}
	BigInt operator/(const BigInt B)const
	{
		BigInt A=*this;
		if(A<B)return 0;
		BigInt C;
		for(int i=num.size()-B.num.size();~i;i--)
		{
			C.num.push_back(0);
			BigInt t1,t2,p10=pw((BigInt)10,i);
			t1=0;
			for(int j=i;j<num.size();j++)
				t1=t1*10+num[j];
			t2=A-t1*p10;
			while(t1>=B)C.num.back()++,t1-=B;
			A=t2+t1*p10;
		}
		reverse(C.num.begin(),C.num.end());
		C.pop_zero();
		return C;
	}
	BigInt operator/=(const BigInt B){(*this)=(*this)/B;}
	BigInt operator%(const BigInt B)const
	{
		BigInt A=*this;
		if(A<B)return A;
		for(int i=num.size()-B.num.size();~i;i--)
		{
			BigInt t1,t2,p10=pw((BigInt)10,i);
			t1=0;
			for(int j=i;j<num.size();j++)
				t1=t1*10+num[j];
			t2=(*this)-t1*p10;
			while(t1>=B)t1-=B;
			A=t2+t1*p10;
		}
		A.pop_zero();
		return A;
	}
	BigInt operator%=(const BigInt B){(*this)=(*this)%B;}
};
istream& operator>>(istream &in,BigInt &A)
{
	string str;
	in>>str;
	A=str;
	return in;
}
ostream& operator<<(ostream &out,const BigInt A)
{
	if(A==0)out<<0;
	else
	{
		for(int i=A.num.size()-1;~i;--i)
			out<<A.num[i];
	}
	return out;
}
/*--------fraction--------*/
Tmpl
struct Frac
{
	_T fz,fm;
	Frac(_T fz=0,_T fm=0):fz(fz),fm(fm){}
	Frac(_T Int_val):fz(Int_val),fm(1){}
	double val(){return (double)fz/fm;}//double value
	ll Mod(){return fz/fm;}
	void yf(){_T g=gcd(fz,fm);fz/=g,fm/=g;}//gcd() needed
	/*----comparing operators----*/
	bool operator==(const Frac B)const{return fz*B.fm==fm*B.fz;}
	bool operator<(const Frac B)const{return fz*B.fm<fm*B.fz;}
	bool operator<=(const Frac B)const{return fz*B.fm<=fm*B.fz;}
	bool operator>(const Frac B)const{return fz*B.fm>fm*B.fz;}
	bool operator>=(const Frac B)const{return fz*B.fm>=fm*B.fz;}
	/*----calculating operators----*/
	Frac operator+(const Frac B)const
	{
		ll Fm=lcm(fm,B.fm);
		ll U=Fm/fm,V=Fm/B.fm;
		ll Fz=U*fz+V*B.fz;
		Fm%=MOD,Fz%=MOD;
		return Frac(Fz,Fm);
	}
	Frac operator+(const ll B)const{return Frac((fz+B*fm)%MOD,fm);}
	Frac operator-(const Frac B)const
	{
		ll Fm=lcm(fm,B.fm);
		ll U=Fm/fm,V=Fm/B.fm;
		ll Fz=U*fz-V*B.fz;
		Fm%=MOD,Fz%=MOD;
		return Frac(Fz,Fm);
	}
	Frac operator-(const ll B)const{return Frac((fz-B*fm)%MOD,fm);}
	Frac operator*(const Frac B)const
	{return Frac(fz*B.fz%MOD,fm*B.fm%MOD);}
	Frac operator*(const ll B)const{return Frac(fz*B%MOD,fm);}
	Frac operator/(const Frac B)const
	{return Frac(fz*B.fm%MOD,fm*B.fz%MOD);}
	Frac operator/(const ll B)const{return Frac(fz,fm*B%MOD);}
};
Tmpl
istream& operator>>(istream &in,Frac<_T> &Fr)
{
	_T Fz,Fm;
	in>>Fz>>Fm;
	Fr=Frac<_T>(Fz,Fm);
	return in;
}
Tmpl
ostream& operator<<(ostream &out,const Frac<_T> Fr)
{
	out<<Fr.fz<<" "<<Fr.fm;// "/"?
	return out;
}
/*------------------------Advanced Template--------------------------*/
/*----------------Data Bases------------------*/
/*--------merging and finding set--------*/
struct BCJ
{
	int n;
	int fa[Size];
	void init(int n_){n=n_;for(int i=1;i<=n;i++)fa[i]=i;}
	//Find Root
	int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
	//Returns if x & y are in the same set
	bool Union(int x,int y){return Find(x)==Find(y);}
	//Merge x & y
	void Merge(int x,int y){if(!Union(x,y))fa[fa[x]]=fa[y];}
};
/*--------Set heap--------*/
Tmpl
struct Deque_Heap
{
	multiset<_T>tmp;
	void clear()
	{
		tmp.clear();
	}
	void insert(_T x)
	{
		tmp.insert(x);
	}
	_T Min()
	{
		return *tmp.begin();
	}
	_T Max()
	{
		return *tmp.rbegin();
	}
	bool del(_T x)
	{
		if(tmp.find(x)!=tmp.end())
		{
			tmp.erase(tmp.find(x));
			return 1;
		}
		else return 0;
	}
	bool pop_min()
	{
		if(tmp.empty())return 0;
		tmp.erase(tmp.find(Max()));
		return 1;
	}
	bool pop_max()
	{
		if(tmp.empty())return 0;
		tmp.erase(tmp.rbegin());
		return 1;
	}
	size_t size()
	{
		return tmp.size();
	}
	bool empty()
	{
		return tmp.empty();
	}
};
/*--------Binary Indexed Tree(BIT)--------*/
Tmpl
struct BIT//Point modify,interval query
{
	int n;
	_T arr[Size],a[Size];
	//lowbit
	int lb(int x){return x&(-x);}
	void add(int pos,_T val)
	{a[pos]+=val;while(pos<=n)arr[pos]+=val,pos+=lb(pos);}
	void modify(int pos,_T val){add(pos,val-a[pos]);}
	void init(){for(int i=1;i<=n;i++)add(i,a[i]);}
	//query prefix sum
	_T query_p(int pos)
	{
		_T res=0;
		while(pos)res+=arr[pos],pos-=lb(pos);
		return res;
	}
	//interval query
	_T query(int l,int r){return query_p(r)-query_p(l-1);}
};
Tmpl
struct BIT2//Interval modify,point query
{
	BIT<_T> t;
	int n;_T a[Size];
	void init()
	{
		t.n=n;
		for(int i=1;i<=n;i++)t.a[i]=a[i]-a[i-1];
		t.init();
	}
	void add(int l,int r,_T val){t.add(l,val);t.add(r+1,-val);}
	ll query(int pos){return t.query_p(pos);}
};
/*--------Segment Tree--------*/
Tmpl
struct SGT//Interval modify,interval query
{
#define lid id<<1
#define rid (lid)+1
	int n;
	_T a[Size];//raw array
	struct tree
	{
		int l,r;
		_T lz,sum;
	}tr[Size<<2];
	void addlz(int id){tr[id].sum+=tr[id].lz*(tr[id].r-tr[id].l+1);}
	void pu(int id){tr[id].sum=tr[lid].sum+tr[rid].sum;}
	void pd(int id)
	{
		_T &lz=tr[id].lz;
		tr[lid].lz+=lz,tr[rid].lz+=lz,lz=0;
		addlz(lid),addlz(rid);
		pu(id);
	}
	void build_t(int l,int r,int id)
	{
		tr[id].l=l,tr[id].r=r,tr[id].lz=0;
		if(l==r)return tr[id].sum=a[id],void();
		int mid=l+r>>1;
		build_t(l,mid,lid),build_t(mid+1,r,rid);
		pu(id);
	}
	void build(){build_t(1,n,1);}
	void modify_t(int l,int r,_T v,int id)
	{
		if(tr[id].l==l&&tr[id].r==r)
			return tr[id].lz+=v,addlz(id),void();
		pd(id);
		if(tr[lid].r>=l)
			if(tr[rid].l<=r)
				modify_t(l,tr[lid].r,v,lid),modify_t(tr[rid].l,r,v,rid);
			else modify_t(l,r,v,lid);
		else modify_t(l,r,v,rid);
		pu(id);
	}
	void modify(int l,int r,_T v=1){modify_t(l,r,v,1);}
	_T query_t(int l,int r,int id)
	{
		if(tr[id].l==l&&tr[id].r==r)return tr[id].sum;
		pd(id);
		if(tr[lid].r>=l)
			if(tr[rid].l<=r)
				return query_t(l,tr[lid].r,lid)+query_t(tr[rid].l,r,rid);
			else return query_t(l,r,lid);
		else return query_t(l,r,rid);
	}
	_T query(int l,int r){return query_t(l,r,1);}
};
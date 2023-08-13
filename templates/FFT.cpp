#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define PB emplace_back
#define PPB pop_back
#define VI vector<int>
#define VL vector<ll>
namespace Conv
{
const double PI=3.141592653589793238;
struct Complex
{//Lower constant
	double rl,im;
	Complex():rl(0.0),im(0.0){}
	Complex(double real):rl(real),im(0.0){}
	Complex(double r,double i):rl(r),im(i){}
	Complex operator+(const Complex &B)const
	{
		return Complex(rl+B.rl,im+B.im);
	}
	Complex operator-(const Complex &B)const
	{
		return Complex(rl-B.rl,im-B.im);
	}
	Complex operator*(const Complex &B)const
	{
		return Complex(rl*B.rl-im*B.im,rl*B.im+im*B.rl);
	}
};
Complex omega(int n){return Complex(cos(2*PI/n),sin(2*PI/n));}
typedef vector<Complex> Poly;
void FFT(Poly &poly)
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
		Complex NowO=omega(i);
		for(int j=0;j<_n;j+=i)
		{
			Complex O(1);
			for(int k=j;k<j+hf;k++)
			{
				Complex u=poly[k],v=O*poly[k+hf];
				poly[k]=u+v,poly[k+hf]=u-v;
				O=O*NowO;
			}
		}
	}
}
void IFFT(Poly &poly)
{
	FFT(poly);
	reverse(poly.begin()+1,poly.end());
}
void convolution(VL &x,VL &y)//x*=y;
{
	int _n=x.size(),_m=y.size(),_t=_n+_m-1,__t=_n+_m-1;
	while((_t&(-_t))!=_t)_t+=_t&(-_t);
	Poly x_,y_;
	for(ll i:x)x_.PB(Complex(i,0));
	for(ll i:y)y_.PB(Complex(i,0));
	while(_n<_t)_n++,x_.PB(Complex());
	while(_m<_t)_m++,y_.PB(Complex());
	FFT(x_);
	FFT(y_);
	for(int i=0;i<_t;i++)x_[i]=x_[i]*y_[i];
	IFFT(x_);
	x.clear();
	for(Complex &i:x_)x.PB(i.rl/_t+0.5);
	while(x.size()>__t)x.PPB();
}
}
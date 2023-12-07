#ifndef YMH_HEADS
#include "heads.h"
#endif

namespace IO//超级读写
{
constexpr size_t Buf_Siz=1919810;
char Buf[Buf_Siz],*it=Buf,*itn=Buf;
char rdc()
{
	if(it==itn&&(it=Buf,itn=Buf+fread(Buf,1,Buf_Siz,stdin))==Buf)return EOF;
	return *(it++);
}
void rdc(char &ch){ch=rdc();}
template<typename T>
void rd(T &Int)
{
	char ch;
	bool neg=0;
	while(!((ch=rdc())&16))if(ch=='-')neg=1;
	Int=0;
	while((ch=rdc())&16)Int=(Int<<3)+(Int<<1)+(ch&15);
	if(neg)Int=-Int;
}
void rdstr(string &str)
{
	str="";
	char ch;
	while((ch=rdc())!=' '&&ch!='\n'&&ch!='\r')str.push_back(ch);
	if(ch=='\r')assert(rdc()=='\n');
}
void rdline(string &str)
{
	str="";
	char ch;
	while((ch=rdc())!='\n'&&ch!='\r')str.push_back(ch);
	if(ch=='\r')assert(rdc()=='\n');
}
}
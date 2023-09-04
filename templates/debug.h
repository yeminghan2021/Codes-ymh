//#include<bits/stdc++.h>
//using namespace std;

template<typename T>
void Print_(const T &Var)
{
	cerr<<Var;
}
void Print_(const char &Ch)
{
	cerr<<"'"<<Ch<<"'";
}
void Print_(const string &Str)
{
	cerr<<"\""<<Str<<"\"";
}
template<typename T>
void Print_(const vector<T> &Vec)
{
	cerr<<"[";
	auto tit=--Vec.end();
	for(auto it=Vec.begin();it!=tit;it++)
		Print_(*it),cerr<<",";
	Print_(*tit);
	cerr<<"]";
}
template<typename T,typename U>
void Print_(const pair<T,U> &Pair)
{
	cerr<<"(";
	Print_(Pair.first);
	cerr<<",";
	Print_(Pair.second);
	cerr<<")";
}
template<typename T>
void Print_(const set<T> &Vec)
{
	cerr<<"{";
	auto tit=--Vec.end();
	for(auto it=Vec.begin();it!=tit;it++)
		Print_(*it),cerr<<",";
	Print_(*tit);
	cerr<<"}";
}
template<typename T,typename U>
void Print_(const map<T,U> &Vec)
{
	cerr<<"{";
	auto tit=--Vec.end();
	for(auto it=Vec.begin();it!=tit;it++)
		Print_(it->first),cerr<<":",Print_(it->second);
	Print_(*tit);
	cerr<<"}";
}
void Print(){}
template<typename T,typename ...Types>
void Print(T fir,Types...follows)
{
	Print_(fir);
	if(sizeof...(follows))cerr<<",";
	Print(follows...);
}

#define dbg(vals...) cerr<<"{"#vals"}={",Print(vals),cerr<<"}\n"

#define msg(msgs...) Print(#msgs)
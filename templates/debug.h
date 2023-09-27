/**	@file debug.h
	@author yeminghan2021
	@version 0.2
	This header is used to make debugging easier in your code.
*/

#ifndef DEBUG
#include<bits/stdc++.h>
using namespace std;
#endif

/// @brief Print a variable in debug form.
/// @param Var 
template<typename T>void Print_(const T &);
void Print_(const char &);
void Print_(const string &);
template<typename T>void Print_(const vector<T> &);
template<typename T,typename U>void Print_(const pair<T,U> &);
template<typename T,typename ...after>void Print_(const set<T,after...> &);
template<typename T,typename U,typename ...after>void Print_(const map<T,U,after...> &);
template<typename T>void Print_(const T &Var)
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
	if(!Vec.empty())
	{
		auto tit=--Vec.end();
		for(auto it=Vec.begin();it!=tit;it++)
			Print_(*it),cerr<<",";
		Print_(*tit);
	}
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
template<typename T,typename ...after>
void Print_(const set<T,after...> &Vec)
{
	cerr<<"{";
	if(!Vec.empty())
	{
		auto tit=--Vec.end();
		for(auto it=Vec.begin();it!=tit;it++)
			Print_(*it),cerr<<",";
		Print_(*tit);
	}
	cerr<<"}";
}
template<typename T,typename U,typename ...after>
void Print_(const map<T,U,after...> &Vec)
{
	cerr<<"{";
	if(!Vec.empty())
	{
		auto tit=--Vec.end();
		for(auto it=Vec.begin();it!=tit;it++)
			cerr<<"(",Print_(it->first),cerr<<":",Print_(it->second),cerr<<")";
	}
	cerr<<"}";
}

/// @brief Print SOME variables.
/// @param ...
void Print(){}
template<typename T,typename ...Types>
void Print(const T &fir,Types...follows)
{
	Print_(fir);
	if(sizeof...(follows))cerr<<",";
	Print(follows...);
}

/// @brief Print SOME variables in debug form.
#define dbg(vals...) cerr<<"<"#vals">=<",Print(vals),cerr<<">\n"

/// @brief Print a message.
#define msg(msgs...) Print(msgs),cerr<<endl
#include "header.hpp"
Number Add(Number a,Number b,int base)
{
	int BASE=base;
	vector<int> x,y,ans;
	int extra = a.exp - b.exp,exp = max(a.exp,b.exp);
	for(int i=0;i < extra;i++)
	{
		y.push_back(0);
	}
	for(int i=0;i< b.dts.size();i++)
	{
		y.push_back(b.dts[i]);
	}
	for(int i=0;i < -extra;i++)
	{
		x.push_back(0);
	}
	for(int i=0;i< a.dts.size();i++)
	{
		x.push_back(a.dts[i]);
	}

	if(x.size()>=y.size())
	{
		add(x,y,ans,BASE);
	}
	else
	{
		add(y,x,ans,BASE);
	}
	Number realAns;
	realAns.dts = ans;
	realAns.exp = exp;
	return realAns;
	
}
Number Mul(Number a,Number b,int base)
{
	int BASE =base;
	vector<int> ans;
	while(a.dts.size() > b.dts.size())
	{
		b.dts.push_back(0);
	}
	while(a.dts.size() < b.dts.size())
	{
		a.dts.push_back(0);
	}
	mul(a.dts,b.dts,ans,BASE);
	int size = ans.size()-1;
	while(size >=0)
	{
		if(ans[size] == 0) ans.pop_back();
		else break;
		size--;
	}
	Number realAns;
	realAns.dts = ans;
	realAns.exp = a.exp + b.exp;
	return realAns;
}
Number Div(Number a,Number b,int precision, int base)
{
	int BASE=base;
	precision+=5;
	Number x,y;
	int st = 0;
	if(a.exp >= (precision+b.exp))
	{
		st = -(b.dts.size() + precision - a.exp);
	}
	else
	{
		for(int i=0;i< b.dts.size() + precision - a.exp;i++)
		{
			x.dts.push_back(0);
			x.exp++;
		}
	}
	for(int i=st;i<a.dts.size();i++)
	{
		x.dts.push_back(a.dts[i]);
		if(i < a.exp) x.exp++;
	}
	int extra = b.dts.size()-1;
	while(extra>=0)
	{
		if(b.dts[extra] != 0) break;
		else extra--;
	}
	for(int i=extra;i>=0;i--)
	{
		y.dts.push_back(b.dts[i]);
	}
	reverse(y.dts.begin(),y.dts.end());
	y.exp = b.exp;
	vector<int> ans,r_ans;
	
	div(x.dts,y.dts,ans,r_ans,BASE);

	extra = ans.size()-1;
	while(extra>=0)
	{
		if(ans[extra] == 0) ans.pop_back();
		else break;
		extra--;
	}
	if(ans.size() == 0) ans.push_back(0);

	Number q;
	q.dts = ans;
	q.exp = x.exp - b.exp;
	return q;
}
Number getbase(int base){
	Number b;
	int n=10;
	int temp;
	while(base!=0){
		temp=base%n;
		b.dts.push_back(temp);
		base=base/n;
	}
	return b;
}
Number changebase (Number a , int base, int precision){
	int temp =0; 
	if (a.exp<0){
		temp=-1*a.exp;
	}
	//making only number base
	Number posbase , negbase ,tempbase;
	posbase=getbase(base);
	tempbase=posbase;
	//posbase.dts.push_back(base);
	//making only number 1
	Number one ;
	one.dts.push_back(1);
	//omly number 1/base;
	negbase=Div(one, posbase, precision,10);
	
	//calulating before decimal
	Number bef_dec;
	//bef_dec.dts.push_back(0);
	// calculating before decimal part ;
	for(int i = temp-1 ; i>=0 ; i--){
		Number x ;
		x.dts.clear();
		x.dts.push_back(a.dts[i]);
		Number t=Mul(negbase ,x,10);
		bef_dec=Add(bef_dec,t,10);
		posbase=Mul(tempbase,posbase,10);
		negbase=Div(one,posbase,precision,10);
	}
	posbase.dts.clear();
	posbase=getbase(base);
	posbase.exp=0;
	for(int i =temp ; i<a.dts.size();i++){
		Number x;
		x.dts.clear();
		x.dts.push_back(a.dts[i]);
		Number t =Mul(one,x,10);
		bef_dec=Add(bef_dec,t,10);
		one=Mul(one,posbase,10);
	}
	return bef_dec;
}
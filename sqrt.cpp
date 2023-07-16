#include "header.hpp"
Number sqr_root(Number a,int precision,int base)
{
	Number x,two;
	x.exp = 1;
	x.dts.push_back(5);
	x.dts.push_back(1);
	two.exp = 0;
	two.dts.push_back(2);
	int tmp = 1;
	while(tmp <= 2*precision)
	{
		x = Div(Add(x,Div(a,x,precision,base),base),two,precision,base);
		tmp = tmp << 1;
	}
	return x;

}

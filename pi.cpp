#include "header.hpp"
Number find_pi(int precision,int base)
{
	Number a0,b0,p0,a1,b1,p1,two,one;
	one.dts.push_back(1);
	two.dts.push_back(2);
	a0 = sqr_root(two,precision,base);
	b0.dts.push_back(0);
	p0 = Add(two,a0,base);
	int c = 1;
	while(c < 2*precision)
	{
		Number tmp[3];
		tmp[0] = Add(sqr_root(a0,precision,base),Div(one,sqr_root(a0,precision,base),precision,base),base);
		a1 = Div(tmp[0],two,precision,base);
		tmp[0] = Add(one,b0,base);
		tmp[1] = Mul(tmp[0],sqr_root(a0,precision,base),base);
		tmp[2] = Add(a0,b0,base);
		b1 = Div(tmp[1],tmp[2],precision,base);
		tmp[0] = Add(one,a1,base);
		tmp[1] = Mul(tmp[0],Mul(p0,b1,base),base);
		tmp[2] = Add(one,b1,base);
		p1 = Div(tmp[1],tmp[2],precision,base);
		c = c << 1;
		p0 = p1;
		a0 = a1;
		b0 = b1;
	}
	return p1;
}
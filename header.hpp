#include <bits/stdc++.h>
using namespace std;
class Number
{
	public:
	vector<int> dts;
	int exp;
	Number()
	{
		exp = 0;
	}
	~Number()
	{
		dts.clear();
	}
};
vector<int> QuoRem(int x, int base);
int AddZeros(vector <int> &a,vector<int> &b);
void add(vector<int> &a,vector<int> &b,vector<int> &c,int B);
Number Add(Number a,Number b,int base);
void mul(vector<int> &a,vector<int> &b,vector<int> &c,int B);
Number Mul(Number a,Number b,int base);
void div(vector<int> &a,vector<int> &b,vector<int> &q,vector<int> &r,int B);
Number Div(Number a,Number b,int precision, int base);
Number getbase(int base);
Number changebase (Number a , int base, int precision);
Number sqr_root(Number a,int precision,int base);
Number find_pi(int precision,int base);
void sub(vector<int> &a,vector<int> &b,vector<int> &c,int B);
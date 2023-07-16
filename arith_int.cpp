#include "header.hpp"
vector<int> QuoRem(int x, int base)
{
    vector<int> ans;
    int q = x/base;
    int rem = x%base;
    if(rem < 0)
    {
        rem += base;
        q -= 1;
    }
    ans.push_back(q);
    ans.push_back(rem);

    return ans;
}
int AddZeros(vector <int> &a,vector<int> &b)
{
	int extra = a.size() - b.size();
	while(extra > 0)
	{
		b.push_back(0);
		extra--;
	}
	while(extra < 0)
	{
		a.push_back(0);
		extra++;
	}
	return a.size();
}
void add(vector<int> &a,vector<int> &b,vector<int> &c,int B)
{
	int carry = 0,k=a.size(),l=b.size(),tmp;
	for (int i = 0; i < l; i++)
	{
		tmp = a[i] + b[i] + carry;
		vector<int> tmp_vec = QuoRem(tmp,B);
		carry = tmp_vec[0];
		c.push_back(tmp_vec[1]);
	}
	for(int i=l ;i< k ;i++)
	{
		tmp = a[i] + carry;
		vector<int> tmp_vec = QuoRem(tmp,B);
		carry = tmp_vec[0];
		c.push_back(tmp_vec[1]);
	}
	if(carry)
	{
		c.push_back(carry);
	}
}
void mul(vector<int> &a,vector<int> &b,vector<int> &c,int B)
{
	int k = a.size(),l = b.size(),carry = 0;
	for(int i=0;i<(k+l);i++)
	{
		c.push_back(0);
	}
	for(int i=0;i<k;i++)
	{
		carry = 0;
		for(int j=0;j<l;j++)
		{
			int tmp = a[i]*b[j] + c[i+j] + carry;
			vector<int> tmp_vec = QuoRem(tmp,B);
			carry = tmp_vec[0];
			c[i+j] = tmp_vec[1];
		}
		c[i+l] = carry;
	}
}
void div(vector<int> &a,vector<int> &b,vector<int> &q,vector<int> &r,int B)
{
	int k = a.size(),l = b.size();
	for (int i = 0; i < k; i++)
	{
		r.push_back(a[i]);
		q.push_back(0);
	}
	r.push_back(0);
	for(int i = (k-l);i>=0;i--)
	{
		q[i] = (r[i+l]*B + r[i+l-1])/b[l-1];
		if(q[i] >= B) q[i] = B - 1;
		int carry = 0;
		for(int j=0 ;j<l;j++)
		{
			int tmp = r[i+j] - q[i]*b[j] + carry;
			vector<int> tmp_vec = QuoRem(tmp,B);
			carry = tmp_vec[0];
			r[i+j] = tmp_vec[1];
		}
		r[i+l] = r[i+l] + carry;
		while (r[i+l] < 0)
		{
			carry =0;
			for(int j=0;j<l;j++)
			{
				int tmp = r[i+j] + b[j] + carry;
				vector<int> tmp_vec = QuoRem(tmp,B);
				carry = tmp_vec[0];
				r[i+j] = tmp_vec[1];
			}
			r[i+l] = r[i+l] + carry;
			q[i] = q[i] - 1;
		}
	}
	for(int i = (k-l+1);i<q.size();i++)
	{
		q.pop_back();
	}
	for(int i=l;i<r.size();i++)
	{
		r.pop_back();
	}
}
void sub(vector<int> &a,vector<int> &b,vector<int> &c,int B)
{
	int carry = 0,k=a.size(),l=b.size(),tmp;
	for (int i = 0; i < l; i++)
	{
		tmp = a[i] - b[i] + carry;
		vector<int> tmp_vec = QuoRem(tmp,B);
		carry = tmp_vec[0];
		c.push_back(tmp_vec[1]);
	}
	for(int i=l ;i< k ;i++)
	{
		tmp = a[i] + carry;
		vector<int> tmp_vec = QuoRem(tmp,B);
		carry = tmp_vec[0];
		c.push_back(tmp_vec[1]);
	}
}

#include "header.hpp"
int main()
{
	int n, precision, m, base;
	cout << "Enter 1 to find pi or 2 to find sqrt(2) : ";
	cin >> n;
	cout << "Enter the precision to be obtained : ";
	cin >> precision;
	cout << "Enter the base in which you want output. eg (base 10 for decimal) : ";
	cin >> base;
	Number c;
	precision=precision++;
	if(n==2){
		Number two;
		two.dts.push_back(2);
		c=sqr_root(two,precision,base);
		c.exp=-1*c.exp;
		c=changebase(c,base,precision);
		int temp = c.dts.size()-precision-1;
		for(int i =c.dts.size()-1 ;i>=temp ;i--){
			cout <<c.dts[i];
			if(i==c.dts.size()-1){
				cout<<".";
			}
		}
		cout<<endl;
	}
	else if(n==1){
        c=find_pi((((10/base)+1)*precision)+15,base);

		int temp = c.dts.size()-precision-1;
		if(base!=10){
			c.exp=-1*c.exp;
			c=changebase(c,base,precision);
		}
		temp = c.dts.size()-precision-1;
		for(int i =c.dts.size()-1 ;i>=temp ;i--){
			cout <<c.dts[i];
			if(i==c.dts.size()-1){
				cout<<".";
			}
		}
		cout<<endl;
	}
	return 0;
}
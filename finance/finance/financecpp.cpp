#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include "math.h" 


using namespace std;

/*

// return a uniformly distributed random number
double uniformRandom()
{
return ((double)(rand()) + 1.) / ((double)(RAND_MAX)+1.);
}
// return a normally distributed random number
double normalRandom()
{
double u1 = uniformRandom();
double u2 = uniformRandom();
return cos(8.*atan(1.)*u2)*sqrt(-2.*log(u1));
}
*/

double sampleNormal() {
	double u = ((double)rand() / (RAND_MAX)) * 2 - 1;
	double v = ((double)rand() / (RAND_MAX)) * 2 - 1;
	double r = u * u + v * v;
	if (r == 0 || r > 1) return sampleNormal();
	double c = sqrt(-2 * log(r) / r);
	return u * c;
}
double simulate(int m, double s, double r, double si){ //add 2 new
	//double b = s;
	//double b = 0;
	for (int i = 0; i < m; i++){
		//double rerate = r + si*sampleNormal();
		//double rerate = r*(1.0 / m) + sqrt(1.0/ m)* si  * sampleNormal(); 
		//s = s* (1+rerate);
		//s = s*(1+ r *( 1 /m) + si*sampleNormal()*sqrt(1.0/m));
		s = s* exp((r - si *si / 2) * 1.0/m + si*sampleNormal()*sqrt(1.0/m));
		//s = s* exp((0.03 - 0.4 *0.4 / 2) * 0.25/m + 0.4*sampleNormal()*sqrt(0.25/m));
		//if (b>=s) b = s;//added for the question 3
		//b = b + s;//for question 4
		//cout << "s: " << s << endl;
		//if (s <= 6) return 12;//make a =12 

	}
	//b = b / m;//question 4
	return s;
	//return b;question 3 4
}


int main(){
	int m=0, n=0,k = 0;
	double s = 68.389999;
	double r=0, si = 0;
	double vp=0,vc = 0;
	
	
	cout << "input steps M" << endl;
	cin >> m;
	cout << "input paths N" << endl;
	cin >> n;
	cout << "input annual miu" << endl; //Newv start
	cin >> r;
	cout << "input annual sigma" << endl;
	cin >> si; 
	cout << "input strike price K" << endl;
	cin >> k;//New end

	/*cout << "how many times you want to loop" << endl;
	cin >> k;*/
	//for (int i = 0; i < 5; i++){ // verify on May 5 2018

	/*cout << "input S0" << endl;
	cin >> s;*/
	for (int l = 0; l < n; l++){
		double a = simulate(m, s, r, si);
		cout << "a1: " << a << endl;
		//if in question 5 s<b, we will get a = 12 here
		double p = k - a;
		double c = a - k;
		//a = 12 - a;//if a = 12 a=12-a =0
		cout << "C: " << c << endl;
		if (c>=0) 
			vc += c;//nothing change to v
		cout << "P: " << p << endl;
		if (p >= 0)
			vp += p;

			//cout << "v: " << v << endl;
	}
		
	vc = vc / n;
	vp = vp / n;
	//v = v* exp(-0.03*0.25);
	vp = vp* exp(-0.03 * 1);
	vc = vc* exp(-0.03 * 1);

	cout << "Call at: " << s << ": " << vc << endl;
	cout << "Put at: " << s << ": " << vp << endl;
	

	//cout <<"price "<< s<<": "<<v<<endl;
	//s++;
	//}
	return 0;
}
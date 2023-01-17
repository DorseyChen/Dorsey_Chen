#include <iostream>
using namespace std;

class Fraction {
	private:
		int numer;
		int denom;
		
		// Calculate the "greatest common divisor" of the two integers
		int gcd(int, int);
		
		// Calculate the "least common multiple" of the two integers
		int lcm(int, int);
		
	public:
		// If the initial values are not assigned, just set it as 0
		Fraction() { numer = 0; denom = 1; };
		
		// Set the fraction's numerator and denominator
		void set(int n, int d);
		
		// Reduce the fraction to the lowest terms
		// Hint: You may use the gcd and lcm
		void reduce();
		
		// Overload operator+
		// Implement the addtion of two fractions
		// aka. Fraction + Fraction
		Fraction operator+(const Fraction &);
		
		// Overload operator+
		// Implement the addtion of a fractions and an integer
		// aka. Fraction + integer
		Fraction operator+(int);

		// Overload ++f
		Fraction operator++();
		
		// Overload f++
		Fraction operator++(int);
		
		// Overload input stream of a fraction
		friend istream& operator>>(istream&, Fraction&);
		
		// Overload output stream of a fraction
		friend ostream& operator<<(ostream&, const Fraction&);
};

int main() {
	Fraction f1,f2,f3;

	cin>>f1>>f2>>f3;
	cout<<"f1: "<<f1<<endl;
	cout<<"f2: "<<f2<<endl;
	cout<<"f3: "<<f3<<endl;
	
	cout<<f1<<" + "<<f2<<" = "<<(f1 + f2)<<endl;
	cout<<f3<<" + "<<"1"<<" = "<<(f3 + 1)<<endl;
	cout<<f1<<" + "<<f2<<" + "<<f3<<" = "<<(f1 + f2 + f3)<<endl;
	cout<<"f2++ = "<<(f2++)<<endl;
	cout<<"++f2 = "<<(++f2)<<endl;
	
	return 0;
}

/* Private methods */ 
int Fraction::gcd(int a, int b) {
	while((b%=a) && (a%=b));
	return a+b;
}

int Fraction::lcm(int a, int b) {
	return a*b/gcd(a,b);
}

/* Public methods */
void Fraction::set(int n, int d) {
	numer = n;
	denom = d;
}
void Fraction::reduce() {
	// Write here
}

Fraction Fraction::operator+(const Fraction & f) {
	// Write here
}

Fraction Fraction::operator+(int n) {
	// Write here
}

Fraction Fraction::operator++() {	// Overload "++f"
	// Write here
}

Fraction Fraction::operator++(int) { // Overload "f++"
	// Write here
}
		
istream& operator>>(istream& in, Fraction& f) {
	in>>f.numer>>f.denom;
	return in;
}
ostream& operator<<(ostream& out, const Fraction& f) {
	out<<"( "<<f.numer<<" / "<<f.denom<<" )";
	return out;
}

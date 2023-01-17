#include<iostream>
#include<stdio.h>
using namespace std;

class Fraction
{
    int number;
    int denom;
    int find_gcd(int,int);
    public:
    Fraction();
    Fraction(int);
    Fraction(int,int);
    void setNum(int);
    void setDEN(int);
    int getNum();
    int getDEN();
    void increment();
    Fraction operator+(const Fraction &fr);
    Fraction operator*(const Fraction &fr);
    void add_fraction(int,int);
    void reduce_fraction(int,int);
    //void multiply_fraction(int,int);
    //void divide_fraction(int,int);
    void print_fraction();
};

int main()
{
    char c;
    Fraction fraction1;
    Fraction fraction2(1,2);
    Fraction fraction3;

    int num,den,gcd;

    cout<<"Please set the first fraction: ";
    cin>>num>>c>>den;
    fraction1.setNum(num);
    fraction1.setDEN(den);

    cout<<"The number and denom you entered: ";
    fraction1.print_fraction();
    fraction3=fraction1;
    fraction3+fraction2;
    cout<<"The sum of the fraction and 1/2 is: ";
    fraction3.increment();
    fraction3.print_fraction();

    cout<<"Please enter a fraction: ";
    cin>>num>>c>>den;
    cout<<"After reducing the second fraction from the first one: ";
    fraction1.reduce_fraction(num,den);
    fraction1.increment();
    fraction1.print_fraction();
    cout<<"After adding the second fraction back: ";
    fraction1.add_fraction(num,den);
    fraction1.increment();
    fraction1.print_fraction();

    return 0;
}



Fraction::Fraction()
{
    number=0;
    denom=1;
}

Fraction::Fraction(int value)
{
    if(number==0&&denom==1)
        number=value;
    else
        denom=value;
}

Fraction::Fraction(int num,int den)
{
    number=num;
    denom=den;
}

int Fraction::find_gcd(int x,int y)
{
    int gcd,i;
    for(i=1;i<=y;i++)
    {
        if(y%i==0&&x%i==0)
            gcd=i;
    }
    return gcd;
}
     
void Fraction::setNum(int num)
{
    number=num;
}

void Fraction::setDEN(int den)
{
    denom=den;
}

int Fraction::getNum()
{
    return number;
}

int Fraction::getDEN()
{
    return denom;
}

void Fraction::increment()
{
    int gcd;
    gcd=find_gcd(number,denom);
    number/=gcd;
    denom/=gcd;
}


Fraction Fraction::operator+(const Fraction &fr)
{
    int tmp,lcm,num;
    if(denom!=fr.denom)
    {
        lcm=denom*fr.denom/find_gcd(denom,fr.denom);
	    tmp=lcm/denom;
        number*=tmp;
        tmp=lcm/fr.denom;
        num=fr.number*tmp;
        denom=lcm;
    }
    cout<<num<<endl;
    number+=num;
}


Fraction Fraction::operator*(const Fraction &fr)
{
    int gcd;
    number*=fr.number;
    denom*=fr.denom;
    gcd=find_gcd(number,denom);
    number/=gcd;
    denom/=gcd;
}

void Fraction::add_fraction(int num,int den)
{
    int tmp,lcm;
    if(denom!=den)
    {
        lcm=denom*den/find_gcd(denom,den);
        tmp=lcm/denom;
        number*=tmp;
        tmp=lcm/den;
        num*=tmp;
        denom=lcm;
    }
    number+=num;
}

void Fraction::reduce_fraction(int num,int den)
{
    int tmp,lcm;
    if(denom!=den)
    {
        lcm=denom*den/find_gcd(denom,den);
        tmp=lcm/denom;
        number*=tmp;
        tmp=lcm/den;
        num*=tmp;
        denom=lcm;
    }
    number-=num;
}

void Fraction::print_fraction()
{
    cout<<number<<"/"<<denom<<endl;
}


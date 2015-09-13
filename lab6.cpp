#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

class fraction
{
  public:
    fraction() : numerator(0), denominator(1){}
    fraction(int n) : numerator(n), denominator(1){} 
    fraction(int n, int d);  
    const fraction operator+(fraction&) const;
    const fraction operator-(fraction&) const;
    const fraction operator*(fraction&) const;
    const fraction operator/(fraction&) const;
    friend ostream& operator<<(ostream&, const fraction&); 
    friend istream& operator>>(istream&, fraction&); 
  private:
    int numerator;
    int denominator;
};

int gcd(int i, int j)
{
  if(i < 0)i = -i;
  if(j < 0)j = -j;
  if(i < j)swap(i,j);
  while(j != 0)
  {
    i = i % j;
    swap(i,j);
  }
  return i;
}

fraction::fraction(int n, int d)
{
  int temp_gcd = gcd(n,d);
  numerator = n / temp_gcd;
  denominator = d / temp_gcd;
}

const fraction fraction::operator+(fraction& rhs) const
{
  fraction result(rhs.numerator, rhs.denominator);
  int d = result.denominator * denominator;
  int n = result.denominator * numerator + result.numerator * denominator; 
  int temp_gcd = gcd(n,d);
  return result = fraction(n / temp_gcd, d / temp_gcd);
}

const fraction fraction::operator-(fraction& rhs) const
{
  fraction result(rhs.numerator, rhs.denominator);
  int d = result.denominator * denominator;
  int n = result.denominator * numerator - result.numerator * denominator; 
  int temp_gcd = gcd(n,d);
  return result = fraction(n / temp_gcd, d / temp_gcd);
}

const fraction fraction::operator*(fraction& rhs) const
{
  fraction result(rhs.numerator, rhs.denominator);
  int d = result.denominator * denominator;
  int n = result.numerator * numerator; 
  int temp_gcd = gcd(n,d);
  return result = fraction(n / temp_gcd, d / temp_gcd);
}

const fraction fraction::operator/(fraction& rhs) const
{
  fraction result(rhs.numerator, rhs.denominator);
  int d = result.numerator * denominator;
  int n = result.denominator * numerator;
  int temp_gcd = gcd(n,d);
  return result = fraction(n / temp_gcd, d / temp_gcd);
}

ostream& operator<<(ostream& os, const fraction& f)
{
  os << f.numerator << "/" << f.denominator;
  return os;
}

istream& operator>>(istream& is, fraction& f)
{
  int temp_numerator, temp_denominator;
  is >> temp_numerator >> temp_denominator;
  f = fraction(temp_numerator, temp_denominator);
  return is;
}

int main(int argc, const char* argv[])
{
  fraction v,t,w;
  char op;
  while(1)
  {
    cout << endl << v << " ";
    
    cin >> op;
    if(op != '+' && op != '-' && op != '*' && op != '/') break;    

    cin >> t;
    if(cin.fail()) break;

    switch(op)
    {
      case '+': w = v + t;
            break;
      case '-': w = v - t;
            break;
      case '*': w = v * t;
            break;
      case '/': w = v / t;
            break;
    }
    cout << v << ' ' << op << t << " = " << w << endl;
    v = w;
  }
  return 0;
}

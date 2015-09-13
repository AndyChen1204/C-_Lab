#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cassert>

using namespace std;

void CalcArea( double, double, double* );
void CalcArea( double, double, double, double* );

int main( int argc, const char* argv[] )
{
  cout << "Please enter three lengrh" << endl;

  double side_a, side_b, side_c;
  cin >> side_a >> side_b >> side_c;
  
  assert( side_a > 0 || side_b > 0 || side_c > 0);

  double recArea;
  CalcArea( side_a, side_b, &recArea);
  cout << "The area of the rectangle is " << recArea << endl;

  double triArea;
  CalcArea( side_a, side_b, side_c, &triArea );
  cout << "The area of the triangle is " << triArea << endl;   
}

void CalcArea( double side_a, double side_b, double* area )
{
  *area = side_a * side_b;
}
void CalcArea( double side_a, double side_b, double side_c, double* area )
{
  double s = ( side_a + side_b + side_c ) / 2;
  *area = sqrt( s * ( s - side_a ) * ( s - side_b ) * ( s - side_c ) );
}

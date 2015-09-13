#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double pi = 3.14;

double distance_2D(double, double, double, double);
double use_local_pi_area(double);
double use_global_pi_area(double);

int main(int argc, const char* argv[])
{
  cout << "Point 1's coordinate:";
  double x1,y1;
  cin >> x1
      >> y1;
  cout << "Point 2's coordinate:";
  double x2,y2;
  cin >> x2
      >> y2;
  double distance = distance_2D(x1,y1,x2,y2);
  double local_pi_area = use_local_pi_area(distance);
  double global_pi_area = use_global_pi_area(distance);
  double abs_difference = fabs(local_pi_area - global_pi_area);
  
  cout << "=========Result========== " << endl; 
  cout << "Distance: " << distance << endl;
  cout << "Area of 2. : " << local_pi_area << endl;
  cout << "Area of 3. : " << global_pi_area << endl;
  cout << "Difference: " << abs_difference << endl;
}

double distance_2D(double x1, double y1, double x2, double y2)
{
  return sqrt(pow(fabs(x2 - x1),2) + pow(fabs(y2 - y1),2));
}
double use_local_pi_area(double radius)
{
  double pi = 3.14159;
  return pow(radius,2)*pi;
}
double use_global_pi_area(double radius)
{
  return pow(radius,2)*pi;
}

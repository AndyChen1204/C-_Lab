#include <iostream>

using namespace std;

void print_binary_format(int);

int main(int argc, const char* argv[])
{
  int number;
  cout << "Please key in a number: ";
  cin >> number;
  cout << endl;
  
  print_binary_format(number);
}

void print_binary_format(int number)
{
  unsigned int musk = 0x80000000;
  for(int i = 0; i < 8*sizeof(int); i++)
  {
    (musk & number) != 0 ? cout << 1 : cout << 0;
    musk = musk >> 1; 
  }
  cout<<endl;
}

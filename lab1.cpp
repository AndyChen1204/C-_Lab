#include <iostream>

using namespace std;

const unsigned int LEGAL_AGE = 18;
int main(int argc, char* argv[]) 
{
  unsigned int numOfPeople = 0;
  unsigned int numOfAdult = 0;
  int sum = 0;
  
  while(1)
  {  
    char temp;
    cout << "Key in Y to insert more personal information or N to exit : "; 
    cin >> temp;
    if(temp == 'N')
      break;
    else if(temp != 'Y')
      continue;
    
    int tempAge; 
    cout << " " << "Key in the age of the person : ";
    cin >> tempAge;
    
    if(tempAge < 0)
    {
      cout << " " << "You Keyed in a negative number. please key in again." << endl;
      continue;
    }
    else if(tempAge >= LEGAL_AGE)
    {
      numOfAdult++;
      numOfPeople++;
      sum += tempAge;
    }
    else
    {
      numOfPeople++;
      sum += tempAge;
    }
  }
  cout << "Exit from inserting personal information." << endl;
  cout << "The number of people is " << numOfPeople << endl;
  cout << "The mean value of their age is ";
  if(numOfPeople == 0)
    cout << 0 << endl;
  else 
    cout << static_cast<double>(sum) / static_cast<double>(numOfPeople) << endl;
  cout << "The number of adult is " << numOfAdult << endl;
  
  return 0;
}



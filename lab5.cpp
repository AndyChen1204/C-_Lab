#include<iostream>
#include<cstdlib>

using namespace std;

class stu_record
{
  public:
    stu_record(); //constructor
    int ID;
    
    void set_score();
    double phy_get();
    double cal_get();
    double oop_get();

  private:
    double phy_score, cal_score, oop_score;
};

stu_record::stu_record() : ID(-1), phy_score(0.0), cal_score(0.0), oop_score(0.0)
{
}
void stu_record::set_score()
{
    cout << "Physics:";
    cin >> phy_score; 
    cout << "Calculus:";
    cin >> cal_score; 
    cout << "Oop:";
    cin >> oop_score; 
}

double stu_record::phy_get()
{
  return phy_score;
}

double stu_record::cal_get()
{
  return cal_score;
}

double stu_record::oop_get()
{
  return oop_score;
}
int main(int argc, const char* argv[])
{
  stu_record rec[100];

  cout << "Please enter the ID:" ;
  int stu_ID;
  cin >> stu_ID;
  
  int index = 0;
  while(stu_ID != -1)  
  {
    rec[index].ID = stu_ID; 
    rec[index].set_score();
    index++;

    cout << "Please enter the ID:" ;
    cin >> stu_ID;
  } 
  
  cout << "number of student:" << index << endl;

  double sum_phy = 0;
  double sum_cal = 0;
  double sum_oop = 0;
  
  int pass_num_phy = 0;
  int pass_num_cal = 0;
  int pass_num_oop = 0;

  for(int i = 0; i < index; i++)
  {

    sum_phy += rec[i].phy_get();
    sum_cal += rec[i].cal_get();
    sum_oop += rec[i].oop_get();
    
    if(rec[i].phy_get() >= 60)pass_num_phy++;
    if(rec[i].cal_get() >= 60)pass_num_cal++;
    if(rec[i].oop_get() >= 60)pass_num_oop++;
  }
  
  cout << "average grade of Physics:" << sum_phy / index << endl;
  cout << "average grade of Calculus:" << sum_cal / index << endl;
  cout << "average grade of Oop:" << sum_oop / index << endl;
  
  cout << "pass rate of Physics:" << pass_num_phy * 100.0 / index << "%" << endl;
  cout << "pass rate of Calculus:" << pass_num_cal * 100.0 / index << "%" << endl;
  cout << "pass rate of Oop:" << pass_num_oop * 100.0 / index << "%" << endl;

  cout << "Student grade:" << endl;

  for(int i = 0; i < index; i++)
  {
    cout << "ID:" << rec[i].ID << " ";  
    cout << "Average:" << (rec[i].phy_get() + rec[i].cal_get() + rec[i].oop_get()) / 3 << " ";
    cout << "Pass/Fail:";
    if((rec[i].phy_get() + rec[i].cal_get() + rec[i].oop_get()) / 3 >= 60)
      cout << "Pass";
    else
      cout << "Fail";
    cout << endl;
  }
  
  return 0;
}


#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class Student
{
  public:
    Student(string, int);
    ~Student();
    void input(string, int);
    void output(ofstream&);
    bool is_in_class(string);
    string get_name(){return name;}
  private:
    string name;
    int num_of_class;
    string* classList;
};

Student::Student(string n, int num)
{
  name = n;
  num_of_class = num; 
  classList = new string[num_of_class];
}

Student::~Student()
{
  delete[] classList;
}

void Student::input(string class_name, int index)
{
  classList[index] = class_name;
}

void Student::output(ofstream& ofs)
{
  ofs << setw(8) << name << setw(4) << num_of_class << " ";
  for(int i = 0; i < num_of_class; i++)
  {
    ofs << classList[i] << " ";
  }
  ofs << endl;
}
bool Student::is_in_class(string class_name)
{
  for(int i = 0; i < num_of_class; i++)
  {
    if(class_name == classList[i])  
      return true;
  }
  return false;
}

void inputFile(int argc, const char* argv[]);
void outputResult(int argc, const char* argv[]);

int total_num_of_stu;
Student** stuList;
int total_num_of_class = 0;
string claList[100];

int main(int argc, const char* argv[])
{
  inputFile(argc, argv);
  outputResult(argc, argv);
}

void inputFile(int argc, const char* argv[])
{
  ifstream fin;
  fin.open(argv[1]);
  if(!fin)
    cout << "input file open fail" << endl;

  string tempString;
  fin >> tempString >> total_num_of_stu; 
  stuList = new Student*[total_num_of_stu];

  for(int i = 0; i < total_num_of_stu; i++)
  {
    string name, class_name;
    int num_of_class; 
    fin >> tempString >> name; 
    fin >> tempString >> num_of_class; 
    stuList[i] = new Student(name, num_of_class);
    
    fin >> tempString;
    for(int j = 0; j < num_of_class; j++)
    {
      string class_name;
      fin >> class_name;
      stuList[i] -> input(class_name, j);
      
      if(total_num_of_class == 0)
      {
        claList[0] = class_name;
        ++total_num_of_class;
      }
      else
      {
        int flag = 1;
        for(int index = 0; index < total_num_of_class; index++)
        {
          if(claList[index] == class_name)
            flag = 0;
        }
        if(flag == 1)
        { 
          claList[total_num_of_class] = class_name;
          ++total_num_of_class;
        }
      }
    }
  }
}

void outputResult(int argc, const char* argv[])
{
  ofstream fout;
  fout.open(argv[2]);
  if(!fout)
    cout << "output file open fail" << endl;
  for(int i = 0; i < total_num_of_class; i++)
  {
    fout << "Class: " << claList[i] << endl;
    fout << "        ";
    for(int j = 0; j < total_num_of_stu; j++)
    {
      if(stuList[j] -> is_in_class(claList[i])) 
        fout << stuList[j] -> get_name() << ", "; 
    }
    fout << endl;
  }

  fout << endl << "#studens: " << total_num_of_stu << endl;
  fout << "Name " << " # " << "Classes" << endl;
  for(int i = 0; i < total_num_of_stu; i++)
  {
    stuList[i] -> output(fout);
  }
}

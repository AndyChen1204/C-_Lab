#include<iostream>
#include<string>

using namespace std;

int main(int argc, const char* argv[])
{
  string text[] = {"(happy)", "(heart)", "(confused)", "(good)", "(angel)"};
  string graph[] = {":D", "<3", "o.O", "(y)", "O:)"};
  while(1)
  {
    int op;
    cout << " -1) exit " << " 0) text -> graph " << " 1) graph -> text : ";
    cin >> op;
    if(op == -1)
      break;

    cout << "Input: "; 
    string input; 

    getline(cin, input); //store enter 
    getline(cin, input);

    switch(op)
    {
      case  0 : 
        for(int index = 0; index < 5; index++)
        {  
          int site = 0;
          while((site = input.find(text[index], site)) != -1)
          {
            string t = input.substr(0, site); 
            input = t + graph[index] + input.substr(site + text[index].size(), input.size());
          } 
        } 
        cout << "Output: " << input << endl;
        break;
      case  1 :
        for(int index = 0; index < 5; index++)
        {  
          int site = 0;
          while((site = input.find(graph[index], site)) != -1)
          {
            string t = input.substr(0, site); 
            input = t + text[index] + input.substr(site + graph[index].size(), input.size());
          } 
        } 
        cout << "Output: " << input << endl;
        break;
      default : 
        break;
    }
  }

  cout << endl;
  return 0;
}


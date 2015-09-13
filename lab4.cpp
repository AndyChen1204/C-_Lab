#include<iostream>
#include<cassert> 

using namespace std;

const int aRowNum = 3;
const int aColumnNum = 3;
const int bRowNum = 2;
const int bColumnNum = 3;

//fill up row then column
void fillUp(int a[], int rowSize, int columnSize);
void print2DArrary(int a[], int rowSize, int columnSize);
void printAndStore2DArraryTranspose(int a[], int rowSize, int columnSize);
void matrixMultiply(int a[], int aRowSize, int aColumnSize,int b[], int bColumnSize, int c[]);

int main(int argc, const char* argv[])
{
  cout << "Input  Matrix A:" << endl;

  int A[aRowNum * aColumnNum];
  fillUp(A, aRowNum, aColumnNum);
  
  cout << "Matrix A : " << endl;
  print2DArrary(A, aRowNum, aColumnNum);
   
  while(1)
  {   
    cout << "Operation: ";
    int Operation;
    cin >> Operation;
    
    assert (Operation == 1 || Operation == 2);

    if(Operation == 1){
      
      cout << "Matrix A:" << endl;
      printAndStore2DArraryTranspose(A, aRowNum, aColumnNum);
      
    }else{
      
      int B[bRowNum * bColumnNum];
      cout << "Matrix B : " << endl;
      fillUp(B, bRowNum, bColumnNum); 
      print2DArrary(B, bRowNum, bColumnNum);
      
      cout << "MatrixA x MatrixB :" << endl;
      int C[aColumnNum * bRowNum];
      matrixMultiply(A, aColumnNum, aRowNum,B, bRowNum, C);
      print2DArrary(C, bRowNum, aColumnNum);
    }
  }
}

void fillUp(int a[], int rowSize, int columnSize)
{
  for(int i = 0; i < columnSize; i++)
  {
    for(int j = 0; j < rowSize; j++)
    {
      cin >> a[j + i * rowSize]; 
    }
  }
}
void print2DArrary(int a[], int rowSize, int columnSize)
{
  for(int i = 0; i < columnSize; i++)
  {
    for(int j = 0; j < rowSize; j++)
    {
      cout << " " << a[j + i * rowSize]; 
    }
    cout << endl;
  }
}
void printAndStore2DArraryTranspose(int a[], int rowSize, int columnSize)
{
  int temp[rowSize * columnSize];
  for(int i = 0; i < rowSize; i++)
  {
    for(int j = 0; j < columnSize; j++)
    {      
      temp[j + i * rowSize] = a[i + j * rowSize];
      cout << " " << a[i + j * rowSize]; 
    }
    cout << endl;
  }
  for(int i = 0; i < columnSize; i++)
  {
    for(int j = 0; j < rowSize; j++)
    {
      a[j + i * rowSize] = temp[j + i * rowSize]; 
    }
  }
}
void matrixMultiply(int a[], int aColumnSize, int aRowSize, int b[], int bRowSize, int c[])
{
  for(int i = 0; i < aColumnSize; i++)
  {
    for(int j = 0; j < bRowSize; j++)
    {
      for(int k = 0; k < aRowSize; k++ )
      {
        c[i * bRowSize + j ] += a[i * aRowSize + k] * b[k * bRowSize + j];  
      }
    }
  }
}

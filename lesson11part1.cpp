#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 21;

// Prototypes
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName);
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size);
bool validateVals(const int square[MAX_SIZE][MAX_SIZE], int size);
void display(const int square[MAX_SIZE][MAX_SIZE], int size);

int main() 
{
  int size;
  int box[MAX_SIZE][MAX_SIZE];

  string filename;

  cout << "Enter input file name" << endl;
  cin >> filename;

  size = readSquare(box, filename);

  if (size == 0)
  {
    cout << "File \"" << filename << "\" could not be opened" << endl;

    return 0;
  }

  else
  {
    display(box, size);

    if (validateSquare(box, size))
    {
      cout << endl << "Valid magic square" << endl;
    }

    else
    {
      cout << endl << "Invalid magic square" << endl;
    }
  }

  return 0;
} 

// Reading Func.
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName)
{
  ifstream loadFile;
  int size;

  loadFile.open(inputFileName);

  if (loadFile.fail())
  {
    return 0;
  }

  else
  {
    loadFile >> size;

    for (int i = 0; i < size; ++i)
    {
      for (int j = 0; j < size; ++j)
      {
        loadFile >> square[i][j];
      }
    }
  }

  return size;
}

// Validating Func.
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size)
{
  if (!validateVals(square,size))
  {
    return false;
  }

   // size calculation
  int correctTotal = size * (size * size + 1) / 2;

  int firstDiagonal = 0;
  int secDiagonal = 0;

  // validate first diagonal
  for (int i = 0; i < size; ++i)
  {
    firstDiagonal += square[i][i];
  }

  if (firstDiagonal != correctTotal)
    return false;

  // validate second diagonal
  for (int i = 0; i < size; ++i)
  {
    secDiagonal += square[i][size - 1 - i];
  }
  
  if (secDiagonal != correctTotal)
    return false;

  int rowVal;

  // validate rows
  for (int i = 0; i < size; ++i)
  {
    rowVal = 0;
    
    for (int j = 0; j < size; ++j)
    {
      rowVal += square[i][j];
    }

    if (rowVal != correctTotal)
      return false;
  }

  int colVal;

  // validate columns
  for (int i = 0; i < size; ++i)
  {
    colVal = 0;
    
    for (int j = 0; j < size; ++j)
    {
      colVal += square[j][i];
    }

    if (colVal != correctTotal)
      return false;
  }

  return true;
}

bool validateVals(const int square[MAX_SIZE][MAX_SIZE], int size)
{
  int area = size * size;
  int counter = 0;

  for (int k = 1; k <= area; ++k)
  {
    for (int i = 0; i < size; ++i)
    {
      for (int j = 0; j < size; ++j)
      {
        if (k == square[i][j])
          ++counter;
      }
    }

    if (counter != 1)
      return false;

    counter = 0;
  }

  return true;
}

// Display Func.
void display(const int square[MAX_SIZE][MAX_SIZE], int size)
{
  cout << "Magic square" << endl;

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cout << square[i][j] << " ";
    }

    cout << endl;
  }
}
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// -- Global variables --
const int MAX_COLUMNS = 5;
const int MAX_ROWS = 30;

// -- Protypes --
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName);
double average(double values[][MAX_COLUMNS], int numberRows);
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows);
double smallestVal(double values[][MAX_COLUMNS], int row);

int main() 
{
  double values[MAX_ROWS][MAX_COLUMNS];

  string filename;

  cout << "Enter input file name" << endl;
  cin >> filename;

  int actualRows = readFile(values, MAX_ROWS, filename);

  if (actualRows == -1)
  {
    cout << "File \"" << filename << "\" could not be opened" << endl;

    return 0;
  }

  else if (actualRows == 0)
  {
    cout << "The input file \"" << filename << "\" did not contain any data" << endl;

    return 0;
  }

  else
  {
    // output stuff
    cout << "Processing " << actualRows << " rows, and " << MAX_COLUMNS << " columns" << endl;
    cout << "Average for all values is " << fixed << setprecision(2) << average(values, actualRows) << endl;

    for (int i = 0; i < MAX_COLUMNS; ++i)
    {
      cout << "Average for column " << i << " is " << fixed << setprecision(2) << columnAverage(values, i, actualRows) << endl;
    }

    for (int i = 0; i < actualRows; ++i)
    {
      cout << "Smallest value for row " << i << " is " << fixed << setprecision(2) << smallestVal(values, i) << endl;
    }
  }


  return 0;
}

// -- Reading file --
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName)
{
  ifstream loadFile;
  int rowCounter = 0;
  double tempStore;

  loadFile.open(inputFileName);

  if (loadFile.fail())
  {
    return -1;
  }

  else
  {
    for (int i = 0; i < MAX_ROWS; ++i)
    {
      for (int j = 0; j < MAX_COLUMNS; ++j)
      {
        if (loadFile >> tempStore)
        {
          values[i][j] = tempStore;
          
          if (j == 4)
          {
            ++rowCounter;
          }
        } 
      }
    }

    loadFile.close();
    return rowCounter;
  }
}

// -- Calculations --
double average(double values[][MAX_COLUMNS], int numberRows)
{
  double sumVal = 0;
  double valCounter = 0;
  double average;

  for (int i = 0; i < numberRows; ++i)
  {
    for (int j = 0; j < MAX_COLUMNS; ++j)
    {
      sumVal += values[i][j];
      ++valCounter;
    }
  }

  average = sumVal / valCounter;

  return average;
}

double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
  double sumVal = 0;
  double valCounter = 0;
  double average;

  for (int j = 0; j < numberRows; ++j)
  {
    sumVal += values[j][column];
    ++valCounter;
  }

  average = sumVal / valCounter;

  return average;
}

double smallestVal(double values[][MAX_COLUMNS], int row)
{
  double smallestVal;

  smallestVal = values[row][0];
  for (int i = 1; i < MAX_COLUMNS; ++i)
  {
    if (values[row][i] < smallestVal)
    {
      smallestVal = values[row][i];
    }
  }

  return smallestVal;
}
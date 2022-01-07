#include <iostream>

using namespace std;

// prototypes
bool LoadFile(string filename, int data[][9]);
bool TestRow(const int data[][9] , int row);
bool TestColumn(const int data[][9], int col);
bool TestBox(const int data[][9], int box);
void Display(const int data[][9]);

int main()
{
  int data[9][9] = 
  {
    {5, 2, 4, 7, 1, 8, 9, 3, 6},
    {8, 4, 6, 3, 5, 9, 4, 1, 7},
    {9, 1, 7, 2, 6, 3, 8, 4, 5},
    {7, 5, 3, 1, 9, 6, 4, 2, 8},
    {4, 9, 1, 8, 2, 5, 7, 6, 3},
    {6, 8, 2, 5, 7, 4, 3, 9, 1},
    {2, 7, 5, 9, 3, 1, 6, 8, 4},
    {1, 3, 9, 6, 8, 7, 2, 5, 2},
    {3, 6, 8, 5, 4, 2, 1, 7, 9}

  };


  for (int i = 0; i < 9; ++i) // loop check row
  {
    if (!TestRow(data, i))
    {
      cout << "fails at row " << i + 1 << endl;
    }

  }

  for (int i = 0; i < 9; ++i) // loop check column
  {
    if (!TestColumn(data,i))
    {
      cout << "fails at column " << i + 1 << endl;
    }

  }

  for (int i = 1; i <= 9; ++i) // box check column
  {
    if (!TestBox(data,i))
    {
      cout << "fails at box " << i << endl;
    }

  }

  return 0;
}

// -- TEST FUNCTIONS --
bool TestRow(const int data[][9] , int row)
{
  int multiVal = 0;

  for (int j = 1; j <= 9; ++j) // value loop
  { 
    for (int i = 0; i < 9; ++i) // column
    {
      if (data[row][i] == j) // go through entire row for wrong vals
      {
        ++multiVal;
      }
    }

    if (multiVal != 1) // after checking row check for failure before moving to the next
    {
      return false;
    }

    multiVal = 0;
  } 

  return true;
}

bool TestColumn(const int data[][9], int col)
{
  int multiVal = 0;

  for (int j = 1; j <= 9; ++j) // value loop
  { 
    for (int i = 0; i < 9; ++i) // row
    {
      if (data[i][col] == j) // go through entire col for wrong vals
      {
        ++multiVal;
      }
    }

    if (multiVal != 1) // after checking col check for failure before moving to the next
    {
      return false;
    }

    multiVal = 0;
  } 

  return true;
}

bool TestBox(const int data[][9], int box)
{
  int multiVal = 0;
  int startCol;
  int endCol;
  int startRow;
  int endRow;
  
  startCol = ((((box - 1) % 3) + 1) * 3) - 3; // determine col vals for loop
  endCol = ((((box - 1) % 3) + 1) * 3);

  if (box >= 1 && box <=3) // determine the row vals for loop
  {
    startRow = 0;
    endRow = 3;
  }

  else if (box >= 4 && box <=6)
  {
    startRow = 3;
    endRow = 6;
  }

  else if (box >= 7 && box <=9)
  {
    startRow = 6;
    endRow = 9;    
  }

  for (int j = 1; j <= 9; ++j) // loop through boxes with start end vals
  {
    for (int i = startRow; i < endRow; ++i)
    {
      for (int k = startCol; k < endCol; ++k)
      {
        if (data[i][k] == j) // same as row col funcs.
        {
          ++multiVal;
        }
      }
    }

    if (multiVal != 1)
    {
      return false;
    }

    multiVal = 0;
  }

  return true;
}
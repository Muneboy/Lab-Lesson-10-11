#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// -- Prototypes --
int LoadArrayVals(string filename, char data[30]);

void Display(char answer[30], char student[30], int arraySize);

int main() 
{
  char answerData[30];
  char studentData[30];

  string answerFile;
  string studentFile;

  int answerSize;
  int studentSize;

  cout << "Enter student answers file name" << endl;
  cin >> studentFile;

  studentSize = LoadArrayVals(studentFile, studentData);

  if (studentSize == -1)
  {
    cout << "File \"" << studentFile << "\" could not be opened" << endl;

    return 0;
  }

  cout << "Enter correct answer file name" << endl;
  cin >> answerFile;

  answerSize = LoadArrayVals(answerFile, answerData);

  if (answerSize == -1)
  {
    cout << "File \"" << answerFile << "\" could not be opened" << endl;

    return 0;
  }

  if (studentSize != answerSize)
  {
    cout << "The student answers file has " << studentSize << " entries and the correct answers file has " << answerSize << " entries" << endl;
    cout << "Grading cannot be done if they are not the same" << endl;
  }

  else if (studentSize == 0 && answerSize == 0)
  {
    cout << "The number of student answers and correct answers are both 0" << endl;
    cout << "No grade can be calculated" << endl;
  }

  else
  {
    Display(answerData, studentData, answerSize);
  }

  return 0;
} 

// -- Loading Files --
int LoadArrayVals(string filename, char data[30])
{
  ifstream loadFile;
  char testVal;
  int sizeCount = 0;

  loadFile.open(filename);

  if (loadFile.fail())
  {
    return -1;
  }

  else
  {
    for (int i = 0; i < 30; ++i)
    {
      if (loadFile >> testVal)
      {
        data[i] = testVal;
        ++sizeCount;
      }

      else
      {
        data[i] = ' ';
      }
    }

    loadFile.close();
    return sizeCount;
  }
}

// -- Display --
void Display(char answer[30], char student[30], int arraySize)
{
  int correctCount = 0;
  int wrongCount = 0;

  double grade;

  for (int i = 0; i < arraySize; ++i)
  {
    if (answer[i] == student[i])
    {
      ++correctCount;
    }

    else
    {
      ++wrongCount;

      cout << "Question " << i + 1 << " has incorrect answer '" << student[i] << "', the correct answer is '" << answer[i] << "'" << endl;
    }
  }

  cout << wrongCount << " questions were missed out of " << arraySize << endl;

  grade = (static_cast<double>(correctCount) / static_cast<double>(arraySize)) * 100.0;

  cout << "The student grade is " << fixed << setprecision(1) << grade << "%" << endl;

  if (grade > 69)
  {
    cout << "The student passed" << endl;
  }

  else
  {
    cout << "The student failed" << endl;
  }
}
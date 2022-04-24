#include<iostream>
#include<fstream>
using namespace std;

class Students //Class to sort names alphabetically
{
public:
  void alphaNames (string *);
  void pNames (string *);
};

void
Students::alphaNames (string * names) //Sorts alphabetical order
{
  string temp;
  for (int i = 0; i < 29; i++)
    {
      for (int j = 0; j < 30 - i - 1; j++)
	{
	  if (names[j].compare (names[j + 1]) > 0)
	    {
	      temp = names[j];
	      names[j] = names[j + 1];
	      names[j + 1] = temp;
	    }
	}
    }
}



void
Students::pNames (string * names) //Printing names
{
  for (int i = 0; i < 30; i++)
    {
      cout << names[i] << endl;
    }
}
int
main () //Main program
{
  Students student; //Reads names to sort from file
  ifstream in ("Names.txt");
  string str, names[30];
  int i = 0;
  while (getline (in, str))
    {
      names[i] = str;
      i++;
    }
  student.alphaNames (names); //Sorts Names Alphabetically
  student.pNames (names); //Displays sorted names
}

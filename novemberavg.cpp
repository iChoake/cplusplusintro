#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class nTemps
{

//private variables

private:

  int count[3];
  float novTemp[30], avg;
  
public:
    nTemps ()
  {
    avg = 0; //int array
    for (int i = 0; i < 3; i++)
      count[i] = 0;
    for (int i = 0; i < 30; i++)
      novTemp[i] = 0;
  }

  void ReadData () //Reads txt file
  {
    ifstream File;
    File.open ("NovTemps.txt");
    if (File.fail ())
      {
	cerr << "File does not exist.\n";
	return;
      }
    int i = 0;
    while (!File.eof ())
      {
	float n;
	File >> n;
	novTemp[i] = n;
	i++;
      }
    File.close ();
  }


  void Calculate ()  //Same/Above/Below avg
  {
    float sum = 0;
    for (int i = 0; i < 30; i++)
      sum += novTemp[i];
    avg = sum / 30;
    for (int i = 0; i < 30; i++)
      {

	if (novTemp[i] < avg)
	  count[0]++;
	else if (novTemp[i] == avg)
	  count[1]++;
	else
	  count[2]++;
      }
  }

  void ShowData () //Display the result
  {
    cout << "Daily Average is: " << avg;
    cout << "\nDays below average: " << count[0];
    cout << "\nDays above average: " << count[1];
    cout << "\nDays equal to the average: " << count[2];

  }

};

//main function

int
main ()
{

  nTemps t;

  t.ReadData ();

  t.Calculate ();

  t.ShowData ();

  return 0;

}

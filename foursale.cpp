#include <iostream>
#include <iomanip>
using namespace std;

//four divisions
string divisions[4] = { "NE", "SE", "NW", "SW" };

//sales amount of four divisions
double sales_amount[4] = { };

// Function to get sales from user with validation
double
getSales (string division)
{
  double amount;

  cout << "Enter the quartely sales for the " << division << " division : ";
  cin >> amount;

  //if negative number  again call the same function to get new value
  if (amount < 0)
    {
      cout << "Sales figures cannot be negative. Please re-enter." << endl;
      getSales (division);
    }
  else
    {
      return amount;
    }
}

//function to find highest amount
void
findHighest (double NE_amt, double SE_amt, double NW_amt, double SW_amt)
{
  //default NE_amt as max with index 0
  int index = 0;
  double max = NE_amt;

  //if SE_amt is greater than max it will set to max be 1
  if (SE_amt > max)
    {
      max = SE_amt;
      index = 1;
    }

  //if NW_amt is greater than max it will set to max be 1
  if (NW_amt > max)
    {
      max = NW_amt;
      index = 2;
    }

  //if SW_amt is greater than max it will set to max be 1
  if (SW_amt > max)
    {
      max = SW_amt;
      index = 3;
    }

  //it will print division name and it's sales value
  cout << endl << "The " << divisions[index] <<
    " division had the highest sales this quarter." << endl;
  cout << "Their sales were $" << setprecision (2) << fixed << max;
}

int
main ()
{
  // to call getSales method for all four divisions
  for (int i = 0; i < 4; i++)
    {
      sales_amount[i] = getSales (divisions[i]);
    }

  //finding highest from all four sales value
  findHighest (sales_amount[0], sales_amount[1], sales_amount[2],
	       sales_amount[3]);

  return 0;
}

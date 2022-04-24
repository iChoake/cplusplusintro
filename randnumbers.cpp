#include<iostream>
using namespace std;
//game class
class game
{
private:			//background data
  int balance;			//sets the Starting $ input 
  int rNum;			//Randomly Number generator RoLL
  string rollYoN;		//Roll again, or Exit

  void validateBalance ()	//validates the input balance value from the user
  {
    if (balance < 1)
      {
	cout << "\n Invalid amount entered, try again: ";
	setbalance ();
      }
  }
  void validaterollYoN ()	//validates the answer if the user wants to roll again (y or n entered)
  {
    int b = 0;
    if (rollYoN == "y" || rollYoN == "Y")
      {
	b = 1;
      }
    else if (rollYoN == "n" || rollYoN == "N")
      {
	b = 1;
      }
    if (b != 1)
      {
	cout << "\n Invalid input, try again: (y/n)";
	setrollYoN ();
      }
  }
public:
  game ()
  {
    srand (time (0));
    balance = 0;		// Starts random generator
  }
  void roll ()			//call the random generator to return a value between 1 and 6
  {
    rNum = rand () % 6 + 1;
  }
  void display ()		//display the results of the roll (odd or even) and the user's balance
  {
    if (rNum % 2 == 0)
      {
	cout << "even rolled, You won $1" << endl;
	balance += 1;
      }
    else
      {
	cout << "odd rolled, You lost $1" << endl;
	balance -= 1;
      }

    cout << "Your balance is: $" << balance << endl;
  }
  void again ()			// determine if the user wants to roll again or quit the game
  {
    cout << "Roll again? (y/n): ";	//validates the answer if the user wants to roll again (y or n entered)
    cin >> rollYoN;
    validaterollYoN ();
  }
  int getbalance ()
  {
    return balance;
  }

  void setbalance ()		//reads in the starting balance entered from the user
  {
    cin >> balance;
    validateBalance ();
  }

  string getrollYoN ()
  {
    return rollYoN;
  }

  void setrollYoN ()
  {
    cin >> rollYoN;
    validaterollYoN ();
  }
};

//******************The Game*******************
int
main ()
{
  game g;			//GameOn
  cout << "Rock Your World!\n\n";
  cout << "Enter your starting balance: (minimum $1)";	//User Prompts
  g.setbalance ();		//reads in the starting balance entered from the user
  cout << "starting balance: $" << g.getbalance () << "\n";
  cout << "Rolling..." << "\n";
  g.roll ();
  g.display ();
  g.again ();
  while (g.getrollYoN () == "y" || g.getrollYoN () == "Y")
    {
      cout << "Rolling..." << endl;
      g.roll ();
      g.display ();
      g.again ();

      if (g.getbalance () < 1)	//Exit Prompts
	{
	  cout << "Game over. Ending balance = $0" << endl;
	  cout << "Thanks for playing!" << endl;
	  break;
	}
    }

  return 0;
}

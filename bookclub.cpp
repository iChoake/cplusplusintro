#include <iostream>

using namespace std;

int
main ()
{

  int numbooks;
  cout << "How many books have you purchased this month?" << endl;
  try
  {
    cin >> numbooks;
    if (cin.fail ())
      throw 99;
    //error
    if (numbooks < 0)
      throw 100;

    //valid 

/*     Purchased 0 books, earn 0 points.
       Purchased 1 book, earn 5 points.
       Purchased 2 books, earn 15 points.
       Purchased 3 books, earn 30 points.
       Purchased 4 or More books, earn 50 points.
*/
    int points = 0;		// 0 books

    if (numbooks == 1)
      points = 5;
    else if (numbooks == 2)
      points = 15;
    else if (numbooks == 3)
      points = 30;
    else if (numbooks >= 4)
      points = 50;

    cout << "Points earned: " << points << endl;
  }
  catch (int e)
  {
    cout << "ErroR! Goodbye!" << endl;
  }

}

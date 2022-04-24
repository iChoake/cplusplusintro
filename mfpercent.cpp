#include<iostream>
#include <iomanip>
using namespace std;

int
main ()
{
  int m, f, total;
  float mpercent, fpercent;
  cout << "Enter number of males in class:";
  cin >> m;
  cout << "Enter number of females in class:";
  cin >> f;
  total = m + f;
  mpercent = (float) m *100 / total;
  fpercent = (float) f *100 / total;
  cout << endl;
  cout << fixed << showpoint << setprecision (2);
  cout << "Males:" << mpercent << "%" << endl;
  cout << "Females:" << fpercent << "%" << endl;
  return 0;
}

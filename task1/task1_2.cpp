#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double x;
  double eps = 1000000;
  double an, sum;
  double n;
  
  cout << "Enter X: " << endl;
  while (!(cin >> x) || (cin.peek() != '\n'))
  {
    cin.clear();
    while (cin.get() != '\n');
    cout << "Input error! Repeat please..."<<endl;
  } 
  an = 1;
  sum = 0;
  n = 0;

  while (fabs(an)<eps)
  {
	n = n + 1.0;
	an = pow(x, n) / pow(n, 2);
	sum = sum + an;
    cout << an << endl;
  }
  cout << sum << " ";
}
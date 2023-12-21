#include <iostream>
#include <cmath>

int main()
{
  double x;
  double eps = 1000000;
  double an = 1;
  double sum = 0;
  double n = 0;
  
  std::cout << "Enter X: " << std::endl;
  while (!(std::cin >> x) || (std::cin.peek() != '\n'))
  {
    std::cin.clear();
    while (std::cin.get() != '\n');
    std::cout << "Input error! Repeat please..." << std::endl;
  } 
  
  while (std::fabs(an) < eps)
  {
    n += 1.0;
    an = std::pow(x, n) / std::pow(n, 2);
    sum += an;
    std::cout << an << std::endl;
  }
  
  std::cout << std::fixed << sum << " ";
  
  return 0;
}
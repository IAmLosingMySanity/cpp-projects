#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    int n;
    double an;

    double eps = 0.001;

    cout << "Enter X: ";
    cin >> x;

    // cout << "Enter N: ";
    // cin >> n;

    double sum = 0.0;

    int i =1;

    while ((fabs(an)>eps) || sum==0)    
    {
        an = pow(x, i) / pow(i, 2);
        sum += an;
        i++;
    }
    

    // for (int i = 1; i <= n; ++i) {
    //     sum += pow(x, i) / pow(i, 2);
    // }

    cout << "Sum is " << sum << endl;

    return 0;
}
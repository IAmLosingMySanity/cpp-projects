#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    int n;

    cout << "Enter X: ";
    cin >> x;

    cout << "Enter N: ";
    cin >> n;

    double sum = 0.0;

    for (int i = 1; i <= n; ++i) {
        sum += pow(x, i) / pow(i, 2);
    }

    cout << "Sum is " << sum << endl;

    return 0;
}
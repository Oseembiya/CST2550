#include <iostream>
using namespace std;

int main()
{
    int y;
    int x;
    int sum, product;
    cout << "Please enter two numbers:";
    cin >> x;
    cin >> y;
    sum = x + y;
    product = (x * y);
    cout << "\n The sum of " << x << "and" << y
         << "is:" << sum << endl;

    cout << "\n The product of " << x << "and" << y
         << "is:" << product << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;
int main()
{

    int num1, num2;
    // prompt the user to enter 2 integer
    cout << "\n enter the first number:";

    cin >> num1;
    cout << "\n enter the second number:";

    cin >> num2;

    int sum = 0;
    for (int i = num1; i <= num2; ++i)
    {
        sum += i;
    }
    // Output the result
    cout << "\n The sum of numbers from " << num1 << " to " << num2 << " is: " << sum << endl;
    return 0;
}

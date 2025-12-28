/* Algorithm Challenge & Problem Solving
 * 47 - Custom Round Function (Without Built-in round)
 *
 * This program implements a custom rounding algorithm without using the built-in round() function in C++.
 *
 * Rounding Rules:
 * - If the fractional part is greater than or equal to 0.5, the number is rounded up.
 * - If the fractional part is less than 0.5, the number is rounded down.
 *
 * The algorithm also correctly handles negative numbers by using the absolute value of the fractional part.
 */

#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart(float Number)
{
    // Extract the fractional part of the number
    // Example: 10.7 - 10 = 0.7
    return Number - int(Number);
}

int MyRound(float Number)
{
    // Extract the integer part of the number
    int IntPart = int(Number);

    // Extract the fractional part
    float FractionPart = GetFractionPart(Number);

    // Check if the absolute fractional part is >= 0.5
    // abs() is used to correctly handle negative values
    if (abs(FractionPart) >= 0.5)
    {
        // If the number is positive, round up
        if (Number > 0)
            return ++IntPart;

        // If the number is negative, round down
        else
            return --IntPart;
    }
    else
    {
        // If fractional part is less than 0.5,
        // return only the integer part
        return IntPart;
    }
}

float ReadNumber()
{
    float Number;

    // Read a floating-point number from the user
    cout << "Enter Number\n";
    cin >> Number;

    return Number;
}

int main()
{
    float Number = ReadNumber();

    // Display custom round result
    cout << "My Round Result : " << MyRound(Number) << endl;

    // Display C++ built-in round result for comparison
    cout << "C++ Round Result : " << round(Number) << endl;

    return 0;
}

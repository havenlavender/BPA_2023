#include <iostream>
#include <math.h>
#include <string>

using namespace std;

// prompts user for input and converts it into a number
// uses recursion to prevent conversion errors
int64_t getInput(string prompt = "")
{
    string input{};
    int64_t output;

    cout << prompt;
    cin >> input;
    
    try { output = stoll(input); }
    catch (exception e)
    {
        cout << "invalid input" << endl;
        output = getInput(prompt);
    }

    return output;
}

// returns a boolean if a number is between 13 and 16 digits
bool checkLength(int64_t n)
{
    int length = (int)log10(n) + 1;
    return (length <= 16 && length >= 13);
}

// checks to see if a given numbers starts with a given value
bool checkPrefix(int64_t n, int value)
{
    // convert n to a string and check if the substring from 0 - n is equal to the prefix
    return stoi(to_string(n).substr(0, to_string(value).size())) == value;
}

// checks if a given number passes the luhn algnorithm
bool checkLuhn(int64_t n)
{
    int even = 0;
    int odd = 0;

    // turn n into a string and loop through it in reverse
    string s = to_string(n);
    for (int i = s.size() - 1; i > -1; i--)
    {
        // check if i is odd or even and add according to luhn algorithm
        if (i % 2 == 1)
        {
            even += stoi(to_string(s[i])) * 2;
        }
        else
        {
            odd += stoi(to_string(s[i]));
        }
    }

    // return true if the sum of even and odd is divisible by 10
    return (even + odd) % 10 == 0;
}

int main()
{
    string input{};
    int64_t cardNum;
    while (true)
    {
        cardNum = getInput("enter number (-1 to exit) : ");

        // check if user wants to close the application or check a credit card
        if (cardNum == -1) break;
        else
        {
            // this checks for :
            // card length between 13 - 16 digits
            // card starts with numbers 4, 5, 6, or 37
            // card passes the luhn algorithm
            if (checkLength(cardNum) && (checkPrefix(cardNum, 4) || checkPrefix(cardNum, 5) || checkPrefix(cardNum, 37) || checkPrefix(cardNum, 6)) && checkLuhn(cardNum))
            {
                cout << "valid card" << endl;
            }
            else
            {
                cout << "invalid card" << endl;
            }
        }
    }

    system("pause");
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include "matrix.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    matrix m;
    char mChoice, nChoice;
    bool input = false, input1 = false, input2 = false;
    char addmulti;
    m.displayMatrices();
    while (input == false)
    {
        cout << "Enter the first Matrix: ";
        cin >> mChoice;
        mChoice = toupper(mChoice);
        cout << "Enter the second Matrix: ";
        cin >> nChoice;
        nChoice = toupper(nChoice);
        cout << "Would You like to add(+) or Multiply(*): ";
        cin >> addmulti;
        for (char i = 'A'; i <= 'D'; i++)
        {
            if (mChoice == i)
            {
                input1 = true;
            }
            if (nChoice == i)
            {
                input2 = true;
            }
        }
        if (input2 == true && input1 == true && (addmulti == '+' || addmulti == '*'))
        {
            input = true;
            break;
        }
        else
        {
            cout << "Wrong Input.." << endl;
            input1 = false;
            input2 = false;
        }
    }
    m.getMatrix(mChoice, nChoice);
    if (addmulti == '+')
    {
        m.addition();
    }
    else
    {
        m.multiplication();
    }

    cout << m;

    return 0;
}
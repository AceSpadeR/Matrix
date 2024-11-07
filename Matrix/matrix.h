#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class matrix
{
private:
    vector<vector<int>> m2x2 = {
        {1, 2},
        {3, 4}};
    vector<vector<int>> m2x3 = {
        {1, 2, 3},
        {4, -5, -6}};
    vector<vector<int>> m3x2 = {
        {1, 2},
        {3, 4},
        {5, 6}};
    vector<vector<int>> m3x3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<vector<int>> M;
    vector<vector<int>> N;
    vector<vector<int>> Answer;
    bool add = false, multi = false;
    bool faladd = false, falmulti = false;

public:
    void displayMatrices();
    void getMatrix(char, char);
    void addition();
    void multiplication();
    friend ostream &operator<<(ostream &, const matrix &);
};

void matrix::displayMatrices()
{
    cout << "A =" << endl;
    for (int r = 0; r < m2x2.size(); r++)
    {
        cout << "|";
        for (int c = 0; c < m2x2[0].size(); c++)
        {
            cout << setw(3) << m2x2[r][c] << " ";
        }
        cout << "|" << endl;
    }
    cout << "B =" << endl;
    for (int r = 0; r < m2x3.size(); r++)
    {
        cout << "|";
        for (int c = 0; c < m2x3[0].size(); c++)
        {
            cout << setw(3) << m2x3[r][c] << " ";
        }
        cout << "|" << endl;
    }
    cout << "C =" << endl;
    for (int r = 0; r < m3x2.size(); r++)
    {
        cout << "|";
        for (int c = 0; c < m3x2[0].size(); c++)
        {
            cout << setw(3) << m3x2[r][c] << " ";
        }
        cout << "|" << endl;
    }
    cout << "D =" << endl;
    for (int r = 0; r < m3x3.size(); r++)
    {
        cout << "|";
        for (int c = 0; c < m3x3[0].size(); c++)
        {
            cout << setw(3) << m3x3[r][c] << " ";
        }
        cout << "|" << endl;
    }
}

void matrix::getMatrix(char mChoice, char nChoice)
{
    switch (mChoice)
    {
    case 'A':
        M = m2x2;
        break;
    case 'B':
        M = m2x3;
        break;
    case 'C':
        M = m3x2;
        break;
    case 'D':
        M = m3x3;
        break;
    }
    switch (nChoice)
    {
    case 'A':
        N = m2x2;
        break;
    case 'B':
        N = m2x3;
        break;
    case 'C':
        N = m3x2;
        break;
    case 'D':
        N = m3x3;
        break;
    }
}

void matrix::addition()
{
    int num = 0;

    if (M.size() == N.size() && M[0].size() == N[0].size())
    {

        for (int r = 0; r < M.size(); r++)
        {
            vector<int> temp;
            Answer.push_back(temp);
            for (int c = 0; c < M[0].size(); c++)
            {
                num = M[r][c] + N[r][c];
                Answer[r].push_back(num);
            }
        }
        add = true;
    }
    else
    {
        faladd = true;
    }
}

void matrix::multiplication()
{
    int sum = 0;
    if (M[0].size() == N.size())
    {
        for (int rc = 0; rc < M.size(); rc++)
        {
            vector<int> temp;
            Answer.push_back(temp);
            for (int mc = 0; mc < N[0].size(); mc++)
            {
                sum = 0;
                for (int nc = 0; nc < N.size(); nc++)
                {
                    sum += (M[rc][nc] * N[nc][mc]);
                }
                Answer[rc].push_back(sum);
            }
        }
        multi = true;
    }
    else
    {
        falmulti = true;
    }
}

ostream &operator<<(ostream &out, const matrix &m)
{
    for (int r = 0; r < m.M.size(); r++)
    {
        out << "|";
        for (int c = 0; c < m.M[0].size(); c++)
        {
            out << setw(4) << m.M[r][c] << " ";
        }
        out << "|" << endl;
    }
    if (m.faladd == true || m.add == true)
    {
        cout << "    +     \n";
    }
    if (m.falmulti == true || m.multi == true)
    {
        cout << "     *     \n";
    }

    for (int r = 0; r < m.N.size(); r++)
    {
        out << "|";
        for (int c = 0; c < m.N[0].size(); c++)
        {
            out << setw(4) << m.N[r][c] << " ";
        }
        out << "|" << endl;
    }
    cout << "      =      \n";
    if (m.add == true || m.multi == true)
    {
        for (int r = 0; r < m.Answer.size(); r++)
        {
            out << "|";
            for (int c = 0; c < m.Answer[0].size(); c++)
            {
                out <<  setw(5) << m.Answer[r][c] << " ";
            }
            out << "|" << endl;
        }
    }
    else
    {
        out << "No Solution...  Incorrect Dimensions";
    }
  return out;
}
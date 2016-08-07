//
//  main.cpp
//  cplusplusTEST
//
//  Created by 77 on 16/7/26.
//  Copyright © 2016年 代昭琦. All rights reserved.
//

#include <iostream>

using namespace std;
string sub(string A, string B);
string add(string A, string B);
int main(int argc, const char * argv[]) {
    string oprandA,oprandB;
    cin >> oprandA >> oprandB;
    
    bool nagativeA = false,nagativeB = false;
    if(oprandA[0] == '-')
    {
        nagativeA = true;
        oprandA.erase( oprandA.begin() );
    }
    if(oprandB[0] == '-')
    {
        nagativeB = true;
        oprandB.erase( oprandB.begin() );
    }
    if(oprandA.length() > oprandB.length())
        oprandB.insert(0, oprandA.length() - oprandB.length(), '0');
    else
        oprandA.insert(0, oprandB.length() - oprandA.length(), '0');
    string Result;
    if(nagativeA ^ nagativeB) //sub
    {
        if(oprandA > oprandB)
        {
            Result = sub(oprandA,oprandB);
            if(nagativeA)
            {
                cout << "-";
            }
        }
        else if(oprandA < oprandB)
        {
            Result = sub(oprandB, oprandA);
            if(nagativeB)
            {
                cout << "-";
            }
        }
        else
        {
            cout << "0";
            return 0;
        }
    }
    else //add
    {
        Result = add(oprandA,oprandB);
        if(Result == "0")
        {
            cout << "0";
            return 0;
        }
        if(nagativeA) cout << "-";
    }
    while(Result[0] == '0')
    {
        if(Result.length() == 1 && Result[0] == '0')
        {
            cout << "0";
            return 0;
        }
        Result.erase(Result.begin());
    }
    unsigned long i = Result.length();
    if(i < 4)
    {
        cout << Result;
        return 0;
    }
    else
    {
        if(i%3 == 0)
        {
            cout << Result.substr(0 , 3);
            Result.erase(0, 3);
            i -= 3;
        }
        else
        {
            cout << Result.substr(0 , i%3);
            Result.erase(0, i%3);
            i -= (i%3);
        }
        for(;i != 0; i -= 3)
        {
            cout << "," << Result.substr(0 , 3);
            Result.erase(0, 3);
        }
    }
    return 0;
}


string sub(string A, string B)
{
    string Result = "";
    int borrow = 0;
    for(int i = static_cast<int>(A.length()) - 1; i >= 0; i--)
    {
        if(A[i] - borrow >= B[i])
        {
            Result.insert(0, 1, '0' + A[i] - borrow - B[i]);
            borrow = 0;
        }
        else
        {
            Result.insert(0, 1, '0' + 10 + A[i] - borrow - B[i]);
            borrow = 1;
        }
    }
    return Result;
}

string add(string A, string B)
{
    string Result = "";
    int carry = 0;
    for(int i = static_cast<int>(A.length()) - 1; i >= 0; i--)
    {
        if(A[i] - '0' + carry + B[i] - '0' < 10)
        {
            Result.insert(0, 1, A[i] - '0' + carry + B[i]);
            carry = 0;
        }
        else
        {
            Result.insert(0, 1, A[i] - '0' + carry + B[i] - 10);
            carry = 1;
        }
    }
    if(carry == 1)
        Result.insert(0, 1, '1');
    return Result;
}

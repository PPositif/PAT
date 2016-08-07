//
//  main.cpp
//  cplusplusTEST
//
//  Created by 77 on 16/7/26.
//  Copyright © 2016年 代昭琦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main(int argc, const char * argv[])
{
    vector<pair<int,double>> A;
    int K;
    int exponent;
    double coefficient;
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        cin >> exponent;
        cin >> coefficient;
        pair<int,double> item;
        item.first = exponent;
        item.second = coefficient;
        A.push_back(item);
    }
    cin >> K;
    vector<pair<int,double>> Result;
    vector<pair<int,double>>::iterator it = A.begin();
    for(int i = 0 ; i < K;i++)
    {
        cin >> exponent;
        cin >> coefficient;
        while(it != A.end() && it->first > exponent)
        {
            Result.push_back(*it);
            it++;
        }
        pair<int,double> item;
        item.first = exponent;
        if(it != A.end() && it->first == exponent)
        {
            if(coefficient + it->second > -0.05 && coefficient + it->second < 0.05)
            {
                it++;
                continue;
            }
            item.second = coefficient + it->second;
            it++;
        }
        else
        {
            item.second = coefficient;
        }
        Result.push_back(item);
    }
    while(it != A.end())
    {
        Result.push_back(*it);
        it++;
    }
    cout << Result.size();
    cout.setf(ios::fixed);
    for(it = Result.begin(); it != Result.end(); it++)
    {
        cout << " " << it->first << " " << setprecision(1) << it->second;
    }
    return 0;
}
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Hash
{
private:
    const int MIN_PASS_SIZE = 16;
    const int MIN_SYMBOL = 32;
    const int MAX_SYMBOL = 127;
    char GetRandSymbol();
    long long GetRawHash(string str);
    void GetSaltString(string& userString);
public:
    long long getHash(string userString);
};

#include"Hash.h"
long long Hash::GetRawHash(string str) {
    const long long mult = 978485227;
    long long hash = 0;
    for (auto& symbol : str) {
        hash = hash * mult + symbol;
    }
    return hash;
}

char Hash::GetRandSymbol() {
    return rand() % (MAX_SYMBOL - MIN_SYMBOL + 1) + MIN_SYMBOL;
}


void Hash::GetSaltString(string& userString) {
    srand(GetRawHash(userString));
    int size = (userString.size() > MIN_PASS_SIZE ? userString.size() : MIN_PASS_SIZE);
    for (int i = userString.size(); i < size; ++i) {
        userString += GetRandSymbol();
    }
}

long long Hash::getHash(string userString) {
    GetSaltString(userString);
    return GetRawHash(userString);
}

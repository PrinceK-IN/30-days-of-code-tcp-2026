#include<iostream>

using namespace std;

class Solution {
public:
    long long mod = 1000000007;

    long long solve(long long base, long long exp) {
        if (exp == 0) return 1;

        long long smallAns = solve(base, exp / 2);
        
        long long longAns = (smallAns * smallAns) % mod;

        if (exp % 2 == 1) {
            return (longAns * base) % mod;
        }
        
        return longAns;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenChoices = solve(5, evenPositions);
        long long oddChoices = solve(4, oddPositions);

        return (evenChoices * oddChoices) % mod;
    }
};
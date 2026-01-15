#include<iostream>
#include<cmath>
#include<numeric>

using namespace std;

class Solution {
    long long get_lcm(long long a, long long b) { 
        return (a * b) / gcd(a, b); 
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1, high = INT_MAX, ans = 0;

        long long ab = get_lcm(a, b);
        long long bc = get_lcm(b, c);
        long long ac = get_lcm(a, c);
        long long abc = get_lcm(a, bc);

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            long long count = (mid/a + mid/b + mid/c) - (mid/ab + mid/bc + mid/ac) + (mid/abc);

            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {

        int totalSum = 0;

        for (int x : nums) {
            int maxDigit = 0;
            int temp = x;
            int count = 0;

            while (temp > 0) {
                maxDigit = max(maxDigit, temp % 10);
                temp /= 10;
                count++;
            }

            int encryptedValue = 0;
            for (int i = 0; i < count; i++) {
                encryptedValue = encryptedValue * 10 + maxDigit;
            }

            totalSum += encryptedValue;
        }

        return totalSum;
    }
};
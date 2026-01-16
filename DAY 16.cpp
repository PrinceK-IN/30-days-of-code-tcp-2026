#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) { 
            return 0;
        }
      
        int sum = 1;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i += 1;
                continue;
            }

            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;
                sum += peak;
                i += 1;
            }

            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                down += 1;
                i += 1 ;
            }

            if (down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
};
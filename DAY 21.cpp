#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> s;

        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                nextGreaterMap[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        vector<int> result;
        for (int num : nums1) {
            if (nextGreaterMap.find(num) != nextGreaterMap.end()) {
                result.push_back(nextGreaterMap[num]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};
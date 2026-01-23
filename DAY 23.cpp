#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            freq[c]++;
        }

        priority_queue<pair<int , char>> pq;

        for(auto it : freq) {
            pq.push({it.second, it.first});
        }

        string result = "";
        while(!pq.empty()) {
            pair<int, char> temp = pq.top();
            pq.pop();

            result.append(temp.first, temp.second);
        }
        return result;
    }
};
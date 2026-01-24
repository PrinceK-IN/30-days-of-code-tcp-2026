#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, d;
    cin >> n >> d;
    vector<long long> p(n);
    
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    sort(p.rbegin(), p.rend());
    
    int max_teams = 0;
    int players_used = 0;
    
    for(int i = 0; i < n; i++) {
        long long needed = (d / p[i]) + 1;
        
        if(players_used + needed <= n) {
            max_teams++;
            players_used += needed;
        }
        else {
            break;
        }
    }
    
    cout << max_teams << endl;
    
    return 0;
}
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll current_window_sum = 0;
    
    for(int i = 0; i < k; i++) {
        current_window_sum += a[i];
    }
    
    ll total_all_weeks = current_window_sum;
    
    for(int i = k; i < n; i++) {
        current_window_sum += a[i] - a[i - k];
        
        total_all_weeks += current_window_sum;
    }
    
    int num_weeks = n - k + 1;
    
    double average = (double)total_all_weeks / num_weeks;
    
    cout << fixed << setprecision(10) << average << endl;
    
    return 0;
}
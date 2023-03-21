// Problem link: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(1e4+1, INT_MIN);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < n; j++){
                if(i - (j + 1) >= 0){
                    dp[i] = max(dp[i], dp[i - (j + 1)] + price[j]);
                }
            }
        }
        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}

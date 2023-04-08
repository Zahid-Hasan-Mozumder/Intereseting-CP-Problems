// Problem link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;


class Solution{
		
	public:
	int minOperations(string str1, string str2){ 
	    string s = " " + str1;
	    string t = " " + str2;
	    int n = s.size(), m = t.size();
	    vector<vector<int>> dp(n, vector<int>(m, 0));
	    for(int i = 1; i < n; i++){
	        for(int j = 1; j < m; j++){
	            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	            if(s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
	        }
	    }
	    int lcs = dp[n - 1][m - 1];
	    return (n - 1) + (m - 1) - (2 * lcs);
	} 
};

int main() { 
   	int t; cin >> t;
    while (t--){
        string s1, s2;
        cin >> s1 >> s2;
	      Solution ob;
	      cout << ob.minOperations(s1, s2) << "\n";
    }
    return 0;
}

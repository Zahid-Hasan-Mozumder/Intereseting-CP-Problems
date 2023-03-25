// Problem link: https://cses.fi/problemset/task/1744/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
 
vvi dp(501, vvi(501, INT_MAX));
void Depression(int a, int b){
    for(int height = 1; height <= a; height++){
        for(int width = 1; width <= b; width++){
            if(height == width)
                dp[height][width] = 0;
            else{
                int ans = INT_MAX;
                for(int i = 1; i < height; i++)
                    ans = min(ans, 1 + dp[height - i][width] + dp[i][width]);
                for(int i = 1; i < width; i++)
                    ans = min(ans, 1 + dp[height][width - i] + dp[height][i]);
                dp[height][width] = ans;
            }
        }
    }
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
int main(){
 
    zahid();
    
    int a, b; cin >> a >> b;
    Depression(a, b);
    cout<< dp[a][b] << '\n';
}

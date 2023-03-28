// Problem link: https://cses.fi/problemset/task/1745/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

int n;
vi a(1e2+2);
vi dp(1e5+2, 0);
set<int> s;

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mxSum = accumulate(a.begin(), a.end(), 0);
    dp[0]= 1;
    for(int i = 0; i < n; i++){
        for(int j = mxSum; j >= 1; j--){
            if(j - a[i] >= 0){
                if(dp[j] == 0 && dp[j - a[i]] == 1){
                    dp[j] = 1;
                    s.insert(j);
                }
            }
        }
    }
    cout<< s.size() << '\n';
    while(!s.empty()){
        cout<< *s.begin() << " ";
        s.erase(s.begin());
    }
}

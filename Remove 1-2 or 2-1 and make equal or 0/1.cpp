// Problem link: https://codeforces.com/problemset/problem/1260/B
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();
    
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int mx = max(a, b), mn = min(a, b);
        if(mn * 2 == mx) cout<< "YES" << '\n';
        else if(mn * 2 < mx) cout<< "NO" << '\n';
        else if(mn * 2 > mx){
            if((2 * mn - mx) % 3 == 0) cout<< "YES" << '\n';
            else cout<< "NO" << '\n';
        }
    }
}

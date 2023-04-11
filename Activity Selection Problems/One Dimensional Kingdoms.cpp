// Problem link: https://www.codechef.com/problems/ONEKING
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        vpii a;
        for(int i = 0; i < n; i++){
            int l, r; 
            cin >> l >> r;
            a.pb({l, r});
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int st = -1, ft = -1;
        for(int i = 0; i < n; i++){
            if(st == -1){
                st = a[i].ff; 
                ft = a[i].ss;
                ans++;
            }
            else{
                if(a[i].ff > ft || a[i].ss < st){
                    st = a[i].ff;
                    ft = a[i].ss;
                    ans++;
                }
                else{
                    st = max(st, a[i].ff);
                    ft = min(ft, a[i].ss);
                }
            }
        }
        cout<< ans << '\n';
    }
}

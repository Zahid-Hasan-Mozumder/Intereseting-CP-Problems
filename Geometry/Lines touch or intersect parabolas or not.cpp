// Problem link: https://codeforces.com/problemset/problem/1805/C
// Helpful video: https://www.youtube.com/watch?v=e-DHx2b0MpI
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();
    
    int t; cin>>t;
    while(t--){
        ll n, m; cin>>n>>m;
        vll k(n);
        for(int i=0; i<n; i++) cin>>k[i];
        sort(k.begin(), k.end());
        for(int i=0; i<m; i++){
            ll a, b, c;
            cin>>a>>b>>c;
            int ind = lower_bound(k.begin(), k.end(), b) - k.begin();
            if(ind == n){
                ind--;
                ll m = k[ind];
                if((b - m) * (b - m) < 4LL * a * c){
                    cout<< "YES" << '\n';
                    cout<< m << '\n';
                }
                else{
                    cout<< "NO" << '\n';
                }
            }
            else if(ind == 0){
                ll m = k[ind];
                if((b - m) * (b - m) < 4LL * a * c){
                    cout<< "YES" << '\n';
                    cout<< m << '\n';
                }
                else{
                    cout<< "NO" << '\n';
                }    
            }
            else{
                ll m1 = k[ind];
                ll m2 = k[--ind];
                if((b - m1) * (b - m1) < 4LL * a * c){
                    cout<< "YES" << '\n';
                    cout<< m1 << '\n';
                }
                else if((b - m2) * (b - m2) < 4LL * a * c){
                    cout<< "YES" << '\n';
                    cout<< m2 << '\n';
                }
                else{
                    cout<< "NO" << '\n';
                }
            }
        }
        cout<< '\n';
    }
}

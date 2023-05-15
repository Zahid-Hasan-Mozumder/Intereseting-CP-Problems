// Problem link: https://codeforces.com/problemset/problem/1766/D
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define pb push_back

const int mod = 1e9+7;
//const int mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e5+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

ll GCD(ll a, ll b){
    ll temp;
    while(b){
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

vector<bool> mark(sz, 0);
vector<int> primes;

void SEIVE(){
    mark[0] = 1;
    mark[1] = 1;
    for(int i=4; i<sz; i+=2)
        mark[i] = 1;
    for(int i=3; i*i<sz; i+=2){
        if(!mark[i]){
            for(int j=i*i; j<sz; j+=(i*2)){
                mark[j] = 1;
            }
        }
    }
    primes.pb(2);
    for(int i=3; i<sz; i+=2){
        if(!mark[i])
            primes.pb(i);
    }
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();
    SEIVE();
    
    int t; cin >>t;
    while(t--){
        int x, y; cin >> x >> y;
        if(x + 1 == y) cout << -1 << '\n';
        else if(GCD(x, y) != 1) cout << 0 << '\n';
        else if(x % 2 != 0 && y % 2 != 0) cout << 1 << '\n';
        else{
            vi pf;
            int diff = y - x;
            for(int i = 0; i <= primes.size() && primes[i] * primes[i] <= diff; i++){
                if(diff % primes[i]) continue;
                pf.pb(primes[i]);
                while(diff % primes[i] == 0) diff /= primes[i];
            }
            if(diff > 1) pf.pb(diff);
            int ans = INT_MAX;
            for(int i = 0; i < pf.size(); i++){
                ans = min(ans, pf[i] - (x % pf[i]));
            }
            cout << ans << '\n';
        }
    }
}

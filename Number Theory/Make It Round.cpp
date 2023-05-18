// Problem link: https://codeforces.com/problemset/problem/1759/D
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define plpii pair<ll, pair<int, int>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
//const ll mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

ll POW(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW(a, b/2);
    if(b&1) return (x * x * a);
    else return (x * x);
}

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll tmp = n;
        ll cnt2 = 0, cnt5 = 0;
        while(tmp % 2 == 0) cnt2++, tmp /= 2;
        while(tmp % 5 == 0) cnt5++, tmp /= 5;
        if(cnt2 > cnt5){
            ll extra5 = 0;
            while(m > 5 && cnt5 + extra5 < cnt2){
                m /= 5;
                extra5++;
            }
            ll cnt10 = 0;
            while(m > 10){
                m /= 10;
                cnt10++;
            }
            ll ans = n;
            if(extra5 > 0) ans *= POW(5, extra5);
            if(cnt10 > 0) ans *= POW(10, cnt10);
            ans *= m;
            cout << ans << '\n';
        }
        else if(cnt2 < cnt5){
            ll extra2 = 0;
            while(m > 2 && cnt2 + extra2 < cnt5){
                m /= 2;
                extra2++;
            }
            ll cnt10 = 0;
            while(m > 10){
                m /= 10;
                cnt10++;
            }
            ll ans = n;
            if(extra2 > 0) ans *= POW(2, extra2);
            if(cnt10 > 0) ans *= POW(10, cnt10);
            ans *= m;
            cout << ans << '\n';
        }
        else{
            ll cnt10 = 0;
            while(m > 10){
                m /= 10;
                cnt10++;
            }
            ll ans = n;
            if(cnt10 > 0) ans *= POW(10, cnt10);
            ans *= m;
            cout << ans << '\n';    
        }
    }
}

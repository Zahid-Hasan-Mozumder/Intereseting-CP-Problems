// Problem link: https://www.codechef.com/problems/SUBSEQINV
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

//const int mod = 1e9+7;
const int mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

ll POW_MOD(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW_MOD(a, b/2);
    if(b&1) return ((((x % mod) * (x % mod)) % mod) * (a % mod)) % mod;
    else return ((x % mod) * (x % mod)) % mod;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi a(n), l(n), r(n), b(n, 1);
        for(int i=0; i<n; i++) cin>>a[i];
        l[0] = a[0];
        for(int i=1; i<n; i++) l[i] = max(l[i - 1], a[i]);
        r[n - 1] = a[n - 1];
        for(int i=n-2; i>=0; i--) r[i] = min(r[i + 1], a[i]);
        for(int i=0; i<n; i++){
            if(i > 0 && a[i] < l[i - 1]) b[i] = 0;
            if(i < n - 1 && a[i] > r[i + 1]) b[i] = 0;
        }
        ll cnt = accumulate(b.begin(), b.end(), 0);
        if(cnt == n){
            ll ans = POW_MOD(2LL, cnt);
            ans--;
            cout << ans << '\n';
        }
        else{
            ll ans = POW_MOD(2LL, cnt);
            cout << ans << '\n';
        }
    }
}

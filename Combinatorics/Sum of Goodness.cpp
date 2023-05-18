// Problem link: https://www.codechef.com/problems/SEQGOODNESS?tab=statement
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int sz = 1e5+2;
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

ll modInv(ll a){
    ll ans = POW_MOD(a, mod-2);
    return ans;
}

vector<ll> modFact(2e6+2);
void generateModFact(){
    modFact[0] = 1;
    for(int i=1; i<=2e6; i++){
        modFact[i] = ((modFact[i-1] % mod) * (i % mod)) % mod;
    }
}

ll mod_nCr(ll n, ll r){
    ll ans = modFact[n];
    ans %= mod;
    ans *= modInv(modFact[r]);
    ans %= mod;
    ans *= modInv(modFact[n - r]);
    ans %= mod;
    return ans;
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
    generateModFact();

    int t; cin >> t;
    while(t--){
        ll n; cin >>n;
        vll a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0; i < n; i++){
            //cout << mod_nCr(i, a[i] - 1) << " " << POW_MOD(2, n - 1 - i) << '\n';
            if(i + 1 >= a[i]){
                ans += ((mod_nCr(i, a[i] - 1) % mod) * (POW_MOD(2, n - 1 - i) % mod)) % mod;
                ans %= mod;
            }
        }
        cout << ans << '\n';
    }
}

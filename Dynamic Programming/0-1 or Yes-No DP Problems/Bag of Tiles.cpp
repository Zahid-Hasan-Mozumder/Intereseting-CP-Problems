// Problem link: https://open.kattis.com/problems/bagoftiles
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define vvs vector<vector<string>>
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
#define vvvll vector<vector<vector<ll>>>

const ll mod = 1e9+7;
//const ll mod = 998244353;
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
    ans *= modInv(modFact[n-r]);
    ans %= mod;
    return ans;
}

ll n;
ll a[31];
ll dp[31][31][10005];
ll depression(ll i, ll sum, ll rem){
    if(sum < 0) return 0;
    if(sum == 0) return (rem == 0 ? 1 : 0);
    if(rem == 0) return 0;
    if(i == n) return 0;
    if(dp[i][rem][sum] != -1) return dp[i][rem][sum];

    ll res = 0;
    res += depression(i + 1, sum - a[i], rem - 1);
    res += depression(i + 1, sum, rem);
    return dp[i][rem][sum] = res;
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

    int t = 1;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        ll m, x; cin >> m >> x;
        cout << "Game " << cs << " -- ";
        ll total = mod_nCr(n, m);
        memset(dp, -1, sizeof(dp));
        ll possible = depression(0, x, m);
        cout << possible << " : " << total - possible << '\n';
    }
}

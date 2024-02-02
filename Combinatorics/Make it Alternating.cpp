// Problem link: https://codeforces.com/contest/1879/problem/C
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define pipll pair<int, pair<ll, ll>>
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvi vector<vector<vector<int>>>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

//const ll mod = 1e9 + 7;
const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

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

ll mod_nPr(ll n, ll r){
    if(n<=0 || r > n)
        return 0;
    ll ans = modFact[n];
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
        string s; cin >> s;
        int n = s.size();
        ll op = 0, comb = 1;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]) cnt++;
            else{
                if(cnt > 1){
                    op += cnt - 1;
                  
                    // Taking a group of y elements from x elements
                    comb *= mod_nCr(cnt, cnt - 1);
                    comb %= mod;
                    
                    cnt = 1;
                }
            }
        }
        if(cnt > 1){
            op += cnt - 1;

            // Taking a group of y elements from x elements
            comb *= mod_nCr(cnt, cnt - 1);
            comb %= mod;
          
            cnt = 1;
        }
      
        // Organizing all the elements in every possible position 
        comb *= modFact[op];
        comb %= mod;
      
        cout << op << " " << comb << '\n';
    }
}

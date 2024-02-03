// Problem link: https://codeforces.com/contest/1882/problem/C
// Video tutorial: https://www.youtube.com/watch?v=3xkucZvNov8&t=498s
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

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
        ll n; cin >> n;
        vll a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll ans = 0, sum = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i & 1){
                if(a[i] >= 0) sum += a[i];
            }
            else{
                if(a[i] >= 0){
                    ans += a[i] + sum;
                    sum = 0;
                }
            }
        }
        if(sum > 0){
            ll mx = 0;
            for(int i = 0; i < n; i++){
                if(!(i & 1) && a[i] >= 0) break;
                if(i & 1){
                    if(a[i] >= 0) sum -= a[i];
                    mx = max(mx, ans + sum);
                }
                else{
                    if(a[i] >= 0) sum -= a[i];
                    mx = max(mx, a[i] + ans + sum);
                }
            }
            cout << mx << '\n';
        }
        else cout << ans << '\n';
    }
}

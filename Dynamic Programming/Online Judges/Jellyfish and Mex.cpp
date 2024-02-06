// Problem link: https://codeforces.com/contest/1875/problem/D
// Video tutorial: https://www.youtube.com/watch?v=Wm4dMYzVv8U
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

int n;
vi dp;
unordered_map<int, int> freq;

int findMex(vi a){
    sort(a.begin(), a.end());
    int mex = 0;
    for(int i = 0; i < a.size(); i++){
        if(mex < a[i]) break;
        if(mex == a[i]) mex++;
    }
    return mex;
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
        cin >> n;
        vi a(n);
        dp.clear(); dp.resize(n + 5, INT_MAX);
        freq.clear();
        for(int i = 0; i < n; i++){
            cin >> a[i];
            freq[a[i]]++;
        }
        int mex = findMex(a);
        for(int i = mex; i < n + 5; i++) dp[i] = 0;
        for(int i = mex - 1; i >= 0; i--){
            for(int j = i + 1; j <= mex; j++){
                dp[i] = min(dp[i], dp[j] + ((freq[i] - 1) * j) + i);
            }
        }
        cout << dp[0] << '\n';
    }
}

// Problem link: https://codeforces.com/gym/104397/problem/A
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

vector<pair<string, int>> ss;
vi one, zero;
bool cmp(pair<string, int> &a, pair<string, int> &b){
    return (one[a.ss] * zero[b.ss]) < (one[b.ss] * zero[a.ss]);
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

    int t = 1; // cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int n; cin >> n;
        one.resize(n, 0);
        zero.resize(n, 0);
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '1') one[i]++;
                else zero[i]++;
            }
            if(!one[i] || !zero[i]) continue;
            ss.pb({s, i});
        }
        sort(ss.begin(), ss.end(), cmp);
        ll res = 0, cnt = 0;
        for(int i = 0; i < ss.size(); i++){
            for(int j = 0; j < ss[i].ff.size(); j++){
                if(ss[i].ff[j] == '1') cnt++;
                else res += cnt;
            }
        }
        cout << res << '\n';
    }
}

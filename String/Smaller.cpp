// Problem link: https://codeforces.com/problemset/problem/1742/F
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        vll cnt1(26, 0), cnt2(26, 0);
        cnt1[0] = 1, cnt2[0] = 1;
        set<char> s1, s2;
        s1.insert('a'), s2.insert('a');
        int q; cin >> q;
        while(q--){
            int qt; cin >> qt;
            if(qt == 1){
                ll k; cin >> k;
                string x; cin >> x;
                for(int i = 0; i < x.size(); i++){
                    cnt1[x[i] - 'a'] += k;
                    s1.insert(x[i]);
                }
            }
            else{
                ll k; cin >> k;
                string x; cin >> x;
                for(int i = 0; i < x.size(); i++){
                    cnt2[x[i] - 'a'] += k;
                    s2.insert(x[i]);
                }
            }
            // s = aaabc...
            // t = baaaa...
            if(s2.size() > 1) cout << "YES" << '\n';
            // s = aaa
            // t = aaaaa
            else if(s1.size() == 1 && s2.size() == 1){
                if(cnt1[0] < cnt2[0]) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
            // s = aaaa
            // t = aab.........
            else cout << "NO" << '\n';
        }
    }
}

// Problem link: https://codeforces.com/problemset/problem/1679/C
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
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

    int n, q; cin >> n >> q;
    vi rows(n + 1, 0), cols(n + 1, 0);
    set<int> non_vis_rows, non_vis_cols;
    for(int i = 1; i <= n; i++){
        non_vis_rows.insert(i);
        non_vis_cols.insert(i);
    }
    while(q--){
        int qt; cin >> qt;
        if(qt == 1){
            int x, y; cin >> x >> y;
            rows[x]++;
            cols[y]++;
            if(rows[x] == 1) non_vis_rows.erase(x);
            if(cols[y] == 1) non_vis_cols.erase(y);
        }
        else if(qt == 2){
            int x, y; cin >> x >> y;
            rows[x]--;
            cols[y]--;
            if(rows[x] == 0) non_vis_rows.insert(x);
            if(cols[y] == 0) non_vis_cols.insert(y);
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool blank_row = false, blank_col = false;
            int rr = *non_vis_rows.lower_bound(x1);
            if(rr >= x1 && rr <= x2) blank_row = true;
            int cc = *non_vis_cols.lower_bound(y1);
            if(cc >= y1 && cc <= y2) blank_col = true;
            if(blank_row && blank_col) cout << "No" << '\n';
            else cout << "Yes" << '\n'; 
        }
    }
}

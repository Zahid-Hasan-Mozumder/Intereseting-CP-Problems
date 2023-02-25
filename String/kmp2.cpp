// Problem link: https://codeforces.com/problemset/problem/471/D
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
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
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvpli vector<vector<pair<ll, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int ans = 0;

vi create_lps(vi a){
    vi lps(a.size(), 0);
    int ind = 0;
    for(int i=1; i<a.size(); ){
        if(a[ind] == a[i]){
            lps[i] = ind + 1;
            ind++; i++;
        }
        else{
            if(ind != 0) ind = lps[ind - 1];
            else i++;
        }
    }
    return lps;
}

void kmp(vi a, vi b){
    vi lps = create_lps(b);
    int i = 0, j = 0;
    while(i < a.size()){
        if(a[i] == b[j]){
            i++; j++;
        }
        else{
            if(j != 0) j = lps[j-1];
            else i++;
        }

        if(j == b.size()){
            ans++;
            j = lps[j-1];
        }
    }
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
    
    int n, m; cin>>n>>m;
    vi a(n), b(m), x(n-1), y(m-1);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    for(int i=0; i<n-1; i++) x[i] = a[i+1] - a[i];
    for(int i=0; i<m-1; i++) y[i] = b[i+1] - b[i];
    if(m==1) cout<< n << '\n';
    else{
        kmp(x, y);
        cout<< ans << '\n';
    }
}

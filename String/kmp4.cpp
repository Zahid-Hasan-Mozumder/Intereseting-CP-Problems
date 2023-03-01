// Problem link: https://codeforces.com/contest/1796/problem/B
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

vector<int> create_lps(string x){
    vector<int> lps(x.size(), 0);
    int ind = 0;
    for(int i=1; i<x.size(); ){
        if(x[ind] == x[i]){
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

    int t; cin>>t;
    while(t--){
        string a, b; cin>>a>>b;
        bool flag = false;
        for(int i=0; i<a.size(); i++){
            string curr = a.substr(i, a.size() - i);
            string x = curr + "#" + b;
            vi lps = create_lps(x);
            int mx = 0;
            for(int j=curr.size() + 1; j<lps.size(); j++){
                mx = max(mx, lps[j]);
            }
            if(mx > 0){
                string ans = a.substr(i, mx);
                if(ans.size() == 1 && a[0] == ans[0] && b[0] == ans[0]){
                    cout<< "YES" << '\n';
                    cout<< ans << "*" << '\n';
                    flag = true;
                    break;
                }
                else if(ans.size() == 1 && a[a.size() - 1] == ans[0] && b[b.size() - 1] == ans[0]){
                    cout<< "YES" << '\n';
                    cout<< "*" << ans << '\n';
                    flag = true;
                    break;
                }
                else if(ans.size() > 1){
                    cout<< "YES" << '\n';
                    cout<< "*" << ans << "*" << '\n';
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) cout<< "NO" << '\n';
    }
}

// Problem link: https://codeforces.com/problemset/problem/1714/E
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        int n; cin >> n;
        vi a(n);
        set<int> s;
        // We changing all the numbers to that next number which has 6 as its last digit because,
        // We can always find a cycle like this, 6 -> 2 -> 4 -> 8 -> 6 -> 2 -> 4 -+ 8 -> 6.......
        // But in case of 5, we can only change it once and that is its next number which is multiple of ten
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 10 == 1) a[i] += 15;
            else if(a[i] % 10 == 2) a[i] += 14;
            else if(a[i] % 10 == 3) a[i] += 3;
            else if(a[i] % 10 == 4) a[i] += 12;
            else if(a[i] % 10 == 5) a[i] += 5;
            else if(a[i] % 10 == 6) a[i] += 0;
            else if(a[i] % 10 == 7) a[i] += 19;
            else if(a[i] % 10 == 8) a[i] += 8;
            else if(a[i] % 10 == 9) a[i] += 17;
            if(a[i] % 10 == 0) s.insert(a[i]);
        }
        // If there is more than 1 tens then we can't make it equal
        if(s.size() > 1) cout << "NO" << '\n';
        // If there is only 1 tens then we should make all the other values equal to this tens
        else if(s.size() == 1){
            bool flag = true;
            sort(a.begin(), a.end());
            for(int i = 0; i < n; i++){
                if(a[i] > *s.begin()){
                    flag = false;
                    break;
                }
                int diff = *s.begin() - a[i];
                if(diff % 20 != 0){
                    flag = false;
                    break;
                }
            }
            if(flag) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        // If there is no tens in the array
        else{
            bool flag = true;
            sort(a.begin(), a.end());
            for(int i = 1; i < n; i++){
                int diff = a[i] - a[i - 1];
                if(diff % 20 != 0){
                    flag = false;
                    break;
                }
            }
            if(flag) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}

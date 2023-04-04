// Problem link: https://codeforces.com/contest/257/problem/C
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
using namespace std;

#define pii pair<int, int>
#define pb push_back

const double pi = acos(-1.0);

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();
  
    int n; cin >> n;
    vector<pii> c;
    vector<double> deg;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        c.pb({x, y});
        deg.pb(atan2(y, x) * 180 / pi);
    }
    sort(deg.begin(), deg.end());
    deg.pb(deg[0] + 360);
    double ans = 0;
    for(int i=0; i<deg.size()-1; i++){
        ans = max(ans, deg[i+1] - deg[i]);
    }
    ans = 360 - ans;
    cout<< fixed << setprecision(10) << ans << '\n';
}

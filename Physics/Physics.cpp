// Problem link: https://www.codechef.com/problems/MRIU3
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------------|
| Initial velocity, u = 0                                 |
| Given,                                                  |
| v and t                                                 |
| We know that, v = u + at                                |
|               a = (v - u) / t                           |
|                 = (v - 0) / t                           |
|                 = v / t                                 |
| Again, velocity at 2t time, fv = u + a * (2t)           |
|                                = 0 + (v / t) * (2t)     |
|                                = (v * 2 * t) / t        |
|                                = v * 2                  |
| Now, distance, s = 1 / 2 * (u + fv) * 2t                |
|                  = 1 / 2 * (0 + v * 2) * 2t             |
|                  = v * 2 * 2t / 2                       |
|                  = v * 2 * t                            |
|---------------------------------------------------------|*/

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        double v, t; cin>>v>>t;
        int s = (v * 2) * t;
        cout << s << '\n';
    }
}

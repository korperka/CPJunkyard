#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    ll h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));

    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];

    set<pair<ll, ll>> v;
    ll py = 0, px = 0, px1, py1;
    while(px < h && py < w && px >= 0 && py >= 0) {
        if(v.count({px, py})) {
            cout << -1;
            return 0;
        }

        v.insert({px, py});
        char c = a[px][py];

        px1 = px; py1 = py;

        if(c == 'U') px--;
        else if(c == 'D') px++;
        else if(c == 'L') py--;
        else py++;
    }

    cout << px1+1 << " " << py1+1;
}
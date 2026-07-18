#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    int t; cin >> t;

    while(t--) {
        ll n, h, k, s; cin >> n >> h >> k >> s;
        bool ans = true;
        vector<vector<ll>> a(n, vector<ll>(2, 0));

        for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];

        ll min_y = s, max_y = s;
        for (int i = 1; i < n; i++) {
            min_y--; max_y += k;

            while (min_y <= a[i][0]) min_y += k+1;
            while (max_y >= a[i][1]) max_y -= k+1;

            if (min_y > max_y) ans = false;
        }

        cout << (ans ? "Yes\n" : "No\n");
    }
}
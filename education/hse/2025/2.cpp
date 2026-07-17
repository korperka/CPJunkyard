#include<bits/stdc++.h>

using ll = long long;
using namespace std;

ll floor_div(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ((-a + b - 1) / b);
}

ll ceil_div(ll a, ll b) {
    if (a >= 0) return (a + b - 1) / b;
    return -((-a) / b);
}

bool check(int y, int h, int l, int r) {
    return y <= h && y >= 1 && y >= l+1 && y <= r-1;
}

int main() {
    int t; cin >> t;

    while(t--) {
        ll n, h, k, s; cin >> n >> h >> k >> s;
        bool ans = true;

        ll min_j = 0, max_j = -1;
        for (int i = 0; i < n; i++) {
            ll l, r; cin >> l >> r;

            max_j++;

            ll new_min_j = ceil_div(l-s+i+1, k+1);
            ll new_max_j = floor_div(r-s+i-1, k+1);

            if (new_min_j > min_j) min_j = new_min_j;
            if (new_max_j < max_j) max_j = new_max_j;

            if (min_j > max_j) {
                ans = false;
            }
        }

        cout << (ans ? "Yes\n" : "No\n");
    }
}
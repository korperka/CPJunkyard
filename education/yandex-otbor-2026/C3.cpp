#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<ll, ll, greater<ll>> a;
    ll n; cin >> n;
    for (int i = 0; i < n; ++i) {
        ll k; cin >> k;
        a[k]++;
    }

    ll s1 = 0, t1 = 0, t2 = 0;
    for (auto c : a) {
        if (c.second >= 4) {
            if (s1 == 0) s1 = c.first*c.first;
        }
        if (c.second >= 2) {
            if (t1 == 0) t1 = c.first;
            else if (t2 == 0) t2 = c.first;
        }
    }

    cout << max(s1, t1*t2);
}

// 8 5 5 3 3 3 3 2 2 -> 5:2 3:4 2:2
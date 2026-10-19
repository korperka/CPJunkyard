#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++) {
        ll k;
        cin >> k;

        deque<int> dmin, dmax;
        dmin.push_back(0);
        dmax.push_back(0);
        pair<ll, ll> ans = {0, -1};
        int l = 0, r = 0;
        while (l < n && r < n) {
            if (dmax.empty() || dmin.empty() || a[dmax.front()] - a[dmin.front()] <= k) {
                if (r - l > ans.second - ans.first) ans = {l, r};
                r++;

                if (r >= n) continue;

                while (!dmin.empty() && a[dmin.back()] >= a[r]) dmin.pop_back();
                dmin.push_back(r);

                while (!dmax.empty() && a[dmax.back()] <= a[r]) dmax.pop_back();
                dmax.push_back(r);
            } else {
                l++;

                if (dmin.front() < l) dmin.pop_front();
                if (dmax.front() < l) dmax.pop_front();
            }
        }

        cout << ans.first + 1 << " " << ans.second + 1 << "\n";
    }
}

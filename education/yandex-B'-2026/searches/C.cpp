#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct Party {
    ll r = 0, b = 0;

    bool operator<(const Party& p) const { return r < p.r; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<pair<Party, ll>> a(n), a1(n);
    vector<pair<ll, ll>> q(n);
    vector<ll> g(n);
    for (int i = 0; i < n; i++) {
        auto p = Party();
        cin >> p.r >> p.b;
        a[i] = {p, i};
        a1[i] = a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> p(n);
    p[0] = a[0].first.r;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i].first.r;
    }

    for (int i = 0; i < n; i++) {
        if (a[i].first.b == -1) {
            q[i] = {1e9, a[i].second};
            g[a[i].second] = 1e9;
            continue;
        }

        ll l = a[i].first.r, r = 1e9;
        while (l <= r) {
            ll m = l + (r - l) / 2;

            auto it = lower_bound(a.begin(), a.end(), m,
                                  [](const pair<Party, ll>& p, ll v) { return p.first.r < v; });
            ll j = it - a.begin();
            if (i == j) j++;
            ll N = n - j;

            if (it == a.end() || j >= n) {
                r = m - 1;
                continue;
            }

            if (m - a[i].first.r >= (p[n - 1] - p[j - 1]) - N * (m - 1))
                r = m - 1;
            else
                l = m + 1;
        }

        q[i] = {(l - a[i].first.r) + a[i].first.b, a[i].second};
        g[a[i].second] = l;
    }

    sort(q.begin(), q.end());

    ll j = q[0].second, c = 0;
    ll v = g[j];
    cout << q[0].first << "\n" << j + 1 << "\n";

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ll k = q[i].second, x = a1[k].first.r;

        if (j == k) continue;

        if (x < v) {
            ans[k] = x;
        } else {
            ans[k] = v - 1;
            c += x - v + 1;
        }
    }

    ans[j] = a1[j].first.r + c;
    ll i = 0, x = v - ans[j];
    while (ans[j] < v) {
        if (i == j) continue;

        if (ans[i] >= x) {
            ans[i] -= x;
            break;
        }

        x -= ans[i];
        ans[i] = 0;

        i++;
    }

    ans[j] = v;

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

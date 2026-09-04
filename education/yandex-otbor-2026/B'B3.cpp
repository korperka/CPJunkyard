#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;

        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first;
        for (int i = 0; i < n; i++) cin >> a[i].second;
        sort(a.begin(), a.end());

        priority_queue<ll> qu;
        vector<ll> p(n, 0), q(n);
        p[0] = a[0].second;
        qu.push(a[0].second);
        q[0] = p[0] * a[0].first;
        for (int i = 1; i < s; i++) {
            p[i] += a[i].second + p[i-1];
            qu.push(a[i].second);
            q[i] = p[i]*a[i].first;
        }

        for (int i = s; i < n; i++) {
            p[i] = p[i-1];
            if (qu.top() > a[i].second) {
                p[i] -= qu.top();
                p[i] += a[i].second;
                qu.pop();
                qu.push(a[i].second);
            }
            q[i] = p[i]*a[i].first;
        }

        ll ans = 2e18;
        for (int i = s-1; i < n; i++) {
            ans = min(ans, q[i]);
        }

        cout << ans << "\n";
    }
}
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n), p(n + 1);

    for (int i = 0; i < n; i++) cin >> a[i];

    p[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        p[i] = a[i - 1] + p[i - 1];
    }

    ll l = 0, bl = 0, ans = LLONG_MIN, r = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] - p[l] > ans) {
            ans = p[i] - p[l];
            r = i;
            bl = l;
        }

        if (p[i] < p[l]) l = i;
    }

    cout << bl + 1 << " " << r << " " << ans << "\n";
}

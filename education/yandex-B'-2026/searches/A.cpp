#include <bits/stdc++.h>

using ll = long long;
using namespace std;

bool check(vector<ll>& a, ll k, ll d) {
    ll c = 1, j = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] - a[j] >= d) {
            c++;
            j = i;
        }
    }

    return c >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll l = 0, r = a.back() - a[0];
    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (check(a, k, m))
            l = m + 1;
        else
            r = m - 1;
    }

    cout << r << "\n";
}

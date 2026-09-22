#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        vector<ll> a(3);
        int n; cin >> n >> a[0] >> a[1] >> a[2];

        sort(a.begin(), a.end());

        cout << n - a[0] << "\n";
    }
}
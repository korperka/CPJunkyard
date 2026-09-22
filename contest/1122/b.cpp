#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll a, b, c; cin >> a >> b >> c;

        if (abs(a-b+c) > abs(a-b)) {
            a += c; c = 0;
        }
        if (abs(a-b-c) < abs(a-b)) b += c;

        cout << abs(a-b) << "\n";
    }
}
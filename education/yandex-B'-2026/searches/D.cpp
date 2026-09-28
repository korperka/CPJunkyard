#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll l = 1, r = n;
    while (r > l + 1) {
        ll m = l + (r - l) / 2;

        bool s;
        if (m == 1) {
            s = true;
        } else if (m == n) {
            s = false;
        } else {
            cout << "? " << m << "\n";
            cout.flush();
            cin >> s;
        }

        if (s)
            l = m;
        else
            r = m;
    }

    cout << "! " << l << "\n";
}

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x;
    cin >> x;

    unordered_set<ll> used;
    ll a = 1, b = 1, p = 0, ans = 0;
    while (p < x) {
        if (a*a < b*b*b) {
            ans = a*a;
            a++;
        } else {
            ans = b*b*b;
            b++;
        }
        used.insert(ans);
        p++;
    }

    cout << ans << "\n";
}

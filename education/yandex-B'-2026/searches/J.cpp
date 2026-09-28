#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;

    ll l = 0, r = 1e18 + 1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;

        __int128 fst = (__int128)a * ((__int128)(mid - mid / k));
        __int128 snd = (__int128)b * ((__int128)(mid - mid / m));
        if (fst + snd >= x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l << "\n";
}

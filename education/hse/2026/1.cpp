#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
    ll l, r; cin >> l >> r;
    ll ans = (r/400 - l/400) + (r/4 - l/4) - (r/100 - l/100);

    if (l == 0) ans++;

    cout << ans;
}
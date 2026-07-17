#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ll n, c1 = 0, c2 = 0; cin >> n;

    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        if (a > 0) c1 += a;
        else c2 += a;
    }

    c2 = -c2;

    cout << max(c1, c2) << endl;
}
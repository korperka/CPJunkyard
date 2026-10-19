#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, f, s; cin >> n >> f >> s;
    unordered_set<ll> p;

    ll c = (f - 1) % n + 1;
    ll x = 1;
    while (!p.contains(c)) {
        p.insert(c);
        c = (f + s*x - 1) % n + 1;
        cout << "x: " << x << " " << "c: " << c << "\n";
        x++;
    }
}
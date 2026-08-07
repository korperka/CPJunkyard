#include<bits/stdc++.h>

using ll = long long;
using namespace std;

vector<ll> factors(ll n) {
    vector<ll> a;

    for(int i = 2; i <= n/i; i++) {
        while (n % i == 0) {
            n /= i;
            a.push_back(i);
        }
    }

    if(n > 1) a.push_back(n);
    return a;
}

int main() {
    mt19937_64 rng(42);
    int n; cin >> n;

    vector<ll> a;
    unordered_map<ll, ll> hashes;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a.push_back(x);

        for(ll c : factors(x)) {
            if(hashes.count(c) == 0) {
                hashes[c] = rng();
            }
        }
    }

    unordered_set<ll> s;
    s.insert(0);
    ll h = 0, ans = 1;
    for(int i = 0; i < n; i++) {
        for(ll c : factors(a[i])) h ^= hashes[c];

        if(s.count(h) > 0) {
            ans++;
            s.clear();
            s.insert(0);

            ll h1 = 0;
            for(ll c : factors(a[i])) h1 ^= hashes[c];
            h = h1;
        }

        s.insert(h);
    }

    cout << ans << "\n";
}
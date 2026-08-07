#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    string t, s; cin >> t >> s;
    t = s + "#" + t;

    vector<ll> p(t.size()+1);

    p[0] = -1;
    for(int i = 1; i <= t.size(); i++) {
        ll k = p[i-1];
        while(k != -1 && t[k] != t[i-1])
            k = p[k];

        p[i] = k+1;
    }

    cout << t << "\n";
    for(ll i : p) {
        cout << i << " ";
    }
}
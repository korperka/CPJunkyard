#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    string s; cin >> s;

    ll l = 0, r = n-1;
    while (l < r && s[l] == s[r] && (s[l+1] == s[l] || s[r-1] == s[r])) {
        if (s[l+1] == s[l]) l++;
        if (s[r-1] == s[r]) r--;
    }

    ll a = l+1, b = n-r;
    if (s[0] != s[n-1] || l >= r) {
        cout << 0 << "\n";
        return 0;
    }
    cout << (a < b ? "-" : "") << min(a, b) << "\n";
}
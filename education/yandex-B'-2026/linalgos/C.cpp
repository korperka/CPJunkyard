#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> s, l(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.back()] >= a[i]) s.pop_back();
        l[i] = s.empty() ? -1 : s.back();
        s.push_back(i);
    }
    s.clear();

    vector<ll> r(n);
    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && a[s.back()] >= a[i]) s.pop_back();
        r[i] = s.empty() ? n : s.back();
        s.push_back(i);
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ll w = (r[i] - l[i] - 1);
        ans[i] = w*a[i];
    }

    sort(ans.begin(), ans.end());

    cout << (ans.empty() ? 0 : ans.back()) << "\n";
}

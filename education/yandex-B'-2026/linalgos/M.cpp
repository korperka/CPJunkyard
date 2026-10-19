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

    vector<ll> p(n);
    deque<ll> dq;
    for (int i = n - 1; i >= 0; i--) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        p[i] = (dq.empty() ? -1 : dq.back());
        dq.push_back(i);
    }

    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << "\n";
}

#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ll t; cin >> t;

    while(t--) {
        vector<int> a(3); cin >> a[0] >> a[1] >> a[2];
        ll ans = 0;

        while(a[0] != a[1] && a[1] != a[2] && a[0] != a[2]) {
            sort(a.begin(), a.end());
            a[2]--; a[0]++;
            ans++;

//            cout << a[0] << " " << a[1] << " " << a[2] << "\n";
        }

        cout << ans << "\n";
    }
}
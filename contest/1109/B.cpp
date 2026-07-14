#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
    int t;
    cin>>t;

    while (t--) {
        ll n; cin >> n;
        bool f = false;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n-1; i++) {
            if (a[i] < i + 1) {
                cout << "NO\n";
                f = true;
                break;
            }

            a[i+1] += a[i]-i-1;
        }

        if (!f) {
            if (a[n-1] < n)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}
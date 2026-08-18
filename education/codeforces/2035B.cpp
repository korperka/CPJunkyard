#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;

        if(n == 1 || n == 3) cout << -1 << "\n";
        else if(n == 2) cout << 66 << "\n";
        else if(n == 4) cout << 3366 << "\n";
        else {
            if(n % 2 == 0) {
                for(int i = 0; i < n-4; i++) cout << 3;
                cout << 3366 << "\n";
            }
            else {
                for(int i = 0; i < n-5; i++) cout << 3;
                cout << 36366 << "\n";
            }
        }
    }
}
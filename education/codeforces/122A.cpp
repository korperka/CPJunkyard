#include<bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
    ll a; cin >> a;

    vector l = {4, 7, 47, 74, 44, 77, 744, 474, 447, 774, 477, 747, 777, 444};
    for (int n : l) {
        if (a % n == 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
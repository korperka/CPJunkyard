#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n, summ = 0; cin >> n;

    for (int i = 0; i < n-1; i++) {
        long long a; cin >> a;
        summ += a;
    }

    cout << n*(n+1)/2 - summ;
}
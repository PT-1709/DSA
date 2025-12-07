
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        double A, B, C;
        cin >> A >> B >> C;
        long long intA = (long long)A; 
        cout << "0x" << hex << nouppercase << intA << "\n";
        cout << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << "\n";
        
        cout << noshowpos << setfill(' ') << scientific << uppercase << setprecision(9) << C << "\n";

    }

    return 0;
}
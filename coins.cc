#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

VVI t;
VI p, c;
int n, A;

//sees if it is possible
//if possible, sets the vector to the number;

int f(int x) {
    
}


int main() {
    while (cin >> n) {
        c = VI(n);
        for (int i = 0; i < n; ++i) cin >> c[i];
        cin >> A;
        p = VI(A + 1, -1);
        t = VVI(A + 1, VI(n, 0));
        f(A);
        if (p[A]) {
            bool first = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < t[A][i]; ++j) {
                    if (first) first = false;
                    else cout <<',';
                    cout << c[i];
                }
            }
            cout << endl;
        } else cout << -1 << endl;
    }
}

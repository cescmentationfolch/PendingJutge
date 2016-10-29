#include <bits/stdc++.h>
using namespace std;

typedef vector<int> fila;
typedef vector<fila> matriu;

int n, m;

void nash(matriu& a, matriu& b)
{
    int nash = 0;
    int nashi, nashj;
    fila millora(m);
    for (int j = 0; j < m; ++j)
    {
        millora[j] = a[0][j];
        for (int i = 0; i < n; ++i)
        {
            if (a[i][j] > millora[j]) millora[j] = a[i][j];
        }
    }
    fila millorb(n);
    for (int i = 0; i < n; ++i)
    {
        millorb[i] = b[i][0];
        for (int j = 0; j < m; ++j)
        {
            if (b[i][j] > millorb[i]) millorb[i] = b[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == millora[j] and b[i][j] == millorb[i])
            {
                nash++;
                nashi = i;
                nashj = j;
            }
        }
    cout << nash << endl;
    if (nash == 1) cout << nashi + 1 << " " << nashj + 1 << endl;
}

int main()
{
    while (cin >> n >> m)
    {
        fila f (n);
        matriu a(m, f);
        matriu b(m, f);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> a[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> b[i][j];
        nash(a, b);
    }
}

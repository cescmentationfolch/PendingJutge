#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<string, vi> psv;
typedef map<psv, int> mp;

mp M;
vs S;
int n;
vvi G;
vi F;

void bug(string a, vi T, int x) {
  //cerr << x << ":\n";
  cerr << a << '\n';
  for (int i = 0; i < (int)T.size(); ++i) {
    if (i) cerr << ' ';
    cerr << T[i];
  }
  cerr << '\n';
  for (int i = 0; i < (int)G[x].size(); ++i) {
    if (i) cerr << ' ';
    cerr << G[x][i];
  }
  cerr << endl;
}

bool check(string& A, vi& T) {
  vi T1;
  bool fin = false;
  for (int w = 0; w < (int)T.size(); ++w) {
    int k = T[w];
    bool fff = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0, j1 = k; j < (int)S[i].size() and j1 < (int)A.size(); ++j, ++j1) {
//        cerr << "cosa\n";
        if (S[i][j] != A[j1]) break;
        if (j1 + 1 == (int)A.size()) {
          if (j + 1 == (int)S[i].size()) fin = true;
          else fff = true; 
        }
      }
    }
    if (fff) T1.push_back(k);
  }
  if (fin) T1.push_back((int)A.size());
  if (T1.size() == 0) return false;
  sort(T1.begin(), T1.end());
  string A1;
  for (int i = T1[0]; i < (int)A.size(); ++i) {
    A1.push_back(A[i]);
  }
  A = A1;
  T = T1;
  for (int i = (int)T.size() -1; i >= 0; --i) {
    T[i] -= T[0];
  }
 // if (A.size() < T.back()) cerr << "BUUUG!!!\n";
  return true;
}

void f(int x, string A, vi T) {
  if ((int)A.size() == T.back()) F[x] = 1;
  string B;
  vi T1;
  for (int i = 0; i < 26; ++i) {
    B = A;
    B.push_back('a' + i);
    T1 = T;
    if (check(B, T1)) {
 //     cerr << "aresta: " << i << '\n';
      int y;
      if (M.count(psv(B, T1)) == 0) {
        y = G.size();
        M[psv(B, T1)] = y;
        G.push_back(vi(0));
        F.push_back(0);
        f(y, B, T1);
      }
      else y = M[psv(B, T1)];
      G[x].push_back(y);
    }
  }
//  bug(A, T, x);
}

vvi AA;
vvi Id;
ll mod = 1e9 + 9;

void create() {
  M.clear();
  F = vi(1, 0);
  G = vvi(1);
  string a = "";
  vi T = vi(1, 0);
  M[psv(a, T)] = 0;
  f(0, a, T);
  int N = G.size();
  vvi MT(N, vi(N, 0));
  Id = MT;
  for (int i = 0; i < N; ++i) {
    Id[i][i] = 1;
    for (int j = 0; j < (int)G[i].size(); ++j) {
      MT[G[i][j]][i]++;
    }
  }
  AA = MT;
// cerr << "N: " << N << '\n';
// for (int i = 0; i < N; ++i) {
 //  for (int j = 0; j < N; ++j) {
  //   if (j) cerr << ' ';
   //  cerr << AA[i][j];
  // }
  // cerr << '\n';
// }
// cerr << '\n';
}

vvi mult(vvi A, vvi B) {
  int N = A.size();
  vvi C(N, vi(N, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        C[i][j] = (C[i][j] + A[i][k]*B[k][j])%mod;
      }
    }
  }
  return C;
}

vvi ex(ll e) {
  if (e == 0) return Id;
  vvi R = ex(e/2);
  R = mult(R, R);
  if (e%2) R = mult(R, AA);
  return R;
}

int main() {
  ll l;
  while (cin >> l >> n) {
    S = vs(n);
    for (int i = 0; i < n; ++i) cin >> S[i];
    create();
    vvi TT = ex(l);
    ll res = 0;
    for (int i = 0; i < (int)TT.size(); ++i) {
      if (F[i]) {
        res = (res + TT[i][0])%mod;
      }
    }
    cout << res << '\n';
  }
}

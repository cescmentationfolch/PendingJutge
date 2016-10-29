#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		vector<pair<long long, int> > s(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (i == 0) s[0].first = v[0];
			else s[i].first = s[i - 1].first + v[i];
			s[i].second = i;
		}
		sort(s.begin(), s.end());
		int imenor = 0, dmenor = 0, m = abs(v[0]); 
		for (int i = 1; i < n; ++i) {
			if (abs(s[i].first - s[i - 1].first) < m) {
				dmenor = s[i].second;
				imenor = s[i - 1].second;
				m = abs(s[i].first - s[i - 1].first);
			}			
		}
		cout << m << " " << imenor << " " << dmenor << endl;
	}
}

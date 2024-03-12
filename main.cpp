#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll t, k;
vs S;

bool check(const string& x) {
  for (auto i = 0; i < x.size(); ++i) {
    if (x[i] != x[x.size() - 1 - i]) {
      return false;
    }
  }

  return true;
}

bool solve() {
  for (auto i = 0; i < k; ++i) {
    for (auto j = 0; j < k; ++j) {
      if (i == j) {
        continue;
      }

      const auto& test = S[i] + S[j];
      if (check(test)) {
        cout << test << '\n';
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> k;
    S = vs(k);
    for (auto&& x : S) {
      cin >> x;
    }

    if (!solve()) {
      cout << 0 << '\n';
    }
  }

  return 0;
}
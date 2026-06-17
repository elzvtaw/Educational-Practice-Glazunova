#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> snow(n + 1);
  std::vector<int> summa(n + 1);
  for (int l = 0; l <= n; ++l) {
    snow[l] = 0;
  }
  for (int m = 0; m <= n; ++m) {
    summa[m] = 0;
  }
  for (int j = 0; j < k; ++j) {
    int id = 0;
    std::cin >> id;
    if (id == 1) {
      int i = 0;
      int x = 0;
      std::cin >> i >> x;
      snow[i] += x;
      summa[0] = 0;
      for (int a = 1; a <= n; ++a) {
        summa[a] = summa[a - 1] + snow[a];
      }
    } else {
      int u = 0;
      int r = 0;
      std::cin >> u >> r;
      int res = summa[r] - summa[u - 1];
      std::cout << res << std::endl;
    }
  }
  return 0;
}
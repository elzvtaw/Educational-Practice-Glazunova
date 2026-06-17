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
  
}
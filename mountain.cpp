#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N = 0;
  std::cin >> N;
  std::vector<std::vector<int>> mountain(N);
  for (int i = 0; i < N; i++) {
    mountain[i].resize(i + 1);
    for (int j = 0; j <= i; j++) {
      std::cin >> mountain[i][j];
    }
  }
  
}
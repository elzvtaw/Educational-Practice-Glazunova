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
  //  dp[i][j] - минимальная сумма от вершины до клетки (i,j)
  std::vector<std::vector<int>> dp(N);
  for (int i = 0; i < N; i++) {
    dp[i].resize(i + 1, 1000000000);
  }
  //  Создаём массив, чтобы запоминать, откуда пришли
  //  parent[i][j] - номер столбца, из которого пришли
  std::vector<std::vector<int>> parent(N);
  for (int i = 0; i < N; i++) {
    parent[i].resize(i + 1, -1);
  }
  dp[0][0] = mountain[0][0];
  parent[0][0] = -1;
  
}
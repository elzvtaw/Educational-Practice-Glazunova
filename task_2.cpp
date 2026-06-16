#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N = 0;
  int M = 0;
  std::cin >> N >> M;
  std::vector<std::vector<int>> graph(N + 1);
  for (int i = 0; i < M; ++i) {
    int from = 0;
    int to = 0;
    std::cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

}
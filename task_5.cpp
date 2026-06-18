#include <iostream>

int main() {
  int h = 0;
  int w = 0;
  std::cin >> h >> w;
  int min_line = w;
  int min_column = h;
  int max_line = -1;
  int max_column = -1;
  int matrix[51][51];
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      std::cin >> matrix[i][j];
    }
  }

}
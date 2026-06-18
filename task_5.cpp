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
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (matrix[i][j] == 1) {
        if (i < min_line) {
          min_line = i;
        } 
        if (j < min_column) {
          min_column = j;
        } 
        if (i > max_line) {
          max_line = i;
        }
        if (j > max_column) {
          max_column = j;
        }
      }
    }
  }
  int left_line = min_line - 1;
  int left_column = min_column - 1;
  int right_line = max_line + 1;
  int right_column = max_column + 1;
  std::cout << left_line << ' ' << left_column << ' ' << right_line << ' ' << right_column << std::endl;
  return 0;
}
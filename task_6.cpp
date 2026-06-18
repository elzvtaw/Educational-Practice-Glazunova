#include <iostream>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    std::cin >> a >> b >> x >> y;
    int count = 0;
    int b1 = std::min(b, x);
    x -= b1;
    count += b1;
    int a2 = std::min(a, y);
    a -= a2;
    y -= a2;
    count += a2;
    int a1 = std::min(a, x);
    a -= a1;
    x -= a1;
    count += a1;
    std::cout << count << ' ';
  }
  std::cout << std::endl;
  return 0;
} 

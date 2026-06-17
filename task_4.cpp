#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string Permutation(std::string& word, std::vector<int>& p) {
  int n = word.size();
  std::string res(n, ' ');
  for (int i = 0; i < n; ++i) {
    res[p[i] - 1] = word[i]; 
  }
  return res;
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  std::string s;
  std::cin >> s;
  std::string result = s;
  for (int j = 0; j < k; ++j) {
    result = Permutation(result, p);
  }
  std::cout << result << std::endl;
  return 0;
}
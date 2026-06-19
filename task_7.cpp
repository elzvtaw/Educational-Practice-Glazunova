#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string number;
  std::cin >> number;
  if (number.length() == 6 and isupper(number[0]) and isdigit(number[1]) and isdigit(number[2]) and isdigit(number[3]) and isupper(number[4]) and isupper(number[5])) {
    //  isupper() проверяет является ли символ заглавной
    //  isdigit() проверяет является ли символ цифрой
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0
}


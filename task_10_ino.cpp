#include <Servo.h>

#define SERVO_PIN 3  // Пин для сервопривода

Servo myServo;  // Создаём объект для сервопривода
int currentAngle = 0;  // Текущий угол (начальный = 0)

void setup() {
  Serial.begin(9600);  // Запуск последовательного порта
  myServo.attach(SERVO_PIN);  // Подключение сервопривода к пину
  myServo.write(currentAngle);  // Устанавливаем начальное положение
  Serial.println("Введите угол от 0 до 180");
  Serial.print("Текущий угол: ");
  Serial.println(currentAngle);
}

// Функция проверки, что строка состоит только из цифр
bool isNumber(String str) {
  if (str.length() == 0) {
    return false;
  }
  for (int i = 0; i < str.length(); i++) {
    if (!isDigit(str.charAt(i))) {
      return false;
    }
  }
  return true;
}

void loop() {
  // Проверяем, есть ли данные в Serial порту
  if (Serial.available() > 0) {
    // Читаем введённую строку
    String input = Serial.readStringUntil('\n');
    input.trim();  // Удаляем пробелы и символы перевода строки
    // Проверяем, что введено число
    if (input.length() > 0 and isNumber(input)) {
      int newAngle = input.toInt();
      // Проверяем диапазон (0-180)
      if (newAngle >= 0 and newAngle <= 180) {
        // Если угол отличается от текущего — поворачиваем
        if (newAngle != currentAngle) {
          Serial.print("Поворачиваем на угол: ");
          Serial.println(newAngle);
          // Плавный поворот
          for (int angle = currentAngle; angle != newAngle; ) {
            if (angle < newAngle) {
              angle++;
            } else {
              angle--;
            }
            myServo.write(angle);
            delay(15);  // Задержка для плавности
          }
          // Принудительно устанавливаем точное значение
          myServo.write(newAngle);
          currentAngle = newAngle;
          Serial.print("Текущий угол: ");
          Serial.println(currentAngle);
        } else {
          Serial.println("Сервопривод уже в этом положении");
        }
      } else {
        Serial.println("Ошибка: угол должен быть от 0 до 180");
      }
    } else {
      Serial.println("Ошибка: введите число от 0 до 180");
    }
  }
}
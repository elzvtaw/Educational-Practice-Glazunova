#include <Servo.h>

#define SERVO_PIN 3  // Пин для сервопривода

Servo myServo;  // Создаём объект для сервопривода
int currentAngle = 0;  // Текущий угол (по умолчанию 90°)

void setup() {
  Serial.begin(9600);  // Запуск последовательного порта
  myServo.attach(SERVO_PIN);  // Подключение сервопривода к пину
  myServo.write(currentAngle);  // Устанавливаем начальное положение
  Serial.println("Введите угол от 0 до 180");
  Serial.print("Текущий угол: ");
  Serial.println(currentAngle);
}

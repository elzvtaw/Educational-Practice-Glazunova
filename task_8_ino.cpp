#include <Adafruit_NeoPixel.h>

// Параметры подключения и матрицы
#define LED_PIN     6
#define LED_COUNT   64
#define BRIGHTNESS  150
#define WIDTH       8
#define HEIGHT      8

// Создание объекта ленты
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Функция для перевода координат (x, y) в индекс светодиода
int getPixelIndex(int x, int y) {
  if (y % 2 == 0) {
    return y * WIDTH + x;
  } else {
    return y * WIDTH + (WIDTH - 1 - x);
  }
}

// Установка цвета пикселя по координатам x, y
void setPixelXY(int x, int y, uint32_t color) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    strip.setPixelColor(getPixelIndex(x, y), color);
  }
}

// Фиолетовый круг
void showPurpleCircle(unsigned long duration) {
  uint8_t circle[8][8] = {
    {0,0,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,0,0}
  };

  unsigned long start = millis();
  while (millis() - start < duration * 1000) {
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if (circle[y][x] == 1) {
          setPixelXY(x, y, strip.Color(128, 0, 255));  // Фиолетовый
        } else {
          setPixelXY(x, y, strip.Color(0, 0, 0));
        }
      }
    }
    strip.show();
    delay(50);
  }
}
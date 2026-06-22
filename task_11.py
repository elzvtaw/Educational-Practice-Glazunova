import cv2
import numpy as np

# Загрузка изображения
image = cv2.imread("C:/Users/lizza/first-task-practice/test1_task_11.jpg")

# Размытие для подавления шума
blurred = cv2.GaussianBlur(image, (11, 11), 0)

# Перевод в HSV
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

# Диапазон синего цвета в HSV
darkblue_min = np.array((100, 80, 80), np.uint8) # Нижняя граница синего
darkblue_max = np.array((140, 255, 255), np.uint8) # Верхняя граница синего

# Создание маски для синего цвета
darkblue_mask = cv2.inRange(hsv, darkblue_min, darkblue_max)

# Нахождение контуров
contours, hierarchy = cv2.findContours(darkblue_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# Обрабатываем только внешние контуры
for i, contour in enumerate(contours):
    # Проверяем иерархию
    if hierarchy[0][i][3] == -1: # Parent == -1 значит внешний контур
        x, y, w, h = cv2.boundingRect(contour)
        center = (int(x + w/2), int(y + h/2))
        cv2.circle(image, center, 7, (0, 0, 255), 2)
        cv2.drawContours(image, [contour], -1, (255, 0, 0), 4)

# Показ результата
cv2.imshow("result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
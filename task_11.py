import cv2
import numpy as np

# Загрузка изображения
image = cv2.imread("C:/Users/lizza/first-task-practice/test1_task_11.jpg")

# Размытие для подавления шума
blurred = cv2.GaussianBlur(image, (11, 11), 0)

# Перевод в HSV
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)
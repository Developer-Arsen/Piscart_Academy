import cv2 as cv
import sys
import numpy as np

cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()
    cv.imshow("test", frame)

    cv.waitKey(25)

cap.release()
cv.destroyAllWindows()
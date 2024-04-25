import cv2 as cv

cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()
    cv.imshow("test", frame)

    cv.waitKey(25)

cap.release()
cv.destroyAllWindows()
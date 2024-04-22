import cv2 as cv
import sys
import numpy as np

def resize(frame, scale = 0.25):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

image = cv.imread(sys.argv[1])

def rotate(img, angle, rotationPoint = None):
    (height, width) = img.shape[:2]

    if rotationPoint is None:
        rotationPoint = (width // 2, height // 2)

    rotMat = cv.getT

    
if image is not None:
    image = resize(image)
    cv.imshow("test", image)
    cv.imwrite("aaaa.jpg",image)
    cv.waitKey(0)


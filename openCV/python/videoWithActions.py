
import cv2 as cv
import numpy as np
import time

flipVerticaly = False
flipHorizontaly = False

bgrToRgb  = False
bgrToLab  = False
bgrToGray = False
bgrToHsv  = False
isCroped  = False
isBlured  = False

def handleKeyPress(key):
    global flipVerticaly 
    global flipHorizontaly

    global bgrToRgb  
    global bgrToLab  
    global bgrToGray 
    global bgrToHsv  
    global isCroped  
    global isBlured  

    if key == 118 : # v
        flipHorizontaly = False
        flipVerticaly = not flipVerticaly

    elif (key == 104) :  # h
        flipHorizontaly = not flipHorizontaly
        flipVerticaly = False
    
    elif (key == 103) :  # g
        bgrToGray = not bgrToGray
        bgrToRgb = False
        bgrToHsv = False
        bgrToLab = False
    
    elif (key == 114) :  # r
        bgrToRgb = not bgrToRgb
        bgrToGray = False
        bgrToHsv  = False
        bgrToLab  = False
    
    elif (key == 108) :  # l
        bgrToLab = not bgrToLab
        bgrToRgb = False
        bgrToHsv  = False
        bgrToGray  = False
    
    elif (key == 115) :  # s
        bgrToHsv = not bgrToHsv
        bgrToRgb = False
        bgrToLab = False
        bgrToGray = False
    
    elif (key == 99) :  # c
        isCroped = not isCroped
    
    elif (key == 98) :  # b
        isBlured = not isBlured
    
def my_resize(frame, scale = 0.25):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

def apply_effect(frame, effect):
    if effect == 'v':
        frame = cv.flip(frame, 0)
    elif effect == 'h':
        frame = cv.flip(frame, 1)
    elif effect == 'r':
        frame = cv.rotate(frame, cv.ROTATE_90_CLOCKWISE)
    elif effect == 'g':
        frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    elif effect == 'b':
        frame = cv.blur(frame, (15, 15))
    elif effect == 'm':
        frame = cv.medianBlur(frame, 15)
    return frame

def handleActions(frame) :
    global flipVerticaly 
    global flipHorizontaly

    global bgrToRgb  
    global bgrToLab  
    global bgrToGray 
    global bgrToHsv  
    global isCroped  
    global isBlured

    if flipVerticaly:
        frame = cv.flip(frame, 0)
    
    elif flipHorizontaly: 
        frame = cv.flip(frame, 1)

    if bgrToGray:
        frame = cv.rotate(frame, cv.ROTATE_90_CLOCKWISE)

    elif bgrToRgb :
        frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    elif bgrToLab :
        frame = cv.blur(frame, (15, 15))
    
    elif bgrToHsv : 
        frame = cv.medianBlur(frame, 15)    
    return frame

def putTexts (frame) :
    current_time = time.strftime('%H:%M:%S', time.localtime())

    cv.putText(frame, f'Time spent: {current_time}', (10, 50), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Flip Vert: v', (10, 80), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Flip Horiz: h', (10, 110), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Bgr to Rgb: r', (10, 140), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Bgr to Hsv: s', (10, 170), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Bgr to Lab: l', (10, 200), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Bgr to Gray: g', (10, 230), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Crop to 410x410: c', (10, 260), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Gaussian blur: b', (10, 290), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)
    cv.putText(frame, 'Esc to close', (10, 320), font, 0.65, (255, 255, 255), 2, cv.LINE_AA)

cap = cv.VideoCapture(0) 
font = cv.FONT_HERSHEY_SIMPLEX

if cap is not None:
    while True:
        isTrue, frame = cap.read() 

        frame = handleActions(frame)
        putTexts(frame)
        cv.imshow("webcam",frame) 


        key = cv.waitKey(100)
        handleKeyPress(key)

        if key == 27:
            break

    cap.release() 
    cv.destroyAllWindows() 


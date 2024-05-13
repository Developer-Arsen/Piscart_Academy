import cv2 as cv

cap = cv.VideoCapture(0)

def faceDetect(image):
    face_cascade = cv.CascadeClassifier("/home/arsen/Piscart_Academy/openCV/haarcascade_frontalface_default.xml")

    faces = face_cascade.detectMultiScale(image, 1.1,10); 
    
    for (x, y, w, h) in faces:
        image = cv.rectangle(image, (x, y), (x+w, y+h), (255, 0, 0), 2)
       

    return image

while True:
    isTrue, frame = cap.read()
    
    frame = faceDetect(frame)
    cv.imshow("test", frame)

    key = cv.waitKey(5)
    if key == 27:
        break


cap.release()
cv.destroyAllWindows()
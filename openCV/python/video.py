import cv2

def main():
    cap = cv2.VideoCapture(0)
    
    if not cap.isOpened():
        print("Error opening video stream")
        return -1

    while True:
        ret, frame = cap.read()

        if not ret:
            print("Failed to grab frame")
            break

        cv2.imshow('Webcam', frame)

        if cv2.waitKey(25) & 0xFF == 27:
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()

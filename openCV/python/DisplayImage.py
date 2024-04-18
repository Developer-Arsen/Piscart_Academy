import cv2
import sys

def main(image_path):
    image = cv2.imread(image_path, cv2.IMREAD_COLOR)
    
    if image is None:
        print("No image data")
        return -1
    
    cv2.namedWindow("Display Image", cv2.WINDOW_AUTOSIZE)
    cv2.imshow("Display Image", image)
    
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python display_image.py <Image_Path>")
        sys.exit(-1)
    
    main(sys.argv[1])

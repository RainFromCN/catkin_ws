import rospy
import cv2
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
import numpy as np
import math

class image_process:
    def __init__(self):
        self.image_pub = rospy.Publisher("cv_bridge_image", Image, queue_size = 1)
        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber("/camera/rgb/image_raw", Image, self.callback)

    def callback(self, data):

        try:
            org = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            print(e)

        org_gray = cv2.cvtColor(org, cv2.COLOR_BGR2GRAY)
        img = cv2.threshold(org_gray, 230, 255, cv2.THRESH_BINARY)[1]

        kernel = np.ones((3, 3), np.uint8)
        img = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernel)

        kernel = np.ones((3, 3), np.uint8)
        img = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)

        img = cv2.Canny(img, 80, 150)

        contours = cv2.findContours(img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[1]

        cnts = []

        for i in range(len(contours)):

            step = 0.01 * cv2.arcLength(contours[i], True)
            epsilon = step

            cnt = contours[i]
            while len(cnt) > 2:

                cnt = cv2.approxPolyDP(contours[i], epsilon, True)
                epsilon += step

            cnts.append(cnt)

        thresh = [1.25, 10]
        feature = []
        pair = []
        feat = []

        for i in range(len(cnts)):
            cnt = cnts[i]
            (p1, p2) = cnt
            (x0, y0) = p1[0]
            (x1, y1) = p2[0]
            
            dy = y0 - y1
            dx = x0 - x1

            length = math.sqrt(dx*dx + dy*dy)

            if abs(dx) > abs(dy):
                continue

            k = dy / dx
            angle = math.atan(k) / math.pi * 180
            if angle < 0:
                angle += 180

            ceny = (y0 + y1) / 2

            feature.append([i, length, angle, ceny])

        for i in range(len(feature) - 1):
            for j in range(i + 1, len(feature)):
                f1 = feature[i]
                f2 = feature[j]

                ok = True

                condi_1 = f1[1] > f2[1] and (f1[1] / f2[1]) < thresh[0]
                condi_2 = f2[1] > f1[1] and (f2[1] / f1[1]) < thresh[0]
                if condi_1 or condi_2:
                    pass
                else:
                    ok = False

                condi_1 = f1[2] > f2[2] and (f1[2] - f2[2]) < thresh[1]
                condi_2 = f2[2] > f1[2] and (f2[2] - f1[2]) < thresh[1]
                if condi_1 or condi_2:
                    pass
                else:
                    ok = False

                length1 = f1[1]
                length2 = f2[1]
                avg_l = (length1 + length2) / 2
                th = avg_l / 5
                cen1 = f1[3]
                cen2 = f2[3]
                condi_1 = cen1 > cen2 and cen1 - cen2 < th
                condi_2 = cen2 > cen1 and cen2 - cen1 < th
                if condi_1 or condi_2:
                    pass
                else:
                    ok = False

                if ok:
                    pair.append([f1[0], f2[0]])
                    feat.append([f1, f2])


        for i in range(len(pair)):
            idxs = pair[i]
            k = idxs[0]
            t = idxs[1]

            cnt = cnts[k]
            (p1, p2) = cnt
            (x1, y1) = p1[0]
            (x2, y2) = p2[0]

            cnt = cnts[t]
            (p1, p2) = cnt
            (x3, y3) = p1[0]
            (x4, y4) = p2[0]

            x = int((x1 + x2 + x3 + x4) / 4)
            y = int((y1 + y2 + y3 + y4) / 4)

            show = org.copy()
            new_cnts = [cnts[k], cnts[t]]
            show = cv2.drawContours(show, new_cnts, -1, (0, 255, 0), 3)
            show = cv2.circle(show, (x, y), 25, (0, 0, 255), 2)
            print "ok"
            cv2.imshow('img', show)
            cv2.waitKey(1000)

        # try:
        #     self.image_pub.publish(self.bridge.cv2_to_imgmsg(cv_image, "bgr8"))
        # except CvBridgeError as e:
        #     print(e)

        

if __name__ == '__main__':
    try:
        rospy.init_node("task1")
        rospy.loginfo("Starting")
        image_process()
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down")
        cv2.destroyAllWindows()
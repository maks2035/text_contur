#include <opencv2/opencv.hpp>

int main() {
   cv::Mat image = cv::imread("D:/virandfpc/b.jpg");

   cv::Mat image_gray;
   cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);

   cv::Mat gauss;
   cv::GaussianBlur(image_gray, gauss, cv::Size(5, 5), 0);

   cv::Mat edges;
   cv::Canny(image_gray, edges, 40, 230); 

   std::vector<std::vector<cv::Point>> contours;
   std::vector<cv::Vec4i> hierarchy;
   cv::findContours(edges, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

   cv::Mat result = cv::Mat::zeros(image.size(), CV_8UC3);
   for (size_t i = 0; i < contours.size(); i++) {
      cv::drawContours(result, contours, i, cv::Scalar(255, 255, 255), 1, cv::LINE_8, hierarchy, 0);
   }

   cv::imshow("image", image);
   cv::imshow("result", result);

   cv::waitKey(0);
   cv::destroyAllWindows();

   return 0;
}
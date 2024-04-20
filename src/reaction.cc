#include <opencv2/opencv.hpp>

int kTrackbarValue = 1000;

void OnTrackbarChange(int value, void* userdata) {
  std::cout << "Trackbar value: " << value << std::endl;
  kTrackbarValue = value + 1;
}

int main(int argc, char** argv) {
  cv::namedWindow("RandomNumbers");
  cv::createTrackbar("", "RandomNumbers", &kTrackbarValue, 3000,
                     OnTrackbarChange);

  int num = 0;
  while (1) {
    cv::Mat image(500, 880, CV_8UC1, cv::Scalar(255));

    const int display_number = rand() % 5 + 1;
    if (num % 2 == 0) {
      cv::putText(image, std::to_string(display_number), cv::Point(100, 350),
                  cv::FONT_HERSHEY_SIMPLEX, 10, cv::Scalar(0), 20);
    } else {
      cv::putText(image, std::to_string(display_number), cv::Point(550, 350),
                  cv::FONT_HERSHEY_SIMPLEX, 10, cv::Scalar(0), 20);
    }

    cv::imshow("RandomNumbers", image);
    int key = cv::waitKey(kTrackbarValue);
    if (key == 27) {
      break;
    }

    ++num;
  }

  cv::destroyAllWindows();
  return 0;
}

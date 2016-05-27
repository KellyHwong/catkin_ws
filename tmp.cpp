#include <cstdio>
#include <iostream>
#include "TagDetector.h"
#include "DebugImage.h"

#define TEST_TAG_FAMILY "Tag36h10"

typedef struct TagTestOptions {
  TagTestOptions() :
      show_debug_info(false),
      show_timing(false),
      show_results(false),
      be_verbose(false),
      no_images(false),
      generate_output_files(false),
      params(),
      family_str(DEFAULT_TAG_FAMILY),
      error_fraction(1){
  }
  bool show_debug_info;
  bool show_timing;
  bool show_results;
  bool be_verbose;
  bool no_images;
  bool generate_output_files;
  TagDetectorParams params;
  std::string family_str;
  double error_fraction;
} TagTestOptions;

int main() {

  TagTestOptions opts;
  opts.family_str = TEST_TAG_FAMILY;
TagFamily family(opts.family_str);
TagDetector detector(family, opts.params);
  TagDetectionArray detections;

  //TODO 把src替换成图片数据
  while (std::max(src.rows, src.cols) > 800) {
    cv::Mat tmp;
    cv::resize(src, tmp, cv::Size(0,0), 0.5, 0.5);
    src = tmp;
  }
  cv::Point2d opticalCenter(0.5*src.rows, 0.5*src.cols);
  detector.process(src, opticalCenter, detections);

    std::cout << "Got " << detections.size() << " detections " << "\n";
      for (size_t i=0; i<detections.size(); ++i) {
        const TagDetection& d = detections[i];
        std::cout << " - Detection: id = " << d.id << ", "
                  << "code = " << d.code << ", "
                  << "rotation = " << d.rotation << "\n";
      }
}

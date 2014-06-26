#ifndef MARKER_TRACKER_H
#define MARKER_TRACKER_H

#include <opencv/cv.h>

struct Marker{
	int code;
	float resultMatrix[16];
};

class CvMemStorage;

class MarkerTracker{
public:
	MarkerTracker(double kMarkerSize_) 
		:	thresh(100),
		bw_thresh(100),
		kMarkerSize(kMarkerSize_)
	{
		init();
	}
	MarkerTracker(double kMarkerSize_, int thresh_, int bw_thresh_) 
		:	thresh(thresh_),
		bw_thresh(bw_thresh_),
		kMarkerSize(kMarkerSize_)
	{
		init();
	}
	~MarkerTracker(){
		cleanup();
	}
	void findMarker( cv::Mat &img_bgr, std::vector<Marker> &markers );
protected:
	void init( );
	void cleanup( );

	//camera settings
	const double kMarkerSize; // Marker size [m]

	cv::Mat img_gray;
	cv::Mat img_mono;

	int thresh; // Threshold (gray to mono)
	int bw_thresh; // threshold for (gray maker to ID image)

	CvMemStorage* memStorage;
};

#endif // MARKER_TRACKER_H

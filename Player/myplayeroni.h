#include"QImage"
#include"OpenNI.h"

class MyPlayerONI{
public:
    int fps = 30;
private:
    openni::Device device;
    openni::PlaybackControl* pb_control;
    openni::VideoStream color_stream;
    openni::VideoStream depth_stream;
    openni::VideoFrameRef color_frame_ref;
    openni::VideoFrameRef depth_frame_ref;

    QImage cur_color_frame_image;
    QImage cur_depth_frame_image;

    bool is_valid = false;
    int max_depth = 5000;
    int cur_frame_index;
    int frame_count;

    QImage toQImageFromRgb(openni::VideoFrameRef colorFrame);

    QImage toQImageFromDepth(openni::VideoFrameRef depthFrame);

public:

    MyPlayerONI();

    ~MyPlayerONI();

    openni::Status LoadFile(QString filename);

    bool isValid();

    void NextFrame();

    void setFrameIndex(int index);

    int getFrameCount();

    QImage getColorFrameImage();

    QImage getDepthFrameImage();

    int getCurentFrameIndex();

    void play();

    void pause();
};

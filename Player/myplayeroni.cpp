#include "myplayeroni.h"

QImage MyPlayerONI::toQImageFromRgb(openni::VideoFrameRef colorFrame) {
    QImage image = QImage((uchar*)(colorFrame.getData()),
                  colorFrame.getWidth(), colorFrame.getHeight(),
                  QImage::Format_RGB888);
    return image;
}

QImage MyPlayerONI::toQImageFromDepth(openni::VideoFrameRef depthFrame) {
    uchar* n_data = (uchar*)(depthFrame.getData());
    int len = depthFrame.getDataSize();
    uchar* data = new uchar[len/2];
    for(int i = 0; i < len; i+=2){
        int k = max_depth - (n_data[i] + n_data[i+1]*256);
        if(k < 0) k = 0;
        data[i/2] = k * 255 / max_depth;
    }
    QImage image= QImage((uchar*)data,
                  depthFrame.getWidth(), depthFrame.getHeight(),
                  QImage::Format_Indexed8);

    delete[] data;
    return image;
}

MyPlayerONI::MyPlayerONI(){
    openni::OpenNI::initialize();
}

MyPlayerONI::~MyPlayerONI(){
    color_stream.stop();
    depth_stream.stop();
    device.close();
    openni::OpenNI::shutdown();
}

openni::Status MyPlayerONI::LoadFile(QString filename){
    color_stream.stop();
    depth_stream.stop();
    device.close();
    is_valid = false;

    openni::Status rc = device.open(filename.toStdString().c_str());

    if(rc == openni::Status::STATUS_OK)
    {
        is_valid = true;
        pb_control = device.getPlaybackControl();
        color_stream.create (device, openni::SENSOR_COLOR);
        depth_stream.create (device, openni::SENSOR_DEPTH);

        max_depth = depth_stream.getMaxPixelValue();

        pb_control->setSpeed(-1);
        fps = color_stream.getVideoMode().getFps();
        frame_count = pb_control->getNumberOfFrames(color_stream);

        color_stream.start();
        depth_stream.start();

        NextFrame();
    }
    return rc;
}

bool MyPlayerONI::isValid(){
    return is_valid;
}

void MyPlayerONI::NextFrame(){
    color_stream.readFrame (&color_frame_ref);
    depth_stream.readFrame (&depth_frame_ref);

    cur_frame_index = color_frame_ref.getFrameIndex();

    QImage temp = cur_color_frame_image;
    cur_color_frame_image = toQImageFromRgb(color_frame_ref);
    if(temp.isNull() == false)
        temp.~QImage();

    temp = cur_depth_frame_image;
    cur_depth_frame_image = toQImageFromDepth(depth_frame_ref);
    if(temp.isNull() == false)
        temp.~QImage();
}

void MyPlayerONI::setFrameIndex(int index){
    if(index <= 1)
    {
        index = frame_count ;
        pb_control->seek(color_stream, index);
        NextFrame();
        NextFrame();
    }
    else{
        pb_control->seek(color_stream, index);
        NextFrame();
    }
}

int MyPlayerONI::getFrameCount(){
    return frame_count;
}

QImage MyPlayerONI::getColorFrameImage(){
    return cur_color_frame_image;
}

QImage MyPlayerONI::getDepthFrameImage(){
    return cur_depth_frame_image;
}

int MyPlayerONI::getCurentFrameIndex(){
    return cur_frame_index;
}

void MyPlayerONI::play(){
    pb_control->setSpeed(1);
}

void MyPlayerONI::pause(){
    pb_control->setSpeed(-1);
}

#include<OpenNI.h>
#include<QObject>

class SignalFrameListener: public QObject, public openni::VideoStream::NewFrameListener
{
public:
    SignalFrameListener(QObject* mw){
        connect(this,SIGNAL(colorFrameReady()),mw,SLOT(onNewColorFrame()));
        connect(this,SIGNAL(depthFrameReady()),mw,SLOT(onNewDepthFrame()));
    }

    void onNewFrame(openni::VideoStream& stream){
        colorFrameReady();
    }
signals:
    void colorFrameReady();
    void depthFrameReady();
};

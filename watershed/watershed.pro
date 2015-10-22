#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T11:23:32
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = watershed
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
INCLUDEPATH+=E:/opencv/build/include

win32:CONFIG(debug, debug|release): {
LIBS += -LE:/opencv/build/x86/vc11/lib \
-lopencv_core2410d \
-lopencv_imgproc2410d \
-lopencv_highgui2410d \
-lopencv_ml2410d \
-lopencv_video2410d \
-lopencv_features2d2410d \
-lopencv_calib3d2410d \
-lopencv_objdetect2410d \
-lopencv_contrib2410d \
-lopencv_legacy2410d \
-lopencv_flann2410d
} else:win32:CONFIG(release, debug|release): {
LIBS += -LE:/opencv/build/x86/vc11/lib \
-lopencv_core2410 \
-lopencv_imgproc2410 \
-lopencv_highgui2410 \
-lopencv_ml2410 \
-lopencv_video2410 \
-lopencv_features2d2410 \
-lopencv_calib3d2410 \
-lopencv_objdetect2410 \
-lopencv_contrib2410 \
-lopencv_legacy2410 \
-lopencv_flann2410
}

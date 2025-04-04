QT += core gui widgets charts

TARGET = Fitts

TEMPLATE = app

CONFIG += c++11

SOURCES += \
	main.cpp \
	view/fittsview.cpp \
	controller/fittscontroller.cpp \
	model/fittsmodel.cpp \
	view/graphicwidget.cpp \
	model/keystrokemodel.cpp \
	view/zoomablechartview.cpp

HEADERS += \
	view/fittsview.h \
	controller/fittscontroller.h \
	model/fittsmodel.h \
	view/graphicwidget.h \
	model/keystrokemodel.h \
	view/zoomablechartview.h

INCLUDEPATH += \
	$$PWD/view \
	$$PWD/controller \
	$$PWD/model

RC_ICONS = res/app.ico

RESOURCES += qtresources.qrc

QMAKE_CXXFLAGS += -Wno-deprecated-declarations

DISTFILES += \
    .gitignore

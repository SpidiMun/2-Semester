QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addwindow.cpp \
    deletewindow.cpp \
    editwindow.cpp \
    main.cpp \
    myglwidget.cpp \
    mypainter.cpp \
    qtwindow.cpp

HEADERS += \
    addwindow.h \
    deletewindow.h \
    editwindow.h \
    myglwidget.h \
    mypainter.h \
    qtwindow.h

FORMS += \
    addwindow.ui \
    deletewindow.ui \
    editwindow.ui \
    qtwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Matrix.txt \
    MatrixCreation.exe \
    MatrixSize.txt \
    run.bat

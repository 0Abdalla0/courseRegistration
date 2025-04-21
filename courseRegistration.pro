QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    course.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    registercourse.cpp \
    signup.cpp \
    student.cpp

HEADERS += \
    course.h \
    loginwindow.h \
    mainwindow.h \
    registercourse.h \
    signup.h \
    student.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminpage.cpp \
    checkprerequisites.cpp \
    course.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    managegrades.cpp \
    registercourse.cpp \
    setprerequisites.cpp \
    signup.cpp \
    student.cpp \
    studentpage.cpp \
    uploadcourse.cpp \
    viewgrades.cpp

HEADERS += \
    admin.h \
    adminpage.h \
    checkprerequisites.h \
    course.h \
    loginwindow.h \
    mainwindow.h \
    managegrades.h \
    registercourse.h \
    setprerequisites.h \
    signup.h \
    student.h \
    studentpage.h \
    uploadcourse.h \
    viewgrades.h

FORMS += \
    adminpage.ui \
    checkprerequisites.ui \
    loginwindow.ui \
    mainwindow.ui \
    managegrades.ui \
    setprerequisites.ui \
    signup.ui \
    studentpage.ui \
    uploadcourse.ui \
    viewgrades.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

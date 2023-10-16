QT = core
CONFIG += c++17 cmdline

TARGET = Email
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

sourcepath="../src"

OBJECTS_DIR += ./objects/
MOC_DIR     += ./moc/
RCC_DIR     += ./rcc/
UI_DIR      += ./ui/

linux {
    QMAKE_CXXFLAGS += -std=c++17
}
else:win32 {
    LIBS += -lws2_32
}

sourcepath="../src"
includepath="../../simple-mail/src"

INCLUDEPATH += $$includepath

SOURCES +=  $$sourcepath/main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../simple-mail/build/src -lSimpleMail2Qt6
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../simple-mail/build/src -lSimpleMail2Qt6
else:unix: LIBS += -L$$PWD/../../simple-mail/build/src -lSimpleMail2Qt6

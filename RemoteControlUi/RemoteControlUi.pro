TEMPLATE = app

QT += qml quick
CONFIG += c++11

HEADERS += *.h
SOURCES += *.cpp
RESOURCES += *.qrc

# Used for SharedLibrary
debug:  BUILDMODE = debug
!debug: BUILDMODE = release
lib.path = $$OUT_PWD
lib.files += ../../../../RemoteControlLib/build/$$BUILDMODE/libRemoteControl.so
INSTALLS += lib
INCLUDEPATH += ../RemoteControlLib/include
LIBS += -L../../../../RemoteControlLib/build/$$BUILDMODE -lRemoteControl -Wl,-rpath=.

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

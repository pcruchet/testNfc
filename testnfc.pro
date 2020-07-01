QT += nfc widgets

CONFIG += strict_flags

TARGET = testnfc

SOURCES += main.cpp \
    lecteurnfc.cpp \
    mainwindow.cpp

HEADERS  += mainwindow.h \
    lecteurnfc.h

FORMS    += mainwindow.ui

target.path = $$[QT_INSTALL_EXAMPLES]/nfc/testnfc
INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

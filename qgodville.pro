######################################################################
# Automatically generated by qmake (2.01a) ?? ???? 26 22:54:26 2012
######################################################################

TEMPLATE = app
TARGET =
CONFIG += static
QT += core gui network maemo5

# Input
HEADERS += Godville.h \
           settingsdialog.h \
           parser.h
SOURCES += Godville.cpp \
           main.cpp \
           settingsdialog.cpp \
           parser.cpp
TRANSLATIONS = qgodville_en.ts
CODECFORTR = UTF-8

unix {
   INSTALLS += target desktop icon48 transl
   target.path = /usr/bin/qgodville
   desktop.path = /usr/share/applications/hildon
   desktop.files += maemofiles/qgodville.desktop
   icon48.path = /usr/share/icons/hicolor/48x48/apps
   icon48.files += maemofiles/qgodville.png
   transl.path = /usr/bin/qgodville
   transl.files += qgodville_en.qm
}

#-------------------------------------------------
#
# Project created by QtCreator 2018-07-07T17:16:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VCL
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++1z

QMAKE_CXXFLAGS += -std=gnu++17

SOURCES += \
        sourcefiles/config_manager.cpp \
        sourcefiles/custom_delegate.cpp \
        sourcefiles/dialog_diff_apply.cpp \
        sourcefiles/dialog_diff_gen.cpp \
        sourcefiles/dialog_settings.cpp \
        sourcefiles/diff_generator.cpp \
        sourcefiles/diff_model.cpp \
        sourcefiles/main.cpp \
        sourcefiles/main_window.cpp \
        sourcefiles/modified_file_system_model.cpp \
        sourcefiles/settings_model.cpp

HEADERS += \
        headerfiles/config_manager.h \
        headerfiles/custom_delegate.h \
        headerfiles/data_objects.h \
        headerfiles/dialog_diff_apply.h \
        headerfiles/dialog_diff_gen.h \
        headerfiles/dialog_settings.h \
        headerfiles/diff_generator.h \
        headerfiles/diff_model.h \
        headerfiles/main_window.h \
        headerfiles/modified_file_system_model.h \
        headerfiles/settings_model.h

UI_DIR = GeneratedFiles/

RESOURCES = resource.qrc

FORMS += \
        mainwindow.ui \
        dialog_diffApply.ui \
        dialog_diffGen.ui \
        dialog_settings.ui \
        dialog_settings_color.ui \
		dialog_settings_command.ui

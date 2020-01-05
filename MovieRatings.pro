
QT       += core gui
QT       += core sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MovieRatings
TEMPLATE = app


SOURCES += main.cpp\
        home.cpp \
    adminlogin.cpp \
    admin_page.cpp \
    bollywood.cpp \
    movie_info.cpp

HEADERS  += home.h \
    adminlogin.h \
    admin_page.h \
    bollywood.h \
    movie_info.h

FORMS    += home.ui \
    adminlogin.ui \
    admin_page.ui \
    bollywood.ui \
    movie_info.ui

RESOURCES +=

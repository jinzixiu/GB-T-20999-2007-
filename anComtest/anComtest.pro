DEFINES += QT_ADDON_SERIALPORT_LIB
#include(../app.pri)
include(./qtserialport/src/qtserialport.pri)

INCLUDEPATH += $$PWD

OTHER_FILES += \
#    a2d.pri

HEADERS += \
    mainwindow.h \
    unit.h \
    cpubsub.h \
    dlgpubparm.h \
    dlgtimebase.h \
    dlgphaseparm.h \
    dlgtimeinterval.h \
    dialogchanneltab.h \
    #dlgtimeplan.h \
    dialogtimeplan.h \
    dialogcontrlparm.h \
    dlgshowswitch.h \
    dialogphasetiming.h \
    dialogunitparm.h \
    dialogphasestatus.h \
    dialogphaseconflict.h \
    dialogparmrun.h \
    dialogmodel.h \
    dialogflowphase.h \
    dialogcartest.h \
    dialogevent.h \
    time.h \
    dlgstatus.h

SOURCES += \  
    main.cpp \
    mainwindow.cpp \
    unit.cpp \
    cpubsub.cpp \
    dlgpubparm.cpp \
    dlgtimebase.cpp \
    dlgphaseparm.cpp \
    dlgtimeinterval.cpp \
    dialogchanneltab.cpp \
    #dlgtimeplan.cpp \
    dialogtimeplan.cpp \
    dialogcontrlparm.cpp \
    dlgshowswitch.cpp \
    dialogphasetiming.cpp \
    dialogunitparm.cpp \
    dialogphasestatus.cpp \
    dialogphaseconflict.cpp \
    dialogparmrun.cpp \
    dialogmodel.cpp \
    dialogflowphase.cpp \
    dialogcartest.cpp \
    dialogevent.cpp \
    time.cpp \
    dlgstatus.cpp

FORMS += \
    mainwindow.ui \
    dlgpubparm.ui \
    dlgtimebase.ui \
    dlgphaseparm.ui \
    dlgtimeinterval.ui \
    dialogchanneltab.ui \
    #dlgtimeplan.ui \
    dialogtimeplan.ui \
    dialogcontrlparm.ui \
    dlgshowswitch.ui \
    dialogphasetiming.ui \
    dialogunitparm.ui \
    dialogphasestatus.ui \
    dialogphaseconflict.ui \
    dialogparmrun.ui \
    dialogmodel.ui \
    dialogflowphase.ui \
    dialogcartest.ui \
    dialogevent.ui \
    dlgstatus.ui
RC_FILE = myapp.rc

RESOURCES += \
    myrs.qrc

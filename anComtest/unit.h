#ifndef UNIT_H
#define UNIT_H

#include <QMessageBox.h>
#include <QWidget>
#include <QLabel>
#include <QCloseEvent>
void isComOpen(QWidget* parm,bool flag);
unsigned short  CommVerify(unsigned char * checksource,unsigned short  length);
void message(QWidget *who,const char *title,const char *neirong);
void messagelab(QLabel *who,const char *title);



#endif // UNIT_H

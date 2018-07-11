#include "widget.h"
#include <QtWidgets>

PeopVSPeop *peopVSpeop;
Widget::Widget(QWidget *parent) : QWidget(parent) {
  QPalette palette;
  QPixmap pixmap(":/resource/image/timg.jpeg");
  pixmap.scaledToWidth(640);
  pixmap.scaledToHeight(1260);
  palette.setBrush(QPalette::Background, QBrush(pixmap));
  setPalette(palette);
  setFixedSize(pixmap.size());

  //aPeopVSPeop = new PeopVSPeop();

  comVSpeoButton = new QPushButton(QString::fromUtf8("人机对战"), this);
  comVSpeoButton->setGeometry(250, 200, 160, 80);
  //peoVSpeoButton = new QPushButton(QString::fromUtf8("双人对战"), this);
  //peoVSpeoButton->setGeometry(300, 260, 160, 80);
  fullScreenButton = new QPushButton(QString::fromUtf8("全屏显示"), this);
  fullScreenButton->setGeometry(250, 300, 160, 80);
  exitFullScreenButton = new QPushButton(QString::fromUtf8("退出全屏"), this);
  exitFullScreenButton->setGeometry(250, 400, 160, 80);

  connect(comVSpeoButton, SIGNAL(clicked()), this, SLOT(pushComBttn()));
  //connect(peoVSpeoButton, SIGNAL(clicked()), this, SLOT(pushPeoBttn()));
  connect(fullScreenButton, SIGNAL(clicked()), this, SLOT(full_screen_slot()));
  connect(exitFullScreenButton, SIGNAL(clicked()), this,
          SLOT(exit_full_scen_slot()));
}

void Widget::pushComBttn() {
  PeopVSComp aPeopVSComp;
  aPeopVSComp.exec();
}
void Widget::pushPeoBttn() {
  //peopVSpeop = new PeopVSPeop();
  //peopVSpeop = dynamic_cast<PeopVSPeop *>(aPeopVSPeop->window());
  ///qDebug() << "in widget:" << peopVSpeop;
  //aPeopVSPeop->exec();
}

void Widget::full_screen_slot() { this->showFullScreen(); }

void Widget::exit_full_scen_slot() {
  this->setMinimumSize(700, 700);
  this->showNormal();
}

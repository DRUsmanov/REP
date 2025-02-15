#include "mywindowwithimage.h"
#include "ui_mywindowwithimage.h"
#include <QCoreApplication>

MyWindowWithImage::MyWindowWithImage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindowWithImage)
{
    ui->setupUi(this);
    QString absolute_path_file = QCoreApplication::applicationDirPath() + "/images/i-love-qt.png";
    SetPixmap(ui->lbl_pixmap, absolute_path_file);
}

MyWindowWithImage::~MyWindowWithImage()
{
    delete ui;
}

void MyWindowWithImage::SetPixmap(QLabel *label_pix, const QString path) {
    QPixmap pix{path};

    // Убедимся, что изображение загрузилось.
    Q_ASSERT(!pix.isNull());

    label_pix->setPixmap(pix);
}

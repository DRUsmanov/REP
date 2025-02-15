#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString image_path = ":/images/images/i-love-qt.png";
    SetPixmap(ui->lbl_pixmap, image_path);
    UpdateSizeLabel();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetPixmap(QLabel *label_pix, const QString path)
{
    // Тут нужно вызвать FitToImage.
    // Подумайте, в каком месте метода это лучше сделать.
    QPixmap pix(path);
    Q_ASSERT(!pix.isNull());
    label_pix->setPixmap( pix );
    FitToImage(label_pix);
    label_pix->show();
}

void MainWindow::FitToImage(QLabel *label){
    QPixmap pix = label->pixmap();
    auto width_pix=pix.width();
    auto heigh_pix=pix.height();
    label->setFixedSize(width_pix, heigh_pix);
    this->setFixedSize(width_pix, heigh_pix);
    label->move(0, 0);
}

void MainWindow::UpdateSizeLabel() {
    auto new_text = std::to_string(this->width()) + "x" + std::to_string(this->height());
    ui->lbl_size->setText(QString::fromStdString(new_text));
}






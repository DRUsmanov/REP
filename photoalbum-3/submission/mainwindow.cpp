#include "mainwindow.h"
#include "ui_mainwindow.h"

// Функция подгоняет изображение под нужный размер окна.
QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if ( w_ratio < h_ratio ) {
        return src.scaledToWidth(window_width);
    } else {
        return src.scaledToHeight(window_height);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetFolder(":/cats/images/");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    Q_ASSERT(!active_pixmap.isNull());

    int window_width=this->width();
    int window_height=this->height();

    // Напишите этот метод.
    // 1. Вызовите ResizeImgToFit.
    QPixmap new_image = ResizeImgToFit(active_pixmap, window_width, window_height);
    // 2. Поместите изображение в lbl_img.
    lbl_new_.setPixmap(new_image);
    // 3. Измените размер lbl_img.
    lbl_new_.resize(new_image.width(),new_image.height());
    // 4. Переместите lbl_img, пользуясь формулами из условия.
    lbl_new_.move((this->width()-new_image.width())/2,(this->height()-new_image.height())/2);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}

QString MainWindow::GetCurrentFile() {
    QDir dir(current_folder_);
    QStringList list = dir.entryList();
    int total=int(list.size());
    int file_index=std::min(cur_file_index_, total-1);
    file_index=std::max(0, file_index);
    return dir.filePath(list[file_index]);
}

void MainWindow::SetFolder(const QString& d){
    cur_file_index_=0;
    current_folder_=d;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}

void MainWindow::UpdateEnabled(){
    int total=QDir(current_folder_).entryInfoList().size();
    ui->btn_left->setEnabled(cur_file_index_>0);
    ui->btn_right->setEnabled(cur_file_index_<total-1);
}
void MainWindow::on_btn_left_clicked()
{
    cur_file_index_-=1;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}


void MainWindow::on_btn_right_clicked()
{
    cur_file_index_+=1;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}


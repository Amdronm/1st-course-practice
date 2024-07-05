#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QColorDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    brush = new QBrush;
    brush->setStyle(Qt::SolidPattern);
    color = Qt::green;
    pen = new QPen;
    pen->setWidth(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt");
    ReadFile(file_name);
}

void MainWindow::ReadFile(const QString &file_name)
{
    v.clear();
    std::ifstream fin(file_name.toStdString());
    int i;
    while (fin >> i) {
        if (maxx < i) {
            maxx = i;
        }
        v.push_back(i);
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter pain(this);
    pain.begin(this);
    brush->setColor(color);
    pain.setBrush(*brush);
    pain.setPen(*pen);
    float x = 0, y = 0, w, h;
    h = (v.size() == 0) ? 0 : (this->height() / v.size());
    float wid = this->width() - 400;
    float ww = this->width() / maxx;
    for (size_t i = 0; i < v.size(); i++) {
        w = ww * v[i];
        pain.drawRect(QRectF(x, y, w, h));
        y += h;
    }
    pain.end();
}

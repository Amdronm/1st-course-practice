#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pen.setColor(QColorConstants::Svg::violet);
    pen.setWidth(4);
    pen.setStyle(Qt::SolidLine);
    font.setPointSize(24);
    font.setBold(true);
    size = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    std::vector<int> v = stack.toVector();
    QPainter pain(this);
    pain.begin(this);
    pain.setBrush(QBrush(Qt::NoBrush));
    pain.setPen(pen);
    pain.setFont(font);
    int x = 200, y = 0, w = 100, h;
    h = (size == 0) ? 0 : (this->height() / size);
    for (int i = 0; i < size; i++) {
        pain.drawRect(QRect(x, y, w, h));
        pain.drawText(x, y, w, h, Qt::AlignCenter, QString::number(v[i]));
        y += h;
    }
    pain.end();
}

void MainWindow::on_pushButtonPush_clicked()
{
    int i = ui->ioput->text().toInt();
    stack.push(i);
    size++;
    ui->ioput->clear();
    this->update();
}


void MainWindow::on_pushButtonPop_clicked()
{
    if (stack.isEmpty()) {
        return;
    } else {
        ui->ioput->setText(QString::number(stack.pop()));
        size--;
    }
    this->update();
}


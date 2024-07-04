#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    brush = new QBrush;
    brush->setStyle(Qt::SolidPattern);
    color = QColorConstants::Svg::violet;
    pen = new QPen;
    pen->setStyle(Qt::NoPen);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    float ww = (this->width() - 350) / maxx;
    for (size_t i = 0; i < v.size(); i++) {
        w = ww * v[i];
        pain.drawRect(QRectF(x, y + h / 4, w, h / 2));
        y += h;
    }
    pain.end();
}

void MainWindow::on_buttonLoad_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.json");
    std::ifstream fin(file_name.toStdString());
    if (!fin.is_open()) {
        return;
    }
    jjj = nlohmann::json::parse(fin);
    upd();
    this->update();
}

void MainWindow::on_buttonAdd_clicked()
{
    jjj[ui->inKey->text().toStdString()] = ui->inValue->text().toInt();
    v.push_back(ui->inValue->text().toInt());
    upd();
    this->update();
}

void MainWindow::on_buttonSave_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.json");
    std::ofstream fout(file_name.toStdString());
    fout << jjj.dump(4);
}

void MainWindow::upd()
{
    v.clear();
    for (const auto &i : jjj) {
        v.push_back(i);
    }
    maxx = *std::max_element(v.begin(), v.end());
}

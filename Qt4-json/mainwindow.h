#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QPainter>

#include <fstream>

#include "json.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_buttonLoad_clicked();

    void on_buttonAdd_clicked();

    void on_buttonSave_clicked();

private:
    Ui::MainWindow *ui;
    QColor color;
    QBrush *brush;
    QPen *pen;
    std::vector<int> v{};
    nlohmann::json jjj;
    int maxx;

    void upd();
};
#endif // MAINWINDOW_H

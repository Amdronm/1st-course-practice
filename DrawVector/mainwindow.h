#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*Задание 1. Для заданного вектора натуральных чисел нарисовать вертикальную гистограмму. Размер и элементы вектора вводятся из текстового файла (std::ifstream).
Задание 2. Нарисовать кораблик, который может поднимать флаг, сделать анимацию воды(упрощенно, как в детском рисунке).*/

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <vector>

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
    void ReadFile(const QString &);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_openFileButton_clicked();

private:
    Ui::MainWindow *ui;
    QColor color;
    QBrush *brush;
    QPen *pen;
    std::vector<int> v{};
    int maxx;
};

#endif // MAINWINDOW_H

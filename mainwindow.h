#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_generate_image();
    void on_reset_image();

signals:
    void generate_image();
    void reset_image();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef MYPAINTEDWIDGET_H
#define MYPAINTEDWIDGET_H

#include <QWidget>

class MyPaintedWidget : public QWidget
{
    Q_OBJECT
public:
    MyPaintedWidget();

    virtual void paintEvent(QPaintEvent *event) override;

public slots:
    void wipe_image();
    void generate_pattern();

private:
    QImage *my_image;
};

#endif // MYPAINTEDWIDGET_H

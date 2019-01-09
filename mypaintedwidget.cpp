#include "mypaintedwidget.h"

#include <QPainter>
#include <QImage>


MyPaintedWidget::MyPaintedWidget() :
    QWidget ()
{
    // Start with an empty image so the user can click the menu option to generate the actual pattern, like the button in the original question.
    my_image = new QImage(512, 512, QImage::Format_RGBA8888);
    my_image->fill(QColor(255,255,255,255));
}

void MyPaintedWidget::paintEvent(QPaintEvent *event)
{
    // Qt has invoked this method.  We never call it ourself.

    // Only ever make one QPainter object per paintEvent.  Managing multiple QPainter objects is a bunch of extra overhead, and hard to do correctly.
    auto p = new QPainter;

    p->begin(this);

    // We prepared the image to be drawn in advance, so we can just draw it in a single command instead of plotting every point.
    // It could be faster to redraw if we stored the final image on the GPU memory instead of resubmitting it each time, but for this use case, this is plenty fast.
    // One command that does a single round trip to the GPU is pretty quick, unless it's an 8k image that we are trying to draw at 120 fps or something extreme like that.
    p->drawImage(0,0, *my_image);

    // Always remember to clean up when you are done.
    p->end();

    delete p;

}

void MyPaintedWidget::wipe_image()
{
    my_image->fill(QColor(255,255,255,255));

    // Don't try to directly do the painting of the widget here!
    // Calling update() tells Qt that it'll need to do a repaint when it's convenient.
    // Qt will handle the details of when to actually call the paint function.
    update();
}

void MyPaintedWidget::generate_pattern()
{

    // This isn't specifically the Game of Life, but could be any pattern generation you want.
    for (int i=0; i< 512; i += 10) {
        for (int j=0; j< 512; j+= 10) {
            QColor c(i%255, j%255, 128, 255);
            my_image->setPixelColor(i, j, c);
        }
    }


    // Same as in wipe_image() -- we changed the image, so we need to tell Qt that the GUI needs to be redrawn.
    // But don't try to directly paint on the widget here!
    update();
}

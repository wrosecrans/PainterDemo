#include "mainwindow.h"
#include <QApplication>
#include "mypaintedwidget.h"
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Main window is generated in the GUI designer
    MainWindow w;

    // My Painted Widget is a custom widget we implemented ourselves.
    auto mpw = new MyPaintedWidget;
    w.setCentralWidget(mpw);

    // Now the designed widget in the form has the custom widget all in one happy window.

    // Connect up the relevant signals and slots that I didn't bother to name consistently because this is mostly a painter example
    mpw->connect( &w, SIGNAL(generate_image()), mpw, SLOT(generate_pattern()) );
    mpw->connect( &w, SIGNAL(reset_image()), mpw, SLOT(wipe_image()) );
    // Now the menu is the designer UI is wired to the custom code, and you can resize the window interactively and it'll look right and do what you want.

    w.show();

    return a.exec();
}

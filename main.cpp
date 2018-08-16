#include <QApplication>
#include "display.h"
#include "camera.h"


#include <string>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Camera camera;
    camera.show();

    Display w;
    w.show();

    return a.exec();
}

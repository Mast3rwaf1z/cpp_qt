#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <list>
#include <QLayout>
#include <QBoxLayout>
#include <math.h>
using namespace std;


int* get_coordinate(int x, int y, int r, int i, int n){
    int* result = (int*) malloc(sizeof(int));
    if(x<M_PI){
        result[0] = x-(r*sin((i*2*M_PI)/n));
        result[1] = y-(r*cos((i*2*M_PI)/n));
    }
    else{
        result[0] = x-(r*-sin((i*2*M_PI)/n));
        result[1] = y-(r*cos((i*2*M_PI)/n));
    }
    
    return result;
}

int main(int argc, char *argv[]){
    int width = 960;
    int height = 540;
    int button_count = 10;
    int button_size = 100;
    QApplication app(argc, argv);
    QWidget* window = new QWidget();
    window->setGeometry(0, 0, width, height);

    for (int i = 1; i < button_count+1; i++){
        int* coordinates = get_coordinate((width/2)-(button_size/2), (height/2)-(button_size/2), (height/2)-button_size/2, i, button_count);
        int x = coordinates[0];
        int y = coordinates[1];
        QPushButton* button = new QPushButton(("Button " + to_string(i)).c_str(), window);
        app.connect(button, &QPushButton::clicked, &app, [=]{
            cout << "button " << i << " pressed!" << endl;
            int x = button->geometry().x();
            int y = button->geometry().y();
            int randx = -100 + (rand() % (100 - (-100) + 1));
            int randy = -100 + (rand() % (100 - (-100) + 1));
            button->move(x+randx, y+randy);
            });
        button->setGeometry(x, y, button_size, button_size);
    }

    
    window->setWindowIcon(QIcon("icon.ico"));
    window->setWindowTitle("Ring Topology");
    window->show();
    return app.exec();
}
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <string>
#include <list>
using namespace std;


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget window(NULL);
    int size = 10;
    QLabel* label = new QLabel("", &window);

    QVBoxLayout* outer_layout = new QVBoxLayout;
    outer_layout->addWidget(label);
    for (int i = 0; i < size*size; i = i + size){
        QHBoxLayout* layout = new QHBoxLayout;
        for(int j = 0; j < size; j++){
            QPushButton* button = new QPushButton(to_string(i+j).c_str());
            app.connect(button, &QPushButton::clicked, &app, [=]{label->setText(("Button " + to_string(i+j)).c_str());});
            layout->addWidget(button);
        }
        outer_layout->addItem(layout);
    }
    window.setLayout(outer_layout);
    window.setWindowTitle(("Button matrix of " + to_string(size*size) + " buttons").c_str());
    window.setWindowIcon(QIcon("icon.ico"));
    
    window.show();
    return app.exec();
}
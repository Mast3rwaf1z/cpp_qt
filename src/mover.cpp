#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <iostream>
using namespace std;


void move_mover(QWidget* mover, string direction, int distance){
    cout << "moving " << distance << "px in direction " << direction << endl;
    if(direction == "left"){
            mover->move(mover->x()-distance, mover->y());     
    }
    else if(direction == "up"){
            mover->move(mover->x(), mover->y()-distance);     
    }
    else if(direction == "down"){
            mover->move(mover->x(), mover->y()+distance);     
    }
    else if(direction == "right"){
            mover->move(mover->x()+distance, mover->y());     
    }
}

int main(int argc, char* argv[]){
    int width = 960;
    int height = 540;
    int distance = 100;
    int* distance_ptr = &distance;
    QApplication app(argc, argv);
    QWidget* window = new QWidget();
    window->setGeometry(0,0,width,height);
    QWidget* mover = new QWidget(window);
    QPalette palette = QPalette();
    palette.setColor(QPalette::Window, Qt::white);
    mover->setAutoFillBackground(true);
    mover->setPalette(palette);
    mover->setGeometry(width/2, height/2, width/5, height/5);
    QHBoxLayout* h_layout = new QHBoxLayout();
    QPushButton* left = new QPushButton("Left");
    app.connect(left, &QPushButton::clicked, &app, [mover, &distance] {
        move_mover(mover, "left", distance);
    });
    QPushButton* up = new QPushButton("Up");
    app.connect(up, &QPushButton::clicked, &app, [mover, &distance] {
        move_mover(mover, "up", distance);
    });
    QPushButton* down = new QPushButton("Down");
    app.connect(down, &QPushButton::clicked, &app, [mover, &distance] {
        move_mover(mover, "down", distance);
    });
    QPushButton* right = new QPushButton("Right");
    app.connect(right, &QPushButton::clicked, &app, [mover, &distance] {
        move_mover(mover, "right", distance);
    });
    QVBoxLayout* v_layout = new QVBoxLayout();

    v_layout->addWidget(up);
    v_layout->addWidget(down);

    h_layout->addWidget(left);
    h_layout->addItem(v_layout);
    h_layout->addWidget(right);

    mover->setLayout(h_layout);
    mover->show();

    QLineEdit* distance_entry = new QLineEdit(to_string(distance).c_str());
    QLabel* distance_label = new QLabel("Distance");
    QPushButton* set_distance = new QPushButton("Set distance");
    app.connect(set_distance, &QPushButton::clicked, &app, [&distance, distance_entry] {
        cout << "set distance from " << distance;
        distance = distance_entry->text().toInt();
        cout << "px to " << distance << "px" << endl;
    });
    QWidget* distance_widget = new QWidget(window);
    QHBoxLayout* distance_layout = new QHBoxLayout();
    distance_layout->addWidget(distance_label);
    distance_layout->addWidget(distance_entry);
    distance_layout->addWidget(set_distance);
    distance_widget->setLayout(distance_layout);
    distance_widget->show();

    window->show();
    return app.exec();
}
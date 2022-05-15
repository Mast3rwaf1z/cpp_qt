#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QWidget* window = new QWidget();
    QVBoxLayout* main_layout = new QVBoxLayout();
    QHBoxLayout* top_labels = new QHBoxLayout();
    QLabel* username_label = new QLabel("Username");
    QLabel* password_label = new QLabel("Password");
    QLabel* target_label = new QLabel("Target");
    QLabel* port_label = new QLabel("Port");
    top_labels->addWidget(username_label);
    top_labels->addWidget(password_label);
    top_labels->addWidget(target_label);
    top_labels->addWidget(port_label);

    QHBoxLayout* entry_fields = new QHBoxLayout();
    QLineEdit* username_field = new QLineEdit("mast3r");
    QLineEdit* password_field = new QLineEdit("");
    QLineEdit* target_field = new QLineEdit("skademaskinen.win");
    QLineEdit* port_field = new QLineEdit("41317");
    entry_fields->addWidget(username_field);
    entry_fields->addWidget(password_field);
    entry_fields->addWidget(target_field);
    entry_fields->addWidget(port_field);

    QPushButton* button = new QPushButton("Connect");
    app.connect(button, &QPushButton::clicked, &app, [=]{
        string username = username_field->text().toStdString();
        string password = password_field->text().toStdString();
        string target = target_field->text().toStdString();
        string port = port_field->text().toStdString();
        window->close();
        system(("konsole -e sshpass -p" + password + " ssh " + username + "@" + target +" -p " + port).c_str());
    });


    main_layout->addItem(top_labels);
    main_layout->addItem(entry_fields);
    main_layout->addWidget(button);
    
    window->setLayout(main_layout);
    window->show();
    return app.exec();
}
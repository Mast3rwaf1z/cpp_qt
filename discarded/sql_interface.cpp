#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <string>
#include <mysql++/mysql++.h>
using namespace mysqlpp;

void init_db(QString server, QString user, QString pass){
    const char* s = (char*) server.toStdString().c_str();
    const char* u = (char*) user.toStdString().c_str();
    const char* p = (char*) pass.toStdString().c_str();
    Connection connection("", s, u, p);

}

int main(int argc, char *argv[]){
    QApplication *app = new QApplication(argc, argv);
    QWidget *window = new QWidget();
    QVBoxLayout *main_layout = new QVBoxLayout();
    QLabel *header = new QLabel("SQL Interface");
    main_layout->addWidget(header);
    QHBoxLayout *credentials_titles = new QHBoxLayout();
    QLabel *username_label = new QLabel("Username");
    QLabel *password_label = new QLabel("Password");
    QLabel *host_label = new QLabel("Host");
    credentials_titles->addWidget(username_label);
    credentials_titles->addWidget(password_label);
    credentials_titles->addWidget(host_label);
    main_layout->addItem(credentials_titles);
    QHBoxLayout *credentials_panel = new QHBoxLayout();
    QLineEdit *username = new QLineEdit("");
    QLineEdit *password = new QLineEdit("");
    QLineEdit *host = new QLineEdit("");
    credentials_panel->addWidget(username);
    credentials_panel->addWidget(password);
    credentials_panel->addWidget(host);
    main_layout->addItem(credentials_panel);
    QPushButton *connect_button = new QPushButton("Connect");
    main_layout->addWidget(connect_button);
    app->connect(connect_button, &QPushButton::clicked, app, [=]{init_db(host->text(), username->text(), password->text());});

    window->setLayout(main_layout);
    window->setWindowTitle("SQL Interface");
    window->setWindowIcon(QIcon("icon.ico"));


    window->show();
    return app->exec();
}
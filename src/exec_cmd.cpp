#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QBoxLayout>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QWidget window(NULL);
    QVBoxLayout vertical(NULL);
    QLineEdit* field = new QLineEdit("ls");
    QPushButton button("exec");
    app.connect(&button, &QPushButton::clicked, &app, [=](){
        const char* cmd = field->text().toStdString().c_str();
        system(cmd);
    });
    vertical.addWidget(field);
    vertical.addWidget(&button);

    window.setLayout(&vertical);
    window.show();
    return app.exec();
}
#include "MainWindow.hpp"
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlineedit.h>
#include "Plugin0Test.hpp"

namespace {

class WidgetOfMainWindow :public QWidget {
    Plugin0Test test;
    QLineEdit * test_plugin_name;
public:
    WidgetOfMainWindow() {
        auto varLayout=new QVBoxLayout;
        this->setLayout(varLayout);
        varLayout->setMargin(0);
        varLayout->setSpacing(0);
        {
            auto varPushButton=new QPushButton(QString::fromUtf8(u8R"(加载插件)"));
            varLayout->addWidget(varPushButton);
            connect(varPushButton,&QPushButton::pressed,
                this,[this]() { Plugin0Test::reload(test_plugin_name->text()); });
        }
        {
            auto varLineEdit=new QLineEdit{ Plugin0Test::defaultPluginName() };
            varLayout->addWidget(varLineEdit);
            test_plugin_name=varLineEdit;
        }
        {
            auto varPushButton=new QPushButton(QString::fromUtf8(u8R"(测试函数)"));
            varLayout->addWidget(varPushButton);
            connect(varPushButton,&QPushButton::pressed,
                this,[this]() {test.foo(); });
        }
    }
};

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    this->setCentralWidget(new WidgetOfMainWindow);
}

MainWindow::~MainWindow() {

}






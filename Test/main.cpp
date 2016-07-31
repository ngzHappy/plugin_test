#include <memory>
#include "MainWindow.hpp"
#include <QApplication>


int main(int argc, char *argv[])
{
    auto app=std::make_unique<QApplication>(argc, argv);

    auto window=std::make_unique<MainWindow>();
    window->show();

    return app->exec();
}

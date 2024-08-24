#include "QtWidgets/QtWidgets"
#include "fmt/format.h"

class MainWindow : public QMainWindow {
   public:
    MainWindow(QWidget* parent = nullptr);
};

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Hello World");
    setContentsMargins(6, 6, 6, 6);

    QLabel* textViewer = new QLabel;
    textViewer->setWordWrap(true);
    textViewer->setAlignment(Qt::AlignCenter);
    textViewer->setText("Hello World");

    QScrollArea* area = new QScrollArea;
    area->setWidget(textViewer);
    area->setWidgetResizable(true);
    setCentralWidget(area);
}

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
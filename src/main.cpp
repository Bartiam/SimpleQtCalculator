#include "QtCalculator.h"
#include "../ui_calculator.h"

int main(int argc, char** argv)
{
	QApplication* app = new QApplication(argc, argv);
	QtCalculator window(nullptr);
	Ui::MainWindow calculator;
	calculator.setupUi(&window);
	window.lineEdit = calculator.lineEdit;
	window.lineEdit_2 = calculator.lineEdit_2;
	window.lineEdit->setReadOnly(true);
	window.lineEdit_2->setReadOnly(true);
	window.show();

	return app->exec();
}

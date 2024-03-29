﻿#include "QtCalculator.h"
#include "../ui_calculator.h"

int main(int argc, char** argv)
{
	QApplication* app = new QApplication(argc, argv);
	QtCalculator window(nullptr);
	Ui::MainWindow calculator;
	calculator.setupUi(&window);
	window.lineEdit = calculator.lineEdit;
	window.lineEdit->setReadOnly(true);
	window.show();

	return app->exec();
}

#pragma once
#include <QMainWindow>
#include <QString>
#include <QRegExp>
#include <QtWidgets/QLineEdit>
#include <stack>

class QtCalculator : public QMainWindow
{
	Q_OBJECT
public:
	// Прототип конструктора класса.
	QtCalculator(QWidget* parent);

	// Поле ввода.
	QLineEdit* lineEdit;

public slots:
	// Прототим метода удаление всех символов;
	void deleteLine() { lineEdit->clear(); };

	// Прототипы методов набора;
	void one();
	void two();
	void three();
	void four();
	void five();
	void six();
	void seven();
	void eight();
	void nine();
	void zero();

	// Прототип метода удаляющего последний символ;
	void deleteOneSymbol();

	// Прототипы операций с числами;
	void plus();

	void minus();

	void divide();

	void multiply();

	// Прототип метода отрицательного числа +/- ;
	void plusMinus();

	// Прототип метода расчёта = ;
	void equal();

	// Прототип метода . ;
	void point();

	// Прототип метода ввода () ;
	void parenthesis();

private:
	bool checkArithmetic() const;

	void DeleteMessageERROR();

	bool rightParenthesis() const;

	QString parseStringAndCalculate();

	void chechPriority(const QChar symbol, short& prior);

	void calculate(const QChar symbol, double& equal,
		std::stack<QChar>& stackSymbols, std::stack<double>& stackValues);

	void incorrectValue();
};
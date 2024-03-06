#include <QMainWindow>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <QtWidgets/QLineEdit>

class QtCalculator : public QMainWindow
{
	Q_OBJECT
public:
	// Конструктор класса.
	QtCalculator(QWidget* parent) : QMainWindow(parent) {};

	// Поле ввода.
	QLineEdit* lineEdit;
	QStringList lst;

public slots:
	// Удаление всех символов;
	void deleteLine() { lineEdit->clear(); };
	// Удаление последнего символа;
	void deleteOneSymbol()
	{
		QString str = lineEdit->text();
		str.chop(1);
		lineEdit->setText(str);
	};

	// Методы ввода цифр;
	void one() { lineEdit->setText(lineEdit->text().append("1")); }
	void two() { lineEdit->setText(lineEdit->text().append("2")); }
	void three() { lineEdit->setText(lineEdit->text().append("3")); }
	void four() { lineEdit->setText(lineEdit->text().append("4")); }
	void five() { lineEdit->setText(lineEdit->text().append("5")); }
	void six() { lineEdit->setText(lineEdit->text().append("6")); }
	void seven() { lineEdit->setText(lineEdit->text().append("7")); }
	void eight() { lineEdit->setText(lineEdit->text().append("8")); }
	void nine() { lineEdit->setText(lineEdit->text().append("9")); }
	void zero() { lineEdit->setText(lineEdit->text().append("0")); }

	// Метод ввода () ;
	void parenthesis() 
	{
		
	};

	// Операции с числами;
	void plus()
	{
		if (!(lineEdit->text().isEmpty()) && !(lineEdit->text().endsWith("+")))
			lineEdit->setText(lineEdit->text().append("+"));
	};

	void minus() 
	{
		if (!(lineEdit->text().isEmpty()) && !(lineEdit->text().endsWith("-")))
			lineEdit->setText(lineEdit->text().append("-"));
	};

	void divide()
	{
		if (!(lineEdit->text().isEmpty()) && !(lineEdit->text().endsWith("/")))
			lineEdit->setText(lineEdit->text().append("/"));
	};

	void multiply()
	{
		if (!(lineEdit->text().isEmpty()) && !(lineEdit->text().endsWith("*")))
			lineEdit->setText(lineEdit->text().append("*"));
	};

	// Метод расчёта = ;
	void equal()
	{
		
	};

	// Метод ввода , ;
	void comma()
	{
		if (lineEdit->text().isEmpty()) { lineEdit->setText(lineEdit->text().append("0,")); }
	};
};
#include <QMainWindow>
#include <QString>
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
	QStringList strList;
	bool isTrue;

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
		if (!(lineEdit->text().isEmpty()) && !checkLine()) { lineEdit->setText(lineEdit->text().append("+")); }
	};

	void minus() 
	{
		if (!(lineEdit->text().isEmpty()) && !checkLine()) { lineEdit->setText(lineEdit->text().append("-")); }
	};

	void divide()
	{
		if (!(lineEdit->text().isEmpty()) && !checkLine()) { lineEdit->setText(lineEdit->text().append("/")); }
	};

	void multiply()
	{
		if (!(lineEdit->text().isEmpty()) && !checkLine()) { lineEdit->setText(lineEdit->text().append("*")); }
	};

	// Метод расчёта = ;
	void equal()
	{
		strList = lineEdit->text().split("*");
		if (!strList.empty())
		{
			double tempVar = 0;
			for (int i = 0; i < strList.size(); ++i)
			{
				tempVar += strList[i].toDouble();
			}

			lineEdit->setText(QString::number(tempVar));
		}
	};

	// Метод ввода , ;
	void comma()
	{
		//if (lineEdit->text().isEmpty()) { lineEdit->setText(lineEdit->text().append("0,")); }
		//else
		{
			strList = lineEdit->text().split("+");
		}
	};

private:
	bool checkLine()
	{
		return lineEdit->text().endsWith("+") || lineEdit->text().endsWith("*") ||
			lineEdit->text().endsWith("-") || lineEdit->text().endsWith("/");
	}
};
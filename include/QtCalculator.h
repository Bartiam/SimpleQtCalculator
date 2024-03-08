﻿#include <QMainWindow>
#include <QString>
#include <QRegExp>
#include <QtWidgets/QLineEdit>

class QtCalculator : public QMainWindow
{
	Q_OBJECT
public:
	// Конструктор класса.
	QtCalculator(QWidget* parent) : QMainWindow(parent) {};

	// Поле ввода.
	QLineEdit* lineEdit;
	

public slots:
	// Удаление всех символов;
	void deleteLine() { lineEdit->clear(); };

	// Методы ввода цифр;
	void one() 
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*1"));
		else lineEdit->setText(lineEdit->text().append("1"));
	}
	void two() 
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*2"));
		else lineEdit->setText(lineEdit->text().append("2"));
	}
	void three() 
	{ 
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*3"));
		else lineEdit->setText(lineEdit->text().append("3"));
	}
	void four() 
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*4"));
		else lineEdit->setText(lineEdit->text().append("4"));
	}
	void five()
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*5"));
		else lineEdit->setText(lineEdit->text().append("5"));
	}
	void six()
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*6"));
		else lineEdit->setText(lineEdit->text().append("6"));
	}
	void seven()
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*7"));
		else lineEdit->setText(lineEdit->text().append("7"));
	}
	void eight()
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*8"));
		else lineEdit->setText(lineEdit->text().append("8"));
	}
	void nine() 
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*9"));
		else lineEdit->setText(lineEdit->text().append("9"));
	}
	void zero() 
	{
		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*0"));
		else lineEdit->setText(lineEdit->text().append("0"));
	}

	// Удаление последнего символа;
	void deleteOneSymbol()
	{
		QString tempStr = lineEdit->text();
		tempStr.chop(1);
		lineEdit->setText(tempStr);
	};

	// Операции с числами;
	void plus()
	{
		if (checkArithmetic())
		{
			QString tempStr = lineEdit->text();
			tempStr.chop(1);
			lineEdit->setText(tempStr.append("+"));
		}
		else if (!(lineEdit->text().isEmpty()))
		{ lineEdit->setText(lineEdit->text().append("+")); }
	};

	void minus() 
	{
		if (checkArithmetic())
		{
			QString tempStr = lineEdit->text();
			tempStr.chop(1);
			lineEdit->setText(tempStr.append("-"));
		}
		else if (!(lineEdit->text().isEmpty()))
		{ lineEdit->setText(lineEdit->text().append("-")); }
	};

	void divide()
	{
		if (checkArithmetic() && !(lineEdit->text().endsWith("(")))
		{
			QString tempStr = lineEdit->text();
			tempStr.chop(1);
			lineEdit->setText(tempStr);
			
			if (!(lineEdit->text().endsWith("(")))
				lineEdit->setText(tempStr.append("/"));
		}
		else if (!(lineEdit->text().isEmpty()) && !(lineEdit->text().endsWith("(")))
		{ lineEdit->setText(lineEdit->text().append("/")); }
	};

	void multiply()
	{
		if (checkArithmetic())
		{
			QString tempStr = lineEdit->text();
			tempStr.chop(1);
			lineEdit->setText(tempStr);

			if (!(lineEdit->text().endsWith("(")))
				lineEdit->setText(tempStr.append("*"));
		}
		else if (!(lineEdit->text().isEmpty()) && !(lineEdit->text().endsWith("(")))
		{ lineEdit->setText(lineEdit->text().append("*")); }
	};

	// Метод отрицательного числа +/- ;
	void plusMinus()
	{
		if (lineEdit->text().isEmpty())
		{
			lineEdit->setText(lineEdit->text().append("(-"));
		}
		else
		{
			QRegExp regex("[\+\/\*\-]");
			QRegExp regexVar("[0-9]");
			QString tempStr = lineEdit->text();

			QStringList tempLst = tempStr.split(regex);
			QString lastStr = tempLst[tempLst.size() - 1];

			if (tempStr.right(2) == "(-") 
			{
				tempStr.chop(2);
				lineEdit->setText(tempStr);
			}
			else if (!lastStr.isEmpty() && lastStr[lastStr.length() - 1] == "%")
			{
				tempStr.append("*(-");
			}
			else
			{

				if (lastStr.contains(regexVar))
				{
					tempStr.chop(lastStr.length());
					if (tempStr.right(2) == "(-")
					{
						tempStr.chop(2);
						lineEdit->setText(tempStr);
						tempStr.append(lastStr);
					}
					else tempStr.append("(-" + lastStr);
				}
				else tempStr.append("(-");

				lineEdit->setText(tempStr);
			}
		}

	}

	// Процент ;
	void percent()
	{
		if (!(lineEdit->text().isEmpty()))
			lineEdit->setText(lineEdit->text().append("%"));
	}

	// Метод расчёта = ;
	void equal()
	{
		
	};

	// Метод ввода () ;
	void parenthesis()
	{
		QRegExp regex("[0-9]");
		QString tempStr = lineEdit->text();
		QString endSymbol;
		if (!tempStr.isEmpty()) endSymbol = tempStr[lineEdit->text().size() - 1];
		
		if (rightParenthesis()) { lineEdit->setText(lineEdit->text().append(")")); }
		else if (endSymbol.contains(regex) || endSymbol == ")") lineEdit->setText(lineEdit->text().append("*("));
		else lineEdit->setText(lineEdit->text().append("("));
	};

	// Метод ввода . ;
	void point()
	{
		if (lineEdit->text().isEmpty()) { lineEdit->setText(lineEdit->text().append("0.")); }
		else
		{
			
		}
	};

private:
	bool checkArithmetic() const
	{
		QRegExp regex("[\-\+\*\/]");
		QString tempStr = lineEdit->text();
		QString endSymbol;

		if (!tempStr.isEmpty()) endSymbol = tempStr[lineEdit->text().size() - 1];

		if (endSymbol.contains(regex)) return true;

		return false;
	}

	bool rightParenthesis() const
	{
		QString tempStr = lineEdit->text();

		bool isTrue = (tempStr.count("(") > tempStr.count(")")) &&
			!(tempStr.endsWith("+") && tempStr.endsWith("-") && tempStr.endsWith("*") && tempStr.endsWith("/")) &&
			!(tempStr.endsWith("("));

		return isTrue;
	}
};
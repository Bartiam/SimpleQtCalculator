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
	// Конструктор класса.
	QtCalculator(QWidget* parent) : QMainWindow(parent) { };

	// Поле ввода.
	QLineEdit* lineEdit;

public slots:
	// Удаление всех символов;
	void deleteLine() { lineEdit->clear(); };

	// Методы ввода цифр;
	void one() 
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*1"));
		else lineEdit->setText(lineEdit->text().append("1"));
	}
	void two() 
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*2"));
		else lineEdit->setText(lineEdit->text().append("2"));
	}
	void three() 
	{ 
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*3"));
		else lineEdit->setText(lineEdit->text().append("3"));
	}
	void four() 
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*4"));
		else lineEdit->setText(lineEdit->text().append("4"));
	}
	void five()
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*5"));
		else lineEdit->setText(lineEdit->text().append("5"));
	}
	void six()
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*6"));
		else lineEdit->setText(lineEdit->text().append("6"));
	}
	void seven()
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*7"));
		else lineEdit->setText(lineEdit->text().append("7"));
	}
	void eight()
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*8"));
		else lineEdit->setText(lineEdit->text().append("8"));
	}
	void nine() 
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*9"));
		else lineEdit->setText(lineEdit->text().append("9"));
	}
	void zero() 
	{
		DeleteMessageERROR();
		incorrectValue();

		if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*0"));
		else lineEdit->setText(lineEdit->text().append("0"));
	}

	// Удаление последнего символа;
	void deleteOneSymbol()
	{
		DeleteMessageERROR();

		QString tempStr = lineEdit->text();
		tempStr.chop(1);
		lineEdit->setText(tempStr);
	};

	// Операции с числами;
	void plus()
	{
		DeleteMessageERROR();

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
		DeleteMessageERROR();

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
		DeleteMessageERROR();

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
		DeleteMessageERROR();

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
		DeleteMessageERROR();

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
			else if (!lastStr.isEmpty() && (lastStr[lastStr.length() - 1] == "%" || lastStr[lastStr.length() - 1] == ")"))
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
			}
			lineEdit->setText(tempStr);
		}

	}

	// Метод расчёта = ;
	void equal()
	{
		if (lineEdit->text().isEmpty() || lineEdit->text().endsWith("+") || lineEdit->text().endsWith("*") 
			|| lineEdit->text().endsWith("-") || lineEdit->text().endsWith("/") || lineEdit->text().endsWith("("))
		{
			lineEdit->setText("ERROR!");
			return;
		}

		QRegExp regex("[\+\/\*\-]");

		QStringList lstValues = lineEdit->text().split(regex);

		QString temp = lineEdit->text().right(lstValues[lstValues.size()-1].size() + 1);

		if (temp.startsWith("/") && lstValues[lstValues.size() - 1].toDouble() == 0)
		{
			lineEdit->setText("ERROR!");
			return;
		}

		if (lineEdit->text() == "ERROR!") return;
		lineEdit->setText(parseStringAndCalculate());
	};

	// Метод , ;
	void point()
	{
		DeleteMessageERROR();

		if (lineEdit->text().isEmpty() || lineEdit->text().endsWith("-") || lineEdit->text().endsWith("(") ||
			lineEdit->text().endsWith("+") || lineEdit->text().endsWith("*") || lineEdit->text().endsWith("/"))
		{
			lineEdit->setText(lineEdit->text().append("0."));
		}
		else if (lineEdit->text().endsWith(")"))
			lineEdit->setText(lineEdit->text().append("*0."));
		else
		{
			QRegExp regex("[\+\/\*\-]");
			QStringList tempLst = lineEdit->text().split(regex);

			if (!(tempLst[tempLst.size() - 1].contains(".")))
				lineEdit->setText(lineEdit->text().append("."));
		}
	}

	// Метод ввода () ;
	void parenthesis()
	{
		DeleteMessageERROR();

		QRegExp regex("[0-9]");
		QString tempStr = lineEdit->text();
		QString endSymbol;
		if (!tempStr.isEmpty()) endSymbol = tempStr[lineEdit->text().size() - 1];
		
		if (rightParenthesis()) { lineEdit->setText(lineEdit->text().append(")")); }
		else if (endSymbol.contains(regex) || endSymbol == ")" || endSymbol == ".") lineEdit->setText(lineEdit->text().append("*("));
		else lineEdit->setText(lineEdit->text().append("("));
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

	void DeleteMessageERROR() { if (lineEdit->text() == "ERROR!") lineEdit->clear(); }

	bool rightParenthesis() const
	{
		QString tempStr = lineEdit->text();

		bool isTrue = (tempStr.count("(") > tempStr.count(")")) &&
			!(tempStr.endsWith("+") || tempStr.endsWith("-") || tempStr.endsWith("*") || tempStr.endsWith("/")) &&
			!(tempStr.endsWith("("));

		return isTrue;
	}

	QString parseStringAndCalculate()
	{
		QString customExample = lineEdit->text();
		QStringRef value;

		short counter1 = 0;
		short counter2 = 0;
		short counterMinus = 0;

		short currentPrior;
		short prevPrior;

		std::stack<QChar> stackSymbols;
		std::stack<double> stackValues;

		double equal = 0.0;

		for (int i = 0; i < customExample.length(); ++i)
		{
			if ((customExample[i] >= "0" && customExample[i] <= "9") || (customExample[i] == "."))
			{
				++counter1;
			}
			else if (customExample[i] == "-" && customExample[i - 1] == "(")
			{
				++counterMinus;
				if (counterMinus == 2) counterMinus = 0;

				counter2 = i + 1;
			}
			else
			{
				if (counter1 != 0)
				{
					value = QStringRef(&customExample, counter2, counter1);
					counter1 = 0;
					if (counterMinus != 0)
						stackValues.push(value.toDouble() * -1);
					else
						stackValues.push(value.toDouble());

					counterMinus = 0;
				}

				counter2 = i + 1;

				if ((stackSymbols.empty() || stackSymbols.top() == '(' || customExample[i] == '(') && (customExample[i] != ")"))
				{
					stackSymbols.push(customExample[i]);
				}
				else
				{
					if (customExample[i] == ")")
					{
						while (stackSymbols.top() != "(")
							{calculate(stackSymbols.top(), equal, stackSymbols, stackValues);}
						stackSymbols.pop();
					}
					else
					{
						chechPriority(customExample[i], currentPrior);
						chechPriority(stackSymbols.top(), prevPrior);

						if (currentPrior > prevPrior)
						{
							stackSymbols.push(customExample[i]);
						}
						else
						{
							calculate(stackSymbols.top(), equal, stackSymbols, stackValues);

							if (!stackSymbols.empty() && stackSymbols.top() != "(" && stackSymbols.top() != ")")
							{
								chechPriority(customExample[i], currentPrior);
								chechPriority(stackSymbols.top(), prevPrior);

								if (currentPrior == prevPrior)
									calculate(stackSymbols.top(), equal, stackSymbols, stackValues);
							}

							stackSymbols.push(customExample[i]);
						}
					}
				}
			}
		}

		if (counter1 != 0)
		{
			counter1 += counterMinus;
			value = QStringRef(&customExample, counter2, counter1);
			stackValues.push(value.toDouble());
		}

		for (int i = 0; i != stackSymbols.size();)
		{
			if (stackSymbols.top() == "(")
				stackSymbols.pop();
			else
			{
				calculate(stackSymbols.top(), equal, stackSymbols, stackValues);
			}
		}

		return QString::number(stackValues.top());
	}

	void chechPriority(const QChar symbol, short& prior)
	{
		switch (symbol.toLatin1())
		{
		case '+':
			prior = 1;
			break;
		case '*':
			prior = 2;
			break;
		case '-':
			prior = 1;
			break;
		case '/':
			prior = 2;
		}
	}

	void calculate(const QChar symbol, double& equal,
		std::stack<QChar>& stackSymbols, std::stack<double>& stackValues)
	{
		double firstVal, secondVal;

		firstVal = stackValues.top();
		stackValues.pop();

		secondVal = stackValues.top();
		stackValues.pop();

		switch (symbol.toLatin1())
		{
		case '+':
			equal = secondVal + firstVal;
			stackValues.push(equal);
			stackSymbols.pop();
			break;
		case '*':
			equal = secondVal * firstVal;
			stackValues.push(equal);
			stackSymbols.pop();
			break;
		case '-':
			equal = secondVal - firstVal;
			stackValues.push(equal);
			stackSymbols.pop();
			break;
		case '/':
			equal = secondVal / firstVal;
			stackValues.push(equal);
			stackSymbols.pop();
			break;
		}
	}

	void incorrectValue()
	{
		QRegExp regex("[\-\+\*\/]");
		QString tempStr = lineEdit->text();
		QStringList tempLst = tempStr.split(regex);

		if (tempLst[tempLst.size() - 1] == "0" && tempLst[tempLst.size() - 1].toDouble() == 0)
		{
			tempStr.chop(1);
			lineEdit->setText(tempStr);
		}
	}
};
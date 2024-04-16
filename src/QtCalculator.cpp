#include "QtCalculator.h"

// Реализация конструктора класса;
QtCalculator::QtCalculator(QWidget* parent) : QMainWindow(parent) { regex = new QRegExp("[\+\/\*\-]"); }

// Реализация методов ввода чисел;

void QtCalculator::one()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*1"));
	else lineEdit->setText(lineEdit->text().append("1"));
}

void QtCalculator::two()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*2"));
	else lineEdit->setText(lineEdit->text().append("2"));
}

void QtCalculator::three()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*3"));
	else lineEdit->setText(lineEdit->text().append("3"));
}

void QtCalculator::four()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*4"));
	else lineEdit->setText(lineEdit->text().append("4"));
}

void QtCalculator::five()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*5"));
	else lineEdit->setText(lineEdit->text().append("5"));
}

void QtCalculator::six()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*6"));
	else lineEdit->setText(lineEdit->text().append("6"));
}

void QtCalculator::seven()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*7"));
	else lineEdit->setText(lineEdit->text().append("7"));
}

void QtCalculator::eight()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*8"));
	else lineEdit->setText(lineEdit->text().append("8"));
}

void QtCalculator::nine()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*9"));
	else lineEdit->setText(lineEdit->text().append("9"));
}

void QtCalculator::zero()
{
	DeleteMessageERROR();
	incorrectValue();

	if (lineEdit->text().endsWith(")")) lineEdit->setText(lineEdit->text().append("*0"));
	else lineEdit->setText(lineEdit->text().append("0"));
}

// Реализация метода удаления последнего символа;
void QtCalculator::deleteOneSymbol()
{
	DeleteMessageERROR();

	QString tempStr = lineEdit->text();
	tempStr.chop(1);
	lineEdit->setText(tempStr);
}

// Реализация методов оперций с числами;
void QtCalculator::plus()
{
	DeleteMessageERROR();

	if (checkArithmetic())
	{
		QString tempStr = lineEdit->text();
		tempStr.chop(1);
		lineEdit->setText(tempStr.append("+"));
	}
	else if (!(lineEdit->text().isEmpty()))
	{
		lineEdit->setText(lineEdit->text().append("+"));
	}
}

void QtCalculator::minus()
{
	DeleteMessageERROR();

	if (checkArithmetic())
	{
		QString tempStr = lineEdit->text();
		tempStr.chop(1);
		lineEdit->setText(tempStr.append("-"));
	}
	else if (!(lineEdit->text().isEmpty()))
	{
		lineEdit->setText(lineEdit->text().append("-"));
	}
}

void QtCalculator::divide()
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
	{
		lineEdit->setText(lineEdit->text().append("/"));
	}
}

void QtCalculator::multiply()
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
	{
		lineEdit->setText(lineEdit->text().append("*"));
	}
}

// Реализация метода отрицательного числа +/-;
void QtCalculator::plusMinus()
{
	DeleteMessageERROR();

	if (lineEdit->text().isEmpty())
	{
		lineEdit->setText(lineEdit->text().append("(-"));
	}
	else
	{
		QRegExp regexVar("[0-9]");
		QString tempStr = lineEdit->text();

		QStringList tempLst = tempStr.split(*regex);
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

// Реализация метода =;
void QtCalculator::equal()
{
	if (lineEdit->text().isEmpty() || lineEdit->text().endsWith("+") || lineEdit->text().endsWith("*")
		|| lineEdit->text().endsWith("-") || lineEdit->text().endsWith("/") || lineEdit->text().endsWith("("))
	{
		lineEdit->setText("ERROR!");
		return;
	}

	QStringList lstValues = lineEdit->text().split(*regex);

	QString temp = lineEdit->text().right(lstValues[lstValues.size() - 1].size() + 1);

	if (temp.startsWith("/") && lstValues[lstValues.size() - 1].toDouble() == 0)
	{
		lineEdit->setText("ERROR!");
		return;
	}

	if (lineEdit->text() == "ERROR!") return;
	lineEdit->setText(parseStringAndCalculate());
}

// Реализация метода .;
void QtCalculator::point()
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
		QStringList tempLst = lineEdit->text().split(*regex);

		if (!(tempLst[tempLst.size() - 1].contains(".")))
			lineEdit->setText(lineEdit->text().append("."));
	}
}

// Реализация метода ();
void QtCalculator::parenthesis()
{
	DeleteMessageERROR();

	QString tempStr = lineEdit->text();
	QString endSymbol;
	if (!tempStr.isEmpty()) endSymbol = tempStr[lineEdit->text().size() - 1];

	if (rightParenthesis()) { lineEdit->setText(lineEdit->text().append(")")); }
	else if (endSymbol.contains(*regex) || endSymbol == ")" || endSymbol == ".") lineEdit->setText(lineEdit->text().append("*("));
	else lineEdit->setText(lineEdit->text().append("("));
}




void QtCalculator::DeleteMessageERROR() { if (lineEdit->text() == "ERROR!") lineEdit->clear(); }

bool QtCalculator::rightParenthesis() const
{
	QString tempStr = lineEdit->text();

	bool isTrue = (tempStr.count("(") > tempStr.count(")")) &&
		!(tempStr.endsWith("+") || tempStr.endsWith("-") || tempStr.endsWith("*") || tempStr.endsWith("/")) &&
		!(tempStr.endsWith("("));

	return isTrue;
}

QString QtCalculator::parseStringAndCalculate()
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
					{
						calculate(stackSymbols.top(), equal, stackSymbols, stackValues);
					}
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

void QtCalculator::chechPriority(const QChar symbol, short& prior)
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

void QtCalculator::calculate(const QChar symbol, double& equal, std::stack<QChar>& stackSymbols, std::stack<double>& stackValues)
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

void QtCalculator::incorrectValue()
{
	QString tempStr = lineEdit->text();
	QStringList tempLst = tempStr.split(*regex);

	if (tempLst[tempLst.size() - 1] == "0" && tempLst[tempLst.size() - 1].toDouble() == 0)
	{
		tempStr.chop(1);
		lineEdit->setText(tempStr);
	}
}

bool QtCalculator::checkArithmetic() const
{
	QString tempStr = lineEdit->text();
	QString endSymbol;

	if (!tempStr.isEmpty()) endSymbol = tempStr[lineEdit->text().size() - 1];

	if (endSymbol.contains(*regex)) return true;

	return false;
}
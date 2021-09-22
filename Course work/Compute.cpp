#include <iostream>
#include "Compute.h"
using namespace std;
Compute::Compute(Base* parent, string name) :Base(parent, name)
{
	cl_num = 3;
}
void Compute::signal1(string& task) // метод сигнала
{
}
void Compute::signal2(string& task)// метод сигнала
{
}
void Compute::hendler1(string task) // метод определиня первого операнда операций
{
	this->operand_1 = atoi(task.c_str()); // опредеяем первоначальное значение результат
}
void Compute::hendler2(string task)// метод опредения знака для математических оперций
{
	this->symbol = task[0]; // определяем символ следующей операции
}
void Compute::hendler3(string task) // метод вычисления математических операций
{
	this->operand_2 = atoi(task.c_str());
	switch (this->symbol) // в зависимости символа производим математическое действие
	{
	case '+':
	this->result = operand_1 + operand_2;
	break;
	case '-':
	this->result = operand_1 - operand_2;
	break;
	case '*':
	this->result = operand_1 * operand_2;
	break;
	case '%':
	this->result = operand_1 % operand_2;
	break;
	}
		this->r = to_string(operand_1) + " " + symbol + " " + to_string(operand_2) + " = " + to_string(result);
	if (flag)
	{
		this->emitSignal(SIGNAL_D(Compute, signal2), this->r);
	}
	else
	{
		this->emitSignal(SIGNAL_D(Compute, signal1), this->r);
		flag = true;
	}
	operand_1 = result;
}
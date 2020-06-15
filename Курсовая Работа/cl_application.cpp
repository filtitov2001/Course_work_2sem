#include <iostream>
#include <string>
#include "Input.h"
#include "Compute.h"
#include "Output.h"
#include "cl_application.h"
using namespace std;
cl_application::cl_application(Base* parent, string name) :Base(parent, name)
{
	cl_num = 1;
}
cl_application::cl_application(Base* parent) : Base(parent)
{
	cl_num = 1;
}
void cl_application::build_tree() //метод построения дерева иерархии и устновки связей
{
	Base* input = new Input(this, "input"); //создаем объекта для ввода данных
	Base* compute = new Compute(this, "compute"); // создам объект для выполнения математических операций
	Base* output = new Output(this, "output"); // создаем объект для вывода данных
	this->setConnect(SIGNAL_D(cl_application, signal4), input,HENDLER_D(Input, get)); //устанавливаем связи
	input -> setConnect(SIGNAL_D(Input, signal1), this, HENDLER_D(cl_application, getTask));
	this->setConnect(SIGNAL_D(cl_application, signal1), compute,HENDLER_D(Compute, hendler1));
	this->setConnect(SIGNAL_D(cl_application, signal2), compute,HENDLER_D(Compute, hendler2));
	this->setConnect(SIGNAL_D(cl_application, signal3), compute,HENDLER_D(Compute, hendler3));
	compute -> setConnect(SIGNAL_D(Compute, signal1), output, HENDLER_D(Output, print));
	compute -> setConnect(SIGNAL_D(Compute, signal2), output, HENDLER_D(Output, print));
}
int cl_application::exec_app() // метод запуска функционирования система
{
	string buf, s;
	this->emitSignal(SIGNAL_D(cl_application, signal4), s);
	int expression = atoi(inStr.c_str());
	int intermediate = inStr.find(' ');
	inStr = inStr.erase(0, intermediate + 1); // вырезаем из выражения первый операнд
		s = to_string(expression);
	this->emitSignal(SIGNAL_D(cl_application, signal1), s);
	while (inStr.size() != 0) // пока введенная строка с выражением есть
	{
		buf = inStr[0]; // определяем знак следующей операции
		intermediate = inStr.find(' '); //определяем границу для выражения
			inStr = inStr.erase(0, intermediate + 1); // вырезаем из выражения следующий операнд
			this->emitSignal(SIGNAL_D(cl_application, signal2), buf);
		intermediate = -1;
		expression = atoi(inStr.c_str());
		intermediate = inStr.find(' ');
		if (intermediate != -1)
			inStr = inStr.erase(0, intermediate + 1);
		else
			inStr = "";
		s = to_string(expression);
		this->emitSignal(SIGNAL_D(cl_application, signal3), s);
	}

	return 0;
}
void cl_application::signal1(string& task) {}
void cl_application::signal2(string& task) {}
void cl_application::signal3(string& task) {}
void cl_application::signal4(string& task) {}
void cl_application::getTask(string task)
{
	this->inStr = task;
}
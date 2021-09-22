#include <iostream>
#include "Input.h"
using namespace std;
Input::Input(Base* parent, string name) :Base(parent, name)
{
	cl_num = 2;
}
void Input::signal1(string& task)// метод сигнала
{
}
void Input::get(string task) // метод считывания введенной строки
{
	getline(cin, task);
	this->emitSignal(SIGNAL_D(Input, signal1), task);
}
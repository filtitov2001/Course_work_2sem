#include "Output.h"
#include <iostream>
Output::Output(Base* parent, string name) :Base(parent, name)
{
	cl_num = 4;
}
void Output::print(string task) // ����� ������ ����������� ��������
{
	if (first)
		cout << task;
	else
		cout << "\n" << task;
	first = false;
}
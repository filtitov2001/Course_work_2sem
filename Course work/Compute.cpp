#include <iostream>
#include "Compute.h"
using namespace std;
Compute::Compute(Base* parent, string name) :Base(parent, name)
{
	cl_num = 3;
}
void Compute::signal1(string& task) // ����� �������
{
}
void Compute::signal2(string& task)// ����� �������
{
}
void Compute::hendler1(string task) // ����� ���������� ������� �������� ��������
{
	this->operand_1 = atoi(task.c_str()); // ��������� �������������� �������� ���������
}
void Compute::hendler2(string task)// ����� ��������� ����� ��� �������������� �������
{
	this->symbol = task[0]; // ���������� ������ ��������� ��������
}
void Compute::hendler3(string task) // ����� ���������� �������������� ��������
{
	this->operand_2 = atoi(task.c_str());
	switch (this->symbol) // � ����������� ������� ���������� �������������� ��������
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
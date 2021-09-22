#include <iostream>

#include "Compute.h"

using namespace std;

Compute::Compute(Base* parent, string name): Base(parent, name) {
	cl_num = 3;
}

void Compute::signal1(string& task) {} // signal method

void Compute::signal2(string& task) {} // signal method

void Compute::hendler1(string task) { // method for determining the first operand of operations
	this->operand_1 = atoi(task.c_str()); // determine the initial value of the result
}

void Compute::hendler2(string task) { // method for determining the sign of mathematical operations
	this->symbol = task[0]; // define the next operation symbol
}

void Compute::hendler3(string task) { // method of calculating mathematical operations

	this->operand_2 = atoi(task.c_str());
	switch (this->symbol) { // depending on the symbol, we perform a mathematical action
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
	
	if (flag) {
		this->emitSignal(SIGNAL_D(Compute, signal2), this->r);
	} else {
		this->emitSignal(SIGNAL_D(Compute, signal1), this->r);
		flag = true;
	}
	
	operand_1 = result;
}

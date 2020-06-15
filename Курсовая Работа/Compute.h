#ifndef _COMPUTE_H
#define _COMPUTE_H
#include "Base.h"
class Compute : public Base
{
	private:
		int result, operand_1, operand_2;
		char symbol;
		string r;
		bool flag = false;
	public:
		Compute(Base* parent, string name);
		//Compute(Base* parent);
		void signal1(string& task);
		void signal2(string& task);
		void hendler1(string task);
		void hendler2(string task);
		void hendler3(string task);
		char getsymbol();
		void setsymbol(char a);
};
#endif

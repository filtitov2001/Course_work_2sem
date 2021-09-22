#ifndef __INPUT_H
#define __INPUT_H
#include "Base.h"
class Input : public Base
{
	public:
		Input(Base* parent, string name);
		//Input(Base* parent);
		void get(string task);
		void signal1(string& task);
};
#endif

#ifndef _OUTPUT_H
#define _OUTPUT_H
#include "Base.h"

class Output : public Base
{
	private:
		//string res;
		bool first = true;
	public:
		//Output(Base* parent);
		Output(Base* parent, string name);
		void print(string task);
};
#endif

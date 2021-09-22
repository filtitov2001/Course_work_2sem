#ifndef _CL_APPLICATION_H
#define _CL_APPLICATION_H

#include "Base.h"

using namespace std;

class cl_application :public Base {
	private:
		string inStr;
	public:
		cl_application(Base* parent, string name);
		cl_application(Base* parent);
	
		void getTask(string task);
	
		void signal1(string& task);
		void signal2(string& task);
		void signal3(string& task);
		void signal4(string& task);
	
		void build_tree();
		int exec_app();
};
#endif

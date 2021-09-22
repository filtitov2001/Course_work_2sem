#ifndef _BASE_H
#define _BASE_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Base;
typedef void(Base::* T_SIGNAL) (string&);
typedef void(Base::* T_HENDLER) (string);
class Base
{
	private:
		struct o_sh
		{
			Base* p_Base;
			T_SIGNAL p_signal;
			T_HENDLER p_hendler;
		};
		Base* parent;
		string name;
		vector<o_sh*> connects;
	protected:
		int cl_num = 1;
		int activity = 0;
		vector<Base*> children;
	public:
		Base(Base* parent);
		Base(Base* parent, string name);
		void setStatus(int activity);
		void printChildren();
		void inputName(string name);
		string getName();
		void printTree(string space);
		Base* searchParent(string name);
		string getTrailItem(string objectPath, int iLevel);
		Base* getObjectRoot();
		Base* getTrailObjectRoot(string objectPath);
		Base* getObject(string objectPath);
		Base* getChild(string nameChild);
		int getClassNumber();
		void setConnect(T_SIGNAL p_signal, Base* p_ob_hend, T_HENDLER
			p_hendler);
		void deleteConnect(T_SIGNAL p_signal, Base* p_ob_hend, T_HENDLER
			p_hendler);
		void emitSignal(T_SIGNAL p_signal, string& command);
		~Base();
};
#define SIGNAL_D(T, signal_f)(T_SIGNAL(&T::signal_f))
#define HENDLER_D(G,hendler_f) (T_HENDLER(&G::hendler_f))
#endif
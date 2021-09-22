#include <iostream>
#include <vector>
#include "Base.h"
using namespace std;
Base::Base(Base* parent) //парметризированный конструктор, определ€ющий родител€ и присваивающий ему ребенка
{
	this->parent = parent;
	if (parent != NULL)
	{
		parent->children.push_back(this);
	}
}
Base::Base(Base* parent, string name)//парметризированный конструктор, определ€ющий родител€, им€ и присваивающий ему ребенка
{
 this->parent = parent;
 this->name = name;
 if (parent != NULL)
 {
 parent->children.push_back(this);
 }
}
void Base::setStatus(int activity) // метод определени€ готовности объекта
{
	this->activity = activity;
}
void Base::printChildren() // метод вывода состо€ни€ готовности объектов
{
	cout << "The object " << this->getName().c_str();
	if (activity > 0)
	{
		cout << " is ready";
	}
	else
	{
		cout << " is not ready";
	}
	for (int i = 0; i < children.size(); i++)
	{
		cout << endl;
		children[i]->printChildren();
	}
}
void Base::inputName(string name) //метод установки имени
{
	this->name = name;
}
void Base::printTree(string space) // метод вывода дерева иерархии объектов
{
	cout << space << this->getName().c_str();
	space += " ";
	for (int i = 0; i < children.size(); i++)
	{
		cout << endl;
		children[i]->printTree(space);
	}
}
Base* Base::searchParent(string name) // метод поиска объекта по имени
{
	Base* search = NULL;
	if (name == this->getName().c_str())
	{
		search = this;
	}
	else if (children.size() > 0)
	{
		for (int i = 0; i < children.size(); i++)
		{
			search = children[i]->searchParent(name);
			if (search != NULL)
				break;
		}
	}
	return search;
}
Base::~Base() //деструктор, уничтожающий объекторв потовков и соединений
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
	for (int i = 0; i < connects.size(); i++)
	{
		delete connects[i];
	}
}
string Base::getName() // метод получени€ имени объекта
{
	return name;
}
string Base::getTrailItem(string objectPath, int index_level) // метод получени€ объкта по пути с помощью индекса
{
	int index_start, index_end, index_merchantLevel;
	index_start = index_merchantLevel = 1;
	while (index_start)
	{
		index_end = objectPath.find("/", index_start);
		if (index_merchantLevel == index_level)
			return objectPath.substr(index_start, index_end -
				index_start);
		index_start = index_end + 1;
		index_merchantLevel++;
	}
	return "";
}
Base* Base::getObjectRoot() // метод поиска корневого объекта
{
	Base* MerchantBase = this;
	while (MerchantBase->parent)
	{
		MerchantBase = MerchantBase->parent;
	}
	return MerchantBase;
}
Base* Base::getTrailObjectRoot(string objectTrail) //метод получени€ пути корневого объекта
{
	int index_level = 1;
	string TrailItem;
	Base* MerchantBase = getObjectRoot();
	if (getTrailItem(objectTrail, index_level) != MerchantBase->name)
		return NULL;
	index_level++;
	TrailItem = getTrailItem(objectTrail, index_level);
	while (!TrailItem.empty())
	{
		MerchantBase = MerchantBase->getChild(TrailItem);
		if (!MerchantBase)
			return NULL;
		index_level++;
		TrailItem = getTrailItem(objectTrail, index_level);
	}
	return MerchantBase;
}
Base* Base::getObject(string objectPath) // метод поучени€ объекта дл€ последующего вывода пути
{
	if ((objectPath[0] == '/') && (objectPath[1] == '/'))
		return searchParent(objectPath.substr(2, string::npos));
	return getTrailObjectRoot(objectPath);
}
Base* Base::getChild(string nameChild) //метод получени€ ребенка по имени
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i]->name == nameChild)
			return children[i];
	}
	return NULL;
}
void Base::setConnect(T_SIGNAL p_signal, Base* p_ob_hend, T_HENDLER
	p_hendler) //метод установки соединений
{
	o_sh* value;
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->p_signal == p_signal && connects[i] -> p_Base == p_ob_hend
			&& connects[i]->p_hendler == p_hendler)
			return;
	}
	value = new o_sh();
	value->p_Base = p_ob_hend;
	value->p_signal = p_signal;
	value->p_hendler = p_hendler;
	connects.push_back(value);
}
void Base::deleteConnect(T_SIGNAL p_signal, Base* p_ob_hend, T_HENDLER
	p_hendler) // метод удалени€ соединений
{
	o_sh* value;
	for (int i = 0; i < connects.size(); i++)
	{
		value = connects[i];
		if (connects[i]->p_signal == p_signal && connects[i] -> p_Base == p_ob_hend
			&& connects[i]->p_hendler == p_hendler)
		{
			delete connects[i];
			connects.erase(connects.begin() + i);
			return;
		}
	}
}
void Base::emitSignal(T_SIGNAL p_signal, string& command) // метод передачи сигнала
{
	T_HENDLER hendler;
	(this->*p_signal)(command);
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->p_signal == p_signal)
		{
			hendler = connects[i]->p_hendler;
			(connects[i]->p_Base->*hendler)(command);
		}
	}
}
int Base::getClassNumber() // возврат номера класса, которому принадлежит используемый объект
{
	return cl_num;
}
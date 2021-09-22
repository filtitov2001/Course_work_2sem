#include <iostream>
#include <vector>

#include "Base.h"

using namespace std;

Base::Base(Base* parent) { // pairametrized constructor that defines a parent and assigns a child to it
	this->parent = parent;
	if (parent != NULL) {
		parent->children.push_back(this);
	}
}

Base::Base(Base* parent, string name) { // pairametrized constructor that defines a parent and assigns a child to it
	this->parent = parent;
	this->name = name;
	if (parent != NULL) {
	 	parent->children.push_back(this);
	}
}

void Base::setStatus(int activity) { // Method for detecting object fit
	this->activity = activity;
}

void Base::printChildren() { // The method of adjusting the condition of the objects
	cout << "The object " << this->getName().c_str();
	
	if (activity > 0) {
		cout << " is ready";
	} else {
		cout << " is not ready";
	}
	
	for (int i = 0; i < children.size(); i++) {
		cout << endl;
		children[i]->printChildren();
	}
}

void Base::inputName(string name) { // Method for setting name
	this->name = name;
}

void Base::printTree(string space) { // method of outputting the tree of the hierarchy of objects
	cout << space << this->getName().c_str();
	
	space += " ";
	for (int i = 0; i < children.size(); i++) {
		cout << endl;
		children[i]->printTree(space);
	}
}

Base* Base::searchParent(string name) { // method of searching for the object by name
	Base* search = NULL;
	
	if (name == this->getName().c_str()) {
		search = this;
	} else if (children.size() > 0) {
		for (int i = 0; i < children.size(); i++) {
			search = children[i]->searchParent(name);
			if (search != NULL)
				break;
		}
	}
	return search;
}

Base::~Base() { // destructor, function of objects of streaming and connections
	for (int i = 0; i < children.size(); i++) {
		delete children[i];
	}
	for (int i = 0; i < connects.size(); i++) {
		delete connects[i];
	}
}

string Base::getName() { // Method for getting name
	return name;
}

string Base::getTrailItem(string objectPath, int index_level) { // The method of obtaining an object along the way using the index
	int index_start, index_end, index_merchantLevel;
	index_start = index_merchantLevel = 1;
	
	while (index_start) {
		index_end = objectPath.find("/", index_start);
		if (index_merchantLevel == index_level)
			return objectPath.substr(index_start, index_end -
				index_start);
		index_start = index_end + 1;
		index_merchantLevel++;
	}
	return "";
}

Base* Base::getObjectRoot() { // method of searching for a root object
	Base* MerchantBase = this;
	
	while (MerchantBase->parent) {
		MerchantBase = MerchantBase->parent;
	}
	return MerchantBase;
}

Base* Base::getTrailObjectRoot(string objectTrail) { // The method of obtaining the path of the root object
	int index_level = 1;
	string TrailItem;
	
	Base* MerchantBase = getObjectRoot();
	
	if (getTrailItem(objectTrail, index_level) != MerchantBase->name)
		return NULL;
	
	index_level++;
	TrailItem = getTrailItem(objectTrail, index_level);
	
	while (!TrailItem.empty()) {
		MerchantBase = MerchantBase->getChild(TrailItem);
		if (!MerchantBase)
			return NULL;
		index_level++;
		TrailItem = getTrailItem(objectTrail, index_level);
	}
	return MerchantBase;
}

Base* Base::getObject(string objectPath) { // Method of drawing an object for subsequent input of a path
	if ((objectPath[0] == '/') && (objectPath[1] == '/'))
		return searchParent(objectPath.substr(2, string::npos));
	return getTrailObjectRoot(objectPath);
}

Base* Base::getChild(string nameChild) { // Method of receiving the child by name
	for (int i = 0; i < children.size(); i++) {
		if (children[i]->name == nameChild)
			return children[i];
	}
	return NULL;
}

void Base::setConnect(T_SIGNAL p_signal, Base* p_ob_hend, T_HENDLER p_hendler) { // Connection method
	o_sh* value;
	for (int i = 0; i < connects.size(); i++) {
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

void Base::deleteConnect(T_SIGNAL p_signal, Base* p_ob_hend, T_HENDLER p_hendler) { // Method for removing connections
	o_sh* value;
	for (int i = 0; i < connects.size(); i++) {
		value = connects[i];
		if (connects[i]->p_signal == p_signal && connects[i] -> p_Base == p_ob_hend
			&& connects[i]->p_hendler == p_hendler) {
			delete connects[i];
			connects.erase(connects.begin() + i);
			return;
		}
	}
}

void Base::emitSignal(T_SIGNAL p_signal, string& command) { // Signal transmission method
	T_HENDLER hendler;
	(this->*p_signal)(command);
	
	for (int i = 0; i < connects.size(); i++) {
		if (connects[i]->p_signal == p_signal) {
			hendler = connects[i]->p_hendler;
			(connects[i]->p_Base->*hendler)(command);
		}
	}
}

int Base::getClassNumber() { // Return the class number to which the used object belongs
	return cl_num;
}

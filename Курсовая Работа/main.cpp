
#include "cl_application.h"

int main() {
	cl_application ob_application(NULL); // Declaration of application object
	ob_application.build_tree(); // построение исходного дерева объектов building object's tree
	return ob_application.exec_app(); // Starting the system functioning
}

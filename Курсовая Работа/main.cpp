
#include "cl_application.h"

int main()
{
	cl_application ob_application(NULL); // объявление объекта приложение
	ob_application.build_tree(); // построение исходного дерева объектов
	return ob_application.exec_app(); // запуск функционирования системы
}

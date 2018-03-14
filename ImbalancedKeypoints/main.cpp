#include "ImbalancedKeypoints.h"
#include <QtWidgets/QApplication>

#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImbalancedKeypoints w;
	w.show();
	return a.exec();
}

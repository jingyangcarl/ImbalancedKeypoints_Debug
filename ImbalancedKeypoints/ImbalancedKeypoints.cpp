#include "ImbalancedKeypoints.h"

ImbalancedKeypoints::ImbalancedKeypoints(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	CPUStatusInitialization();

	QVTKWidget_1Initializer();
	QVTKWidget_2Initializer();
	QVTKWidget_3Initializer();
	QTextEditInitializer();

	SampleCloud_1Initializer();
	SampleCloud_2Initializer();
	SampleCloud_3Initializer();
	SampleMesh_1Initializer();
	SampleMesh_2Initializer();
	SampleMesh_3Initializer();

	EventFilterInstaller();
	PointPickUpInstaller();

	SignalSlotConnection();
	//QVTKWidget_1CloudConnection();
	//QVTKWidget_2CloudConnection();
	//QVTKWidget_3CloudConnection();
	QVTKWidget_1MeshConnection();
	QVTKWidget_2MeshConnection();
	QVTKWidget_3MeshConnection();

	CameraSynToQVTKWidget_1();

	QTextEditGreenOutput("If you need help, please enter \"show help\"");

}

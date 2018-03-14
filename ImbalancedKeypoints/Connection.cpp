#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::QVTKWidget_1CloudConnection() {
	// Carl: connect QVTKWidget_1 and cloud_1

	viewer_1->addPointCloud(cloud_1, "cloud_1");
	viewer_1->resetCamera();
	ui.qvtkWidget_1->update();

	qVTKWidget_1CloudConnection = true;
	QTextEditGrayOutput("QVTKWidget_1 and cloud_1 connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2CloudConnection() {
	// Carl: connect QVTKWidget_2 and cloud_2

	viewer_2->addPointCloud(cloud_2, "cloud_2");
	viewer_2->resetCamera();
	ui.qvtkWidget_2->update();

	qVTKWidget_2CloudConnection = true;
	QTextEditGrayOutput("QVTKWidget_2 and cloud_2 connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3CloudConnection() {
	// Carl: connect QVTKWidget_3 and cloud_3

	viewer_3->addPointCloud(cloud_3, "cloud_3");
	viewer_3->resetCamera();
	ui.qvtkWidget_3->update();

	qVTKWidget_3CloudConnection = true;
	QTextEditGrayOutput("QVTKWidget_3 and cloud_3 connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_1MeshConnection() {
	// Carl: connect QVTKWidget_1 and mesh_1

	viewer_1->addPolygonMesh(mesh_1, "mesh_1");
	viewer_1->resetCamera();
	ui.qvtkWidget_1->update();

	qVTKWidget_1MeshConnection = true;
	QTextEditGrayOutput("QVTKWidget_1 and mesh_1 connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2MeshConnection() {
	// Carl: connect QVTKWidget_2 and mesh_2

	viewer_2->addPolygonMesh(mesh_2, "mesh_2");
	viewer_2->resetCamera();
	ui.qvtkWidget_2->update();

	qVTKWidget_2MeshConnection = true;
	QTextEditGrayOutput("QVTKWidget_2 and mesh_2 connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3MeshConnection() {
	// Carl: connect QVTKWidget_3 and mesh_3

	viewer_3->addPolygonMesh(mesh_3, "mesh_3");
	viewer_3->resetCamera();
	ui.qvtkWidget_3->update();

	qVTKWidget_3MeshConnection = true;
	QTextEditGrayOutput("QVTKWidget_3 and mesh_3 connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_1MeshCloudConnection() {
	// Carl: connect QVTKWidget_1 and mesh_1Cloud

	viewer_1->addPointCloud(mesh_1Cloud, "mesh_1Cloud");
	viewer_1->resetCamera();
	ui.qvtkWidget_1->update();

	qVTKWidget_1MeshCloudConnection = true;
	QTextEditGrayOutput("QVTKWidget_1 and mesh_1Cloud connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2MeshCloudConnection() {
	// Carl: connect QVTKWidget_2 and mesh_2Cloud

	viewer_2->addPointCloud(mesh_2Cloud, "mesh_2Cloud");
	viewer_2->resetCamera();
	ui.qvtkWidget_2->update();

	qVTKWidget_2MeshCloudConnection = true;
	QTextEditGrayOutput("QVTKWidget_2 and mesh_2Cloud connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3MeshCloudConnection() {
	// Carl: connect QVTKWidget_3 and mesh_3Cloud

	viewer_3->addPointCloud(mesh_3Cloud, "mesh_3Cloud");
	viewer_3->resetCamera();
	ui.qvtkWidget_3->update();

	qVTKWidget_3MeshCloudConnection = true;
	QTextEditGrayOutput("QVTKWidget_3 and mesh_3Cloud connected");
	return;
}

void ImbalancedKeypoints::QVTKWidget_1CloudDeconnection() {
	// Carl: deconnect QVTKWidget_1 and cloud_1

	viewer_1->removePointCloud("cloud_1");
	viewer_1->updateCamera();
	ui.qvtkWidget_1->update();

	qVTKWidget_1CloudConnection = false;
	QTextEditGrayOutput("QVTKWidget_1 and cloud_1 connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2CloudDeconnection() {
	// Carl: deconnect QVTKWidget_2 and cloud_2
	viewer_2->removePointCloud("cloud_2");
	viewer_2->updateCamera();
	ui.qvtkWidget_2->update();

	qVTKWidget_2CloudConnection = false;
	QTextEditGrayOutput("QVTKWidget_2 and cloud_2 connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3CloudDeconnection() {
	// Carl: deconnect QVTKWidget_3 and cloud_3
	viewer_3->removePointCloud("cloud_3");
	viewer_3->updateCamera();
	ui.qvtkWidget_3->update();

	qVTKWidget_3CloudConnection = false;
	QTextEditGrayOutput("QVTKWidget_3 and cloud_3 connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_1MeshDeconnection() {
	// Carl: deconnect QVTKWidget_1 and mesh_1

	viewer_1->removePolygonMesh("mesh_1");
	viewer_1->updateCamera();
	ui.qvtkWidget_1->update();

	qVTKWidget_1MeshConnection = false;
	QTextEditGrayOutput("QVTKWidget_1 and mesh_1 connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2MeshDeconnection() {
	// Carl: deconnect QVTKWidget_2 and mesh_2

	viewer_2->removePolygonMesh("mesh_2");
	viewer_2->updateCamera();
	ui.qvtkWidget_2->update();

	qVTKWidget_2MeshConnection = false;
	QTextEditGrayOutput("QVTKWidget_2 and mesh_2 connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3MeshDeconnection() {
	// Carl: deconnect QVTKWidget_3 and mesh_3

	viewer_3->removePolygonMesh("mesh_3");
	viewer_3->updateCamera();
	ui.qvtkWidget_3->update();

	qVTKWidget_3MeshConnection = false;
	QTextEditGrayOutput("QVTKWidget_3 and mesh_3 connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_1MeshCloudDeconnection() {
	// Carl: deconnect QVTKWidget_1 and mesh_1Cloud

	viewer_1->removePointCloud("mesh_1Cloud");
	viewer_1->updateCamera();
	ui.qvtkWidget_1->update();

	qVTKWidget_1MeshCloudConnection = false;
	QTextEditGrayOutput("QVTKWidget_1 and mesh_1Cloud connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2MeshCloudDeconnection() {
	// Carl: deconnect QVTKWidget_2 and mesh_2Cloud

	viewer_2->removePointCloud("mesh_2Cloud");
	viewer_2->updateCamera();
	ui.qvtkWidget_2->update();

	qVTKWidget_2MeshCloudConnection = false;
	QTextEditGrayOutput("QVTKWidget_2 and mesh_2Cloud connection broken");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3MeshCloudDeconnection() {
	// Carl: deconnect QVTKWidget_3 and mesh_3Cloud

	viewer_3->removePointCloud("mesh_3Cloud");
	viewer_3->updateCamera();
	ui.qvtkWidget_3->update();

	qVTKWidget_3MeshCloudConnection = false;
	QTextEditGrayOutput("QVTKWidget_3 and mesh_3Cloud connection broken");
	return;
}

void ImbalancedKeypoints::SignalSlotConnection() {
	// Carl: connect singal and slot

	//qRegisterMetaType<ReturnMsgList>("ReturnMsgList");
	//connect(ui.actionTest, SIGNAL(triggered()), this, SLOT(ReturnMsgProcess(ReturnMsgList)));
	//connect(processor, &InstructionProcessor::SendReturnMsgList, this, &ImbalancedKeypoints::ReturnMsgProcess);

	QTextEditGrayOutput("Signal and slot connected");
	return;
}

#include "ImbalancedKeypoints.h"
#include <vtkRenderWindow.h>
#include <pcl\io\ply_io.h>

void ImbalancedKeypoints::CPUStatusInitialization() {
	SYSTEM_INFO sysInfo;
	FILETIME ftime, fsys, fuser;

	GetSystemInfo(&sysInfo);
	numProcessors = sysInfo.dwNumberOfProcessors;

	GetSystemTimeAsFileTime(&ftime);
	memcpy(&lastCPU, &ftime, sizeof(FILETIME));

	self = GetCurrentProcess();
	GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
	memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
	memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
}

void ImbalancedKeypoints::QVTKWidget_1Initializer() {
	// Carl: initializer of QVTKWidget_1

	ui.qvtkWidget_1->setWindowFlags(Qt::SubWindow);
	viewer_1.reset(new pcl::visualization::PCLVisualizer("Viewer_1", false));
	ui.qvtkWidget_1->SetRenderWindow(viewer_1->getRenderWindow());
	viewer_1->setupInteractor(ui.qvtkWidget_1->GetInteractor(), ui.qvtkWidget_1->GetRenderWindow());
	ui.qvtkWidget_1->update();

	QTextEditGrayOutput("QVTKWidget_1 initialization finished");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2Initializer() {
	// Carl: initializer of QVTKWidget_2

	ui.qvtkWidget_2->setWindowFlags(Qt::SubWindow);
	viewer_2.reset(new pcl::visualization::PCLVisualizer("Viewer_2", false));
	ui.qvtkWidget_2->SetRenderWindow(viewer_2->getRenderWindow());
	viewer_2->setupInteractor(ui.qvtkWidget_2->GetInteractor(), ui.qvtkWidget_2->GetRenderWindow());
	ui.qvtkWidget_2->update();

	QTextEditGrayOutput("QVTKWidget_2 initialization finished");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3Initializer() {
	// Carl: initializer of QVTKWidget_3

	ui.qvtkWidget_3->setWindowFlags(Qt::SubWindow);
	viewer_3.reset(new pcl::visualization::PCLVisualizer("Viewer_3", false));
	ui.qvtkWidget_3->SetRenderWindow(viewer_3->getRenderWindow());
	viewer_3->setupInteractor(ui.qvtkWidget_3->GetInteractor(), ui.qvtkWidget_3->GetRenderWindow());
	ui.qvtkWidget_3->update();

	QTextEditGrayOutput("QVTKWidget_3 initialization finished");
	return;
}

void ImbalancedKeypoints::QTextEditInitializer() {
	// Carl: set up the style of text edit
	
	QPalette palette = ui.textEdit->palette();
	palette.setColor(QPalette::Base, Qt::black);
	palette.setColor(QPalette::Text, Qt::white);
	ui.textEdit->setPalette(palette);
	
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.movePosition(QTextCursor::Start);
	ui.textEdit->setTextCursor(cursor);

	ui.textEdit->textCursor().insertText(">> ");
	printedContentLen = ui.textEdit->toPlainText().size();

	QTextEditGrayOutput("QTextEdit initialization finished");
	return;
}

void ImbalancedKeypoints::SampleCloud_1Initializer() {
	// Carl: set up the cloud pointer for cloud_1
	cloud_1.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
	cloud_1->points.resize(10000);

	srand(time(NULL));
	cloud_1Color.setRed((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_1Color.setGreen((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_1Color.setBlue((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);

	for (int i = 0; i < cloud_1->points.size(); i++) {
		cloud_1->points[i].x = 2014 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_1->points[i].y = 1024 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_1->points[i].z = 512 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_1->points[i].r = cloud_1Color.red();
		cloud_1->points[i].g = cloud_1Color.green();
		cloud_1->points[i].b = cloud_1Color.blue();
	}

	QTextEditGrayOutput("SampleCloud_1 initialization finished");
	return;
}

void ImbalancedKeypoints::SampleCloud_2Initializer() {
	// Carl: set up the cloud pointer for cloud_2
	cloud_2.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
	cloud_2->points.resize(10000);

	srand(time(NULL));
	cloud_2Color.setRed((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_2Color.setGreen((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_2Color.setBlue((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);

	for (int i = 0; i < cloud_2->points.size(); i++) {
		cloud_2->points[i].x = 512 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_2->points[i].y = 2014 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_2->points[i].z = 1024 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_2->points[i].r = cloud_1Color.red();
		cloud_2->points[i].g = cloud_1Color.green();
		cloud_2->points[i].b = cloud_1Color.blue();
	}

	QTextEditGrayOutput("SampleCloud_2 initialization finished");
	return;
}

void ImbalancedKeypoints::SampleCloud_3Initializer() {
	// Carl: set up the cloud pointer for cloud_3
	cloud_3.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
	cloud_3->points.resize(10000);

	srand(time(NULL));
	cloud_3Color.setRed((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_3Color.setGreen((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_3Color.setBlue((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);

	for (int i = 0; i < cloud_3->points.size(); i++) {
		cloud_3->points[i].x = 1024 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_3->points[i].y = 512 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_3->points[i].z = 2014 * ((rand() / (RAND_MAX + 1.0f)) - 0.5);
		cloud_3->points[i].r = cloud_1Color.red();
		cloud_3->points[i].g = cloud_1Color.green();
		cloud_3->points[i].b = cloud_1Color.blue();
	}

	QTextEditGrayOutput("SampleCloud_3 initialization finished");
	return;
}

void ImbalancedKeypoints::SampleMesh_1Initializer() {
	// Carl: set up the mesh pointer for mesh_1

	// Carl: clear mesh_1
	pcl::PolygonMesh empty;
	mesh_1 = empty;

	// Carl: load mesh_1
	mesh_1_path = "../MeshFile/Normal PLY/footbones.ply";
	mesh_1_path = "../MeshFile/Normal PLY/tetrahedron.ply";
	pcl::io::loadPLYFile(mesh_1_path.toStdString(), mesh_1);

	srand(time(NULL));
	mesh_1CloudColor.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);
	mesh_1CloudColor.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);
	mesh_1CloudColor.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);

	if (!mesh_1.cloud.data.empty()) {
		QTextEditGrayOutput("SampleMesh_1 initialization finished");
		mesh_1Cloud.reset(new pcl::PointCloud < pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_1.cloud, *mesh_1Cloud);
		for (int i = 0; i < mesh_1Cloud->points.size(); i++) {
			mesh_1Cloud->points[i].r = mesh_1CloudColor.red();
			mesh_1Cloud->points[i].g = mesh_1CloudColor.green();
			mesh_1Cloud->points[i].b = mesh_1CloudColor.blue();
		}
		QTextEditGrayOutput("SampleMesh_1Cloud initialization finished");
		isKeypoints_1.clear();
	}
	else
		QTextEditRedOutput("SampleMesh_1 initialization failed");

	return;
}

void ImbalancedKeypoints::SampleMesh_2Initializer() {
	// Carl: set up the mesh pointer for mesh_2

	// Carl: clear mesh_2
	pcl::PolygonMesh empty;
	mesh_2 = empty;

	// Carl: load mesh_2
	mesh_2_path = "../MeshFile/Normal PLY/footbones.ply";
	mesh_2_path = "../MeshFile/Normal PLY/tetrahedron.ply";
	pcl::io::loadPLYFile(mesh_2_path.toStdString(), mesh_2);

	srand(time(NULL));
	mesh_2CloudColor.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);
	mesh_2CloudColor.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);
	mesh_2CloudColor.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);

	if (!mesh_2.cloud.data.empty()) {
		QTextEditGrayOutput("SampleMesh_2 initialization finished");
		mesh_2Cloud.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_2.cloud, *mesh_2Cloud);
		for (int i = 0; i < mesh_2Cloud->points.size(); i++) {
			mesh_2Cloud->points[i].r = mesh_2CloudColor.red();
			mesh_2Cloud->points[i].g = mesh_2CloudColor.green();
			mesh_2Cloud->points[i].b = mesh_2CloudColor.blue();
		}
		QTextEditGrayOutput("SampleMesh_2Cloud initialization finished");
		isKeypoints_2.clear();
	}
	else
		QTextEditRedOutput("SampleMesh_2 initialization failed");

	return;
}

void ImbalancedKeypoints::SampleMesh_3Initializer() {
	// Carl: set up the mesh pointer for mesh_3

	// Carl: clear mesh_3
	pcl::PolygonMesh empty;
	mesh_3 = empty;

	// Carl: load mesh_3
	mesh_3_path = "../MeshFile/Normal PLY/footbones.ply";
	mesh_3_path = "../MeshFile/Normal PLY/tetrahedron.ply";
	pcl::io::loadPLYFile(mesh_3_path.toStdString(), mesh_3);

	srand(time(NULL));
	mesh_3CloudColor.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);
	mesh_3CloudColor.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);
	mesh_3CloudColor.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 256);

	if (!mesh_3.cloud.data.empty()) {
		QTextEditGrayOutput("SampleMesh_3 initialization finished");
		mesh_3Cloud.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_3.cloud, *mesh_3Cloud);
		for (int i = 0; i < mesh_3Cloud->points.size(); i++) {
			mesh_3Cloud->points[i].r = mesh_3CloudColor.red();
			mesh_3Cloud->points[i].g = mesh_3CloudColor.green();
			mesh_3Cloud->points[i].b = mesh_3CloudColor.blue();
		}
		QTextEditGrayOutput("SampleMesh_3Cloud initialization finished");
		isKeypoints_3.clear();
	}
	else
		QTextEditRedOutput("SampleMesh_3 initialization failed");

	return;
}

void ImbalancedKeypoints::CellularCloud_1Initializer(int size) {
	// Carl: set up the cloud for cellular automaton
	cloud_1.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
	cloud_1->points.resize(size*size);

	srand(time(NULL));
	cloud_1Color.setRed((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_1Color.setGreen((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_1Color.setBlue((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cloud_1->points[i*size + j].x = i;
			cloud_1->points[i*size + j].y = j;
			cloud_1->points[i*size + j].z = 0;
			cloud_1->points[i*size + j].r = isAlive_1.at(i*size + j) ? cloud_1Color.red() : 0;
			cloud_1->points[i*size + j].g = isAlive_1.at(i*size + j) ? cloud_1Color.green() : 0;
			cloud_1->points[i*size + j].b = isAlive_1.at(i*size + j) ? cloud_1Color.blue() : 0;
		}
	}

	QTextEditGrayOutput("Cloud_1 used for cellular automaton initialization finished");
	return;
}

void ImbalancedKeypoints::CellularCloud_2Initializer(int size) {
	// Carl: set up the cloud for cellular automaton
	cloud_2.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
	cloud_2->points.resize(size*size);

	srand(time(NULL));
	cloud_2Color.setRed((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_2Color.setGreen((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_2Color.setBlue((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cloud_2->points[i*size + j].x = i;
			cloud_2->points[i*size + j].y = j;
			cloud_2->points[i*size + j].z = 0;
			cloud_2->points[i*size + j].r = cloud_2Color.red();
			cloud_2->points[i*size + j].g = cloud_2Color.green();
			cloud_2->points[i*size + j].b = cloud_2Color.blue();
		}
	}
	isAlive_2.assign(size*size, true);

	QTextEditGrayOutput("Cloud_2 used for cellular automaton initialization finished");
	return;
}

void ImbalancedKeypoints::CellularCloud_3Initializer(int size) {
	// Carl: set up the cloud for cellular automaton
	cloud_3.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
	cloud_3->points.resize(size*size);

	srand(time(NULL));
	cloud_3Color.setRed((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_3Color.setGreen((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);
	cloud_3Color.setBlue((int)(256 * rand() / (RAND_MAX + 1.0f)) % 256);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cloud_3->points[i*size + j].x = i;
			cloud_3->points[i*size + j].y = j;
			cloud_3->points[i*size + j].z = 0;
			cloud_3->points[i*size + j].r = cloud_3Color.red();
			cloud_3->points[i*size + j].g = cloud_3Color.green();
			cloud_3->points[i*size + j].b = cloud_3Color.blue();
		}
	}
	isAlive_3.assign(size*size, true);

	QTextEditGrayOutput("Cloud_3 used for cellular automaton initialization finished");
	return;
}

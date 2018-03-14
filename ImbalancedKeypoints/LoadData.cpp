#include "ImbalancedKeypoints.h"
#include <qfiledialog.h>
#include <pcl\io\ply_io.h>
#include <pcl\io\obj_io.h>

#include "MeshLoader.h"
#include "CloudLoader.h"

QString ImbalancedKeypoints::CloudLoad(int view) {
	// Carl: load data for cloud

	QString tempPath;
	if (view == 1) { tempPath = cloud_1_path; cloud_1_path = QFileDialog::getOpenFileName(this, tr("Select Cloud File for Cloud 1"), "../CloudFile", tr("Cloud Files(*.pcd)")); }
	if (view == 2) { tempPath = cloud_2_path; cloud_2_path = QFileDialog::getOpenFileName(this, tr("Select Cloud File for Cloud 2"), "../CloudFile", tr("Cloud Files(*.pcd)")); }
	if (view == 3) { tempPath = cloud_3_path; cloud_3_path = QFileDialog::getOpenFileName(this, tr("Select Cloud File for Cloud 3"), "../CloudFile", tr("Cloud Files(*.pcd)")); }

	// Carl: initialization
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr tempCloud, empty;
	if (view == 1) { tempCloud = cloud_1; cloud_1 = empty; }
	if (view == 2) { tempCloud = cloud_2; cloud_2 = empty; }
	if (view == 3) { tempCloud = cloud_3; cloud_3 = empty; }

	CloudLoader cloudLoader(
		view == 1 ? cloud_1_path : view == 2 ? cloud_2_path : cloud_3_path,
		view == 1 ? cloud_1 : view == 2 ? cloud_2 : cloud_3
	);
	cloudLoader.SetCloudColor(view == 1 ? cloud_1Color : view == 2 ? cloud_2Color : cloud_3Color);

	// Carl: set timer
	clock_t start, stop;
	cloudLoader.start();
	start = clock();

	// Carl: lock textEdit and update info
	ui.textEdit->setEnabled(false);
	QTextCursor cursor = ui.textEdit->textCursor();
	ui.textEdit->setTextColor(QColor("green"));

	QString processInfo = "Cloud Loader Running - -";
	ui.textEdit->textCursor().insertText(processInfo);
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	// Carl: loader will call run() as a thread;
	int timer(0), changeTime(30);
	while (cloudLoader.isRunning() && ++timer) {
		// Carl: update processing information;
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		if ((timer % (4 * changeTime)) / changeTime == 0)
			cursor.insertText("- -");
		else if ((timer % (4 * changeTime)) / changeTime == 1)
			cursor.insertText("\\ \\");
		else if ((timer % (4 * changeTime)) / changeTime == 2)
			cursor.insertText("| |");
		else if ((timer % (4 * changeTime)) / changeTime == 3)
			cursor.insertText("/ /");

		// Carl: call event process;
		QCoreApplication::processEvents();
	}

	// Carl: eliminate processing infor
	for (int i = 0; i < processInfo.size(); i++)
		cursor.deletePreviousChar();

	// Carl: wait for the thread;
	stop = clock();
	cloudLoader.wait();

	// Carl: output info
	if (view == 1 ? (cloud_1 != NULL && !cloud_1->empty()) : view == 2 ? (cloud_2 != NULL && !cloud_2->empty()) : (cloud_3 != NULL && !cloud_3->empty())) {

		// Carl: output timer
		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Cloud Loader running finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
		content.append(QPair<QColor, QString>(QColor("yellow"),
			view == 1 ? ("[Points: " + QString::number(cloud_1->height*cloud_1->width) + "]  ") :
			view == 2 ? ("[Points: " + QString::number(cloud_2->height*cloud_2->width) + "]  ") :
			("[Points: " + QString::number(cloud_3->height*cloud_3->width) + "]  ")));
		QTextEditColoredOutput(content);
		content.clear();

		content.append(QPair<QColor, QString>(QColor("gray"), view == 1 ? "Cloud_1 Load finished: " : view == 2 ? "Cloud_2 Load finished: " : "Cloud_3 Load finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), view == 1 ? ("[" + cloud_1_path + "]") : view == 2 ? ("[" + cloud_2_path + "]") : ("[" + cloud_3_path + "]")));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput(view == 1 ? ("Cloud_1 Load failed: [" + cloud_1_path + "]") : view == 2 ? ("Cloud_2 Load failed: [" + cloud_2_path + "]") : ("Cloud_3 Load failed: [" + cloud_3_path + "]"));
		if (view == 1) { cloud_1 = tempCloud; cloud_1_path = tempPath; }
		if (view == 2) { cloud_2 = tempCloud; cloud_2_path = tempPath; }
		if (view == 3) { cloud_3 = tempCloud; cloud_3_path = tempPath; }
		return QString::null;
	}

	return view == 1 ? cloud_1_path : view == 2 ? cloud_2_path : cloud_3_path;
}

QString ImbalancedKeypoints::CloudLoad(int view, QString cloudFile) {
	// Carl: laod data for cloud
	QString tempPath;
	if (view == 1) { tempPath = cloud_1_path; cloud_1_path = cloudFile; }
	if (view == 2) { tempPath = cloud_2_path; cloud_2_path = cloudFile; }
	if (view == 3) { tempPath = cloud_3_path; cloud_3_path = cloudFile; }

	// Carl: initialization
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr tempCloud, empty;
	if (view == 1) { tempCloud = cloud_1; cloud_1 = empty; }
	if (view == 2) { tempCloud = cloud_2; cloud_2 = empty; }
	if (view == 3) { tempCloud = cloud_3; cloud_3 = empty; }

	CloudLoader cloudLoader(
		view == 1 ? cloud_1_path : view == 2 ? cloud_2_path : cloud_3_path,
		view == 1 ? cloud_1 : view == 2 ? cloud_2 : cloud_3
	);
	cloudLoader.SetCloudColor(view == 1 ? cloud_1Color : view == 2 ? cloud_2Color : cloud_3Color);

	// Carl: set timer
	clock_t start, stop;
	cloudLoader.start();
	start = clock();

	// Carl: lock textEdit and update info
	ui.textEdit->setEnabled(false);
	QTextCursor cursor = ui.textEdit->textCursor();
	ui.textEdit->setTextColor(QColor("green"));

	QString processInfo = "Cloud Loader Running - -";
	ui.textEdit->textCursor().insertText(processInfo);
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	// Carl: loader will call run() as a thread;
	int timer(0), changeTime(30);
	while (cloudLoader.isRunning() && ++timer) {
		// Carl: update processing information;
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		if ((timer % (4 * changeTime)) / changeTime == 0)
			cursor.insertText("- -");
		else if ((timer % (4 * changeTime)) / changeTime == 1)
			cursor.insertText("\\ \\");
		else if ((timer % (4 * changeTime)) / changeTime == 2)
			cursor.insertText("| |");
		else if ((timer % (4 * changeTime)) / changeTime == 3)
			cursor.insertText("/ /");

		// Carl: call event process;
		QCoreApplication::processEvents();
	}

	// Carl: eliminate processing infor
	for (int i = 0; i < processInfo.size(); i++)
		cursor.deletePreviousChar();

	// Carl: wait for the thread;
	stop = clock();
	cloudLoader.wait();

	// Carl: output info
	if (view == 1 ? !cloud_1->empty() : view == 2 ? !cloud_2->empty() : !cloud_3->empty()) {

		// Carl: output timer
		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Cloud Loader running finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
		content.append(QPair<QColor, QString>(QColor("yellow"),
			view == 1 ? ("[Points: " + QString::number(cloud_1->height*cloud_1->width) + "]  ") :
			view == 2 ? ("[Points: " + QString::number(cloud_2->height*cloud_2->width) + "]  ") :
			("[Points: " + QString::number(cloud_3->height*cloud_3->width) + "]  ")));
		QTextEditColoredOutput(content);
		content.clear();

		content.append(QPair<QColor, QString>(QColor("gray"), view == 1 ? "Cloud_1 Load finished: " : view == 2 ? "Cloud_2 Load finished: " : "Cloud_3 Load finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), view == 1 ? ("[" + cloud_1_path + "]") : view == 2 ? ("[" + cloud_2_path + "]") : ("[" + cloud_3_path + "]")));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput(view == 1 ? ("Cloud_1 Load failed: [" + cloud_1_path + "]") : view == 2 ? ("Cloud_2 Load failed: [" + cloud_2_path + "]") : ("Cloud_3 Load failed: [" + cloud_3_path + "]"));
		if (view == 1) { cloud_1 = tempCloud; cloud_1_path = tempPath; }
		if (view == 2) { cloud_2 = tempCloud; cloud_2_path = tempPath; }
		if (view == 3) { cloud_3 = tempCloud; cloud_3_path = tempPath; }
		return QString::null;
	}

	return view == 1 ? cloud_1_path : view == 2 ? cloud_2_path : cloud_3_path;
}

QString ImbalancedKeypoints::MeshLoad(int view) {
	// Carl: load data for mesh
	QString tempPath;
	if (view == 1) { tempPath = mesh_1_path; mesh_1_path = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 1"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)")); }
	if (view == 2) { tempPath = mesh_2_path; mesh_2_path = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 2"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)")); }
	if (view == 3) { tempPath = mesh_3_path; mesh_3_path = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 3"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)")); }
	
	// Carl: initialization
	pcl::PolygonMesh tempMesh, empty;
	if (view == 1) { tempMesh = mesh_1; mesh_1 = empty; }
	if (view == 2) { tempMesh = mesh_2; mesh_2 = empty; }
	if (view == 3) { tempMesh = mesh_3; mesh_3 = empty; }

	MeshLoader meshLoader(
		view == 1 ? mesh_1_path : view == 2 ? mesh_2_path : mesh_3_path,
		view == 1 ? mesh_1 : view == 2 ? mesh_2 : mesh_3,
		view == 1 ? mesh_1Cloud : view == 2 ? mesh_2Cloud : mesh_3Cloud, 
		view == 1 ? isKeypoints_1 : view == 2 ? isKeypoints_2 : isKeypoints_3);
	meshLoader.SetCloudColor(view == 1 ? mesh_1CloudColor : view == 2 ? mesh_2CloudColor : mesh_3CloudColor);

	// Carl: set timer
	clock_t start, stop;
	meshLoader.start();
	start = clock();

	// Carl: lock textEdit and update info
	ui.textEdit->setEnabled(false);
	QTextCursor cursor = ui.textEdit->textCursor();
	ui.textEdit->setTextColor(QColor("green"));

	QString processInfo = "Mesh Loader Running - -";
	ui.textEdit->textCursor().insertText(processInfo);
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	// Carl: loader will call run() as a thread;
	int timer(0), changeTime(30);
	while (meshLoader.isRunning() && ++timer) {
		// Carl: update processing information;
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		if ((timer % (4 * changeTime)) / changeTime == 0)
			cursor.insertText("- -");
		else if ((timer % (4 * changeTime)) / changeTime == 1)
			cursor.insertText("\\ \\");
		else if ((timer % (4 * changeTime)) / changeTime == 2)
			cursor.insertText("| |");
		else if ((timer % (4 * changeTime)) / changeTime == 3)
			cursor.insertText("/ /");

		// Carl: call event process;
		QCoreApplication::processEvents();
	}

	// Carl: eliminate processing infor
	for (int i = 0; i < processInfo.size(); i++)
		cursor.deletePreviousChar();

	// Carl: wait for the thread;
	stop = clock();
	meshLoader.wait();

	// Carl: output info
	if (view == 1 ? !mesh_1.cloud.data.empty() : view == 2 ? !mesh_2.cloud.data.empty() : !mesh_3.cloud.data.empty()) {

		// Carl: output timer
		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
		content.append(QPair<QColor, QString>(QColor("yellow"),
			view == 1 ? ("[Points: " + QString::number(mesh_1.cloud.height*mesh_1.cloud.width) + "]  ") :
			view == 2 ? ("[Points: " + QString::number(mesh_2.cloud.height*mesh_2.cloud.width) + "]  ") :
			("[Points: " + QString::number(mesh_3.cloud.height*mesh_3.cloud.width) + "]  ")));
		content.append(QPair<QColor, QString>(QColor("green"),
			view == 1 ? ("[Faces: " + QString::number(mesh_1.polygons.size()) + "]  ") :
			view == 2 ? ("[Faces: " + QString::number(mesh_2.polygons.size()) + "]  ") :
			("[Faces: " + QString::number(mesh_2.polygons.size()) + "]  ")));
		QTextEditColoredOutput(content);
		content.clear();

		content.append(QPair<QColor, QString>(QColor("gray"), view == 1 ? "Mesh_1 Load finished: " : view == 2 ? "Mesh_2 Load finished: " : "Mesh_3 Load finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), view == 1 ? ("[" + mesh_1_path + "]"): view == 2 ? ("[" + mesh_2_path + "]") : ("[" + mesh_3_path + "]")));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput(view == 1 ? ("Mesh_1 Load failed: [" + mesh_1_path + "]") : view == 2 ? ("Mesh_2 Load failed: [" + mesh_2_path + "]") : ("Mesh_3 Load failed: [" + mesh_3_path + "]"));
		if (view == 1) { mesh_1 = tempMesh; mesh_1_path = tempPath; }
		if (view == 2) { mesh_2 = tempMesh; mesh_2_path = tempPath; }
		if (view == 3) { mesh_3 = tempMesh; mesh_3_path = tempPath; }
		return QString::null;
	}

	return view == 1 ? mesh_1_path : view == 2 ? mesh_2_path : mesh_3_path;
}

QString ImbalancedKeypoints::MeshLoad(int view, QString meshFile) {
	// Carl: load data for mesh_1

	QString tempPath;
	if (view == 1) { tempPath = mesh_1_path; mesh_1_path = meshFile; }
	if (view == 2) { tempPath = mesh_2_path; mesh_2_path = meshFile; }
	if (view == 3) { tempPath = mesh_3_path; mesh_3_path = meshFile; }

	// Carl: initialization
	pcl::PolygonMesh tempMesh, empty;
	if (view == 1) { tempMesh = mesh_1; mesh_1 = empty; }
	if (view == 2) { tempMesh = mesh_2; mesh_2 = empty; }
	if (view == 3) { tempMesh = mesh_3; mesh_3 = empty; }

	MeshLoader meshLoader(
		view == 1 ? mesh_1_path : view == 2 ? mesh_2_path : mesh_3_path,
		view == 1 ? mesh_1 : view == 2 ? mesh_2 : mesh_3,
		view == 1 ? mesh_1Cloud : view == 2 ? mesh_2Cloud : mesh_3Cloud,
		view == 1 ? isKeypoints_1 : view == 2 ? isKeypoints_2 : isKeypoints_3);
	meshLoader.SetCloudColor(view == 1 ? mesh_1CloudColor : view == 2 ? mesh_2CloudColor : mesh_3CloudColor);

	// Carl: set timer
	clock_t start, stop;
	meshLoader.start();
	start = clock();

	// Carl: lock textEdit and update info
	ui.textEdit->setEnabled(false);
	QTextCursor cursor = ui.textEdit->textCursor();
	ui.textEdit->setTextColor(QColor("green"));

	QString processInfo = "Mesh Loader Running - -";
	ui.textEdit->textCursor().insertText(processInfo);
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	// Carl: loader will call run() as a thread;
	int timer(0), changeTime(30);
	while (meshLoader.isRunning() && ++timer) {
		// Carl: update processing information;
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		cursor.deletePreviousChar();
		if ((timer % (4 * changeTime)) / changeTime == 0)
			cursor.insertText("- -");
		else if ((timer % (4 * changeTime)) / changeTime == 1)
			cursor.insertText("\\ \\");
		else if ((timer % (4 * changeTime)) / changeTime == 2)
			cursor.insertText("| |");
		else if ((timer % (4 * changeTime)) / changeTime == 3)
			cursor.insertText("/ /");

		// Carl: call event process;
		QCoreApplication::processEvents();
	}
	// Carl: eliminate processing infor
	for (int i = 0; i < processInfo.size(); i++)
		cursor.deletePreviousChar();

	// Carl: wait for the thread;
	stop = clock();
	meshLoader.wait();

	// Carl: output info
	if (view == 1 ? !mesh_1.cloud.data.empty() : view == 2 ? !mesh_2.cloud.data.empty() : !mesh_3.cloud.data.empty()) {

		// Carl: output timer
		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
		content.append(QPair<QColor, QString>(QColor("yellow"),
			view == 1 ? ("[Points: " + QString::number(mesh_1.cloud.height*mesh_1.cloud.width) + "]  ") :
			view == 2 ? ("[Points: " + QString::number(mesh_2.cloud.height*mesh_2.cloud.width) + "]  ") :
			("[Points: " + QString::number(mesh_3.cloud.height*mesh_3.cloud.width) + "]  ")));
		content.append(QPair<QColor, QString>(QColor("green"),
			view == 1 ? ("[Faces: " + QString::number(mesh_1.polygons.size()) + "]  ") :
			view == 2 ? ("[Faces: " + QString::number(mesh_2.polygons.size()) + "]  ") :
			("[Faces: " + QString::number(mesh_2.polygons.size()) + "]  ")));
		QTextEditColoredOutput(content);
		content.clear();

		content.append(QPair<QColor, QString>(QColor("gray"), view == 1 ? "Mesh_1 Load finished: " : view == 2 ? "Mesh_2 Load finished: " : "Mesh_3 Load finished: "));
		content.append(QPair<QColor, QString>(QColor("green"), view == 1 ? ("[" + mesh_1_path + "]") : view == 2 ? ("[" + mesh_2_path + "]") : ("[" + mesh_3_path + "]")));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput(view == 1 ? ("Mesh_1 Load failed: [" + mesh_1_path + "]") : view == 2 ? ("Mesh_2 Load failed: [" + mesh_2_path + "]") : ("Mesh_3 Load failed: [" + mesh_3_path + "]"));
		if (view == 1) { mesh_1 = tempMesh; mesh_1_path = tempPath; }
		if (view == 2) { mesh_2 = tempMesh; mesh_2_path = tempPath; }
		if (view == 3) { mesh_3 = tempMesh; mesh_3_path = tempPath; }
		return QString::null;
	}

	return view == 1 ? mesh_1_path : view == 2 ? mesh_2_path : mesh_3_path;
}

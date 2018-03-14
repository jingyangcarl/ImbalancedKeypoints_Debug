#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::pp_callback_1(const pcl::visualization::PointPickingEvent& event, void*) {
	
	int index = event.getPointIndex();

	if (!isAlive_1.empty()) {

		if (isAlive_1.at(index)) {
			isAlive_1.at(index) = false;
			cloud_1->points[index].r = 0;
			cloud_1->points[index].g = 0;
			cloud_1->points[index].b = 0;
		}
		else {
			isAlive_1.at(index) = true;
			cloud_1->points[index].r = cloud_1Color.red();
			cloud_1->points[index].g = cloud_1Color.green();
			cloud_1->points[index].b = cloud_1Color.blue();
		}

		viewer_1->updatePointCloud(cloud_1, "cloud_1");
		ui.qvtkWidget_1->update();
	}
	else {
		//QTextEditRedOutput("Cellular automaton 1 hasn't been initialized");
		if (index < mesh_1Cloud->points.size()) {
			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Point in mesh_1Cloud with index "));
			content.append(QPair<QColor, QString>(QColor(mesh_1Cloud->points[index].r, mesh_1Cloud->points[index].g, mesh_1Cloud->points[index].b), QString::number(index)));
			content.append(QPair<QColor, QString>(QColor("gray"), " is selected at "));
			content.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number(mesh_1Cloud->points[index].x) + ", " + QString::number(mesh_1Cloud->points[index].y) + ", " + QString::number(mesh_1Cloud->points[index].z) + "]"));
			QTextEditColoredOutput(content);
		}
		else {
			QTextEditRedOutput("selected point is not on the mesh_1");
		}

		// show fitted plan
	}
}

void ImbalancedKeypoints::pp_callback_2(const pcl::visualization::PointPickingEvent& event, void*) {

	int index = event.getPointIndex();

	if (!isAlive_2.empty()) {

		if (isAlive_2.at(index)) {
			isAlive_2.at(index) = false;
			cloud_2->points[index].r = 0; 
			cloud_2->points[index].g = 0;
			cloud_2->points[index].b = 0;
		}
		else {
			isAlive_2.at(index) = true;
			cloud_2->points[index].r = cloud_2Color.red();
			cloud_2->points[index].g = cloud_2Color.green();
			cloud_2->points[index].b = cloud_2Color.blue();
		}

		viewer_2->updatePointCloud(cloud_2, "cloud_2");
		ui.qvtkWidget_2->update();
	}
	else {
		//QTextEditRedOutput("Cellular automaton 2 hasn't been initialized");
		if (index < mesh_2Cloud->points.size()) {
			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Point in mesh_2Cloud with index "));
			content.append(QPair<QColor, QString>(QColor(mesh_2Cloud->points[index].r, mesh_2Cloud->points[index].g, mesh_2Cloud->points[index].b), QString::number(index)));
			content.append(QPair<QColor, QString>(QColor("gray"), " is selected at "));
			content.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number(mesh_2Cloud->points[index].x) + ", " + QString::number(mesh_2Cloud->points[index].y) + ", " + QString::number(mesh_2Cloud->points[index].z) + "]"));
			QTextEditColoredOutput(content);
		}
		else {
			QTextEditRedOutput("selected point is not on the mesh_2");
		}
	}
}

void ImbalancedKeypoints::pp_callback_3(const pcl::visualization::PointPickingEvent & event, void *) {

	int index = event.getPointIndex();

	if (!isAlive_3.empty()) {

		if (isAlive_3.at(index)) {
			isAlive_3.at(index) = false;
			cloud_3->points[index].r = 0;
			cloud_3->points[index].g = 0;
			cloud_3->points[index].b = 0;
		}
		else {
			isAlive_3.at(index) = true;
			cloud_3->points[index].r = cloud_3Color.red();
			cloud_3->points[index].g = cloud_3Color.green();
			cloud_3->points[index].b = cloud_3Color.blue();
		}

		viewer_3->updatePointCloud(cloud_3, "cloud_3");
		ui.qvtkWidget_3->update();
	}
	else {
		//QTextEditRedOutput("Cellular automaton 3 hasn't been initialized");
		if (index < mesh_3Cloud->points.size()) {
			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Point in mesh_3Cloud with index "));
			content.append(QPair<QColor, QString>(QColor(mesh_3Cloud->points[index].r, mesh_3Cloud->points[index].g, mesh_3Cloud->points[index].b), QString::number(index)));
			content.append(QPair<QColor, QString>(QColor("gray"), " is selected at "));
			content.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number(mesh_3Cloud->points[index].x) + ", " + QString::number(mesh_3Cloud->points[index].y) + ", " + QString::number(mesh_3Cloud->points[index].z) + "]"));
			QTextEditColoredOutput(content);
		}
		else {
			QTextEditRedOutput("selected point is not on the mesh_3");
		}
	}

}

void ImbalancedKeypoints::PointPickUpInstaller() {
	viewer_1->registerPointPickingCallback(&ImbalancedKeypoints::pp_callback_1, *this);
	viewer_2->registerPointPickingCallback(&ImbalancedKeypoints::pp_callback_2, *this);
	viewer_3->registerPointPickingCallback(&ImbalancedKeypoints::pp_callback_3, *this);
}
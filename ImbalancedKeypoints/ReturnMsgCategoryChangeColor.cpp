#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryChangeColor(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD) {
		QVTKWidget_1CloudColorChange();
		viewer_1->updatePointCloud(cloud_1, "cloud_1");
		ui.qvtkWidget_1->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD) {
		QVTKWidget_1MeshCloudColorChange();
		viewer_1->updatePointCloud(mesh_1Cloud, "mesh_1Cloud");
		ui.qvtkWidget_1->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT) {
		QVTKWidget_1MeshKeypointColorChange();
		viewer_1->updatePointCloud(mesh_1Cloud, "mesh_1Cloud");
		ui.qvtkWidget_1->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH) {
		QVTKWidget_1MeshMatchedPointColorChange();
		viewer_1->updatePointCloud(mesh_1Cloud, "mesh_1Cloud");
		ui.qvtkWidget_1->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD) {
		QVTKWidget_2CloudColorChange();
		viewer_2->updatePointCloud(cloud_2, "cloud_2");
		ui.qvtkWidget_2->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD) {
		QVTKWidget_2MeshCloudColorChange();
		viewer_2->updatePointCloud(mesh_2Cloud, "mesh_2Cloud");
		ui.qvtkWidget_2->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT) {
		QVTKWidget_2MeshKeypointColorChange();
		viewer_2->updatePointCloud(mesh_2Cloud, "mesh_2Cloud");
		ui.qvtkWidget_2->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH) {
		QVTKWidget_2MeshMatchedPointColorChange();
		viewer_2->updatePointCloud(mesh_2Cloud, "mesh_2Cloud");
		ui.qvtkWidget_2->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD) {
		QVTKWidget_3CloudColorChange();
		viewer_3->updatePointCloud(cloud_3, "cloud_3");
		ui.qvtkWidget_3->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD) {
		QVTKWidget_3MeshCloudColorChange();
		viewer_3->updatePointCloud(mesh_3Cloud, "mesh_3Cloud");
		ui.qvtkWidget_3->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT) {
		QVTKWidget_3MeshKeypointColorChange();
		viewer_3->updatePointCloud(mesh_3Cloud, "mesh_3Cloud");
		ui.qvtkWidget_3->update();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH) {
		QVTKWidget_3MeshMatchedPointColorChange();
		viewer_3->updatePointCloud(mesh_3Cloud, "mesh_3Cloud");
		ui.qvtkWidget_3->update();
	}
}

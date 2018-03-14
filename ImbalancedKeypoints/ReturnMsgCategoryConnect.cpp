#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryConnect(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD) {
		QVTKWidget_1CloudConnection();
		CameraSynToQVTKWidget_2();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QVTKWidget_1MeshConnection();
		CameraSynToQVTKWidget_2();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD) {
		QVTKWidget_1MeshCloudConnection();
		CameraSynToQVTKWidget_2();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD) {
		QVTKWidget_2CloudConnection();
		CameraSynToQVTKWidget_3();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QVTKWidget_2MeshConnection();
		CameraSynToQVTKWidget_3();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD) {
		QVTKWidget_2MeshCloudConnection();
		CameraSynToQVTKWidget_3();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD) {
		QVTKWidget_3CloudConnection();
		CameraSynToQVTKWidget_1();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QVTKWidget_3MeshConnection();
		CameraSynToQVTKWidget_1();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD) {
		QVTKWidget_3MeshCloudConnection();
		CameraSynToQVTKWidget_1();
	}
}

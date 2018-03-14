#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryLoad(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD) {
		QVTKWidget_1CloudDeconnection();
		CloudLoad(1);
		QVTKWidget_1CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QVTKWidget_1MeshCloudDeconnection();
		QVTKWidget_1MeshDeconnection();
		MeshLoad(1);
		QVTKWidget_1MeshConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD) {
		QVTKWidget_2CloudDeconnection();
		CloudLoad(2);
		QVTKWidget_2CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QVTKWidget_2MeshCloudDeconnection();
		QVTKWidget_2MeshDeconnection();
		MeshLoad(2);
		QVTKWidget_2MeshConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD) {
		QVTKWidget_3CloudDeconnection();
		CloudLoad(3);
		QVTKWidget_3CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QVTKWidget_3MeshCloudDeconnection();
		QVTKWidget_3MeshDeconnection();
		MeshLoad(3);
		QVTKWidget_3MeshConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH + ReturnMsg::Q_VTK_WIDGET_2_MESH + ReturnMsg::Q_VTK_WIDGET_3_MESH) {

		QVTKWidget_1MeshCloudDeconnection();
		QVTKWidget_1MeshDeconnection();
		QVTKWidget_2MeshCloudDeconnection();
		QVTKWidget_2MeshDeconnection();
		QVTKWidget_3MeshCloudDeconnection();
		QVTKWidget_3MeshDeconnection();

		MeshLoad(3, MeshLoad(2, MeshLoad(1)));

		QVTKWidget_1MeshConnection();
		QVTKWidget_2MeshConnection();
		QVTKWidget_3MeshConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD + ReturnMsg::Q_VTK_WIDGET_2_CLOUD + ReturnMsg::Q_VTK_WIDGET_3_CLOUD) {

		QVTKWidget_1CloudDeconnection();
		QVTKWidget_2CloudDeconnection();
		QVTKWidget_3CloudDeconnection();

		CloudLoad(3, CloudLoad(2, CloudLoad(1)));

		QVTKWidget_1CloudConnection();
		QVTKWidget_2CloudConnection();
		QVTKWidget_3CloudConnection();

	}
}

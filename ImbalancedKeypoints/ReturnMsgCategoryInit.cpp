#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryInit(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD) {
		// Carl: deconnect relation between viewer and cloud_1, which is a necessary procedure
		QVTKWidget_1CloudDeconnection();
		SampleCloud_1Initializer();
		// Carl: synchronize with initial visual status
		//QVTKWidget_1CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		// Carl: deconnect relation between viewer and mesh_1, meshcloud_1, which is a necessary procedure
		QVTKWidget_1MeshDeconnection();
		QVTKWidget_1MeshCloudDeconnection();
		SampleMesh_1Initializer();
		// Carl: synchronize with initial visual status
		QVTKWidget_1MeshConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD) {
		// Carl: deconnect relation between viewer and cloud_2, which is a necessary procedure
		QVTKWidget_2CloudDeconnection();
		SampleCloud_2Initializer();
		// Carl: synchronize with initial visual status
		//QVTKWidget_2CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		// Carl: deconnect relation between viewer and mesh_2, meshcloud_2, which is a necessary procedure
		QVTKWidget_2MeshDeconnection();
		QVTKWidget_2MeshCloudDeconnection();
		SampleMesh_2Initializer();
		// Carl: synchronize with initial visual status
		QVTKWidget_2MeshConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD) {
		// Carl: deconnect relation between viewer and cloud_3, which is a necessary procedure
		QVTKWidget_3CloudDeconnection();
		SampleCloud_3Initializer();
		// Carl: synchronize with initial visual status
		//QVTKWidget_3CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		// Carl: deconnect relation between viewer and mesh_3, meshcloud_3, which is a necessary procedure
		QVTKWidget_3MeshDeconnection();
		QVTKWidget_3MeshCloudDeconnection();
		SampleMesh_3Initializer();
		// Carl: synchronize with initial visual status
		QVTKWidget_3MeshConnection();
	}
}

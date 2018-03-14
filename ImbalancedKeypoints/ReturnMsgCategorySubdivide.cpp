#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategorySubdivide(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS) {
		QTextEditGrayOutput("MeshSubdivisor mesh loaded");
	}
	else if ((*i).second == ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED) {
		QTextEditRedOutput("MeshSubdivisor mesh loading failed");
	}
	else if ((*i).second == ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS) {
		QTextEditGrayOutput("MeshSubdivisor mesh subdivision complete");
	}
	else if ((*i).second == ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_FAILED) {
		QTextEditRedOutput("ImbDetector mesh subdivision failed");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QTextEditGrayOutput("QVTKWidget_1 mesh subdivisor loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE) {
		QString filePath = (*(++i)).second;
		QVTKWidget_1MeshCloudDeconnection();
		QVTKWidget_1MeshDeconnection();
		MeshLoad(1, filePath);
		QVTKWidget_1MeshConnection();
		CameraSynToQVTKWidget_2();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QTextEditGrayOutput("QVTKWidget_2 mesh subdivisor loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE) {
		QString filePath = (*(++i)).second;
		QVTKWidget_2MeshCloudDeconnection();
		QVTKWidget_2MeshDeconnection();
		MeshLoad(2, filePath);
		QVTKWidget_2MeshConnection();
		CameraSynToQVTKWidget_3();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QTextEditGrayOutput("QVTKWidget_3 mesh subdivisor loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE) {
		QString filePath = (*(++i)).second;
		QVTKWidget_3MeshCloudDeconnection();
		QVTKWidget_3MeshDeconnection();
		MeshLoad(3, filePath);
		QVTKWidget_3MeshConnection();
		CameraSynToQVTKWidget_1();
	}
}

#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryMatch(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_SUCCESS) {
		QTextEditGrayOutput("MeshMatcher mesh 1 loaded");
	}
	else if ((*i).second == ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_FAILED) {
		QTextEditGrayOutput("MeshMatcher mesh 1 loading failed");
	}
	else if ((*i).second == ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_SUCCESS) {
		QTextEditGrayOutput("MeshMatcher mesh 2 loaded");
	}
	else if ((*i).second == ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_FAILED) {
		QTextEditGrayOutput("MeshMatcher mesh 2 loading failed");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QTextEditGrayOutput("QVTKWidget_1 mesh added");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE) {
		QString content = (*(++i)).second;
		QStringList contentEntries = content.split('\n');
		contentEntries.removeOne("");
		isMatched_1.clear();

		for (QStringList::iterator iter = contentEntries.begin(); iter != contentEntries.end(); iter++) {
			if ((*iter) == "1")	isMatched_1.push_back(true);
			if ((*iter) == "0") isMatched_1.push_back(false);
		}
		QTextEditGrayOutput("MeshMatcher mesh 1 list received");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QTextEditGrayOutput("QVTKWidget_2 mesh added");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE) {
		QString content = (*(++i)).second;
		QStringList contentEntries = content.split('\n');
		contentEntries.removeOne("");
		isMatched_2.clear();

		for (QStringList::iterator iter = contentEntries.begin(); iter != contentEntries.end(); iter++) {
			if ((*iter) == "1")	isMatched_2.push_back(true);
			if ((*iter) == "0") isMatched_2.push_back(false);
		}
		QTextEditGrayOutput("MeshMatcher mesh 2 list received");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QTextEditGrayOutput("QVTKWidget_3 mesh added");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE) {

		QString content = (*(++i)).second;
		QStringList contentEntries = content.split('\n');
		contentEntries.removeOne("");
		isMatched_3.clear();

		for (QStringList::iterator iter = contentEntries.begin(); iter != contentEntries.end(); iter++) {
			if ((*iter) == "1")	isMatched_3.push_back(true);
			if ((*iter) == "0") isMatched_3.push_back(false);
		}
		QTextEditGrayOutput("MeshMatcher mesh 3 list received");
	}

}

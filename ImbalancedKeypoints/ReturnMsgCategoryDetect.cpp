#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryDetect(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS) {
		QTextEditGrayOutput("ImbDetector mesh loaded");
	}
	else if ((*i).second == ReturnMsg::IMB_DETECTOR_LOAD_FAILED) {
		QTextEditRedOutput("ImbDetector mesh loading failed");
	}
	else if ((*i).second == ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS) {
		QTextEditGrayOutput("ImbDetector mesh keypoints detection complete");
	}
	else if ((*i).second == ReturnMsg::IMB_DETECTOR_DETECT_FAILED) {
		QTextEditRedOutput("ImbDetector mesh detection failed");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QTextEditGrayOutput("QVTKWidget_1 mesh imbalanced keypoints detector loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE) {
		QString content = (*(++i)).second;
		for (QString::iterator iter = content.begin(); iter != content.end(); iter++) {
			if ((*iter) == "1")	isKeypoints_1.push_back(true);
			if ((*iter) == "0") isKeypoints_1.push_back(false);
		}
		QTextEditGrayOutput("ImbDetector mesh keypoints_1 list received");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QTextEditGrayOutput("QVTKWidget_2 mesh imbalanced keypoints detector loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE) {
		QString content = (*(++i)).second;
		for (QString::iterator iter = content.begin(); iter != content.end(); iter++) {
			if ((*iter) == "1")	isKeypoints_2.push_back(true);
			if ((*iter) == "0") isKeypoints_2.push_back(false);
		}
		QTextEditGrayOutput("ImbDetector mesh keypoints_2 list received");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QTextEditGrayOutput("QVTKWidget_3 mesh imbalanced keypoints detector loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE) {
		QString content = (*(++i)).second;
		for (QString::iterator iter = content.begin(); iter != content.end(); iter++) {
			if ((*iter) == "1")	isKeypoints_3.push_back(true);
			if ((*iter) == "0") isKeypoints_3.push_back(false);
		}
		QTextEditGrayOutput("ImbDetector mesh keypoints_3 list received");
	}
}

#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryClear(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::Q_TEXT_EDIT) {
		ui.textEdit->clear();
		ui.textEdit->setTextColor(QColor("gray"));
		ui.textEdit->textCursor().insertText(">> ");
		printedContentLen = ui.textEdit->toPlainText().size();
		ui.textEdit->setTextColor(QColor("white"));
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD) {
		QVTKWidget_1CloudDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QVTKWidget_1MeshDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD) {
		QVTKWidget_1MeshCloudDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD) {
		QVTKWidget_2CloudDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QVTKWidget_2MeshDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD) {
		QVTKWidget_2MeshCloudDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD) {
		QVTKWidget_3CloudDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QVTKWidget_3MeshDeconnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD) {
		QVTKWidget_3MeshCloudDeconnection();
	}
}

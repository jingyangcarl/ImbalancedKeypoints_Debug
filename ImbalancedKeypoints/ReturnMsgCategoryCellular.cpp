#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryCellular(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::CELLULAR_AUTOMATON_1_INIT) {
		QVTKWidget_1CloudDeconnection();
		QString content = (*(++i)).second;
		QString sizeStr = content.split("|").at(0);
		QString isAliveStr = content.split("|").at(1);

		isAlive_1.clear();
		for (QString::iterator i = isAliveStr.begin(); i != isAliveStr.end(); i++)
			isAlive_1.push_back((*i) == "1" ? true : false);

		CellularCloud_1Initializer(sizeStr.toInt());
		QVTKWidget_1CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD_USERDEFINE) {
		QString content = (*(++i)).second;
		for (std::vector<bool>::iterator i = isAlive_1.begin(); i != isAlive_1.end(); i++)
			*i = content.at(i - isAlive_1.begin()) == "1" ? true : false;
		QVTKWidget_1CloudColorSwitch();
		viewer_1->updatePointCloud(cloud_1, "cloud_1");
		ui.qvtkWidget_1->update();
	}
	else if ((*i).second == ReturnMsg::CELLULAR_AUTOMATON_2_INIT) {
		QVTKWidget_2CloudDeconnection();
		int size = (*(++i)).second.toInt();
		CellularCloud_2Initializer(size);
		QVTKWidget_2CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD_USERDEFINE) {
		QString content = (*(++i)).second;
		for (std::vector<bool>::iterator i = isAlive_2.begin(); i != isAlive_2.end(); i++)
			*i = content.at(i - isAlive_2.begin()) == "1" ? true : false;
		QVTKWidget_2CloudColorSwitch();
		viewer_2->updatePointCloud(cloud_2, "cloud_2");
		ui.qvtkWidget_2->update();
	}
	else if ((*i).second == ReturnMsg::CELLULAR_AUTOMATON_3_INIT) {
		QVTKWidget_3CloudDeconnection();
		int size = (*(++i)).second.toInt();
		CellularCloud_3Initializer(size);
		QVTKWidget_3CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD_USERDEFINE) {
		QString content = (*(++i)).second;
		for (std::vector<bool>::iterator i = isAlive_3.begin(); i != isAlive_3.end(); i++)
			*i = content.at(i - isAlive_3.begin()) == "1" ? true : false;
		QVTKWidget_3CloudColorSwitch();
		viewer_3->updatePointCloud(cloud_3, "cloud_3");
		ui.qvtkWidget_3->update();
	}
}

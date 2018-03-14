#include "InstructionProcessor.h"

void InstructionProcessor::InstructionCategoryChangeColor() {

	if (instruction == "change color") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "change color 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
	}
	else if (instruction == "change color 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
	}
	else if (instruction == "change color 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "change color cloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "change color cloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
	}
	else if (instruction == "change color cloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
	}
	else if (instruction == "change color cloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "change color meshcloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "change color meshcloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
	}
	else if (instruction == "change color meshcloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
	}
	else if (instruction == "change color meshcloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "change color meshkp") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "change color meshkp 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
	}
	else if (instruction == "change color meshkp 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
	}
	else if (instruction == "change color meshkp 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "change color meshmp") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));
	}
	else if (instruction == "change color meshmp 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));
	}
	else if (instruction == "change color meshmp 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));
	}
	else if (instruction == "change color meshmp 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

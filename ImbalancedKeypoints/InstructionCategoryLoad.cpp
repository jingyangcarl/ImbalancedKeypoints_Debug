#include "InstructionProcessor.h"

void InstructionProcessor::InstructionCategoryLoad() {

	if (instruction == "load mesh") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_1_MESH + ReturnMsg::Q_VTK_WIDGET_2_MESH + ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "load mesh 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_1_MESH));
	}
	else if (instruction == "load mesh 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_2_MESH));
	}
	else if (instruction == "load mesh 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "load cloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_1_CLOUD + ReturnMsg::Q_VTK_WIDGET_2_CLOUD + ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "load cloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
	}
	else if (instruction == "load cloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
	}
	else if (instruction == "load cloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::LOAD, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

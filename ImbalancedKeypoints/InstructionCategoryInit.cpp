#include "InstructionProcessor.h"

void InstructionProcessor::InstructionCategoryInit() {

	if (instruction == "init") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "init 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
	}
	else if (instruction == "init 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
	}
	else if (instruction == "init 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "init cloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "init cloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
	}
	else if (instruction == "init cloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
	}
	else if (instruction == "init cloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "init mesh") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "init mesh 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
	}
	else if (instruction == "init mesh 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
	}
	else if (instruction == "init mesh 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::INIT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

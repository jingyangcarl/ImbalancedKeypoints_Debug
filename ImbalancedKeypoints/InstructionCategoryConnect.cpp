#include "InstructionProcessor.h"

void InstructionProcessor::InstructionCategoryConnect() {

	if (instruction == "connect") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "connect 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
	}
	else if (instruction == "connect 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
	}
	else if (instruction == "connect 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "connect cloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "connect cloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
	}
	else if (instruction == "connect cloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
	}
	else if (instruction == "connect cloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "connect mesh") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "connect mesh 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
	}
	else if (instruction == "connect mesh 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));
	}
	else if (instruction == "connect mesh 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "connect meshcloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "connect meshcloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
	}
	else if (instruction == "connect meshcloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
	}
	else if (instruction == "connect meshcloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

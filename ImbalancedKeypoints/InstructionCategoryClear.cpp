#include "InstructionProcessor.h"

void InstructionProcessor::InstructionCategoryClear() {

	if (instruction == "clear text") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_TEXT_EDIT));
	}
	else if (instruction == "clear") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "clear 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
	}
	else if (instruction == "clear 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
	}
	else if (instruction == "clear 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "clear cloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "clear cloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
	}
	else if (instruction == "clear cloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
	}
	else if (instruction == "clear cloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "clear mesh") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "clear mesh 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESH));
	}
	else if (instruction == "clear mesh 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESH));
	}
	else if (instruction == "clear mesh 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "clear meshcloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "clear meshcloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
	}
	else if (instruction == "clear meshcloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
	}
	else if (instruction == "clear meshcloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CLEAR, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

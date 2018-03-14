#include "InstructionProcessor.h"

void InstructionProcessor::InstructionCategoryShowStatus() {

	if (instruction == "show help") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_NOTE));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_MOUSE));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_KEY));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_INSTRUCTION));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_END));
	}
	else if (instruction == "show help note") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_NOTE));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_END));
	}
	else if (instruction == "show help mouse") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_MOUSE));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_END));
	}
	else if (instruction == "show help key") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_KEY));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_END));
	}
	else if (instruction == "show help instruction") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_INSTRUCTION));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_HELP_END));
	}
	else if (instruction == "show system") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::IMB_ENVIRONMENT));
	}
	else if (instruction == "show status") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "show status 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
	}
	else if (instruction == "show status 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
	}
	else if (instruction == "show status 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "show status color") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_COLOR));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_COLOR));
	}
	else if (instruction == "show status color 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_COLOR));
	}
	else if (instruction == "show status color 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_COLOR));
	}
	else if (instruction == "show status color 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_COLOR));
	}
	else if (instruction == "show status cloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "show status cloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_CLOUD));
	}
	else if (instruction == "show status cloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_CLOUD));
	}
	else if (instruction == "show status cloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_CLOUD));
	}
	else if (instruction == "show status mesh") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "show status mesh 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESH));
	}
	else if (instruction == "show status mesh 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESH));
	}
	else if (instruction == "show status mesh 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESH));
	}
	else if (instruction == "show status meshcloud") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "show status meshcloud 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
	}
	else if (instruction == "show status meshcloud 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
	}
	else if (instruction == "show status meshcloud 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else if (instruction == "show status meshkp") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "show status meshkp 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
	}
	else if (instruction == "show status meshkp 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
	}
	else if (instruction == "show status meshkp 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "show status meshmp") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));
	}
	else if (instruction == "show status meshmp 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));
	}
	else if (instruction == "show status meshmp 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));
	}
	else if (instruction == "show status meshmp 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

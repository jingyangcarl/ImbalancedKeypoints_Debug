#include "InstructionProcessor.h"

void InstructionProcessor::InstructionCategoryExit() {

	if (instruction == "exit") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::EXIT, ReturnMsg::EXIT));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}
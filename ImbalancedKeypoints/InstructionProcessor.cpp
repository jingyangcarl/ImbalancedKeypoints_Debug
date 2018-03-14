#include "InstructionProcessor.h"

ReturnMsgList InstructionProcessor::Process() {
	// Carl: process instructions

	returnMsgList.clear();

	if (instruction.startsWith("exit"))
		InstructionCategoryExit();
	else if (instruction.startsWith("clear"))
		InstructionCategoryClear();
	else if (instruction.startsWith("init"))
		InstructionCategoryInit();
	else if (instruction.startsWith("load"))
		InstructionCategoryLoad();
	else if (instruction.startsWith("connect"))
		InstructionCategoryConnect();
	else if (instruction.startsWith("show"))
		InstructionCategoryShowStatus();
	else if (instruction.startsWith("change color"))
		InstructionCategoryChangeColor();
	else if (instruction.startsWith("detect"))
		InstructionCategoryDetect();
	else if (instruction.startsWith("subdivide"))
		InstructionCategorySubdivide();
	else if (instruction.startsWith("surfacefit"))
		InstructionCategoryMeshSurfaceFit();
	else if (instruction.startsWith("cellular"))
		InstructionCategoryCellular();
	else if (instruction.startsWith("match"))
		InstructionCategoryMatch();
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

	
	return returnMsgList;
}

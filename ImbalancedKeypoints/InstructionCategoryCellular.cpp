#include "InstructionProcessor.h"
#include "CellularAutomaton.h"

void InstructionProcessor::InstructionCategoryCellular() {

	if (instruction == "cellular iter") {
		CellularAutomaton cellularAutomaton;
		QString content;

		if (!isAlive_1.empty()) {
			cellularAutomaton.SetAliveVector(isAlive_1);
			cellularAutomaton.SetSize(sqrt(isAlive_1.size()));
			isAlive_1 = cellularAutomaton.Iteration();
			for (std::vector<bool>::iterator i = isAlive_1.begin(); i != isAlive_1.end(); i++)
				content += QString::number(*i);

			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
		}
		else {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular 1 hasn't been initialized"));
		}
		content = "";

		if (!isAlive_2.empty()) {
			cellularAutomaton.SetAliveVector(isAlive_2);
			cellularAutomaton.SetSize(sqrt(isAlive_2.size()));
			isAlive_2 = cellularAutomaton.Iteration();
			for (std::vector<bool>::iterator i = isAlive_2.begin(); i != isAlive_2.end(); i++)
				content += QString::number(*i);

			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
		}
		else {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular 2 hasn't been initialized"));
		}
		content = "";

		if (!isAlive_3.empty()) {
			cellularAutomaton.SetAliveVector(isAlive_3);
			cellularAutomaton.SetSize(sqrt(isAlive_3.size()));
			isAlive_3 = cellularAutomaton.Iteration();
			for (std::vector<bool>::iterator i = isAlive_3.begin(); i != isAlive_3.end(); i++)
				content += QString::number(*i);

			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
		}
		else {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular 3 hasn't been initialized"));
		}
	}
	else if (instruction == "cellular iter 1") {

		if (!isAlive_1.empty()) {
			CellularAutomaton cellularAutomaton;
			cellularAutomaton.SetAliveVector(isAlive_1);
			cellularAutomaton.SetSize(sqrt(isAlive_1.size()));
			isAlive_1 = cellularAutomaton.Iteration();
			QString content;
			for (std::vector<bool>::iterator i = isAlive_1.begin(); i != isAlive_1.end(); i++)
				content += QString::number(*i);

			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::Q_VTK_WIDGET_1_CLOUD_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
		}
		else {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular 1 hasn't been initialized"));
		}
	}
	else if (instruction == "cellular iter 2") {

		if (!isAlive_2.empty()) {
			CellularAutomaton cellularAutomaton;
			cellularAutomaton.SetAliveVector(isAlive_2);
			cellularAutomaton.SetSize(sqrt(isAlive_2.size()));
			isAlive_2 = cellularAutomaton.Iteration();
			QString content;
			for (std::vector<bool>::iterator i = isAlive_2.begin(); i != isAlive_2.end(); i++)
				content += QString::number(*i);

			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::Q_VTK_WIDGET_2_CLOUD_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
		}
		else {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular 2 hasn't been initialized"));
		}
	}
	else if (instruction == "cellular iter 3") {

		if (!isAlive_3.empty()) {
			CellularAutomaton cellularAutomaton;
			cellularAutomaton.SetAliveVector(isAlive_3);
			cellularAutomaton.SetSize(sqrt(isAlive_3.size()));
			isAlive_3 = cellularAutomaton.Iteration();
			QString content;
			for (std::vector<bool>::iterator i = isAlive_3.begin(); i != isAlive_3.end(); i++)
				content += QString::number(*i);

			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::Q_VTK_WIDGET_3_CLOUD_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
		}
		else {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular 3 hasn't been initialized"));
		}
	}
	else if (instruction.startsWith("cellular 1 init")) {
		QString parameterStr;
		QString::iterator i;
		CellularAutomaton cellularAutomaton;
		QString content;

		// Carl: get parameter for cellular init

		if (instruction == "cellular 1 init") {
			// Carl: without parameter
			isAlive_1 = cellularAutomaton.Initialize(cellularAutomaton.GetSize());
			content = QString::number(cellularAutomaton.GetSize()) + "|";
			for (std::vector<bool>::iterator i = isAlive_1.begin(); i != isAlive_1.end(); i++)
				content += QString::number(*i);

			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::CELLULAR_AUTOMATON_1_INIT));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
		}
		else if (instruction.at(QString("cellular 1 init").size()) == " ") {
			// Carl: with parameter
			parameterStr = instruction.right(instruction.size() - QString("cellular 1 init ").size());

			for (i = parameterStr.begin(); i != parameterStr.end() && (*i).isNumber(); i++);

			if (i == parameterStr.end()) {
				isAlive_1 = cellularAutomaton.Initialize(parameterStr.toInt());
				content = QString::number(cellularAutomaton.GetSize()) + "|";
				for (std::vector<bool>::iterator i = isAlive_1.begin(); i != isAlive_1.end(); i++)
					content += QString::number(*i);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::CELLULAR_AUTOMATON_1_INIT));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, content));
			}
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular initialization parameter error"));
			}
		}
		else {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::RERROR, "Cellular initialization parameter error"));
		}
	}
	else if (instruction == "cellular 2 init") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::CELLULAR_AUTOMATON_2_INIT));

		CellularAutomaton cellularAutomaton;
		QString content = QString::number(cellularAutomaton.GetSize());

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
	}
	else if (instruction == "cellular 3 init") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CELLULAR, ReturnMsg::CELLULAR_AUTOMATON_3_INIT));

		CellularAutomaton cellularAutomaton;
		QString content = QString::number(cellularAutomaton.GetSize());

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

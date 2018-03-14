#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::InstructionProcess(QString instruction) {
	// Carl: process input

	processor = new InstructionProcessor(instruction);
	lastInstruction = instruction;
	instructionList.push_back(instruction);
	instructionPointer = instructionList.end();
	processor->SetCloud_1_Path(cloud_1_path);
	processor->SetCloud_2_Path(cloud_2_path);
	processor->SetCloud_3_Path(cloud_3_path);
	processor->SetAlive_1Vector(isAlive_1);
	processor->SetAlive_2Vector(isAlive_2);
	processor->SetAlive_3Vector(isAlive_3);
	processor->SetMesh_1_Path(mesh_1_path);
	processor->SetMesh_2_Path(mesh_2_path);
	processor->SetMesh_3_Path(mesh_3_path);

	// Carl: processor will call run() as a thread;
	clock_t start, stop;
	processor->start();
	start = clock();

	// Carl: get CPU
	int timer(0), changeTime(8);
	double processorAverageUsage = getProcesssorCurrentUsageDouble();
	double processorLastUsage, processorCurrentUsage, processorMaxUsage(0), processorMinUsage(100);
	QString processorAverageUsageStr;

	// Carl: lock textEdit and update information
	ui.textEdit->setEnabled(false);
	QTextCursor cursor = ui.textEdit->textCursor();
	ui.textEdit->setTextColor(QColor("green"));

	// Carl: output
	QString processInfo = "Instruction Processor Running - -\t[CPU: " + processorAverageUsageStr.setNum(processorAverageUsage, 'f', 6) + " %]";
	ui.textEdit->textCursor().insertText(processInfo);
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	while (processor->isRunning() && ++timer) {
		// Carl: update processing information;

		// Carl: delete outdated info
		for (int i = 0; i < 13 + processorAverageUsageStr.size(); i++)
			cursor.deletePreviousChar();

		// Carl: update animation
		
		if ((timer % (4 * changeTime)) / changeTime == 0)
			cursor.insertText("- -\t");
		else if ((timer % (4 * changeTime)) / changeTime == 1)
			cursor.insertText("\\ \\\t");
		else if ((timer % (4 * changeTime)) / changeTime == 2)
			cursor.insertText("| |\t");
		else if ((timer % (4 * changeTime)) / changeTime == 3)
			cursor.insertText("/ /\t");

		// Carl: calc CPU if needed
		processorCurrentUsage = getProcesssorCurrentUsageDouble();
		processorMaxUsage = processorCurrentUsage > processorMaxUsage ? processorCurrentUsage : processorMaxUsage;
		processorMinUsage = processorCurrentUsage < processorMinUsage ? processorCurrentUsage : processorMinUsage;
		processorAverageUsage = (processorAverageUsage * timer + processorCurrentUsage) / (timer + 1);

		// Carl: update CPU
		if (timer % changeTime == 0) {
			cursor.insertText("[CPU: " + processorAverageUsageStr.setNum(processorCurrentUsage, 'f', 6) + " %]");
			processorLastUsage = processorCurrentUsage;
		}
		else {
			cursor.insertText("[CPU: " + processorAverageUsageStr.setNum(processorLastUsage, 'f', 6) + " %]");
		}

		// Carl: call event process;
		QCoreApplication::processEvents();
	}
	// Carl: eliminate processing infor
	for (int i = 0; i < 43 + processorAverageUsageStr.size(); i++)
		cursor.deletePreviousChar();

	// Carl: wait for the thread;
	stop = clock();
	processor->wait();

	// Carl: output timer
	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("gray"), "Instruction processor running finished: "));
	content.append(QPair<QColor, QString>(QColor("green"), "[Time: " + QString::number((double)(stop - start) / 1000) + "s]  "));
	content.append(QPair<QColor, QString>(QColor("yellow"), "[CPU avg: " + QString::number(processorAverageUsage) + "%]  "));
	content.append(QPair<QColor, QString>(QColor("green"), "[CPU max: " + QString::number(processorMaxUsage) + "%]  "));
	content.append(QPair<QColor, QString>(QColor("green"), "[CPU min: " + QString::number(processorMinUsage) + "%]  "));
	QTextEditColoredOutput(content);

	// Carl: output
	returnMsgList = processor->GetReturnMsgList();
	ReturnMsgProcess();
	ui.textEdit->setEnabled(true);
	ui.textEdit->setFocus();

	return;
}
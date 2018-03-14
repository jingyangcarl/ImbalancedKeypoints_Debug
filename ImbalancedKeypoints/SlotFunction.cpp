#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::QVTKWidget_1FullScreen() {
	// Carl: set the status of Normal QVTKWidget to Full Screen Model
	ui.qvtkWidget_1->setWindowFlags(Qt::Window);
	ui.qvtkWidget_1->showFullScreen();

	QTextEditGrayOutput("QVTKWidget_1 shows in full screen");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2FullScreen() {
	// Carl: set the status of Normal QVTKWidget to Full Screen Model
	ui.qvtkWidget_2->setWindowFlags(Qt::Window);
	ui.qvtkWidget_2->showFullScreen();

	QTextEditGrayOutput("QVTKWidget_2 shows in full screen");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3FullScreen() {
	// Carl: set the status of Normal QVTKWidget to Full Screen Model
	ui.qvtkWidget_3->setWindowFlags(Qt::Window);
	ui.qvtkWidget_3->showFullScreen();

	QTextEditGrayOutput("QVTKWidget_3 shows in full screen");
	return;
}

void ImbalancedKeypoints::QVTKWidget_1NormalScreen() {
	// Carl: set the status of Full Screen QVTKWidget to Normal Model
	ui.qvtkWidget_1->setWindowFlags(Qt::SubWindow);
	ui.qvtkWidget_1->showNormal();

	QTextEditGrayOutput("QVTKWidget_1 shows in normal screen");
	return;
}

void ImbalancedKeypoints::QVTKWidget_2NormalScreen() {
	// Carl: set the status of Full Screen QVTKWidget to Normal Model
	ui.qvtkWidget_2->setWindowFlags(Qt::SubWindow);
	ui.qvtkWidget_2->showNormal();

	QTextEditGrayOutput("QVTKWidget_2 shows in normal screen");
	return;
}

void ImbalancedKeypoints::QVTKWidget_3NormalScreen() {
	// Carl: set the status of Full Screen QVTKWidget to Normal Model
	ui.qvtkWidget_3->setWindowFlags(Qt::SubWindow);
	ui.qvtkWidget_3->showNormal();

	QTextEditGrayOutput("QVTKWidget_3 shows in normal screen");
	return;
}

void ImbalancedKeypoints::QTextEditGrayOutput(QString content) {
	// Carl: output normal content to the text edit

	// Carl: save current input
	QString tempContent = "";
	if (!content.isEmpty())
		tempContent = ui.textEdit->toPlainText().right(ui.textEdit->toPlainText().size() - printedContentLen);

	// Carl: save current input
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit->setTextCursor(cursor);

	// Carl: delete current input
	for (int i = 0; i < tempContent.size(); i++)	cursor.deletePreviousChar();

	ui.textEdit->setTextColor(QColor("gray"));
	ui.textEdit->textCursor().insertText(content);
	ui.textEdit->setTextColor(QColor("gray"));
	ui.textEdit->textCursor().insertText("\n>> ");
	printedContentLen = ui.textEdit->toPlainText().size();

	// Carl: output saved current input 
	ui.textEdit->setTextColor(QColor("white"));
	ui.textEdit->textCursor().insertText(tempContent);

	// Carl: scroll to the end
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	return;
}

void ImbalancedKeypoints::QTextEditRedOutput(QString content) {
	// Carl: output error content to the text edit

	// Carl: save current input
	QString tempContent = ui.textEdit->toPlainText().right(ui.textEdit->toPlainText().size() - printedContentLen);
	
	// Carl: move cursor to the end of text
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit->setTextCursor(cursor);

	// Carl: delete current input
	for (int i = 0; i < tempContent.size(); i++)	cursor.deletePreviousChar();

	// Carl: output error info
	ui.textEdit->setTextColor(QColor("red"));
	ui.textEdit->textCursor().insertText(content);
	ui.textEdit->setTextColor(QColor("gray"));
	ui.textEdit->textCursor().insertText("\n>> ");
	printedContentLen = ui.textEdit->toPlainText().size();

	// Carl: output saved current input 
	ui.textEdit->setTextColor(QColor("white"));
	ui.textEdit->textCursor().insertText(tempContent);

	// Carl: scroll to the end
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	return;
}

void ImbalancedKeypoints::QTextEditGreenOutput(QString content) {
	// Carl: output help content to the text edit

	// Carl: save current input
	QString tempContent = ui.textEdit->toPlainText().right(ui.textEdit->toPlainText().size() - printedContentLen);

	// Carl: move cursor to the end of text
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit->setTextCursor(cursor);

	// Carl: delete current input
	for (int i = 0; i < tempContent.size(); i++)	cursor.deletePreviousChar();

	// Carl: output help info
	ui.textEdit->setTextColor(QColor("green"));
	ui.textEdit->textCursor().insertText(content);
	ui.textEdit->setTextColor(QColor("gray"));
	ui.textEdit->textCursor().insertText("\n>> ");
	printedContentLen = ui.textEdit->toPlainText().size();

	// Carl: output saved current input 
	ui.textEdit->setTextColor(QColor("white"));
	ui.textEdit->textCursor().insertText(tempContent);

	// Carl: scroll to the end
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	return;
}

void ImbalancedKeypoints::QTextEditColoredOutput(QVector<QPair<QColor, QString>> content) {
	// Carl: output colored content to the text edit
	QTextCursor cursor = ui.textEdit->textCursor();
	cursor.movePosition(QTextCursor::End);
	ui.textEdit->setTextCursor(cursor);

	for (QVector<QPair<QColor, QString>>::iterator i = content.begin(); i != content.end(); i++) {
		ui.textEdit->setTextColor((*i).first);
		ui.textEdit->textCursor().insertText((*i).second);
	}
	ui.textEdit->setTextColor(QColor("gray"));
	ui.textEdit->textCursor().insertText("\n>> ");
	printedContentLen = ui.textEdit->toPlainText().size();

	ui.textEdit->setTextColor(QColor("white"));
	ui.textEdit->verticalScrollBar()->setValue(ui.textEdit->verticalScrollBar()->maximum());

	return;
}

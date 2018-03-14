#include "ImbalancedKeypoints.h"
#include <QtGui>

bool ImbalancedKeypoints::eventFilter(QObject *object, QEvent *e){
	
	if (e->type() == QEvent::MouseButtonDblClick) {

		if (object == ui.qvtkWidget_1) {
			if(ui.qvtkWidget_1->windowFlags().testFlag(Qt::SubWindow))
				QVTKWidget_1FullScreen();
			else
				QVTKWidget_1NormalScreen();

			return true;
		}
		else if (object == ui.qvtkWidget_2) {
			if (ui.qvtkWidget_2->windowFlags().testFlag(Qt::SubWindow))
				QVTKWidget_2FullScreen();
			else
				QVTKWidget_2NormalScreen();

			return true;
		}
		else if (object == ui.qvtkWidget_3) {
			if (ui.qvtkWidget_3->windowFlags().testFlag(Qt::SubWindow))
				QVTKWidget_3FullScreen();
			else
				QVTKWidget_3NormalScreen();

			return true;
		}

	}
	else if (e->type() == QEvent::MouseMove ) {

		if (object == ui.qvtkWidget_1) {
			CameraSynToQVTKWidget_1();
			ui.qvtkWidget_2->resize(ui.qvtkWidget_1->size());
			ui.qvtkWidget_3->resize(ui.qvtkWidget_1->size());
			return false;
		}
		else if (object == ui.qvtkWidget_2) {
			CameraSynToQVTKWidget_2();
			ui.qvtkWidget_1->resize(ui.qvtkWidget_2->size());
			ui.qvtkWidget_3->resize(ui.qvtkWidget_2->size());
			return false;
		}
		else if (object == ui.qvtkWidget_3) {
			CameraSynToQVTKWidget_3();
			ui.qvtkWidget_1->resize(ui.qvtkWidget_3->size());
			ui.qvtkWidget_2->resize(ui.qvtkWidget_3->size());
			return false;
		}

	}
	else if (e->type() == QEvent::Wheel) {

		if (object == ui.qvtkWidget_1) {
			CameraSynToQVTKWidget_1();
			return false;
		}
		else if (object == ui.qvtkWidget_2) {
			CameraSynToQVTKWidget_2();
			return false;
		}
		else if (object == ui.qvtkWidget_3) {
			CameraSynToQVTKWidget_3();
			return false;
		}
	}
	else if (e->type() == QEvent::KeyPress) {

		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);

		if (keyEvent->modifiers() == Qt::ShiftModifier) {
			// Carl: shift status
			if (keyEvent->key() == Qt::Key_Up) {
				// Carl: output last instruction and process
				QTextCursor cursor = ui.textEdit->textCursor();
				cursor.movePosition(QTextCursor::End);
				ui.textEdit->setTextCursor(cursor);

				while (cursor.position() > printedContentLen)
					cursor.deletePreviousChar();

				ui.textEdit->setTextColor(QColor("white"));
				ui.textEdit->textCursor().insertText(lastInstruction);

				QString input = lastInstruction;
				QTextEditGrayOutput("");
				if (input.size())
					InstructionProcess(input);

				ui.textEdit->setTextColor(QColor("white"));
				return true;
			}
		}
		else {
			// Carl: normal status
			if (keyEvent->key() == Qt::Key_Return) {
				QString input = ui.textEdit->toPlainText().right(ui.textEdit->toPlainText().size() - printedContentLen);
				QTextEditGrayOutput("");
				if (input.size())
					InstructionProcess(input);

				ui.textEdit->setTextColor(QColor("white"));
				return true;
			}
			else if (keyEvent->key() == Qt::Key_Backspace) {

				if (ui.textEdit->toPlainText().size() <= printedContentLen)
					return true;
				else {
					if (!ui.textEdit->textCursor().hasSelection() && ui.textEdit->textCursor().position() <= printedContentLen)
						return true;
					else if (ui.textEdit->textCursor().hasSelection()) {
						if (ui.textEdit->textCursor().selectionEnd() < printedContentLen)
							return true;
						else if (ui.textEdit->textCursor().selectionStart() < printedContentLen) {
							int deletedLen = ui.textEdit->textCursor().selectionEnd() - printedContentLen;
							QTextCursor cursor = ui.textEdit->textCursor();
							cursor.setPosition(printedContentLen);
							ui.textEdit->setTextCursor(cursor);
							for (int i = 0; i < deletedLen; i++)
								cursor.deleteChar();
							ui.textEdit->setTextColor(QColor("white"));
							return true;
						}
						else if (ui.textEdit->textCursor().selectionStart() > printedContentLen) {
							int deletedLen = ui.textEdit->textCursor().selectedText().size();
							QTextCursor cursor = ui.textEdit->textCursor();
							cursor.setPosition(ui.textEdit->textCursor().selectionStart());
							ui.textEdit->setTextCursor(cursor);
							for (int i = 0; i < deletedLen; i++)
								cursor.deleteChar();
							ui.textEdit->setTextColor(QColor("white"));
							return true;
						}
						else
							return false;
					}
					else if (ui.textEdit->textCursor().position() > printedContentLen) {
						QTextCursor cursor = ui.textEdit->textCursor();
						cursor.deletePreviousChar();
						ui.textEdit->setTextColor(QColor("white"));
						return true;
					}
				}

			}
			else if (keyEvent->key() == Qt::Key_Up) {
				// Carl: output last instruction
				QTextCursor cursor = ui.textEdit->textCursor();
				cursor.movePosition(QTextCursor::End);
				ui.textEdit->setTextCursor(cursor);

				while (cursor.position() > printedContentLen)
					cursor.deletePreviousChar();

				ui.textEdit->setTextColor(QColor("white"));

				if (instructionPointer != instructionList.begin())
					instructionPointer--;

				if(!instructionList.isEmpty() && *instructionPointer != QString::null)
					ui.textEdit->textCursor().insertText(*instructionPointer);

				return true;
			}
			else if (keyEvent->key() == Qt::Key_Down) {
				// Carl: output last instruction
				QTextCursor cursor = ui.textEdit->textCursor();
				cursor.movePosition(QTextCursor::End);
				ui.textEdit->setTextCursor(cursor);

				while (cursor.position() > printedContentLen)
					cursor.deletePreviousChar();

				ui.textEdit->setTextColor(QColor("white"));

				if (instructionPointer != instructionList.end())
					instructionPointer++;

				if (!instructionList.isEmpty() && *instructionPointer != QString::null && instructionPointer != instructionList.end())
					ui.textEdit->textCursor().insertText(*instructionPointer);

				return true;
			}
			else if (ui.textEdit->textCursor().position() < printedContentLen) {
				QTextCursor cursor = ui.textEdit->textCursor();
				cursor.movePosition(QTextCursor::End);
				ui.textEdit->setTextCursor(cursor);
				ui.textEdit->setTextColor(QColor("white"));
				return false;
			}
		}
	}

	return false;
}

void ImbalancedKeypoints::EventFilterInstaller() {
	// Carl: install eventfilter for QWidgets;
	ui.qvtkWidget_1->installEventFilter(this);
	ui.qvtkWidget_2->installEventFilter(this);
	ui.qvtkWidget_3->installEventFilter(this);
	ui.textEdit->installEventFilter(this);

	QTextEditGrayOutput("eventFilter installation finished");
	return;
}
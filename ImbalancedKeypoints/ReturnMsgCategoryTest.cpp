#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryTest(ReturnMsgList::iterator &i) {
	QTextEditRedOutput("ui.qvtkWidget_1:\theight: " + QString::number(ui.qvtkWidget_1->size().height()) + "\twidth: " + QString::number(ui.qvtkWidget_1->size().width()));
	QTextEditRedOutput("ui.qvtkWidget_2:\theight: " + QString::number(ui.qvtkWidget_2->size().height()) + "\twidth: " + QString::number(ui.qvtkWidget_2->size().width()));
	QTextEditRedOutput("ui.qvtkWidget_3:\theight: " + QString::number(ui.qvtkWidget_3->size().height()) + "\twidth: " + QString::number(ui.qvtkWidget_3->size().width()));
}


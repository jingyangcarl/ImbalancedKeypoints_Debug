#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryUnknown(ReturnMsgList::iterator &i) {
	QTextEditRedOutput("Unknown instruction " + (*i).second + " processing failed");
}

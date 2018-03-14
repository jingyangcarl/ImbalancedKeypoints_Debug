#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryRerror(ReturnMsgList::iterator &i) {
	QTextEditRedOutput((*i).second);
}

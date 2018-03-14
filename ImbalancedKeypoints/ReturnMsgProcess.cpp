#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgProcess() {
	// Carl: process return cmessage
	for (ReturnMsgList::iterator i = returnMsgList.begin(); i != returnMsgList.end(); i++) {

		if ((*i).first == ReturnMsg::EXIT)
			ReturnMsgCategoryExit(i);
		else if ((*i).first == ReturnMsg::UNKNOWN)
			ReturnMsgCategoryUnknown(i);
		else if ((*i).first == ReturnMsg::USERDEFINE)
			ReturnMsgCategoryUserDefine(i);
		else if ((*i).first == ReturnMsg::RERROR)
			ReturnMsgCategoryRerror(i);
		else if ((*i).first == ReturnMsg::TEST)
			ReturnMsgCategoryTest(i);
		else if ((*i).first == ReturnMsg::CLEAR)
			ReturnMsgCategoryClear(i);
		else if ((*i).first == ReturnMsg::INIT)
			ReturnMsgCategoryInit(i);
		else if ((*i).first == ReturnMsg::LOAD)
			ReturnMsgCategoryLoad(i);
		else if ((*i).first == ReturnMsg::CONNECT)
			ReturnMsgCategoryConnect(i);
		else if ((*i).first == ReturnMsg::SHOWSTATUS)
			ReturnMsgCategoryShowStatus(i);
		else if ((*i).first == ReturnMsg::CHANGECOLOR)
			ReturnMsgCategoryChangeColor(i);
		else if ((*i).first == ReturnMsg::DETECT)
			ReturnMsgCategoryDetect(i);
		else if ((*i).first == ReturnMsg::SUBDIVIDE)
			ReturnMsgCategorySubdivide(i);
		else if ((*i).first == ReturnMsg::MESHSURFACEFIT)
			ReturnMsgCategoryMeshSurfaceFit(i);
		else if ((*i).first == ReturnMsg::CELLULAR)
			ReturnMsgCategoryCellular(i);
		else if ((*i).first == ReturnMsg::MATCH)
			ReturnMsgCategoryMatch(i);

	}
}

#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryShowStatus(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::IMB_HELP_NOTE) {
		QTextEditGreenOutput("---------------------------- NOTE -----------------------------");
		QTextEditGreenOutput("NOTE: meshcloud is the cloud data of mesh");
		QTextEditGreenOutput("NOTE: meshkeypoint is the keypoint data of mesh");
		QTextEditGreenOutput("NOTE: () default parameter");
		QTextEditGreenOutput("NOTE: [] nondefault parameter");
		QTextEditGreenOutput("NOTE: N parameter is a number");
	}
	else if ((*i).second == ReturnMsg::IMB_HELP_MOUSE) {
		QTextEditGreenOutput("---------------------------- MOUSE ----------------------------");
		QTextEditGreenOutput("L_DRAG: rotation");
		QTextEditGreenOutput("L_DOUBLE_CLICK: fullscreen");
		QTextEditGreenOutput("R_DRAG: zoom in");
		QTextEditGreenOutput("M_DRAG: translation");
		QTextEditGreenOutput("M_SCROLL: zoom in");
		QTextEditGreenOutput("SHIFT + L_CLICK: select point");
		QTextEditGreenOutput("SHIFT + L_DRAG: translation");
	}
	else if ((*i).second == ReturnMsg::IMB_HELP_KEY) {
		QTextEditGreenOutput("----------------------------- KEY -----------------------------");
		QTextEditGreenOutput("KEY_W :: line mesh mode");
		QTextEditGreenOutput("KEY_S :: face mesh mode");
		QTextEditGreenOutput("KEY_P :: point cloud mode");
		QTextEditGreenOutput("KEY_G :: show coordinate system");
		QTextEditGreenOutput("KEY_R :: reset camera");
		QTextEditGreenOutput("KEY_F :: change focus to the current pointer");
		QTextEditGreenOutput("KEY_J :: screenshot");
		QTextEditGreenOutput("KEY_+ :: increase point size");
		QTextEditGreenOutput("KEY_- :: decrease point size");
		QTextEditGreenOutput("KEY_UP :: show last instruction");
		QTextEditGreenOutput("SHIFT + KEY_UP :: process last instruction");
	}
	else if ((*i).second == ReturnMsg::IMB_HELP_INSTRUCTION) {
		QTextEditGreenOutput("------------------------- INSTRUSTION -------------------------");
		QTextEditGreenOutput("cellular [init/iter] (1/2/3) :: cellular automaton");
		QTextEditGreenOutput("change color (cloud/meshcloud/meshkp/meshmp) (1/2/3) :: change color");
		QTextEditGreenOutput("clear text :: clear text");
		QTextEditGreenOutput("clear (cloud/mesh/meshcloud) (1/2/3) :: destroy the connection between Widget and [cloud/mesh/meshcloud]");
		QTextEditGreenOutput("connect (cloud/mesh/meshcloud) (1/2/3) :: estabilish the connection between Widget and [cloud/mesh/meshcloud]");
		QTextEditGreenOutput("detect keypoint (1/2/3) :: keypoint detection");
		QTextEditGreenOutput("exit :: exit runtime");
		QTextEditGreenOutput("init (cloud/mesh) (1/2/3) :: load sample [cloud/mesh] for widget [1/2]");
		QTextEditGreenOutput("load [cloud/mesh] [1/2/3] :: load [cloud/mesh] for widget [1/2]");
		QTextEditGreenOutput("match point [1/2/3] [1/2/3] :: match different meshes");
		QTextEditGreenOutput("show help (note/mouse/key/instruction):: show help");
		QTextEditGreenOutput("show status (color/cloud/mesh/meshcloud/meshkp/meshmp) (1/2/3) :: show the status of viewers");
		QTextEditGreenOutput("subdivide self (plane2/plane3/plane5/plane6/weight2/weight4) (1/2/3) :: subdivide mesh by self created methods");
		QTextEditGreenOutput("subdivide tool [catmull/butterfly/loop] (1/2/3) :: subdivide mesh with tools in OpenMesh");
		QTextEditGreenOutput("surfacefit [plane2/plane3] [1/2/3] [N/all] :: neighbor points surface pitting, N represent the handle of the points");
	}
	else if ((*i).second == ReturnMsg::IMB_HELP_END) {
		QTextEditGreenOutput("----------------------------- END -----------------------------");
	}
	else if ((*i).second == ReturnMsg::IMB_ENVIRONMENT) {
		QTextEditColoredOutput(getProcesssorNumber());
		QTextEditColoredOutput(getProcesssorType());
		QTextEditColoredOutput(getProcesssorLevel());
		QTextEditColoredOutput(getProcesssorArchitecture());
		QTextEditColoredOutput(getProcesssorCurrentUsage());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_COLOR) {
		QTextEditColoredOutput(getQVTKWidget_1ColorStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD) {
		QTextEditGreenOutput(getQVTKWidget_1CloudStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QTextEditGreenOutput(getQVTKWidget_1MeshStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD) {
		QTextEditGreenOutput(getQVTKWidget_1MeshCloudStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT) {
		QTextEditGreenOutput(getKeypoints_1Status());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH) {
		QTextEditGreenOutput(getPointMatched_1Status());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_COLOR) {
		QTextEditColoredOutput(getQVTKWidget_2ColorStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD) {
		QTextEditGreenOutput(getQVTKWidget_2CloudStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QTextEditGreenOutput(getQVTKWidget_2MeshStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD) {
		QTextEditGreenOutput(getQVTKWidget_2MeshCloudStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT) {
		QTextEditGreenOutput(getKeypoints_2Status());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH) {
		QTextEditGreenOutput(getPointMatched_2Status());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_COLOR) {
		QTextEditColoredOutput(getQVTKWidget_3ColorStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD) {
		QTextEditGreenOutput(getQVTKWidget_3CloudStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QTextEditGreenOutput(getQVTKWidget_3MeshStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD) {
		QTextEditGreenOutput(getQVTKWidget_3MeshCloudStatus());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT) {
		QTextEditGreenOutput(getKeypoints_3Status());
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH) {
		QTextEditGreenOutput(getPointMatched_3Status());
	}
}

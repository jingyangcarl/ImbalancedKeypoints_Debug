#include "InstructionProcessor.h"
#include "MeshMatcher.h"

void InstructionProcessor::InstructionCategoryMatch() {

	if (instruction == "match point 1 2" || instruction == "match point 2 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshMatcher meshMatcher;
		// Carl: load first mesh
		if (meshMatcher.LoadMeshFile_1(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_SUCCESS));

			// Carl: load second mesh
			if (meshMatcher.LoadMeshFile_2(mesh_2_path.toStdString())) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_SUCCESS));

				// Carl: compare
				std::pair<std::string, std::string> meshReturn = meshMatcher.MeshPointComparision();
				QString mesh_1_return = QString::fromStdString(meshMatcher.MeshPointComparision().first);
				QString mesh_2_return = QString::fromStdString(meshMatcher.MeshPointComparision().second);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, mesh_1_return));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, mesh_2_return));

				// Carl: change colors
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));

				// Carl: connect cloud
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));

			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_FAILED));
	}
	else if (instruction == "match point 2 3" || instruction == "match point 3 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_2_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshMatcher meshMatcher;
		// Carl: load first mesh
		if (meshMatcher.LoadMeshFile_1(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_SUCCESS));

			// Carl: load second mesh
			if (meshMatcher.LoadMeshFile_2(mesh_3_path.toStdString())) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_SUCCESS));

				// Carl: compare
				std::pair<std::string, std::string> meshReturn = meshMatcher.MeshPointComparision();
				QString mesh_1_return = QString::fromStdString(meshMatcher.MeshPointComparision().first);
				QString mesh_2_return = QString::fromStdString(meshMatcher.MeshPointComparision().second);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, mesh_1_return));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, mesh_2_return));

				// Carl: change colors
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));

				// Carl: connect cloud
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));

			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_FAILED));
	}
	else if (instruction == "match point 3 1" || instruction == "match point 1 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_3_MESH));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshMatcher meshMatcher;
		// Carl: load first mesh
		if (meshMatcher.LoadMeshFile_1(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_SUCCESS));

			// Carl: load second mesh
			if (meshMatcher.LoadMeshFile_2(mesh_1_path.toStdString())) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_SUCCESS));

				// Carl: compare
				std::pair<std::string, std::string> meshReturn = meshMatcher.MeshPointComparision();
				QString mesh_1_return = QString::fromStdString(meshMatcher.MeshPointComparision().first);
				QString mesh_2_return = QString::fromStdString(meshMatcher.MeshPointComparision().second);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, mesh_1_return));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, mesh_2_return));

				// Carl: change colors
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH));

				// Carl: connect cloud
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));

			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::MATCH, ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_FAILED));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

#include "InstructionProcessor.h"
#include "ImbDetector.h"

void InstructionProcessor::InstructionCategoryDetect() {

	if (instruction == "detect keypoint") {

		ImbDetector imbDetector;

		// Carl: detect mesh_1
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		if (imbDetector.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (!isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));
				QString content;
				for (std::vector<bool>::iterator i = isKeypoints.begin(); i != isKeypoints.end(); i++)
					content += QString::number(*i);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));

		// Carl: detect mesh_2
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		if (imbDetector.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (!isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));
				QString content;
				for (std::vector<bool>::iterator i = isKeypoints.begin(); i != isKeypoints.end(); i++)
					content += QString::number(*i);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));

		// Carl: detect mesh_3
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		if (imbDetector.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (!isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));
				QString content;
				for (std::vector<bool>::iterator i = isKeypoints.begin(); i != isKeypoints.end(); i++)
					content += QString::number(*i);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
	}
	else if (instruction == "detect keypoint 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		ImbDetector imbDetector;
		if (imbDetector.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (!isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));
				QString content;
				for (std::vector<bool>::iterator i = isKeypoints.begin(); i != isKeypoints.end(); i++)
					content += QString::number(*i);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD));
	}
	else if (instruction == "detect keypoint 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		ImbDetector imbDetector;
		if (imbDetector.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (!isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));
				QString content;
				for (std::vector<bool>::iterator i = isKeypoints.begin(); i != isKeypoints.end(); i++)
					content += QString::number(*i);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD));
	}
	else if (instruction == "detect keypoint 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		ImbDetector imbDetector;
		if (imbDetector.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (!isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));
				QString content;
				for (std::vector<bool>::iterator i = isKeypoints.begin(); i != isKeypoints.end(); i++)
					content += QString::number(*i);

				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, content));
			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SHOWSTATUS, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CHANGECOLOR, ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT));
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::CONNECT, ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

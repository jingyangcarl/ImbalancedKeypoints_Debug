#include "InstructionProcessor.h"
#include "MeshSurfaceFitter.h"

void InstructionProcessor::InstructionCategoryMeshSurfaceFit() {
	// Carl: instruction has the pattern of "pointfit [fitting type] [point handle] [widget]

	instruction = instruction.right(instruction.size() - QString("surfacefit ").size());
	QStringList parameters = instruction.split(' ');
	QString fittingType;
	int widgetNum;
	MeshSurfaceFitter meshSurfacefitter;
	// Carl: remove space char
	parameters.removeAll("");

	if (parameters.size() == 3) {
		// Carl: analysis parameters
		QString::iterator iterWidgetNum, iterIndex;
		for (iterWidgetNum = parameters[1].begin(); iterWidgetNum != parameters[1].end() && (*iterWidgetNum).isDigit(); iterWidgetNum++);
		for (iterIndex = parameters[2].begin(); iterIndex != parameters[2].end() && (*iterIndex).isDigit(); iterIndex++);

		fittingType = parameters[0];
		if (meshSurfacefitter.isTypeValid(fittingType.toStdString())) {
			// Carl: fitting type check
			meshSurfacefitter.SetFittingType(fittingType.toStdString());

			if (iterWidgetNum == parameters[1].end()) {
				// Carl: widgetNum check
				widgetNum = parameters[1].toInt();

				if (widgetNum == 1) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::Q_VTK_WIDGET_1_MESH));

					if (meshSurfacefitter.LoadMeshFile(mesh_1_path.toStdString())) {
						returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_LOAD_SUCCESS));

						if (iterIndex == parameters[2].end()) {
							// Carl: get point handle
							meshSurfacefitter.SetPointHandle(parameters[2].toInt());
							meshSurfacefitter.SetOutputCloudPath("./oCloud_1.pcd");
							int returnValue = meshSurfacefitter.OneRingFitting();
							if (returnValue != -1) {
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_FITTING_SUCCESS));

								// Carl: write cloud
								QString filePath = QString::fromStdString(meshSurfacefitter.OutputCloud());
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::Q_VTK_WIDGET_1_CLOUD_USERDEFINE));
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
							}
							else
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_FITTING_FAILED));
						}
						else if (parameters[2] == "all") {
							// Carl: general test;

							std::string content = meshSurfacefitter.OverallOneRingFitting();
							returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::USERDEFINE));
							returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, QString::fromStdString(content)));
						}
					}
					else
						returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_LOAD_FAILED));
				}
				else if (widgetNum == 2) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::Q_VTK_WIDGET_2_MESH));

					if (meshSurfacefitter.LoadMeshFile(mesh_2_path.toStdString())) {
						returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_LOAD_SUCCESS));

						if (iterIndex == parameters[2].end()) {
							// Carl: get point handle
							meshSurfacefitter.SetPointHandle(parameters[2].toInt());
							meshSurfacefitter.SetOutputCloudPath("./oCloud_2.pcd");
							int returnValue = meshSurfacefitter.OneRingFitting();
							if (returnValue != -1) {
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_FITTING_SUCCESS));

								// Carl: write cloud
								QString filePath = QString::fromStdString(meshSurfacefitter.OutputCloud());
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::Q_VTK_WIDGET_2_CLOUD_USERDEFINE));
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
							}
							else
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_FITTING_FAILED));
						}
						else if (parameters[2] == "test") {
							// Carl: general test;

							std::string content = meshSurfacefitter.OverallOneRingFitting();
							returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::USERDEFINE));
							returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, QString::fromStdString(content)));
						}
					}
					else
						returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_LOAD_FAILED));
				}
				else if (widgetNum == 3) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::Q_VTK_WIDGET_3_MESH));

					if (meshSurfacefitter.LoadMeshFile(mesh_3_path.toStdString())) {
						returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_LOAD_SUCCESS));

						if (iterIndex == parameters[2].end()) {
							// Carl: get point handle
							meshSurfacefitter.SetPointHandle(parameters[2].toInt());
							meshSurfacefitter.SetOutputCloudPath("./oCloud_3.pcd");
							int returnValue = meshSurfacefitter.OneRingFitting();
							if (returnValue != -1) {
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_FITTING_SUCCESS));

								// Carl: write cloud
								QString filePath = QString::fromStdString(meshSurfacefitter.OutputCloud());
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::Q_VTK_WIDGET_3_CLOUD_USERDEFINE));
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
							}
							else
								returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_FITTING_FAILED));
						}
						else if (parameters[2] == "test") {
							// Carl: general test;

							std::string content = meshSurfacefitter.OverallOneRingFitting();
							returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::USERDEFINE));
							returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, QString::fromStdString(content)));
						}
						else
							returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_LOAD_FAILED));
					}
					else
						returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_LOAD_FAILED));
				}
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_ERROR_PARAMETER));
			}
			else
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_ERROR_PARAMETER));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_ERROR_PARAMETER));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::MESHSURFACEFIT, ReturnMsg::MESH_SURFACEFITTER_ERROR_PARAMETER));

}

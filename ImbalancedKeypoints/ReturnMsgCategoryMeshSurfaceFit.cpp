#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::ReturnMsgCategoryMeshSurfaceFit(ReturnMsgList::iterator &i) {

	if ((*i).second == ReturnMsg::MESH_SURFACEFITTER_ERROR_PARAMETER) {
		QTextEditRedOutput("MeshPointFitter parameter load failed");
	}
	else if ((*i).second == ReturnMsg::MESH_SURFACEFITTER_LOAD_FAILED) {
		QTextEditRedOutput("MeshPointFitter mesh loading failed");
	}
	else if ((*i).second == ReturnMsg::MESH_SURFACEFITTER_LOAD_SUCCESS) {
		QTextEditGrayOutput("MeshPointFitter mesh loaded");
	}
	else if ((*i).second == ReturnMsg::MESH_SURFACEFITTER_FITTING_FAILED) {
		QTextEditRedOutput("MeshPointFitter fitting failed");
	}
	else if ((*i).second == ReturnMsg::MESH_SURFACEFITTER_FITTING_SUCCESS) {
		QTextEditGrayOutput("MeshPointFitter fitting complete");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_MESH) {
		QTextEditGrayOutput("QVTKWidget_1 mesh point fitter loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_1_CLOUD_USERDEFINE) {
		QString filePath = (*(++i)).second;
		QVTKWidget_1CloudDeconnection();
		CloudLoad(1, filePath);
		QVTKWidget_1CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_MESH) {
		QTextEditGrayOutput("QVTKWidget_2 mesh point fitter loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_2_CLOUD_USERDEFINE) {
		QString filePath = (*(++i)).second;
		QVTKWidget_2CloudDeconnection();
		CloudLoad(2, filePath);
		QVTKWidget_2CloudConnection();
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_MESH) {
		QTextEditGrayOutput("QVTKWidget_3 mesh point fitter loading");
	}
	else if ((*i).second == ReturnMsg::Q_VTK_WIDGET_3_CLOUD_USERDEFINE) {
		QString filePath = (*(++i)).second;
		QVTKWidget_3CloudDeconnection();
		CloudLoad(3, filePath);
		QVTKWidget_3CloudConnection();
	}
	else if ((*i).second == ReturnMsg::USERDEFINE) {
		QString content = (*(++i)).second;
		QStringList contentEntries = content.split('\n');
		QVector<QPair<QColor, QString>> output;

		for (QStringList::iterator i = contentEntries.begin(); i != contentEntries.end(); i++) {

			int index = i - contentEntries.begin();

			if (index % 6 == 0) {
				output.append(QPair<QColor, QString>(QColor("gray"), "Vertex: " + QString::number(index / 6) + "  \t"));
				output.append(QPair<QColor, QString>(QColor("green"), "[inv3D: " + *i + "] "));
			}
			else if (index % 6 == 1)
				output.append(QPair<QColor, QString>(QColor("green"), "[det3D: " + *i + "] \t"));
			else if (index % 6 == 2)
				output.append(QPair<QColor, QString>(QColor("green"), "[inv2D: " + *i + "] "));
			else if (index % 6 == 3)
				output.append(QPair<QColor, QString>(QColor("green"), "[det2D: " + *i + "]     \t"));
			else if (index % 6 == 4)
				output.append(QPair<QColor, QString>(QColor("green"), "[inv1D: " + *i + "]"));
			else if (index % 6 == 5) {
				output.append(QPair<QColor, QString>(QColor("green"), "[det1D: " + *i + "]"));
				QTextEditColoredOutput(output);
				output.clear();
			}

			QCoreApplication::processEvents();
		}
	}
}

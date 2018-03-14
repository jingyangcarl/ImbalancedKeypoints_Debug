#pragma once
#include <qstring.h>
#include <qmetatype.h>

typedef QList<QPair<QString, QString>> ReturnMsgList;

struct ReturnMsg {
	// Carl: return type
	static QString EXIT;
	static QString UNKNOWN;
	static QString TEST;
	static QString RERROR;
	static QString CLEAR;
	static QString INIT;
	static QString LOAD;
	static QString CONNECT;
	static QString SHOWSTATUS;
	static QString CHANGECOLOR;
	static QString DETECT;
	static QString SUBDIVIDE;
	static QString MESHSURFACEFIT;
	static QString CELLULAR;
	static QString MATCH;
	static QString USERDEFINE;

	// Carl: return content
	static QString IMB_HELP_NOTE;
	static QString IMB_HELP_MOUSE;
	static QString IMB_HELP_KEY;
	static QString IMB_HELP_INSTRUCTION;
	static QString IMB_HELP_END;
	static QString IMB_ENVIRONMENT;
	static QString Q_TEXT_EDIT;
	static QString Q_VTK_WIDGET_1_CLOUD;
	static QString Q_VTK_WIDGET_1_CLOUD_USERDEFINE;
	static QString Q_VTK_WIDGET_1_MESH;
	static QString Q_VTK_WIDGET_1_MESHCLOUD;
	static QString Q_VTK_WIDGET_1_MESHKEYPOINT;
	static QString Q_VTK_WIDGET_1_MESHPOINTMATCH;
	static QString Q_VTK_WIDGET_1_MESH_USERDEFINE;
	static QString Q_VTK_WIDGET_1_COLOR;
	static QString Q_VTK_WIDGET_2_CLOUD;
	static QString Q_VTK_WIDGET_2_CLOUD_USERDEFINE;
	static QString Q_VTK_WIDGET_2_MESH;
	static QString Q_VTK_WIDGET_2_MESHCLOUD;
	static QString Q_VTK_WIDGET_2_MESHKEYPOINT;
	static QString Q_VTK_WIDGET_2_MESHPOINTMATCH;
	static QString Q_VTK_WIDGET_2_MESH_USERDEFINE;
	static QString Q_VTK_WIDGET_2_COLOR;
	static QString Q_VTK_WIDGET_3_CLOUD;
	static QString Q_VTK_WIDGET_3_CLOUD_USERDEFINE;
	static QString Q_VTK_WIDGET_3_MESH;
	static QString Q_VTK_WIDGET_3_MESHCLOUD;
	static QString Q_VTK_WIDGET_3_MESHKEYPOINT;
	static QString Q_VTK_WIDGET_3_MESHPOINTMATCH;
	static QString Q_VTK_WIDGET_3_MESH_USERDEFINE;
	static QString Q_VTK_WIDGET_3_COLOR;
	static QString IMB_DETECTOR_LOAD_SUCCESS;
	static QString IMB_DETECTOR_LOAD_FAILED;
	static QString IMB_DETECTOR_DETECT_SUCCESS;
	static QString IMB_DETECTOR_DETECT_FAILED;
	static QString MESH_SUBDIVISOR_LOAD_SUCCESS;
	static QString MESH_SUBDIVISOR_LOAD_FAILED;
	static QString MESH_SUBDIVISOR_SUBDIVISION_SUCCESS;
	static QString MESH_SUBDIVISOR_SUBDIVISION_FAILED;
	static QString MESH_SURFACEFITTER_LOAD_SUCCESS;
	static QString MESH_SURFACEFITTER_LOAD_FAILED;
	static QString MESH_SURFACEFITTER_FITTING_SUCCESS;
	static QString MESH_SURFACEFITTER_FITTING_FAILED;
	static QString MESH_SURFACEFITTER_ERROR_PARAMETER;
	static QString CELLULAR_AUTOMATON_1_INIT;
	static QString CELLULAR_AUTOMATON_2_INIT;
	static QString CELLULAR_AUTOMATON_3_INIT;
	static QString MESH_COMPARISON_MESH_1_LOAD_SUCCESS;
	static QString MESH_COMPARISON_MESH_1_LOAD_FAILED;
	static QString MESH_COMPARISON_MESH_2_LOAD_SUCCESS;
	static QString MESH_COMPARISON_MESH_2_LOAD_FAILED;

};

Q_DECLARE_METATYPE(ReturnMsg);

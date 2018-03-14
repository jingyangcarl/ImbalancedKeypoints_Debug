#include "ReturnMsg.h"

// Carl: return type
QString ReturnMsg::EXIT = "EXIT";
QString ReturnMsg::UNKNOWN = "UNKNOWN";
QString ReturnMsg::TEST = "TEST";
QString ReturnMsg::RERROR = "RERROR";
QString ReturnMsg::CLEAR = "CLEAR";
QString ReturnMsg::INIT = "INIT";
QString ReturnMsg::LOAD = "LOAD";
QString ReturnMsg::CONNECT = "CONNECT";
QString ReturnMsg::SHOWSTATUS = "SHOWSTATUS";
QString ReturnMsg::CHANGECOLOR = "CHANGECOLOR";
QString ReturnMsg::DETECT = "DETECT";
QString ReturnMsg::SUBDIVIDE = "SUBDIVIDE";
QString ReturnMsg::MESHSURFACEFIT = "MESHSURFACEFIT";
QString ReturnMsg::CELLULAR = "CELLULAR";
QString ReturnMsg::MATCH = "MATCH";
QString ReturnMsg::USERDEFINE = "USERDEFINE";

// Carl: return content
QString ReturnMsg::IMB_HELP_NOTE = "IMB_HELP_NOTE";
QString ReturnMsg::IMB_HELP_MOUSE = "IMB_HELP_MOUSE";
QString ReturnMsg::IMB_HELP_KEY = "IMB_HELP_KEY";
QString ReturnMsg::IMB_HELP_INSTRUCTION = "IMB_HELP_INSTRUCTION";
QString ReturnMsg::IMB_ENVIRONMENT = "IMB_ENVIRONMENT";
QString ReturnMsg::IMB_HELP_END = "IMB_HELP_END";
QString ReturnMsg::Q_TEXT_EDIT = "Q_TEXT_EDIT";
QString ReturnMsg::Q_VTK_WIDGET_1_CLOUD = "Q_VTK_WIDGET_1_CLOUD";
QString ReturnMsg::Q_VTK_WIDGET_1_CLOUD_USERDEFINE = "Q_VTK_WIDGET_1_CLOUD_USERDEFINE";
QString ReturnMsg::Q_VTK_WIDGET_1_MESH = "Q_VTK_WIDGET_1_MESH";
QString ReturnMsg::Q_VTK_WIDGET_1_MESHCLOUD = "Q_VTK_WIDGET_1_MESHCLOUD";
QString ReturnMsg::Q_VTK_WIDGET_1_MESHKEYPOINT = "Q_VTK_WIDGET_1_MESHKEYPOINT";
QString ReturnMsg::Q_VTK_WIDGET_1_MESHPOINTMATCH = "Q_VTK_WIDGET_1_MESHPOINTMATCH";
QString ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE = "Q_VTK_WIDGET_1_MESH_USERDEFINE";
QString ReturnMsg::Q_VTK_WIDGET_1_COLOR = "Q_VTK_WIDGET_1_COLOR";
QString ReturnMsg::Q_VTK_WIDGET_2_CLOUD = "Q_VTK_WIDGET_2_CLOUD";
QString ReturnMsg::Q_VTK_WIDGET_2_CLOUD_USERDEFINE = "Q_VTK_WIDGET_2_CLOUD_USERDEFINE";
QString ReturnMsg::Q_VTK_WIDGET_2_MESH = "Q_VTK_WIDGET_2_MESH";
QString ReturnMsg::Q_VTK_WIDGET_2_MESHCLOUD = "Q_VTK_WIDGET_2_MESHCLOUD";
QString ReturnMsg::Q_VTK_WIDGET_2_MESHKEYPOINT = "Q_VTK_WIDGET_2_MESHKEYPOINT";
QString ReturnMsg::Q_VTK_WIDGET_2_MESHPOINTMATCH = "Q_VTK_WIDGET_2_MESHPOINTMATCH";
QString ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE = "Q_VTK_WIDGET_2_MESH_USERDEFINE";
QString ReturnMsg::Q_VTK_WIDGET_2_COLOR = "Q_VTK_WIDGET_2_COLOR";
QString ReturnMsg::Q_VTK_WIDGET_3_CLOUD = "Q_VTK_WIDGET_3_CLOUD";
QString ReturnMsg::Q_VTK_WIDGET_3_CLOUD_USERDEFINE = "Q_VTK_WIDGET_3_CLOUD_USERDEFINE";
QString ReturnMsg::Q_VTK_WIDGET_3_MESH = "Q_VTK_WIDGET_3_MESH";
QString ReturnMsg::Q_VTK_WIDGET_3_MESHCLOUD = "Q_VTK_WIDGET_3_MESHCLOUD";
QString ReturnMsg::Q_VTK_WIDGET_3_MESHKEYPOINT = "Q_VTK_WIDGET_3_MESHKEYPOINT";
QString ReturnMsg::Q_VTK_WIDGET_3_MESHPOINTMATCH = "Q_VTK_WIDGET_3_MESHPOINTMATCH";
QString ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE = "Q_VTK_WIDGET_3_MESH_USERDEFINE";
QString ReturnMsg::Q_VTK_WIDGET_3_COLOR = "Q_VTK_WIDGET_3_COLOR";
QString ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS = "IMB_DETECTOR_LOAD_SUCCESS";
QString ReturnMsg::IMB_DETECTOR_LOAD_FAILED = "IMB_DETECTOR_LOAD_FAILED";
QString ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS = "IMB_DETECTOR_DETECT_SUCCESS";
QString ReturnMsg::IMB_DETECTOR_DETECT_FAILED = "IMB_DETECTOR_DETECT_FAILED";
QString ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS = "MESH_SUBDIVISOR_LOAD_SUCCESS";
QString ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED = "MESH_SUBDIVISOR_LOAD_FAILED";
QString ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS = "MESH_SUBDIVISOR_SUBDIVISION_SUCCESS";
QString ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_FAILED = "MESH_SUBDIVISOR_SUBDIVISION_FAILED";
QString ReturnMsg::MESH_SURFACEFITTER_LOAD_SUCCESS = "MESH_SURFACEFITTER_LOAD_SUCCESS";
QString ReturnMsg::MESH_SURFACEFITTER_LOAD_FAILED = "MESH_SURFACEFITTER_LOAD_FAILED";
QString ReturnMsg::MESH_SURFACEFITTER_FITTING_SUCCESS = "MESH_SURFACEFITTER_FITTING_SUCCESS";
QString ReturnMsg::MESH_SURFACEFITTER_FITTING_FAILED = "MESH_SURFACEFITTER_FITTING_FAILED";
QString ReturnMsg::MESH_SURFACEFITTER_ERROR_PARAMETER = "MESH_SURFACEFITTER_ERROR_PARAMETER";
QString ReturnMsg::CELLULAR_AUTOMATON_1_INIT = "CELLULAR_AUTOMATON_1_INIT";
QString ReturnMsg::CELLULAR_AUTOMATON_2_INIT = "CELLULAR_AUTOMATON_2_INIT";
QString ReturnMsg::CELLULAR_AUTOMATON_3_INIT = "CELLULAR_AUTOMATON_3_INIT";
QString ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_SUCCESS = "MESH_COMPARISON_MESH_1_LOAD_SUCCESS";
QString ReturnMsg::MESH_COMPARISON_MESH_1_LOAD_FAILED = "MESH_COMPARISON_MESH_1_LOAD_FAILED";
QString ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_SUCCESS = "MESH_COMPARISON_MESH_2_LOAD_SUCCESS";
QString ReturnMsg::MESH_COMPARISON_MESH_2_LOAD_FAILED = "MESH_COMPARISON_MESH_2_LOAD_FAILED";

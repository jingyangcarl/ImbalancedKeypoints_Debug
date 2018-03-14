#pragma once

#include <QtWidgets/QMainWindow>
#include <qscrollbar.h>
#include <qfile.h>
#include "ui_ImbalancedKeypoints.h"
#include <Windows.h>

#include "InstructionProcessor.h"
#include <pcl\point_cloud.h>
#include <pcl\visualization\pcl_visualizer.h>

class ImbalancedKeypoints : public QMainWindow
{
	Q_OBJECT

public:
	ImbalancedKeypoints(QWidget *parent = Q_NULLPTR);

private:
	Ui::ImbalancedKeypointsClass ui;

	int printedContentLen = 0;
	// Carl: used for saving the length of excuted content;

	// Carl: cloud data;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_1;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_2;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_3;
	// Carl: cloud path
	QString cloud_1_path;
	QString cloud_2_path;
	QString cloud_3_path;
	// Carl: cloud point vectors;
	std::vector<bool> isAlive_1;
	std::vector<bool> isAlive_2;
	std::vector<bool> isAlive_3;
	// Carl: cloud point point color
	QColor cloud_1Color;
	QColor cloud_2Color;
	QColor cloud_3Color;

	// Carl: mesh data;
	pcl::PolygonMesh mesh_1;
	pcl::PolygonMesh mesh_2;
	pcl::PolygonMesh mesh_3;
	// Carl: mesh path
	QString mesh_1_path;
	QString mesh_2_path;
	QString mesh_3_path;
	// Carl: mesh keypoints cloud
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr mesh_1Cloud;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr mesh_2Cloud;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr mesh_3Cloud;
	// Carl: mesh keypoints vector
	std::vector<bool> isKeypoints_1;
	std::vector<bool> isKeypoints_2;
	std::vector<bool> isKeypoints_3;
	// Carl: mesh comparision vector
	std::vector<bool> isMatched_1;
	std::vector<bool> isMatched_2;
	std::vector<bool> isMatched_3;
	// Carl: mesh point color
	QColor mesh_1CloudColor;
	QColor mesh_2CloudColor;
	QColor mesh_3CloudColor;
	QColor mesh_1KeypointColor;
	QColor mesh_2KeypointColor;
	QColor mesh_3KeypointColor;

	// Carl: pcl viewers;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_1;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_2;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_3;

	// Carl: instruction processor;
	InstructionProcessor *processor;
	QString lastInstruction;
	QStringList instructionList;
	QStringList::iterator instructionPointer = instructionList.end();

	// Carl: used for storing return message
	ReturnMsgList returnMsgList;

	// Carl: CPU
	ULARGE_INTEGER lastCPU;
	ULARGE_INTEGER lastSysCPU;
	ULARGE_INTEGER lastUserCPU;
	int numProcessors;
	HANDLE self;

	// Carl: widgets status;
	bool qVTKWidget_1CloudConnection = false;
	bool qVTKWidget_2CloudConnection = false;
	bool qVTKWidget_3CloudConnection = false;
	bool qVTKWidget_1MeshConnection = false;
	bool qVTKWidget_2MeshConnection = false;
	bool qVTKWidget_3MeshConnection = false;
	bool qVTKWidget_1MeshCloudConnection = false;
	bool qVTKWidget_2MeshCloudConnection = false;
	bool qVTKWidget_3MeshCloudConnection = false;

	/******************** Initialization.cpp ********************/
	void CPUStatusInitialization();
	void QVTKWidget_1Initializer();
	void QVTKWidget_2Initializer();
	void QVTKWidget_3Initializer();
	void QTextEditInitializer();
	void SampleCloud_1Initializer();
	void SampleCloud_2Initializer();
	void SampleCloud_3Initializer();
	void SampleMesh_1Initializer();
	void SampleMesh_2Initializer();
	void SampleMesh_3Initializer();
	void CellularCloud_1Initializer(int size);
	void CellularCloud_2Initializer(int size);
	void CellularCloud_3Initializer(int size);

	/******************** Connection.cpp ********************/
	void QVTKWidget_1CloudConnection();
	void QVTKWidget_2CloudConnection();
	void QVTKWidget_3CloudConnection();
	void QVTKWidget_1MeshConnection();
	void QVTKWidget_2MeshConnection();
	void QVTKWidget_3MeshConnection();
	void QVTKWidget_1MeshCloudConnection();
	void QVTKWidget_2MeshCloudConnection();
	void QVTKWidget_3MeshCloudConnection();
	void QVTKWidget_1CloudDeconnection();
	void QVTKWidget_2CloudDeconnection();
	void QVTKWidget_3CloudDeconnection();
	void QVTKWidget_1MeshDeconnection();
	void QVTKWidget_2MeshDeconnection();
	void QVTKWidget_3MeshDeconnection();
	void QVTKWidget_1MeshCloudDeconnection();
	void QVTKWidget_2MeshCloudDeconnection();
	void QVTKWidget_3MeshCloudDeconnection();
	void SignalSlotConnection();

	/******************** LoadData.cpp ********************/
	QString CloudLoad(int);
	QString CloudLoad(int, QString);
	QString MeshLoad(int);
	QString MeshLoad(int, QString);

	/******************** EventFilter.cpp ********************/
	bool eventFilter(QObject *, QEvent *);
	void EventFilterInstaller();

	/******************** PointPickUp.cpp ********************/
	void PointPickUpInstaller();
	void pp_callback_1(const pcl::visualization::PointPickingEvent&, void*);
	void pp_callback_2(const pcl::visualization::PointPickingEvent&, void*);
	void pp_callback_3(const pcl::visualization::PointPickingEvent&, void*);

	/******************** SlotFunction.cpp ********************/
public slots:
	// Carl: the member functions to make normal screen fullscreen;
	void QVTKWidget_1FullScreen();
	void QVTKWidget_2FullScreen();
	void QVTKWidget_3FullScreen();
	// Carl: the member functions to make full screen normal size;
	void QVTKWidget_1NormalScreen();
	void QVTKWidget_2NormalScreen();
	void QVTKWidget_3NormalScreen();
	// Carl: the member functions deal with the output;
	void QTextEditGrayOutput(QString);
	void QTextEditRedOutput(QString);
	void QTextEditGreenOutput(QString);
	void QTextEditColoredOutput(QVector<QPair<QColor, QString>>);

	/******************** GetStatus.cpp ********************/
	// Carl: get status
	QString getQVTKWidget_1CloudStatus();
	QString getQVTKWidget_2CloudStatus();
	QString getQVTKWidget_3CloudStatus();
	QString getQVTKWidget_1MeshStatus();
	QString getQVTKWidget_2MeshStatus();
	QString getQVTKWidget_3MeshStatus();
	QString getQVTKWidget_1MeshCloudStatus();
	QString getQVTKWidget_2MeshCloudStatus();
	QString getQVTKWidget_3MeshCloudStatus();
	QString getKeypoints_1Status();
	QString getKeypoints_2Status();
	QString getKeypoints_3Status();
	QString getPointMatched_1Status();
	QString getPointMatched_2Status();
	QString getPointMatched_3Status();
	QVector<QPair<QColor, QString>> getProcesssorNumber();
	QVector<QPair<QColor, QString>> getProcesssorType();
	QVector<QPair<QColor, QString>> getProcesssorLevel();
	QVector<QPair<QColor, QString>> getProcesssorArchitecture();
	QVector<QPair<QColor, QString>> getProcesssorCurrentUsage();
	double getProcesssorCurrentUsageDouble();
	QVector<QPair<QColor, QString>> getQVTKWidget_1ColorStatus();
	QVector<QPair<QColor, QString>> getQVTKWidget_2ColorStatus();
	QVector<QPair<QColor, QString>> getQVTKWidget_3ColorStatus();
	// Carl: get input status;
	bool isQVTKWidget_1CloudEmpty();
	bool isQVTKWidget_2CloudEmpty();
	bool isQVTKWidget_3CloudEmpty();
	bool isQVTKWidget_1MeshEmpty();
	bool isQVTKWidget_2MeshEmpty();
	bool isQVTKWidget_3MeshEmpty();
	bool isQVTKWidget_1MeshCloudEmpty();
	bool isQVTKWidget_2MeshCloudEmpty();
	bool isQVTKWidget_3MeshCloudEmpty();
	bool isKeypoints_1Empty();
	bool isKeypoints_2Empty();
	bool isKeypoints_3Empty();
	// Carl: get connection status;
	bool isQVTKWidget_1CloudConnected();
	bool isQVTKWidget_2CloudConnected();
	bool isQVTKWidget_3CloudConnected();
	bool isQVTKWidget_1MeshConnected();
	bool isQVTKWidget_2MeshConnected();
	bool isQVTKWidget_3MeshConnected();
	bool isQVTKWidget_1MeshCloudConnected();
	bool isQVTKWidget_2MeshCloudConnected();
	bool isQVTKWidget_3MeshCloudConnected();

	/******************** ColorChange.cpp ********************/
	// Carl: change the color the point cloud
	void QVTKWidget_1CloudColorChange();
	void QVTKWidget_2CloudColorChange();
	void QVTKWidget_3CloudColorChange();
	void QVTKWidget_1CloudColorSwitch();
	void QVTKWidget_2CloudColorSwitch();
	void QVTKWidget_3CloudColorSwitch();
	void QVTKWidget_1MeshCloudColorChange();
	void QVTKWidget_2MeshCloudColorChange();
	void QVTKWidget_3MeshCloudColorChange();
	void QVTKWidget_1MeshKeypointColorChange();
	void QVTKWidget_2MeshKeypointColorChange();
	void QVTKWidget_3MeshKeypointColorChange();
	void QVTKWidget_1MeshMatchedPointColorChange();
	void QVTKWidget_2MeshMatchedPointColorChange();
	void QVTKWidget_3MeshMatchedPointColorChange();

	/******************** InstructionProcess.cpp ********************/
	// Carl: process instruction
	void InstructionProcess(QString);

	/******************** ReturnMsgProcess.cpp ********************/
	// Carl: process return message
	void ReturnMsgProcess();
	/******************** ReturnMsgCategoryExit.cpp ********************/
	void ReturnMsgCategoryExit(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryUnknown.cpp ********************/
	void ReturnMsgCategoryUnknown(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryUserDefine.cpp ********************/
	void ReturnMsgCategoryUserDefine(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryRerror.cpp ********************/
	void ReturnMsgCategoryRerror(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryTest.cpp ********************/
	void ReturnMsgCategoryTest(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryClear.cpp ********************/
	void ReturnMsgCategoryClear(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryInit.cpp ********************/
	void ReturnMsgCategoryInit(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryLoad.cpp ********************/
	void ReturnMsgCategoryLoad(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryConnect.cpp ********************/
	void ReturnMsgCategoryConnect(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryShowStatus.cpp ********************/
	void ReturnMsgCategoryShowStatus(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryChangeColor.cpp ********************/
	void ReturnMsgCategoryChangeColor(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryDetect.cpp ********************/
	void ReturnMsgCategoryDetect(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategorySubdivide.cpp ********************/
	void ReturnMsgCategorySubdivide(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryMeshSurfaceFit.cpp ********************/
	void ReturnMsgCategoryMeshSurfaceFit(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryCellular.cpp ********************/
	void ReturnMsgCategoryCellular(ReturnMsgList::iterator &);
	/******************** ReturnMsgCategoryMatch.cpp ********************/
	void ReturnMsgCategoryMatch(ReturnMsgList::iterator &);

	/******************** CameraSynchronization.cpp ********************/
	// Carl: the member functions deal with the camera synchronization;
	void CameraSynToQVTKWidget_1();
	void CameraSynToQVTKWidget_2();
	void CameraSynToQVTKWidget_3();

};

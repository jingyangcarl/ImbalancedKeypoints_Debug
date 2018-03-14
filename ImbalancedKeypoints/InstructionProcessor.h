#pragma once
#include <qthread.h>
#include <qstring.h>
#include <qlist.h>
#include <qmap.h>
#include "ReturnMsg.h"

class InstructionProcessor : public QThread
{
	Q_OBJECT

public:
	InstructionProcessor();
	InstructionProcessor(QString);
	~InstructionProcessor();

	/******************** InstructionProcessorAppend.cpp ********************/

	void SetInstruction(QString);

	// Carl: set path;
	void SetCloud_1_Path(QString);
	void SetCloud_2_Path(QString);
	void SetCloud_3_Path(QString);
	void SetMesh_1_Path(QString);
	void SetMesh_2_Path(QString);
	void SetMesh_3_Path(QString);

	// Carl: set vector for cloud
	void SetAlive_1Vector(std::vector<bool>);
	void SetAlive_2Vector(std::vector<bool>);
	void SetAlive_3Vector(std::vector<bool>);
	
	// Carl: get path;
	QString GetCloud_1_Path();
	QString GetCloud_2_Path();
	QString GetCloud_3_Path();
	QString GetMesh_1_Path();
	QString GetMesh_2_Path();
	QString GetMesh_3_Path();

	// Carl: get returnMsgList;
	ReturnMsgList GetReturnMsgList();

	/******************** InstructionProcessor.cpp ********************/
	// Carl: process instruction
	ReturnMsgList Process();

protected:
	void run();

signals:
	void SendReturnMsgList(ReturnMsgList);

private:
	// Carl: instruction
	QString instruction;
	// Carl: return message list
	ReturnMsgList returnMsgList;
	
	// Carl: cloud path
	QString cloud_1_path;
	QString cloud_2_path;
	QString cloud_3_path;
	// Carl: cloud isAlive;
	std::vector<bool> isAlive_1;
	std::vector<bool> isAlive_2;
	std::vector<bool> isAlive_3;

	// Carl: mesh path
	QString mesh_1_path;
	QString mesh_2_path;
	QString mesh_3_path;


	// Carl: Instruction Category
	/******************** InstructionCategoryExit.cpp ********************/
	void InstructionCategoryExit();
	/******************** InstructionCategoryClear.cpp ********************/
	void InstructionCategoryClear();
	/******************** InstructionCategoryInit.cpp ********************/
	void InstructionCategoryInit();
	/******************** InstructionCategoryLoad.cpp ********************/
	void InstructionCategoryLoad();
	/******************** InstructionCategoryConnect.cpp ********************/
	void InstructionCategoryConnect();
	/******************** InstructionCategoryShowStatus.cpp ********************/
	void InstructionCategoryShowStatus();
	/******************** InstructionCategoryChangeColor.cpp ********************/
	void InstructionCategoryChangeColor();
	/******************** InstructionCategoryDetect.cpp ********************/
	void InstructionCategoryDetect();
	/******************** InstructionCategorySubdivide.cpp ********************/
	void InstructionCategorySubdivide();
	/******************** InstructionCategoryMeshSurfaceFit.cpp ********************/
	void InstructionCategoryMeshSurfaceFit();
	/******************** InstructionCategoryCellular.cpp ********************/
	void InstructionCategoryCellular();
	/******************** InstructionCategoryMatch.cpp ********************/
	void InstructionCategoryMatch();
};
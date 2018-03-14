#include "InstructionProcessor.h"


InstructionProcessor::InstructionProcessor() {
	this->instruction = "";
}

InstructionProcessor::InstructionProcessor(QString instruction) {
	instruction = instruction.trimmed();
	this->instruction = instruction;
}

InstructionProcessor::~InstructionProcessor() {
	this->instruction = instruction;
}

void InstructionProcessor::SetInstruction(QString instruction) {
	instruction = instruction.trimmed();
	this->instruction = instruction;
}

void InstructionProcessor::SetCloud_1_Path(QString cloud_1_path) {
	this->cloud_1_path = cloud_1_path;
	return;
}

void InstructionProcessor::SetCloud_2_Path(QString cloud_2_path) {
	this->cloud_2_path = cloud_2_path;
	return;
}

void InstructionProcessor::SetCloud_3_Path(QString cloud_3_path) {
	this->cloud_3_path = cloud_3_path;
	return;
}

void InstructionProcessor::SetMesh_1_Path(QString mesh_1_path) {
	this->mesh_1_path = mesh_1_path;
	return;
}

void InstructionProcessor::SetMesh_2_Path(QString mesh_2_path) {
	this->mesh_2_path = mesh_2_path;
	return;
}

void InstructionProcessor::SetMesh_3_Path(QString mesh_3_path) {
	this->mesh_3_path = mesh_3_path;
	return;
}

void InstructionProcessor::SetAlive_1Vector(std::vector<bool> isAlive_1) {
	this->isAlive_1 = isAlive_1;
}

void InstructionProcessor::SetAlive_2Vector(std::vector<bool> isAlive_2) {
	this->isAlive_2 = isAlive_2;
}

void InstructionProcessor::SetAlive_3Vector(std::vector<bool> isAlive_3) {
	this->isAlive_3 = isAlive_3;
}

QString InstructionProcessor::GetCloud_1_Path() {
	return this->cloud_1_path;
}

QString InstructionProcessor::GetCloud_2_Path() {
	return this->cloud_2_path;
}

QString InstructionProcessor::GetCloud_3_Path() {
	return this->cloud_3_path;
}

QString InstructionProcessor::GetMesh_1_Path() {
	return this->mesh_1_path;
}

QString InstructionProcessor::GetMesh_2_Path() {
	return this->mesh_2_path;
}

QString InstructionProcessor::GetMesh_3_Path() {
	return this->mesh_3_path;
}

ReturnMsgList InstructionProcessor::GetReturnMsgList() {
	return this->returnMsgList;
}

void InstructionProcessor::run() {
	Process();
}

#include "CellularAutomaton.h"

CellularAutomaton::CellularAutomaton() {

}

void CellularAutomaton::SetAliveVector(std::vector<bool> isAliveVector) {
	this->isAliveVector = isAliveVector;
}

void CellularAutomaton::SetSize(int size) {
	this->size = size;
}

int CellularAutomaton::GetSize() {
	return this->size;
}

std::vector<bool> CellularAutomaton::Iteration() {
	std::vector<bool> resIsAliveVector = isAliveVector;
	Eigen::Matrix3i matrix;
	Eigen::RowVector3i rowVector;
	Eigen::Vector3i colVector;
	int entry;

	for (std::vector<bool>::iterator i = isAliveVector.begin()+size+1; i < isAliveVector.end()-size-1; i++) {

 		matrix << (int)*(i - size - 1), (int)*(i - size), (int)*(i - size + 1),
				(int)*(i - 1), (int)*(i), (int)*(i + 1),
				(int)*(i + size - 1), (int)*(i + size), (int)*(i + size + 1);
		rowVector << 1, 1, 1;
		colVector << 1, 1, 1;
		entry = rowVector*matrix*colVector - (int)(*i);

		// Carl: Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
		if (*i && entry < 2)					resIsAliveVector.at(i - isAliveVector.begin()) = false;
		// Carl: Any live cell with two or three live neighbours lives on to the next generation.
		if (*i && (entry == 2 || entry == 3))	resIsAliveVector.at(i - isAliveVector.begin()) = true;
		// Carl: Any live cell with more than three live neighbours dies, as if by overpopulation.
		if (*i && entry > 3)					resIsAliveVector.at(i - isAliveVector.begin()) = false;
		// Carl: Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
		if (!*i && entry == 3)					resIsAliveVector.at(i - isAliveVector.begin()) = true;

		if ((i + 2 - isAliveVector.begin()) % size == 0)	i = i + 2;
	}
	return resIsAliveVector;
}

std::vector<bool> CellularAutomaton::Initialize(int size) {
	std::vector<bool> cellular;
	size += 2;
	this->size = size;

	cellular.assign(size*size, true);

	// Carl: dark boundary
	for (int i = 0; i < size; i++) {
		cellular.at(i) = false;
		cellular.at((size - 1)*size + i) = false;
		cellular.at(i*size) = false;
		cellular.at((i + 1)*size - 1) = false;
	}

	return cellular;
}


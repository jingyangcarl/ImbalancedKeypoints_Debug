#pragma once

#include "cellularautomaton_global.h"
#include <Eigen\Dense>
#include <vector>



class CELLULARAUTOMATON_EXPORT CellularAutomaton
{
public:
	CellularAutomaton();
	
	// Carl: set
	void SetAliveVector(std::vector<bool>);
	void SetSize(int);

	// Carl: get
	int GetSize();

	// Carl: iteration
	std::vector<bool> Iteration();

	// Carl: initialization
	std::vector<bool> Initialize(int);

private:
	// Carl: point cloud;
	std::vector<bool> isAliveVector;

	// Carl: point cloud dimension
	int size = 64;
};

#pragma once

#include "meshmatcher_global.h"
#include <OpenMesh\Core\IO\MeshIO.hh>
#include <OpenMesh\Core\Mesh\TriMesh_ArrayKernelT.hh>

class MESHMATCHER_EXPORT MeshMatcher
{
private:

	// Carl: triangle mesh data;
	OpenMesh::TriMesh_ArrayKernelT<> mesh_1;
	OpenMesh::TriMesh_ArrayKernelT<> mesh_2;
	// Carl: mesh path;
	std::string meshPath_1;
	std::string meshPath_2;
	// Carl: mesh scale;
	OpenMesh::Vec3f meshScale_1;
	OpenMesh::Vec3f meshScale_2;
	// Carl: single direction threold
	double threold = 1e-7;

	/******************** MeshMatcher.cpp ********************/
public:
	// Carl: Comparision;
	std::pair<std::string, std::string> MeshPointComparision();
	std::pair<std::string, std::string> MeshFaceComparision();
	std::pair<std::string, std::string> MeshEdgeComparision();
	std::pair<std::string, std::string> MeshShapeComparision();

	/******************** MeshMatcherAppend.cpp ********************/
public:
	// Carl: constructor
	MeshMatcher();
	// Carl: load mesh file
	bool LoadMeshFile_1(std::string);
	bool LoadMeshFile_2(std::string);
private:
	void GetMeshScale_1();
	void GetMeshScale_2();
};

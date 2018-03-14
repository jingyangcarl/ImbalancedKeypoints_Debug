#pragma once

#include "imbdetector_global.h"
#include <OpenMesh\Core\IO\MeshIO.hh>
#include <OpenMesh\Core\Mesh\TriMesh_ArrayKernelT.hh>
#include <omp.h>

class IMBDETECTOR_EXPORT ImbDetector
{

private:
	// Carl: triangle mesh data;
	OpenMesh::TriMesh_ArrayKernelT<> mesh;
	// Carl: mesh path;
	std::string filePath;

	/******************** ImbDetector.cpp ********************/
public:
	// Carl: start detection;
	std::vector<bool> ImbDetection();
private:
	// Carl & FKY: detect the imbalanced threshold for given points;
	bool ImbThresholdDetection(OpenMesh::Vec3f grid2D[3][3], std::vector<OpenMesh::FaceHandle>, OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle, OpenMesh::TriMesh_ArrayKernelT<> &);


	/******************** ImbDetectorAppend.cpp ********************/
public:
	ImbDetector();
	bool LoadMeshFile(std::string);

private:
	// Carl & FKY: get mesh scale
	double GetMeshScale();
	// Carl & FKY: normalize the vector
	void GetNormalizedVector(float &, float &, float &);
	// Carl & FKY: get plane equation
	void GetFaceEquation(float &, float &, float &, float &, float *);
	// Carl & FKY: get point intersection
	void GetPointofIntersection(float, float, float, float, float *, float *, float *);
	// Carl & FKY: get angle
	float GetAngle(float *, float *, float *);
	// Carl & FKY: get euclide distance
	float GetEuclidDistance(float *, float *);
};

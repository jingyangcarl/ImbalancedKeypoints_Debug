#pragma once

#include "meshsubdivisor_global.h"
#include <OpenMesh\Core\IO\MeshIO.hh>
#include <OpenMesh\Core\Mesh\TriMesh_ArrayKernelT.hh>
#include <Eigen\Dense>

using namespace OpenMesh;

class MESHSUBDIVISOR_EXPORT MeshSubdivisor
{
private:

	struct Traits : public OpenMesh::DefaultTraits {
		// Carl: delete_face() Needs the Attributes::Status attribute for vertices, edges and faces.
		VertexAttributes(OpenMesh::Attributes::Status);
		FaceAttributes(OpenMesh::Attributes::Status);
		EdgeAttributes(OpenMesh::Attributes::Status);
	};

	// Carl: triangle mesh data;
	OpenMesh::TriMesh_ArrayKernelT<Traits> iMesh;
	OpenMesh::TriMesh_ArrayKernelT<Traits> oMesh;
	OpenMesh::Vec3f meshScale;
	OpenMesh::Vec3f meshMiddle;
	double determinantThreshold = 1e-5;
	double moveThreshold = 3;
	// Carl: mesh path;
	std::string iMeshPath;
	std::string oMeshPath;

	/******************** MeshSubdivisor.cpp ********************/
public:
	// Carl: subdivision
	void MeshSubdivision();
	// Carl: subdivision accroding to the keypoints
	void MeshSubdivision(std::vector<bool>);
	// Carl: subdivision with fitting
	void MiddlePointsFittingPlaneGuiding();
	void BottomPointsFittingPlaneGuiding();
	void NeighborPointsFittingPlaneGuiding();
	void AllPointsFittingPlaneGuiding();
	void NeighborWeightedPointGuiding();
	void NeighborWeightedFaceGuiding();
	void NeighborWeightedGuiding(std::vector<bool>);
	// Carl: subdivision tool
	void MeshSubdivisionToolCatmull();
	void MeshSubdivisionToolButterfly();
	void MeshSubdivisionToolLoop();
	// Carl: CPU idling, reference: "MeshSubdivisor Idling.xlsx"
	void MeshIdlingTraverse();
	// Carl: test
	void TestMeshSubdivision();


	/******************** MeshSubdivisorAppend.cpp ********************/
public:
	// Carl: constructor
	MeshSubdivisor();
	// Carl: load mesh file
	bool LoadMeshFile(std::string);

	// Carl: output to a temp file;
	std::string OutputiMesh();
	std::string OutputoMesh();
	// Carl: set Path;
	void SetOutputiMeshPath(std::string);
	void SetOutputoMeshPath(std::string);

private:
	// Carl: append function
	OpenMesh::Vec3f GetMeshScale();
	TriMesh_ArrayKernelT<>::Point GetMidPoint(TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point);
	TriMesh_ArrayKernelT<>::Point GetMidPoint(TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point);
	TriMesh_ArrayKernelT<>::Point GetMidPoint(TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point);
	TriMesh_ArrayKernelT<>::Point GetMidPoint(TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Normal, TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Normal, bool);
	TriMesh_ArrayKernelT<>::Point AddGaussianNoise(TriMesh_ArrayKernelT<>::Point);
	// Carl: point adjustment
	TriMesh_ArrayKernelT<>::Point PointFittingPlaneAdjustment(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>, TriMesh_ArrayKernelT<>::Point);
	TriMesh_ArrayKernelT<>::Point PointNeighborWeightedAdjustment(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>, TriMesh_ArrayKernelT<>::Point);

	/******************** GetOneRingPoints.cpp ********************/
	// Carl: reference from MeshSurfaceFitter to get one ring points
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingMiddlePoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingBasePoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingBottomPoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingNeighborPoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingAllPoints(int);
};

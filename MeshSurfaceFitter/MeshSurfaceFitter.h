#pragma once

#include "meshsurfacefitter_global.h"
#include <OpenMesh\Core\IO\MeshIO.hh>
#include <OpenMesh\Core\Mesh\TriMesh_ArrayKernelT.hh>
#include <pcl\point_cloud.h>
#include <pcl\point_types.h>
#include <pcl\io\pcd_io.h>
#include <iostream>
#include <sstream>

using namespace OpenMesh;

class MESHSURFACEFITTER_EXPORT MeshSurfaceFitter
{
private:

	struct Traits : public OpenMesh::DefaultTraits {
		// Carl: delete_face() Needs the Attributes::Status attribute for vertices, edges and faces.
		VertexAttributes(OpenMesh::Attributes::Status);
		FaceAttributes(OpenMesh::Attributes::Status);
		EdgeAttributes(OpenMesh::Attributes::Status);
	};

	typedef struct {
		bool invertible3D;
		double determinant3D;
		bool invertible2D;
		double determinant2D;
		bool invertible1D;
		double determinant1D;
	} VertexMatrixStatus;

	// Carl: triangle mesh data;
	OpenMesh::TriMesh_ArrayKernelT<Traits> mesh;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
	// Carl: output path
	std::string outputCloudPath;
	// Carl: selected point handle
	int pointHandle;
	// Carl: mesh scale
	OpenMesh::Vec3f meshScale;
	// Carl: fitting type
	std::string fittingType;
	// Carl: determinant threshold
	double determinantThreshold = 1e-5;

	/******************** MeshSurfaceFitter.cpp ********************/
public:
	// Carl: one ring fitting
	int OneRingFitting();
	// Carl: overall one ring fitting test
	std::string OverallOneRingFitting();

private:
	// Carl: fit a plane
	void FitPlane(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>, TriMesh_ArrayKernelT<>::Point);
	// Carl: test each vertices for plane fitting algoritym
	std::vector<VertexMatrixStatus> OverallMiddlePointsFitPlane();
	std::vector<VertexMatrixStatus> OverallBottomPointsFitPlane();
	std::vector<VertexMatrixStatus> OverallNeighborPointsFitPlane();
	std::vector<VertexMatrixStatus> OverallAllPointsFitPlane();

	// Carl: get one ring points
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingMiddlePoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingBottomPoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingNeighborPoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingAllPoints(int);

	/******************** MeshSurfaceFitterAppend.cpp ********************/
public:
	MeshSurfaceFitter();
	// Carl: load mesh file
	bool LoadMeshFile(std::string);
	// Carl: set
	void SetPointHandle(int);
	void SetFittingType(std::string);
	void SetOutputCloudPath(std::string);
	// Carl: is type valied
	bool isTypeValid(std::string);
	// Carl: output to a temp file;
	std::string OutputCloud();
private:
	// Carl: get mesh scale;
	OpenMesh::Vec3f GetMeshScale();
	// Carl: get middle point
	TriMesh_ArrayKernelT<>::Point GetMidPoint(TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point);
};
#include "MeshMatcher.h"

MeshMatcher::MeshMatcher() {

}

bool MeshMatcher::LoadMeshFile_1(std::string meshPath_1) {
	// Carl: load mesh file and update normals;
	this->meshPath_1 = meshPath_1;
	if (OpenMesh::IO::read_mesh(mesh_1, meshPath_1)) {
		GetMeshScale_1();
		return true;
	}
	return false;
}

bool MeshMatcher::LoadMeshFile_2(std::string meshPath_2) {
	// Carl: load mesh file and update normals;
	this->meshPath_2 = meshPath_2;
	if (OpenMesh::IO::read_mesh(mesh_2, meshPath_2)) {
		GetMeshScale_2();
		return true;
	}
	return false;
}

void MeshMatcher::GetMeshScale_1() {
	// Carl: get mesh scale
	/* to calculate the minimum coordinates and form point min and max
	which is a box that will contains the entire mesh; */

	OpenMesh::TriMesh_ArrayKernelT<>::Point temp;
	OpenMesh::TriMesh_ArrayKernelT<>::Point min;
	OpenMesh::TriMesh_ArrayKernelT<>::Point max;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter;

	min = mesh_1.point(mesh_1.vertices_begin());
	max = mesh_1.point(mesh_1.vertices_begin());
	for (verIter = mesh_1.vertices_begin(); verIter != mesh_1.vertices_end(); verIter++) {
		temp = mesh_1.point(*verIter);
		min[0] = temp[0] < min[0] ? temp[0] : min[0];
		min[1] = temp[1] < min[1] ? temp[1] : min[1];
		min[2] = temp[2] < min[2] ? temp[2] : min[2];
		max[0] = temp[0] > max[0] ? temp[0] : max[0];
		max[1] = temp[1] > max[1] ? temp[1] : max[1];
		max[2] = temp[2] > max[2] ? temp[2] : max[2];
	}
	meshScale_1 = max - min;
}

void MeshMatcher::GetMeshScale_2() {
	// Carl: get mesh scale
	/* to calculate the minimum coordinates and form point min and max
	which is a box that will contains the entire mesh; */

	OpenMesh::TriMesh_ArrayKernelT<>::Point temp;
	OpenMesh::TriMesh_ArrayKernelT<>::Point min;
	OpenMesh::TriMesh_ArrayKernelT<>::Point max;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter;

	min = mesh_2.point(mesh_2.vertices_begin());
	max = mesh_2.point(mesh_2.vertices_begin());
	for (verIter = mesh_2.vertices_begin(); verIter != mesh_2.vertices_end(); verIter++) {
		temp = mesh_2.point(*verIter);
		min[0] = temp[0] < min[0] ? temp[0] : min[0];
		min[1] = temp[1] < min[1] ? temp[1] : min[1];
		min[2] = temp[2] < min[2] ? temp[2] : min[2];
		max[0] = temp[0] > max[0] ? temp[0] : max[0];
		max[1] = temp[1] > max[1] ? temp[1] : max[1];
		max[2] = temp[2] > max[2] ? temp[2] : max[2];
	}
	meshScale_2 = max - min;
}

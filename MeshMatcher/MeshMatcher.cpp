#include "MeshMatcher.h"

std::pair<std::string, std::string> MeshMatcher::MeshPointComparision() {
	// Carl: compare the points difference of given meshes 
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter_1;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter_2;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verFirstEnd;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verSecondEnd;
	OpenMesh::TriMesh_ArrayKernelT<>::Point point_1;
	OpenMesh::TriMesh_ArrayKernelT<>::Point point_2;
	std::string returnMsg_1 = "";
	std::string returnMsg_2 = "";

	// Carl: for mesh_1
	for (verIter_1 = mesh_1.vertices_begin(); verIter_1 != mesh_1.vertices_end(); verIter_1++) {
		// Carl: for each vertex on mesh_1
		point_1 = mesh_1.point(*verIter_1);

		for (verIter_2 = mesh_2.vertices_begin(); verIter_2 != mesh_2.vertices_end(); verIter_2++) {
			// Carl: for each vertex on mesh_2
			point_2 = mesh_2.point(*verIter_2);

			if (point_1 == point_2) { returnMsg_1 += "1\n"; break; }
		}

		if (verIter_2 == mesh_2.vertices_end()) returnMsg_1 += "0\n";
	}
	
	// Carl: for mesh_2
	for (verIter_2 = mesh_2.vertices_begin(); verIter_2 != mesh_2.vertices_end(); verIter_2++) {
		// Carl: for each vertex on mesh_2
		point_2 = mesh_2.point(*verIter_2);

		for (verIter_1 = mesh_1.vertices_begin(); verIter_1 != mesh_1.vertices_end(); verIter_1++) {
			// Carl: for each vertex on mesh_1
			point_1 = mesh_1.point(*verIter_1);

			if (point_1 == point_2) { returnMsg_2 += "1\n"; break; }
		}

		if (verIter_1 == mesh_1.vertices_end()) returnMsg_2 += "0\n";
	}

	return std::pair<std::string, std::string>(returnMsg_1, returnMsg_2);
}

std::pair<std::string, std::string> MeshMatcher::MeshFaceComparision() {
	// Carl: compare the faces difference of given meshes 
	return std::pair<std::string, std::string>();
}

std::pair<std::string, std::string> MeshMatcher::MeshEdgeComparision() {
	// Carl: compare the edges difference of given meshes 
	return std::pair<std::string, std::string>();
}

std::pair<std::string, std::string> MeshMatcher::MeshShapeComparision() {
	// Carl: compare the shape difference of given meshes 
	return std::pair<std::string, std::string>();
}

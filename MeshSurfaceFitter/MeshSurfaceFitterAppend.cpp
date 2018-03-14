#include "MeshSurfaceFitter.h"

MeshSurfaceFitter::MeshSurfaceFitter() {

}

bool MeshSurfaceFitter::LoadMeshFile(std::string filePath) {
	// Carl: load mesh file and update normals;
	if (OpenMesh::IO::read_mesh(mesh, filePath)) {
		// Carl request for update;
		mesh.request_face_normals();
		mesh.request_vertex_normals();
		// Carl: update
		mesh.update_normals();
		// Carl: get mesh scale;
		meshScale = GetMeshScale();

		return true;
	}
	else
		return false;
}

void MeshSurfaceFitter::SetPointHandle(int pointHandle) {
	this->pointHandle = pointHandle;
}

void MeshSurfaceFitter::SetFittingType(std::string fittingType) {
	this->fittingType = fittingType;
}

void MeshSurfaceFitter::SetOutputCloudPath(std::string outputCloudPath) {
	this->outputCloudPath = outputCloudPath;
}

bool MeshSurfaceFitter::isTypeValid(std::string fittingType) {

	if (fittingType == "plane2") {
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 12, and 13;
		return true;
	}
	else if (fittingType == "plane3") {
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 2, 23, and 3
		return true;
	}
	else if (fittingType == "plane5") {
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 2, 3, 12, 23, and 31
		return true;
	}
	else if (fittingType == "plane6") {
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 1, 2, 3, 12, 23, and 31
		return true;
	}
	else
		return false;
}

std::string MeshSurfaceFitter::OutputCloud() {
	if (!pcl::io::savePCDFileASCII(outputCloudPath, *cloud))
		return outputCloudPath;
	else
		return "";
}

OpenMesh::Vec3f MeshSurfaceFitter::GetMeshScale() {
	// Carl: get mesh scale
	/* to calculate the minimum coordinates and form point min and max
	which is a box that will contains the entire mesh; */

	OpenMesh::TriMesh_ArrayKernelT<>::Point temp;
	OpenMesh::TriMesh_ArrayKernelT<>::Point min = mesh.point(mesh.vertices_begin());
	OpenMesh::TriMesh_ArrayKernelT<>::Point max = mesh.point(mesh.vertices_begin());
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter;

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {
		temp = mesh.point(*verIter);
		min[0] = temp[0] < min[0] ? temp[0] : min[0];
		min[1] = temp[1] < min[1] ? temp[1] : min[1];
		min[2] = temp[2] < min[2] ? temp[2] : min[2];
		max[0] = temp[0] > max[0] ? temp[0] : max[0];
		max[1] = temp[1] > max[1] ? temp[1] : max[1];
		max[2] = temp[2] > max[2] ? temp[2] : max[2];
	}

	return OpenMesh::Vec3f(max - min);
}

TriMesh_ArrayKernelT<>::Point MeshSurfaceFitter::GetMidPoint(TriMesh_ArrayKernelT<>::Point point1, TriMesh_ArrayKernelT<>::Point point2) {
	// Carl: get midpoint between point1 and point2;
	float midX = (point1[0] + point2[0]) / 2;
	float midY = (point1[1] + point2[1]) / 2;
	float midZ = (point1[2] + point2[2]) / 2;

	return TriMesh_ArrayKernelT<>::Point(midX, midY, midZ);
}

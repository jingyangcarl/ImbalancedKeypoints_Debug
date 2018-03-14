#include <OpenMesh\Core\IO\reader\PLYReader.hh>
#include "ImbDetector.h"
#include "Macro.h"

ImbDetector::ImbDetector() {
	this->filePath = "";
}

bool ImbDetector::LoadMeshFile(std::string filePath) {
	// Carl: Load mesh file and update normals;
	this->filePath = filePath;
	if (OpenMesh::IO::read_mesh(mesh, filePath)) {
		// Carl: request for update
		mesh.request_face_normals();
		mesh.request_vertex_normals();
		// Carl: update
		mesh.update_normals();
		return true;
	}
	else
		return false;
}

double ImbDetector::GetMeshScale() {
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

	return OpenMesh::Vec3f(max - min).norm();
}

void ImbDetector::GetNormalizedVector(float &x, float &y, float &z) {
	// Carl: normalize the vector
	double abs = sqrt(x*x + y*y + z*z);
	x = x / abs;
	y = y / abs;
	z = z / abs;

	return;
}

void ImbDetector::GetFaceEquation(float &a, float &b, float &c, float &d, float *point) {
	// Carl: get plane equation
	float x1 = point[0];
	float y1 = point[1];
	float z1 = point[2];
	float x2 = point[3];
	float y2 = point[4];
	float z2 = point[5];
	float x3 = point[6];
	float y3 = point[7];
	float z3 = point[8];

	a = y1*z2 - y1*z3 - y2*z1 + y2*z3 + y3*z1 - y3*z2;
	b = x1*z3 + x2*z1 - x2*z3 - x3*z1 + x3*z2 - x1*z2;
	c = x1*y2 - x1*y3 - x2*y1 + x2*y3 + x3*y1 - x3*y2;
	d = x1*y3*z2 + x2*y1*z3 - x2*y3*z1 - x3*y1*z2 + x3*y2*z1 - x1*y2*z3;
}

void ImbDetector::GetPointofIntersection(float a, float b, float c, float d, float *pointOfIntersection, float *point, float *normal) {
	// Carl: get point intersection
	float x, y, z;
	float xn = normal[0];
	float yn = normal[1];
	float zn = normal[2];
	float x0 = point[0];
	float y0 = point[1];
	float z0 = point[2];

	x = (x0 * (b*yn + c*zn) - xn*(b*y0 + c*z0 + d)) / (a* xn + b* yn + c*zn);
	y = (y0 * (a*xn + c*zn) - yn*(a*x0 + c*z0 + d)) / (a* xn + b* yn + c*zn);
	z = (z0 * (a*xn + b*yn) - zn*(a*x0 + b*y0 + d)) / (a* xn + b* yn + c*zn);

	pointOfIntersection[0] = x;
	pointOfIntersection[1] = y;
	pointOfIntersection[2] = z;
}

float ImbDetector::GetAngle(float *gridPointcenter, float *p1, float *p2) {
	// Carl: get angle

	float x_n1 = p1[0] - gridPointcenter[0];
	float y_n1 = p1[1] - gridPointcenter[1];
	float z_n1 = p1[2] - gridPointcenter[2];

	float x_n2 = p2[0] - gridPointcenter[0];
	float y_n2 = p2[1] - gridPointcenter[1];
	float z_n2 = p2[2] - gridPointcenter[2];


	float normN1 = sqrt(x_n1*x_n1 + y_n1*y_n1 + z_n1*z_n1);
	float normN2 = sqrt(x_n2*x_n2 + y_n2*y_n2 + z_n2*z_n2);

	float alpha = acos((x_n1*x_n2 + y_n1*y_n2 + z_n1*z_n2) / (normN1 *normN2));

	return alpha;
}

float ImbDetector::GetEuclidDistance(float *pointOfIntersection, float *gridPoint) {
	// Carl: get euclide distance
	float distX = pointOfIntersection[0] - gridPoint[0];
	float distY = pointOfIntersection[1] - gridPoint[1];
	float distZ = pointOfIntersection[2] - gridPoint[2];

	float dist = sqrt(distX*distX + distY*distY + distZ*distZ);

	return dist;
}

#include "MeshSubdivisor.h"

MeshSubdivisor::MeshSubdivisor() {
	this->iMeshPath = "";
	this->oMeshPath = "";
}

OpenMesh::Vec3f MeshSubdivisor::GetMeshScale() {
	// Carl: get mesh scale
	/* to calculate the minimum coordinates and form point min and max
	which is a box that will contains the entire mesh; */

	OpenMesh::TriMesh_ArrayKernelT<>::Point temp;
	OpenMesh::TriMesh_ArrayKernelT<>::Point min = iMesh.point(iMesh.vertices_begin());
	OpenMesh::TriMesh_ArrayKernelT<>::Point max = iMesh.point(iMesh.vertices_begin());
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		temp = iMesh.point(*verIter);
		min[0] = temp[0] < min[0] ? temp[0] : min[0];
		min[1] = temp[1] < min[1] ? temp[1] : min[1];
		min[2] = temp[2] < min[2] ? temp[2] : min[2];
		max[0] = temp[0] > max[0] ? temp[0] : max[0];
		max[1] = temp[1] > max[1] ? temp[1] : max[1];
		max[2] = temp[2] > max[2] ? temp[2] : max[2];
	}

	meshScale = max - min;
	meshMiddle = (max + min) / 2;

	return OpenMesh::Vec3f(max - min);
}

bool MeshSubdivisor::LoadMeshFile(std::string filePath) {
	// Carl: load mesh file and update normals;
	this->iMeshPath = filePath;
	if (OpenMesh::IO::read_mesh(iMesh, iMeshPath)) {
		// Carl request for update;
		iMesh.request_face_normals();
		iMesh.request_vertex_normals();
		iMesh.request_halfedge_normals();
		// Carl: update
		iMesh.update_normals();
		// Carl: synchronize
		oMesh = iMesh;
		// Carl: get mesh scale;
		GetMeshScale();
		return true;
	}
	else
		return false;
}

std::string MeshSubdivisor::OutputiMesh() {
	if (IO::write_mesh(iMesh, iMeshPath))
		return iMeshPath;
	else
		return "";
}

std::string MeshSubdivisor::OutputoMesh() {
	if (IO::write_mesh(oMesh, oMeshPath))
		return oMeshPath;
	else
		return "";
}

void MeshSubdivisor::SetOutputiMeshPath(std::string iMeshPath) {
	this->iMeshPath = iMeshPath;
}

void MeshSubdivisor::SetOutputoMeshPath(std::string oMeshPath) {
	this->oMeshPath = oMeshPath;
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisor::GetMidPoint(TriMesh_ArrayKernelT<>::Point point1, TriMesh_ArrayKernelT<>::Point point2) {
	// Carl: get midpoint between point1 and point2;
	/// Position:	point1 --- mid --- point2
	/// Weight:		0.5 ------ mid ------ 0.5

	double midX = (point1[0] + point2[0]) / 2.0;
	double midY = (point1[1] + point2[1]) / 2.0;
	double midZ = (point1[2] + point2[2]) / 2.0;

	return TriMesh_ArrayKernelT<>::Point(midX, midY, midZ);
}
 
TriMesh_ArrayKernelT<>::Point MeshSubdivisor::GetMidPoint(TriMesh_ArrayKernelT<>::Point point1, TriMesh_ArrayKernelT<>::Point point2, TriMesh_ArrayKernelT<>::Point point3) {
	// Carl: get centroid
	/// Position:      point1
	///               /  |  \
	///              /  mid  \
	///             /  /   \  \
	///          point2 --- point3
	/// Weight:         1/3
	///               /  |  \
	///              /  mid  \
	///             /  /   \  \
	///            1/3 ----- 1/3
	double midX = (point1[0] + point2[0] + point3[0]) / 3;
	double midY = (point1[1] + point2[1] + point3[1]) / 3;
	double midZ = (point1[2] + point2[2] + point3[2]) / 3;

	return TriMesh_ArrayKernelT<>::Point(midX, midY, midZ);
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisor::GetMidPoint(TriMesh_ArrayKernelT<>::Point endPoint1, TriMesh_ArrayKernelT<>::Point endPoint2, TriMesh_ArrayKernelT<>::Point sidePoint1, TriMesh_ArrayKernelT<>::Point sidePoint2) {
	// Carl: get midpoint between endPoint1, endPoint2, sidePoint1, and sidePoint2
	/// Position:       sidePoint1
	///                /          \
	///               /            \
	///              /              \
	///         endPoint1 - mid - endPoint2
	///              \              /
	///               \            /
	///                \          /
	///                 sidePoint2
	/// Weight:            1/8
	///                /          \
	///               /            \
	///              /              \
	///             3/8 --- mid --- 3/8
	///              \              /
	///               \            /
	///                \          /
	///                    1/8

	double midX = (3.0 * endPoint1[0] + 3.0 * endPoint2[0] + sidePoint1[0] + sidePoint2[0]) / 8.0;
	double midY = (3.0 * endPoint1[1] + 3.0 * endPoint2[1] + sidePoint1[1] + sidePoint2[1]) / 8.0;
	double midZ = (3.0 * endPoint1[2] + 3.0 * endPoint2[2] + sidePoint1[2] + sidePoint2[2]) / 8.0;
	
	return TriMesh_ArrayKernelT<>::Point(midX, midY, midZ);
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisor::GetMidPoint(TriMesh_ArrayKernelT<>::Point point1, TriMesh_ArrayKernelT<>::Normal normal1, TriMesh_ArrayKernelT<>::Point point2, TriMesh_ArrayKernelT<>::Normal normal2, bool) {
	// Carl: get midpoint between point1 and point2;

	double midX = (point1[0] + point2[0]) / 2;
	double midY = (point1[1] + point2[1]) / 2;
	double midZ = (point1[2] + point2[2]) / 2;

	// Carl: get normal
	TriMesh_ArrayKernelT<>::Normal normal = normal1.normalize() + normal2.normalize();
	return (-normal.normalize() * (meshScale / 32 ) + TriMesh_ArrayKernelT<>::Point(midX, midY, midZ));
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisor::AddGaussianNoise(TriMesh_ArrayKernelT<>::Point point) {
	// Carl: add gaussian noise to the point

	srand(time(NULL));
	double x = point[0] + ((double)rand() / RAND_MAX)*(meshScale[0] / 500);
	double y = point[1] + ((double)rand() / RAND_MAX)*(meshScale[1] / 500);
	double z = point[2] + ((double)rand() / RAND_MAX)*(meshScale[2] / 500);

	return TriMesh_ArrayKernelT<>::Point(x, y, z);
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisor::PointFittingPlaneAdjustment(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor, TriMesh_ArrayKernelT<>::Point point) {
	// Carl: using neighbors get a fitting plane and guide point to the plane

	// Carl: least squares theory to find plane
	/// plane equation is Ax + By + Cz + D = 0;
	/// change equation form will get z = (-A/C)x + (-B/C)y + (-D/C);
	/// if we set a0 = (-A/C), a1 = (-B/C), a2 = (-D/C);
	/// plane equation will has a form of 
	/// z = a0x + a1y + a2;
	/// Given a set of point, using least squares will find out a0, a1, and a2.
	/// If write this method into a formua, it will be Argmin(Sum((a0xi + a1yi + a2 - z) * (a0xi + a1yi + a2 - z))), where i iterate from 0 to n-1;
	/// Let's denote S = Sum((a0xi + a1yi + a2 - z) * (a0xi + a1yi + a2 - z)), the short form will be Argmin(S);
	/// By using partial derivative, we can find out the answer by form a equation system which including the following equations
	/// | Partial(S)/Partial(a0) = 0;
	/// | Partial(S)/Partial(a1) = 0;
	/// | Partial(S)/Partial(a2) = 0;
	/// which will be
	/// | Sum(2 * (a0x + a1y + a2 - z) * xi) = 0;
	/// | Sum(2 * (a0x + a1y + a2 - z) * yi) = 0;
	/// | Sum(2 * (a0x + a1y + a2 - z) * 1) = 0;
	/// which will be
	/// | a0 * Sum(xi * xi) + a1 * Sum(xi * yi) + a2 * Sum(xi) = Sum(xi * zi);
	/// | a0 * Sum(xi * yi) + a1 * Sum(yi * yi) + a2 * Sum(yi) = Sum(yi * zi);
	/// | a0 * Sum(xi) + a1 * Sum(yi) + a2 * Sum(1) = Sum(zi);
	/// which will be
	/// | Sum(xi * xi), Sum(xi * yi), Sum(xi) |   | a0 |   | Sum(xi * zi) | 
	/// | Sum(xi * yi), Sum(yi * yi), Sum(yi) | * | a1 | = | Sum(yi * zi) |
	/// | Sum(xi)     , Sum(yi)     , Sum(zi) |   | a2 |   | Sum(zi)      |
	/// Denote first matrix as COE, second column vector as A, and last column vector as B
	/// Then we get the answer
	/// A = INV(COE) * B

	// Carl: define
	double sumX(0), sumY(0), sumZ(0);
	double sumXX(0), sumYY(0), sumXY(0), sumXZ(0), sumYZ(0);

	// Carl: sum
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter = neighbor.begin();
	while (iter != neighbor.end()) {
		double x = (*iter).first[0];
		double y = (*iter).first[1];
		double z = (*iter).first[2];

		sumX += x;
		sumY += y;
		sumZ += z;
		sumXX += x*x;
		sumYY += y*y;
		sumXY += x*y;
		sumXZ += x*z;
		sumYZ += y*z;

		iter++;
	}

	// Carl: get solution
	Eigen::Matrix3d coe3D;
	Eigen::Matrix3d coe3DInverse;
	bool invertible;
	double determinant;
	Eigen::Vector3d a3D;
	Eigen::Vector3d b3D;

	coe3D << sumXX, sumXY, sumX, sumXY, sumYY, sumY, sumX, sumY, neighbor.size();
	b3D << sumXZ, sumYZ, sumZ;

	// Carl: check invertibility
	coe3D.computeInverseAndDetWithCheck(coe3DInverse, determinant, invertible);
	if (invertible && determinant > determinantThreshold) {
		// Carl: coe3D is invertible, the calculation is within 3D space

		a3D = coe3DInverse * b3D;
		TriMesh_ArrayKernelT<>::Normal normal(a3D[0], a3D[1], -1);
		normal = normal.normalize();

		// Carl: point project on the plane;
		/// change plane equation into normal form, it will be
		/// a0x + a1y - z + a2 = 0;
		/// normal vector will be (a0, a1, -1);
		/// the line which is vertical to the plane and go through the give point should be
		/// a0 * (x-x0) + a1 * (y-y0) + (-1) * (z-z0) = 0
		/// by using a parameter t, we can change the equation in to its parameter form
		/// | (x-x0) / a0 = t
		/// | (y-y0) / a1 = t
		/// | (z-z0) / -1 = t
		/// which will be
		/// | x = x0 - a0t
		/// | y = y0 - a1t
		/// | z = z0 + t
		/// replace the corresponding unknowns in the surface equation will get
		/// a0 * (x0-a0*t) + a1 * (y0-a1*t) - (z0 + t) + a2 = 0
		/// which will be
		/// t = (a0*x0 + a1*y0 - z0 + a2) / (a0*a0 + a1*a1 + 1)
		/// which will get the coordination of the projection points;

		double t = (a3D[0] * point[0] + a3D[1] * point[1] + (-1) * point[2] + a3D[2]) / (a3D[0] * a3D[0] + a3D[1] * a3D[1] + (-1) * (-1));
		TriMesh_ArrayKernelT<>::Point projection3D(point[0] - a3D[0] * t, point[1] - a3D[1] * t, point[2] - (-1) * t);

		// Carl: translation along normal vector 
		/// if the point(x, y, z) translate to point'(x', y', z');
		/// it can be written with a parameter tx, ty, tz for three dimensionla translation
		/// | x' = x + tx;
		/// | y' = y + ty;
		/// | z' = z + tz;
		/// change it in to matrix form
		///                                  | 1 , 0 , 0 , 0 |
		///                                  | 0 , 1 , 0 , 0 |
		/// (x', y', z', 1) = (x, y, z, 1) * | 0 , 0 , 1 , 0 |
		///                                  | tx, ty, tz, 1 |

		Eigen::Matrix4d translation;
		Eigen::RowVector4d after;
		Eigen::RowVector4d before;

		if (projection3D != point) {
			TriMesh_ArrayKernelT<>::Normal directionalNormal(projection3D - point);
			// Carl: largest move distance is the distance between projection and point;
			double largestMoveDistance = directionalNormal.norm();
			TriMesh_ArrayKernelT<>::Normal distance = directionalNormal.normalize() * (largestMoveDistance / moveThreshold);

			translation << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, distance[0], distance[1], distance[2], 1;
			before << point[0], point[1], point[2], 1;
			after = before * translation;
		}
		else {
			after << point[0], point[1], point[2], 1;
		}
		return TriMesh_ArrayKernelT<>::Point(after[0], after[1], after[2]);
	}
	else {
		// Carl: coe3D is not invertible
		/// normal vector of the plane has the format (a0, a1, 0), which means that the plane is perpendicular to xOy plane;
		/// what matters is the x and y coordinates of points
		/// the model degenerate from 3 dimension to 2 dimension;
		/// by using the 2 dimensional least squares, these points will fit a line. 

		// Carl: least squares theory to find a line
		/// line equation is Ax + By + C = 0;
		/// change equation form will get y = (-A/B)x + (-C/B);
		/// if we set a0 = (-A/B), a1 = (-C/B)
		/// line equation will has a form of
		/// y = a0x + a1;
		/// Given a set of point, using least squares will find out a0, and a1.
		/// If write this method into a formula, it will be Argmin(Sum(a0xi + a1 - yi)^2), where i iterates from 0 to n-1;
		/// Let's denote S = Sum(a0xi + a1 - yi)^2), the short form will be Argmin(S)
		/// By using partial derivative, we can find out the answer by form a equation system which includes the following equations
		/// | Partial(S)/Partial(a0) = 0;
		/// | Partial(S)/Partial(a1) = 0;
		/// which will be
		/// | Sum(2 * (a0xi + a1 - yi) * xi) = 0
		/// | Sum(2 * (a0xi + a1 - yi) * 1) = 0
		/// which will be
		/// | Sum(xi * xi), Sum(xi) | * | a0 | = | Sum(xi * yi) |
		/// | Sum(xi)     , Sum(1)  |   | a1 |   | Sum(yi)      |
		/// Denote first matrix as COE2D, second vector as A2D, and last column vector as B2D
		/// Then we get the answer
		/// A2D = INV(COE2D) * B2D

		// Carl: define
		double sumX(0), sumY(0);
		double sumXX(0), sumXY(0);

		// Carl: sum
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter = neighbor.begin();
		while (iter != neighbor.end()) {
			double x = (*iter).first[0];
			double y = (*iter).first[1];

			sumX += x;
			sumY += y;
			sumXX += x*x;
			sumXY += x*y;

			iter++;
		}

		// Carl: get solution
		Eigen::Matrix2d coe2D;
		Eigen::Matrix2d coe2DInverse;
		bool invertible;
		double determinant;
		Eigen::Vector2d a2D;
		Eigen::Vector2d b2D;

		coe2D << sumXX, sumX, sumX, neighbor.size();
		b2D << sumXY, sumY;

		// Carl: check invertibility
		coe2D.computeInverseAndDetWithCheck(coe2DInverse, determinant, invertible);
		if (invertible && determinant > determinantThreshold) {
			// Carl: coe2D is invertible, the calculation is within 2D space
			a2D = coe2D.inverse() * b2D;
			TriMesh_ArrayKernelT<>::Normal normal(a2D[0], -1, 0);
			normal = normal.normalize();

			// Carl: point project on the plane;
			/// change plane equation into normal form, it will be
			/// a0x - y + a1 = 0;
			/// normal vector will be (a0, -1, 0)
			/// the line which is vertical to the plane and go throught the given point should be
			/// a0 * (x-x0) + (-1) + (y-y0) = 0;
			/// by using a parameter t, we can change the equation in to its parameter form
			/// | (x-x0) / a0 = t;
			/// | (y-y0) / -1 = t;
			/// | z = z0
			/// which will be
			/// | x = x0 - a0t;
			/// | y = y0 + t; 
			/// replace the corresponding unknowns in the line equation 
			/// a0 * (x0 - a0*t) - (y0 - t) + a1 = 0
			/// which will be
			/// t = (a0*x0 - y0 + a1) / (a0 * a0 + 1)
			/// which will get the coordination of the projection points;

			double t = (a2D[0] * point[0] + (-1) * point[1] + a2D[1]) / (a2D[0] * a2D[0] + 1);
			TriMesh_ArrayKernelT<>::Point projection2D(point[0] - a2D[0] * t, point[1] + t, point[2]);

			// Carl: translation along normal vector 
			/// if the point(x, y, z) translate to point'(x', y', z');
			/// it can be written with a parameter tx, ty, tz for three dimensionla translation
			/// | x' = x + tx;
			/// | y' = y + ty;
			/// | z' = z + tz;
			/// change it in to matrix form
			///                                  | 1 , 0 , 0 , 0 |
			///                                  | 0 , 1 , 0 , 0 |
			/// (x', y', z', 1) = (x, y, z, 1) * | 0 , 0 , 1 , 0 |
			///                                  | tx, ty, tz, 1 |

			Eigen::Matrix4d translation;
			Eigen::RowVector4d after;
			Eigen::RowVector4d before;

			if (projection2D != point) {
				TriMesh_ArrayKernelT<>::Normal directionalNormal(projection2D - point);
				// Carl: largest move distance is the distance between projection and point;
				double largestMoveDistance = directionalNormal.norm();
				TriMesh_ArrayKernelT<>::Normal distance = directionalNormal.normalize() * (largestMoveDistance / moveThreshold);

				translation << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, distance[0], distance[1], distance[2], 1;
				before << point[0], point[1], point[2], 1;
				after = before * translation;
			}
			else {
				after << point[0], point[1], point[2], 1;
			}
			return TriMesh_ArrayKernelT<>::Point(after[0], after[1], after[2]);
		}
		else {
			// Carl: coe2D is not invertible
			/// normal vector of the plane has the format (a0, 0, 0)
			/// what matters is the x coordinate of points
			/// the model degenerate from 2 dimension to 1 dimension
			/// the vector point from origin to the point is the normal vector

			// Carl: least squares theory to find a point
			/// point equation is Ax + B = 0;
			/// change equation form will get x = (-B/A);
			/// if we set a0 = (-B/A)
			/// point equation will has a form of
			/// x = a0;
			/// Given a set of point using least squares will find out a0.
			/// If write this method in to a fomula, it will be Argmin(Sum(a0 - xi)^2), where i iterates from 0 to n-1;
			/// Let's denote S = Sum(a0-xi)^2, the short form will be Argmin(S)
			/// By using partial derivative, we can find out the answer by form a equation which includes the following equation
			/// | Paritial(S)/Partial(a0) = 0
			/// which will be
			/// | Sum(2 * (s0-xi) * 1) = 0
			/// which will be 
			/// | Sum(1) | * | a0 | = | Sum(xi) |
			/// Denote first matrix as COE1D, second vector as A1D, and last column vector as B1D
			/// Then we get the answer
			/// A1D = INV(COE1D) * B1D

			// Carl: define
			double sumX(0);

			// Carl: sum
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter = neighbor.begin();
			while (iter != neighbor.end()) {
				double x = (*iter).first[0];

				sumX += x;

				iter++;
			}

			// Carl: get solution
			double coe1D, a1D, b1D;

			coe1D = neighbor.size();
			b1D = sumX;

			// Carl: coe1D must be invertible
			a1D = b1D / coe1D;
			TriMesh_ArrayKernelT<>::Normal normal(-1, 0, 0);
			normal = normal.normalize();

			// Carl: pointprojection on the plane;
			/// change plane equation into normal form, it will be
			/// a0 - x = 0;
			/// normal vector will be (-1, 0, 0)
			/// the line which is vertical to the plane and go though the given point shoudld be
			/// (-1) * (x-x0) = 0;
			/// by using a parameter t, we can change the equation into ints parameter form
			/// | (x-x0) / -1 = t;
			/// | y = y0;
			/// | z = z0;
			/// which will be
			/// | x = x0 + t;
			/// replace the corresponding unknowns in the line equation
			/// a0 - (x0 + t) = 0
			/// which will be
			/// t = (-x0 + a0)
			/// which will get the coordination of the projection points;

			double t = (-1) * point[0] + a1D;
			TriMesh_ArrayKernelT<>::Point projection1D(point[0] + t, point[1], point[2]);

			// Carl: translation along normal vector 
			/// if the point(x, y, z) translate to point'(x', y', z');
			/// it can be written with a parameter tx, ty, tz for three dimensionla translation
			/// | x' = x + tx;
			/// | y' = y + ty;
			/// | z' = z + tz;
			/// change it in to matrix form
			///                                  | 1 , 0 , 0 , 0 |
			///                                  | 0 , 1 , 0 , 0 |
			/// (x', y', z', 1) = (x, y, z, 1) * | 0 , 0 , 1 , 0 |
			///                                  | tx, ty, tz, 1 |

			Eigen::Matrix4d translation;
			Eigen::RowVector4d after;
			Eigen::RowVector4d before;

			if (projection1D != point) {
				TriMesh_ArrayKernelT<>::Normal directionalNormal(projection1D - point);
				// Carl: largest move distance is the distance between projection and point;
				double largestMoveDistance = directionalNormal.norm();
				TriMesh_ArrayKernelT<>::Normal distance = directionalNormal.normalize() * (largestMoveDistance / moveThreshold);

				translation << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, distance[0], distance[1], distance[2], 1;
				before << point[0], point[1], point[2], 1;
				after = before * translation;
			}
			else {
				after << point[0], point[1], point[2], 1;
			}

			return TriMesh_ArrayKernelT<>::Point(after[0], after[1], after[2]);
		}
	}
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisor::PointNeighborWeightedAdjustment(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor, TriMesh_ArrayKernelT<>::Point point) {
	// Carl: using neighbors position infor to get new point position
	/// We use a weighted centroid for triangular surfaces
	/// the centroid takes 1/4 of the vertex being repositioned plus 3/8 of the two neighboring vertices.
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// in this triangle, the weight of vertex 1 is 1/4, while the weight of 2 and 3 are 3/8 and 3/8 respectively
	/// reference http://www.holmes3d.net/graphics/subdivision/
	/// reference http://blog.csdn.net/lafengxiaoyu/article/details/51524302
	/// reference http://blog.csdn.net/bugrunner/article/details/6249417
	/// if the amount of neighbor faces are N, then the weight of centroid should be (1 - N * beta) and that for other neighbor vertices are (beta);
	/// notive the centroid calculation for triangels is not uniform and depends upon which vertex the centroid is being accumulated into.

	TriMesh_ArrayKernelT<>::Point position(0.0, 0.0, 0.0);

	// Carl: beta version 1: from A Factored Approach to Subdivision Surfaces
	//double beta = (5.0/3.0 - 8.0/3.0 * ((3.0/8.0 + 1.0/4.0 * cos(2.0*M_PI/neighbor.size())) * (3.0/8.0 + 1.0/4.0 * cos(2.0*M_PI/neighbor.size())))) / neighbor.size();

	// Carl: beta version 2: from http://blog.csdn.net/bugrunner/article/details/6249417
	double beta = (5.0/8.0 - (3.0/8.0 + 1.0/4.0 * cos(2.0*M_PI/neighbor.size())) * (3.0/8.0 + 1.0/4.0 * cos(2.0*M_PI/neighbor.size()))) / neighbor.size();

	// Carl: beta version 3: from OpenMesh
	//double beta = (40.0 - (3.0 + 2.0*cos(2.0*M_PI/neighbor.size())) * (3.0 + 2.0*cos(2.0*M_PI / neighbor.size()))) / (neighbor.size() * 64.0);

	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;
	for (iter = neighbor.begin(); iter != neighbor.end(); iter++)
		position += (*iter).first * beta;

	position += (1 - neighbor.size() * beta) * point;

	return position;
}
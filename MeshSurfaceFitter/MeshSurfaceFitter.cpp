#include "MeshSurfaceFitter.h"

int MeshSurfaceFitter::OneRingFitting() {
	// Carl: find point accroding pointHandle in the mesh and search its one ring faces

	if (pointHandle >= mesh.n_vertices()) {
		return -1;
	}


	if (fittingType == "plane2") {
		// Carl: plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 12, and 13;
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingMiddlePoints(pointHandle);
		FitPlane(oneRingVertexMap, mesh.point(mesh.vertex_handle(pointHandle)));

		return 0;
	}
	else if (fittingType == "plane3") {
		// plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 2, 23, and 3
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingBottomPoints(pointHandle);
		FitPlane(oneRingVertexMap, mesh.point(mesh.vertex_handle(pointHandle)));
	}
	else if (fittingType == "plane5") {
		// plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 2, 3, 12, 23, and 31
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingNeighborPoints(pointHandle);
		FitPlane(oneRingVertexMap, mesh.point(mesh.vertex_handle(pointHandle)));
	}
	else if (fittingType == "plane6") {
		// plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 1, 2, 3, 12, 23, and 31
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingAllPoints(pointHandle);
		FitPlane(oneRingVertexMap, mesh.point(mesh.vertex_handle(pointHandle)));
	}
	else {

	}
}

std::string MeshSurfaceFitter::OverallOneRingFitting() {
	// Carl: giveout a overall one ring fitting test

	std::vector<VertexMatrixStatus> vertexMatrixStatus;
	std::string vertexMatrixStatusStr;

	if (fittingType == "plane2") {
		// Carl: ovreall plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 12, and 13;
		vertexMatrixStatus = OverallMiddlePointsFitPlane();
	}
	else if (fittingType == "plane3") {
		// Carl: ovreall plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 2, 23, and 3
		vertexMatrixStatus = OverallBottomPointsFitPlane();
	}
	else if (fittingType == "plane5") {
		// plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 2, 3, 12, 23, and 31
		vertexMatrixStatus = OverallNeighborPointsFitPlane();
	}
	else if (fittingType == "plane6") {
		// Carl: ovreall plane fitting;
		/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
		/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
		/// this part is used to apply algorithm on 1, 2, 3, 12, 23, and 31
		vertexMatrixStatus = OverallAllPointsFitPlane();
	}

	std::ostringstream oss;
	for (std::vector<VertexMatrixStatus>::iterator i = vertexMatrixStatus.begin(); i < vertexMatrixStatus.end(); i++) {

		oss << (*i).invertible3D;
		vertexMatrixStatusStr += oss.str() + "\n";
		oss.str("");

		oss << (*i).determinant3D;
		vertexMatrixStatusStr += oss.str() + "\n";
		oss.str("");

		oss << (*i).invertible2D;
		vertexMatrixStatusStr += oss.str() + "\n";
		oss.str("");

		oss << (*i).determinant2D;
		vertexMatrixStatusStr += oss.str() + "\n";
		oss.str("");

		oss << (*i).invertible1D;
		vertexMatrixStatusStr += oss.str() + "\n";
		oss.str("");

		oss << (*i).determinant1D;
		vertexMatrixStatusStr += oss.str() + "\n";
	}

	return vertexMatrixStatusStr;
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSurfaceFitter::GetOneRingMiddlePoints(int pointHandle) {
	// Carl: get points within one ring neighbor including part of subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 12, and 31

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = mesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = mesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
		// Carl: Face in One Ring

		// Carl: define handle for each vertex
		TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
		// Carl: define normal for each vertex
		TriMesh_ArrayKernelT<>::Normal normal1;
		TriMesh_ArrayKernelT<>::Normal normal2;
		TriMesh_ArrayKernelT<>::Normal normal3;
		// Carl: faceVertex;
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = mesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = mesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = mesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = mesh.normal(verHandle3);

		// Carl: point23 is not related to point1, so it will change every iteration
		// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
		TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
		TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
		TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

		// Carl: efface all the repeated points and faces
		// Carl: make sure that the point is unique
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

		if (point1 == mesh.point(vertHandle)) {

			// Carl: point12
			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

			// Carl: point31
			iter = oneRingVertexMap.find(point31);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

		}
		else if (point2 == mesh.point(vertHandle)) {

			// Carl: point12
			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

			// Carl: point23
			iter = oneRingVertexMap.find(point23);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

		}
		else if (point3 == mesh.point(vertHandle)) {

			// Carl: point23
			iter = oneRingVertexMap.find(point23);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

			// Carl: point31
			iter = oneRingVertexMap.find(point31);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

		}

	}

	return oneRingVertexMap;
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSurfaceFitter::GetOneRingBottomPoints(int pointHandle) {
	// Carl: get points within one ring neighbor including part of subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, 23, and 3

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = mesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = mesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
		// Carl: Face in One Ring

		// Carl: define handle for each vertex
		TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
		// Carl: define normal for each vertex
		TriMesh_ArrayKernelT<>::Normal normal1;
		TriMesh_ArrayKernelT<>::Normal normal2;
		TriMesh_ArrayKernelT<>::Normal normal3;
		// Carl: faceVertex;
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = mesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = mesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = mesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = mesh.normal(verHandle3);

		// Carl: point23 is not related to point1, so it will change every iteration
		// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
		TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
		TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
		TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

		// Carl: efface all the repeated points and faces
		// Carl: make sure that the point is unique
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

		if (point1 == mesh.point(vertHandle)) {

			// Carl: point2
			iter = oneRingVertexMap.find(point2);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point2, verHandle2));

			// Carl: point3
			iter = oneRingVertexMap.find(point3);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point3, verHandle3));

			// Carl: point23
			iter = oneRingVertexMap.find(point23);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

		}
		else if (point2 == mesh.point(vertHandle)) {

			// Carl: point1
			iter = oneRingVertexMap.find(point1);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point1, verHandle1));

			// Carl: point3
			iter = oneRingVertexMap.find(point3);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point3, verHandle3));

			// Carl: point31
			iter = oneRingVertexMap.find(point31);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

		}
		else if (point3 == mesh.point(vertHandle)) {

			// Carl: point1
			iter = oneRingVertexMap.find(point1);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point1, verHandle1));

			// Carl: point2
			iter = oneRingVertexMap.find(point2);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point2, verHandle2));

			// Carl: point12
			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

		}

	}

	return oneRingVertexMap;
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSurfaceFitter::GetOneRingNeighborPoints(int pointHandle) {
	// Carl: get points within one ring neighbor including subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, 3, 12, 23, and 31

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = mesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
	oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(mesh.point(vertHandle), vertHandle));

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = mesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
		// Carl: Face in One Ring

		// Carl: define handle for each vertex
		TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
		// Carl: define normal for each vertex
		TriMesh_ArrayKernelT<>::Normal normal1;
		TriMesh_ArrayKernelT<>::Normal normal2;
		TriMesh_ArrayKernelT<>::Normal normal3;
		// Carl: faceVertex;
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = mesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = mesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = mesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = mesh.normal(verHandle3);

		// Carl: point23 is not related to point1, so it will change every iteration
		// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
		TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
		TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
		TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

		// Carl: efface all the repeated points and faces
		// Carl: make sure that the point is unique
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

		// Carl: point1
		iter = oneRingVertexMap.find(point1);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point1, verHandle1));

		// Carl: point2
		iter = oneRingVertexMap.find(point2);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point2, verHandle2));

		// Carl: point3
		iter = oneRingVertexMap.find(point3);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point3, verHandle3));

		// Carl: point12
		iter = oneRingVertexMap.find(point12);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

		// Carl: point23
		iter = oneRingVertexMap.find(point23);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

		// Carl: point31
		iter = oneRingVertexMap.find(point31);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

	}

	// Carl: remove itself;
	oneRingVertexMap.erase(mesh.point(vertHandle));

	return oneRingVertexMap;
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSurfaceFitter::GetOneRingAllPoints(int pointHandle) {
	// Carl: get points within one ring neighbor including subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 1, 2, 3, 12, 23, and 31

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = mesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
	oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(mesh.point(vertHandle), vertHandle));

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = mesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
		// Carl: Face in One Ring

		// Carl: define handle for each vertex
		TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
		// Carl: define normal for each vertex
		TriMesh_ArrayKernelT<>::Normal normal1;
		TriMesh_ArrayKernelT<>::Normal normal2;
		TriMesh_ArrayKernelT<>::Normal normal3;
		// Carl: faceVertex;
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = mesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = mesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = mesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = mesh.normal(verHandle3);

		// Carl: point23 is not related to point1, so it will change every iteration
		// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
		TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
		TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
		TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

		// Carl: efface all the repeated points and faces
		// Carl: make sure that the point is unique
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

		// Carl: point1
		iter = oneRingVertexMap.find(point1);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point1, verHandle1));

		// Carl: point2
		iter = oneRingVertexMap.find(point2);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point2, verHandle2));

		// Carl: point3
		iter = oneRingVertexMap.find(point3);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point3, verHandle3));

		// Carl: point12
		iter = oneRingVertexMap.find(point12);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

		// Carl: point23
		iter = oneRingVertexMap.find(point23);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

		// Carl: point31
		iter = oneRingVertexMap.find(point31);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

	}

	return oneRingVertexMap;
}

void MeshSurfaceFitter::FitPlane(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor, TriMesh_ArrayKernelT<>::Point point) {
	// Carl: using neighbors get a fitting plane and guide point to the plane

	// Carl: least squares theory to find plane
	/// plane equation is Ax + By + Cz + D = 0;
	/// change equation form will get z = (-A/C)x + (-B/C)y + (-D/C);
	/// if we set a0 = (-A/C), a1 = (-B/C), a2 = (-D/C);
	/// plane equation will has a form of 
	/// z = a0x + a1y + a2;
	/// Given a set of point, using least squares will find out a0, a1, and a2.
	/// If write this method into a formua, it will be Argmin(Sum(a0xi + a1yi + a2 - zi)^2), where i iterates from 0 to n-1;
	/// Let's denote S = Sum((a0xi + a1yi + a2 - zi)^2), the short form will be Argmin(S);
	/// By using partial derivative, we can find out the answer by form a equation system which includes the following equations
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
	/// | Sum(xi)     , Sum(yi)     , Sum(1)  |   | a2 |   | Sum(zi)      |
	/// Denote first matrix as COE3D, second column vector as A3D, and last column vector as B3D
	/// Then we get the answer
	/// A3D = INV(COE3D) * B3D

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


		// Carl: generate points on the plane
		cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
		cloud->width = cloud->height = 100;
		cloud->points.resize(cloud->width * cloud->height);
		srand(time(NULL));

		for (int i = 0; i < cloud->points.size(); i++) {
			if (i % 10 != 0) {
				// plane
				cloud->points[i].x = 0.3 * meshScale.norm() * (rand() / (RAND_MAX + 1.0f) - 0.5) + projection3D[0];
				cloud->points[i].y = 0.3 * meshScale.norm() * (rand() / (RAND_MAX + 1.0f) - 0.5) + projection3D[1];
				cloud->points[i].z = a3D[0] * cloud->points[i].x + a3D[1] * cloud->points[i].y + a3D[2];
			}
			else {
				// normal vector
				double scale = 2 * (rand() / (RAND_MAX + 1.0f) - 0.5);
				cloud->points[i].x = projection3D[0] + scale * normal[0];
				cloud->points[i].y = projection3D[1] + scale * normal[1];
				cloud->points[i].z = projection3D[2] + scale * normal[2];
			}
		}
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

			// Carl: generate points on the plane
			cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
			cloud->width = cloud->height = 100;
			cloud->points.resize(cloud->width * cloud->height);
			srand(time(NULL));

			for (int i = 0; i < cloud->points.size(); i++) {
				if (i % 10 != 0) {
					// Plane
					cloud->points[i].x = 0.3 * meshScale.norm() * (rand() / (RAND_MAX + 1.0f) - 0.5) + projection2D[0];
					cloud->points[i].y = a2D[0] * cloud->points[i].x + a2D[1];
					cloud->points[i].z = 0.3 * meshScale.norm() * (rand() / (RAND_MAX + 1.0f) - 0.5) + projection2D[2];
				}
				else {
					// normal vector
					double scale = 2 * (rand() / (RAND_MAX + 1.0f) - 0.5);
					cloud->points[i].x = projection2D[0] + scale * normal[0];
					cloud->points[i].y = projection2D[1] + scale * normal[1];
					cloud->points[i].z = projection2D[2] + scale * normal[2];
				}
			}
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

			// Carl: generate points on the plane
			cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
			cloud->width = cloud->height = 100;
			cloud->points.resize(cloud->width * cloud->height);
			srand(time(NULL));

			for (int i = 0; i < cloud->points.size(); i++) {
				if (i % 10 != 0) {
					// Plane
					cloud->points[i].x = a1D;
					cloud->points[i].y = 0.3 * meshScale.norm() * (rand() / (RAND_MAX + 1.0f) - 0.5) + projection1D[1];
					cloud->points[i].z = 0.3 * meshScale.norm() * (rand() / (RAND_MAX + 1.0f) - 0.5) + projection1D[2];

				}
				else {
					// normal vector
					double scale = 2 * (rand() / (RAND_MAX + 1.0f) - 0.5);
					cloud->points[i].x = projection1D[0] + scale * normal[0];
					cloud->points[i].y = projection1D[1] + scale * normal[1];
					cloud->points[i].z = projection1D[2] + scale * normal[2];
				}
			}
		}
	}

}

std::vector<MeshSurfaceFitter::VertexMatrixStatus> MeshSurfaceFitter::OverallMiddlePointsFitPlane() {
	// Carl: auto test for each vertex on the mesh model, which is a overall traverse of 
	/// function FitPlane(neighbor, point) is used for process plane fitting for a given point
	/// when the size of mesh is large, that function doesn't work will
	/// this function traverse each vertex and return test result
	/// test result is a pair of hashmap with the same structure that contains invertibility and determinant of coe matrix
	/// each map structure represents a couple of information in a dimension

	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this part is used to apply algorithm on 12, and 13;

	std::vector<MeshSurfaceFitter::VertexMatrixStatus> testResult;

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor = GetOneRingMiddlePoints(verIter->idx());

		// Carl: define
		double sumX(0), sumY(0), sumZ(0);
		double sumXX(0), sumYY(0), sumXY(0), sumXZ(0), sumYZ(0);

		// Carl: sum
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter = neighbor.begin();
		while (iter != neighbor.end()) {
			double x = (*iter).first[0], y = (*iter).first[1], z = (*iter).first[2];

			sumX += x; sumY += y; sumZ += z;
			sumXX += x*x; sumYY += y*y; sumXY += x*y; sumXZ += x*z; sumYZ += y*z;
			iter++;
		}

		// Carl: get solution
		Eigen::Matrix3d coe3D, coe3DInverse;
		Eigen::Vector3d a3D;
		double determinant3D;
		bool invertible3D;

		coe3D << sumXX, sumXY, sumX, sumXY, sumYY, sumY, sumX, sumY, neighbor.size();

		// Carl: check invertibility
		coe3D.computeInverseAndDetWithCheck(coe3DInverse, determinant3D, invertible3D);

		// Carl: get solution
		Eigen::Matrix2d coe2D, coe2DInverse;
		Eigen::Vector2d a2D;
		double determinant2D;
		bool invertible2D;

		coe2D << sumXX, sumX, sumX, neighbor.size();

		// Carl: check invertibility
		coe2D.computeInverseAndDetWithCheck(coe2DInverse, determinant2D, invertible2D);

		// Carl: get solution
		double coe1D;

		coe1D = neighbor.size();

		// Carl: insert data
		VertexMatrixStatus vertexMatrixStatus;
		vertexMatrixStatus.determinant1D = coe1D;
		vertexMatrixStatus.determinant2D = determinant2D;
		vertexMatrixStatus.determinant3D = determinant3D;
		vertexMatrixStatus.invertible1D = true;
		vertexMatrixStatus.invertible2D = invertible2D;
		vertexMatrixStatus.invertible3D = invertible3D;

		testResult.push_back(vertexMatrixStatus);

	}

	return testResult;
}

std::vector<MeshSurfaceFitter::VertexMatrixStatus> MeshSurfaceFitter::OverallBottomPointsFitPlane() {
	// Carl: auto test for each vertex on the mesh model, which is a overall traverse of 
	/// function FitPlane(neighbor, point) is used for process plane fitting for a given point
	/// when the size of mesh is large, that function doesn't work will
	/// this function traverse each vertex and return test result
	/// test result is a pair of hashmap with the same structure that contains invertibility and determinant of coe matrix
	/// each map structure represents a couple of information in a dimension

	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this part is used to apply algorithm on 2, 23, and 3

	std::vector<MeshSurfaceFitter::VertexMatrixStatus> testResult;

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor = GetOneRingBottomPoints(verIter->idx());

		// Carl: define
		double sumX(0), sumY(0), sumZ(0);
		double sumXX(0), sumYY(0), sumXY(0), sumXZ(0), sumYZ(0);

		// Carl: sum
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter = neighbor.begin();
		while (iter != neighbor.end()) {
			double x = (*iter).first[0], y = (*iter).first[1], z = (*iter).first[2];

			sumX += x; sumY += y; sumZ += z;
			sumXX += x*x; sumYY += y*y; sumXY += x*y; sumXZ += x*z; sumYZ += y*z;
			iter++;
		}

		// Carl: get solution
		Eigen::Matrix3d coe3D, coe3DInverse;
		Eigen::Vector3d a3D;
		double determinant3D;
		bool invertible3D;

		coe3D << sumXX, sumXY, sumX, sumXY, sumYY, sumY, sumX, sumY, neighbor.size();

		// Carl: check invertibility
		coe3D.computeInverseAndDetWithCheck(coe3DInverse, determinant3D, invertible3D);

		// Carl: get solution
		Eigen::Matrix2d coe2D, coe2DInverse;
		Eigen::Vector2d a2D;
		double determinant2D;
		bool invertible2D;

		coe2D << sumXX, sumX, sumX, neighbor.size();

		// Carl: check invertibility
		coe2D.computeInverseAndDetWithCheck(coe2DInverse, determinant2D, invertible2D);

		// Carl: get solution
		double coe1D;

		coe1D = neighbor.size();

		// Carl: insert data
		VertexMatrixStatus vertexMatrixStatus;
		vertexMatrixStatus.determinant1D = coe1D;
		vertexMatrixStatus.determinant2D = determinant2D;
		vertexMatrixStatus.determinant3D = determinant3D;
		vertexMatrixStatus.invertible1D = true;
		vertexMatrixStatus.invertible2D = invertible2D;
		vertexMatrixStatus.invertible3D = invertible3D;

		testResult.push_back(vertexMatrixStatus);

	}

	return testResult;
}

std::vector<MeshSurfaceFitter::VertexMatrixStatus> MeshSurfaceFitter::OverallNeighborPointsFitPlane() {
	// Carl: auto test for each vertex on the mesh model, which is a overall traverse of 
	/// function FitPlane(neighbor, point) is used for process plane fitting for a given point
	/// when the size of mesh is large, that function doesn't work will
	/// this function traverse each vertex and return test result
	/// test result is a pair of hashmap with the same structure that contains invertibility and determinant of coe matrix
	/// each map structure represents a couple of information in a dimension

	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this part is used to apply algorithm on 2, 3, 12, 23, and 31

	std::vector<MeshSurfaceFitter::VertexMatrixStatus> testResult;

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor = GetOneRingNeighborPoints(verIter->idx());

		// Carl: define
		double sumX(0), sumY(0), sumZ(0);
		double sumXX(0), sumYY(0), sumXY(0), sumXZ(0), sumYZ(0);

		// Carl: sum
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter = neighbor.begin();
		while (iter != neighbor.end()) {
			double x = (*iter).first[0], y = (*iter).first[1], z = (*iter).first[2];

			sumX += x; sumY += y; sumZ += z;
			sumXX += x*x; sumYY += y*y; sumXY += x*y; sumXZ += x*z; sumYZ += y*z;
			iter++;
		}

		// Carl: get solution
		Eigen::Matrix3d coe3D, coe3DInverse;
		Eigen::Vector3d a3D;
		double determinant3D;
		bool invertible3D;

		coe3D << sumXX, sumXY, sumX, sumXY, sumYY, sumY, sumX, sumY, neighbor.size();

		// Carl: check invertibility
		coe3D.computeInverseAndDetWithCheck(coe3DInverse, determinant3D, invertible3D);

		// Carl: get solution
		Eigen::Matrix2d coe2D, coe2DInverse;
		Eigen::Vector2d a2D;
		double determinant2D;
		bool invertible2D;

		coe2D << sumXX, sumX, sumX, neighbor.size();

		// Carl: check invertibility
		coe2D.computeInverseAndDetWithCheck(coe2DInverse, determinant2D, invertible2D);

		// Carl: get solution
		double coe1D;

		coe1D = neighbor.size();

		// Carl: insert data
		VertexMatrixStatus vertexMatrixStatus;
		vertexMatrixStatus.determinant1D = coe1D;
		vertexMatrixStatus.determinant2D = determinant2D;
		vertexMatrixStatus.determinant3D = determinant3D;
		vertexMatrixStatus.invertible1D = true;
		vertexMatrixStatus.invertible2D = invertible2D;
		vertexMatrixStatus.invertible3D = invertible3D;

		testResult.push_back(vertexMatrixStatus);

	}

	return testResult;
}

std::vector<MeshSurfaceFitter::VertexMatrixStatus> MeshSurfaceFitter::OverallAllPointsFitPlane() {
	// Carl: auto test for each vertex on the mesh model, which is a overall traverse of 
	/// function FitPlane(neighbor, point) is used for process plane fitting for a given point
	/// when the size of mesh is large, that function doesn't work will
	/// this function traverse each vertex and return test result
	/// test result is a pair of hashmap with the same structure that contains invertibility and determinant of coe matrix
	/// each map structure represents a couple of information in a dimension

	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this part is used to apply algorithm on 1, 2, 3, 12, 23, and 31

	std::vector<MeshSurfaceFitter::VertexMatrixStatus> testResult;

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor = GetOneRingAllPoints(verIter->idx());

		// Carl: define
		double sumX(0), sumY(0), sumZ(0);
		double sumXX(0), sumYY(0), sumXY(0), sumXZ(0), sumYZ(0);

		// Carl: sum
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter = neighbor.begin();
		while (iter != neighbor.end()) {
			double x = (*iter).first[0], y = (*iter).first[1], z = (*iter).first[2];

			sumX += x; sumY += y; sumZ += z;
			sumXX += x*x; sumYY += y*y; sumXY += x*y; sumXZ += x*z; sumYZ += y*z;
			iter++;
		}

		// Carl: get solution
		Eigen::Matrix3d coe3D, coe3DInverse;
		Eigen::Vector3d a3D;
		double determinant3D;
		bool invertible3D;

		coe3D << sumXX, sumXY, sumX, sumXY, sumYY, sumY, sumX, sumY, neighbor.size();

		// Carl: check invertibility
		coe3D.computeInverseAndDetWithCheck(coe3DInverse, determinant3D, invertible3D);

		// Carl: get solution
		Eigen::Matrix2d coe2D, coe2DInverse;
		Eigen::Vector2d a2D;
		double determinant2D;
		bool invertible2D;

		coe2D << sumXX, sumX, sumX, neighbor.size();

		// Carl: check invertibility
		coe2D.computeInverseAndDetWithCheck(coe2DInverse, determinant2D, invertible2D);

		// Carl: get solution
		double coe1D;

		coe1D = neighbor.size();

		// Carl: insert data
		VertexMatrixStatus vertexMatrixStatus;
		vertexMatrixStatus.determinant1D = coe1D;
		vertexMatrixStatus.determinant2D = determinant2D;
		vertexMatrixStatus.determinant3D = determinant3D;
		vertexMatrixStatus.invertible1D = true;
		vertexMatrixStatus.invertible2D = invertible2D;
		vertexMatrixStatus.invertible3D = invertible3D;

		testResult.push_back(vertexMatrixStatus);

	}

	return testResult;
}



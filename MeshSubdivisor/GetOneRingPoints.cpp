#include "MeshSubdivisor.h"

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSubdivisor::GetOneRingMiddlePoints(int pointHandle) {
	// Carl: get points within one ring neighbor including part of subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 12, and 31

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = iMesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = iMesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
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
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = iMesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = iMesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = iMesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = iMesh.normal(verHandle3);

		// Carl: point23 is not related to point1, so it will change every iteration
		// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
		TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
		TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
		TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

		// Carl: efface all the repeated points and faces
		// Carl: make sure that the point is unique
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

		if (point1 == iMesh.point(vertHandle)) {

			// Carl: point12
			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

			// Carl: point31
			iter = oneRingVertexMap.find(point31);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

		}
		else if (point2 == iMesh.point(vertHandle)) {

			// Carl: point12
			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

			// Carl: point23
			iter = oneRingVertexMap.find(point23);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

		}
		else if (point3 == iMesh.point(vertHandle)) {

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

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSubdivisor::GetOneRingBasePoints(int pointHandle) {
	// Carl: get points within one ring neighbor including part of subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, and 3

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = iMesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = iMesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
		// Carl: Face in One Ring

		// Carl: define handle for each vertex
		TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
		// Carl: faceVertex;
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = iMesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); 

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

	}

	// Carl: remove itself;
	oneRingVertexMap.erase(iMesh.point(vertHandle));

	return oneRingVertexMap;
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSubdivisor::GetOneRingBottomPoints(int pointHandle) {
	// Carl: get points within one ring neighbor including part of subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, 23, and 3

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = iMesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = iMesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
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
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = iMesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = iMesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = iMesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = iMesh.normal(verHandle3);

		// Carl: point23 is not related to point1, so it will change every iteration
		// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
		TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
		TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
		TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

		// Carl: efface all the repeated points and faces
		// Carl: make sure that the point is unique
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

		if (point1 == iMesh.point(vertHandle)) {

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
		else if (point2 == iMesh.point(vertHandle)) {

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
		else if (point3 == iMesh.point(vertHandle)) {

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

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSubdivisor::GetOneRingNeighborPoints(int pointHandle) {
	// Carl: get points within one ring neighbor including subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, 3, 12, 23, and 31

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = iMesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
	oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(iMesh.point(vertHandle), vertHandle));

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = iMesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
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
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = iMesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = iMesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = iMesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = iMesh.normal(verHandle3);

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
	oneRingVertexMap.erase(iMesh.point(vertHandle));

	return oneRingVertexMap;
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSubdivisor::GetOneRingAllPoints(int pointHandle) {
	// Carl: get points within one ring neighbor including subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 1, 2, 3, 12, 23, and 31

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = iMesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
	oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(iMesh.point(vertHandle), vertHandle));

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = iMesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
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
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = iMesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); normal1 = iMesh.normal(verHandle1); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); normal2 = iMesh.normal(verHandle2); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle(); normal3 = iMesh.normal(verHandle3);

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
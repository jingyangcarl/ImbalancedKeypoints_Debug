#include "MeshSubdivisor.h"
#include "Macro.h"
#include <time.h>
#include <OpenMesh\Tools\Subdivider\Uniform\CatmullClarkT.hh>
#include <OpenMesh\Tools\Subdivider\Uniform\ModifiedButterFlyT.hh>
#include <OpenMesh\Tools\Subdivider\Uniform\LoopT.hh>
#include <OpenMesh\Core\Mesh\CirculatorsT.hh>


void MeshSubdivisor::MeshSubdivision() {
	// Carl: subdivision without fitting

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;

	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			//faceHandle = verFaceIter;
			//faceVerIter = iMesh.cfv_iter(faceHandle);
			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1 will not change as iteration going
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


			// Carl: faster than VERSION_2, and VERSION_3, 50% slower than VERSION_1
			// Carl: efface all the repeated points and faces
			// Carl: make sure that the point is unique
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

		}

	}

	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
}

void MeshSubdivisor::MeshSubdivision(std::vector<bool> isKeypoints) {
	// Carl: subdivision accroding to the keypoints

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;

	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {

		if (isKeypoints.at(verIter.handle().idx())) {
			// Carl: current point is a keypoint

			for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
				// Carl: Face in One Ring

				// Carl: define handle for each vertex
				TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
				TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
				TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
				TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
				TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
				TriMesh_ArrayKernelT<>::VertexHandle verHandle31;

				faceVerIter = iMesh.cfv_iter(verFaceIter);

				// Carl: point1 will not change as iteration going
				const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
				verHandle1 = faceVerIter.handle(); faceVerIter++;
				const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
				verHandle2 = faceVerIter.handle(); faceVerIter++;
				const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
				verHandle3 = faceVerIter.handle();

				// Carl: point23 is not related to point1, so it will change every iteration
				// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
				TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
				TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
				TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

				std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;
				iter = vertexMap.find(point12);
				if (iter != vertexMap.end())
					verHandle12 = iter->second;
				else {
					verHandle12 = oMesh.add_vertex(point12);
					vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
				}

				iter = vertexMap.find(point23);
				if (iter != vertexMap.end())
					verHandle23 = iter->second;
				else {
					verHandle23 = oMesh.add_vertex(point23);
					vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
				}

				iter = vertexMap.find(point31);
				if (iter != vertexMap.end())
					verHandle31 = iter->second;
				else {
					verHandle31 = oMesh.add_vertex(point31);
					vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
				}

				// Carl: get vertexhandle;
				if (!oMesh.status(verFaceIter).deleted()) {
					oMesh.delete_face(verFaceIter, true);

					oMesh.add_face(verHandle1, verHandle12, verHandle31);
					oMesh.add_face(verHandle2, verHandle23, verHandle12);
					oMesh.add_face(verHandle3, verHandle31, verHandle23);
					oMesh.add_face(verHandle12, verHandle23, verHandle31);
				}

			}

		}

	}

	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();

}

void MeshSubdivisor::MeshSubdivisionToolCatmull() {
	Subdivider::Uniform::CatmullClarkT<TriMesh_ArrayKernelT<Traits>> catmull;
	catmull.attach(oMesh);
	catmull(1);
	catmull.detach();
}

void MeshSubdivisor::MeshSubdivisionToolButterfly() {
	Subdivider::Uniform::ModifiedButterflyT<TriMesh_ArrayKernelT<Traits>> butterfly;
	butterfly.attach(oMesh);
	butterfly(1);
	butterfly.detach();
}

void MeshSubdivisor::MeshSubdivisionToolLoop() {
	Subdivider::Uniform::LoopT<TriMesh_ArrayKernelT<Traits>> loop;
	loop.attach(oMesh);
	loop(1);
	loop.detach();
}

void MeshSubdivisor::MiddlePointsFittingPlaneGuiding() {
	// Carl: subdivide and move points according to the following rules
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 12, and 31

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

#ifdef GET_NEIGHBOR_VERSION_1
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
#endif // GET_NEIGHBOR_VERSION_1
#ifdef GET_NEIGHBOR_VERSION_2
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingMiddlePoints(verIter->idx());
#endif // GET_NEIGHBOR_VERSION_2

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			faceVerIter = iMesh.cfv_iter(verFaceIter);

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

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

#ifdef GET_NEIGHBOR_VERSION_1

			// Carl: add points into one ring map
			if (point1 == iMesh.point(verIter)) {

				// Carl: point12
				iter = oneRingVertexMap.find(point12);
				if (iter == oneRingVertexMap.end())
					oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

				// Carl: point31
				iter = oneRingVertexMap.find(point31);
				if (iter == oneRingVertexMap.end())
					oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

			}
			else if (point2 == iMesh.point(verIter)) {

				// Carl: point12
				iter = oneRingVertexMap.find(point12);
				if (iter == oneRingVertexMap.end())
					oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

				// Carl: point23
				iter = oneRingVertexMap.find(point23);
				if (iter == oneRingVertexMap.end())
					oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

			}
			else if (point3 == iMesh.point(verIter)) {

				// Carl: point23
				iter = oneRingVertexMap.find(point23);
				if (iter == oneRingVertexMap.end())
					oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

				// Carl: point31
				iter = oneRingVertexMap.find(point31);
				if (iter == oneRingVertexMap.end())
					oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

			}

#endif // GET_NEIGHBOR_VERSION_1
			
		}
		// Carl: adjust point positions
		oMesh.point(verIter) = PointFittingPlaneAdjustment(oneRingVertexMap, iMesh.point(verIter));
	}
	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
}

void MeshSubdivisor::BottomPointsFittingPlaneGuiding() {
	// Carl: subdivide and move points according to the following rules
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, 23, and 3

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

#ifdef GET_NEIGHBOR_VERSION_1
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
#endif // GET_NEIGHBOR_VERSION_1
#ifdef GET_NEIGHBOR_VERSION_2
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingBottomPoints(verIter->idx());
#endif // GET_NEIGHBOR_VERSION_2

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			faceVerIter = iMesh.cfv_iter(verFaceIter);

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

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

#ifdef GET_NEIGHBOR_VERSION_1

			// Carl: add points into one ring map
			if (point1 == iMesh.point(verIter)) {

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
			else if (point2 == iMesh.point(verIter)) {

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
			else if (point3 == iMesh.point(verIter)) {

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

#endif // GET_NEIGHBOR_VERSION_1

		}

		// Carl: remove itself;
		oneRingVertexMap.erase(iMesh.point(verIter));

		// Carl: adjust point positions
		oMesh.point(verIter) = PointFittingPlaneAdjustment(oneRingVertexMap, iMesh.point(verIter));
	}
	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
}

void MeshSubdivisor::NeighborPointsFittingPlaneGuiding() {
	// Carl: subdivide and move points according to the following rules
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, 3, 12, 23, and 31

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

#ifdef GET_NEIGHBOR_VERSION_1
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
#endif // GET_NEIGHBOR_VERSION_1
#ifdef GET_NEIGHBOR_VERSION_2
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingNeighborPoints(verIter->idx());
#endif // GET_NEIGHBOR_VERSION_2

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			faceVerIter = iMesh.cfv_iter(verFaceIter);

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

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

#ifdef GET_NEIGHBOR_VERSION_1

			// Carl: add points into one ring map
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

#endif // GET_NEIGHBOR_VERSION_1

		}
		// Carl: adjust point positions
		oMesh.point(verIter) = PointFittingPlaneAdjustment(oneRingVertexMap, iMesh.point(verIter));
	}
	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
}

void MeshSubdivisor::AllPointsFittingPlaneGuiding() {
	// Carl: subdivide and move points according to the following rules
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 1, 2, 3, 12, 23, and 31

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

#ifdef GET_NEIGHBOR_VERSION_1
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
#endif // GET_NEIGHBOR_VERSION_1
#ifdef GET_NEIGHBOR_VERSION_2
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap = GetOneRingAllPoints(verIter->idx());
#endif // GET_NEIGHBOR_VERSION_2

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			faceVerIter = iMesh.cfv_iter(verFaceIter);

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

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

#ifdef GET_NEIGHBOR_VERSION_1

			// Carl: add points into one ring map
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

#endif // GET_NEIGHBOR_VERSION_1

		}
		// Carl: adjust point positions
		oMesh.point(verIter) = PointFittingPlaneAdjustment(oneRingVertexMap, iMesh.point(verIter));
	}
	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
}

void MeshSubdivisor::NeighborWeightedPointGuiding() {
	// Carl: new created points is decided by adjacent points

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex
				
		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			faceVerIter = iMesh.cfv_iter(verFaceIter);

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

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

		}
	}
	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();

	// Carl: recalculate position
	iMesh = oMesh;
	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());
		// Carl: adjust point positions
		oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
	}
}

void MeshSubdivisor::NeighborWeightedFaceGuiding() {
	// Carl: the new created points is decided by the adjacent faces;
	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	TriMesh_ArrayKernelT<>::HalfedgeIter halfedgeIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
			// Carl: Face in One Ring

			// Carl: define handle for each vertex
			///  12Prime -- 1 -- 31Prime
			///      \     / \     /
			///       \   12  31  /
			///        \ /     \ /
			///         2- 23 - 3
			///          \     /
			///           \   /
			///            \ /
			///          23Prime 

			TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31Prime;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle12;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle23;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle31;
			TriMesh_ArrayKernelT<>::HalfedgeHandle nextHalfedgeHandle;

			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1, point2, and point3 are the triangle vertices
			const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
			verHandle1 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
			verHandle2 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
			verHandle3 = faceVerIter.handle();

			// Carl: get halfedge handles
			halfedgeHandle12 = iMesh.find_halfedge(verHandle1, verHandle2);
			halfedgeHandle23 = iMesh.find_halfedge(verHandle2, verHandle3);
			halfedgeHandle31 = iMesh.find_halfedge(verHandle3, verHandle1);

			// Carl: point12Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle12);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle12Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point12Prime = iMesh.point(verHandle12Prime);

			// Carl: point23Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle23);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle23Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point23Prime = iMesh.point(verHandle23Prime);

			// Carl: point31Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle31);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle31Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point31Prime = iMesh.point(verHandle31Prime);

			// Carl: point23 is not related to point1, so it will change every iteration
			// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
			TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2, point3, point12Prime);
			TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3, point1, point23Prime);
			TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1, point2, point31Prime);

			// Carl: efface all the repeated points and faces
			// Carl: make sure that the point is unique
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, false);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

		}

		// Carl: adjust point positions
		oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
	}

	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
}

void MeshSubdivisor::NeighborWeightedGuiding(std::vector<bool> isKeypoints) {
	// Carl: a combination of NeighborWeightedPointGuiding and NeighborWeighteFaceGuiding, controlled by keypoints;

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> middleNeighbors = GetOneRingMiddlePoints(verIter->idx());

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
			// Carl: Face in One Ring

			// Carl: define handle for each vertex
			///  12Prime -- 1 -- 31Prime
			///      \     / \     /
			///       \   12  31  /
			///        \ /     \ /
			///         2- 23 - 3
			///          \     /
			///           \   /
			///            \ /
			///          23Prime 

			// Carl: define handle for each vertex
			TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31Prime;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle12;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle23;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle31;
			TriMesh_ArrayKernelT<>::HalfedgeHandle nextHalfedgeHandle;

			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1, point2, and point3 are the triangle vertices
			const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
			verHandle1 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
			verHandle2 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
			verHandle3 = faceVerIter.handle();

			// Carl: get halfedge handles
			halfedgeHandle12 = iMesh.find_halfedge(verHandle1, verHandle2);
			halfedgeHandle23 = iMesh.find_halfedge(verHandle2, verHandle3);
			halfedgeHandle31 = iMesh.find_halfedge(verHandle3, verHandle1);

			// Carl: point12Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle12);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle12Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point12Prime = iMesh.point(verHandle12Prime);

			// Carl: point23Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle23);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle23Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point23Prime = iMesh.point(verHandle23Prime);

			// Carl: point31Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle31);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle31Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point31Prime = iMesh.point(verHandle31Prime);

			// Carl: point12, point23, or point31 will be the touching point to other vertex iteration
			/// the position depends on weather point1 and point23Prime are both keypoints, which leads the following situations
			/// if point1 and point23Prime are both keypoints, point23 should be calculated by point1, point2, point3, and point23Prime in each iteration
			/// else if point1 and point23Prime are both anti-keypoints, point23 should be calculated by point2, and point3 in each iteration.
			/// else if point1 are keypoint but point23Prime, point23 should be calculated by a weighted combination method of the last two situations.
			TriMesh_ArrayKernelT<>::Point point12, point23, point31;
			TriMesh_ArrayKernelT<>::Point point12Face = GetMidPoint(point1, point2, point3, point12Prime);
			TriMesh_ArrayKernelT<>::Point point23Face = GetMidPoint(point2, point3, point1, point23Prime);
			TriMesh_ArrayKernelT<>::Point point31Face = GetMidPoint(point3, point1, point2, point31Prime);
			TriMesh_ArrayKernelT<>::Point point12Point = GetMidPoint(point1, point2);
			TriMesh_ArrayKernelT<>::Point point23Point = GetMidPoint(point2, point3);
			TriMesh_ArrayKernelT<>::Point point31Point = GetMidPoint(point3, point1);
			double point12FaceWeight(0), point23FaceWeight(0), point31FaceWeight(0);
			double point12PointWeight(0), point23PointWeight(0), point31PointWeight(0);

			// Carl: within a couple of triangle, the weighted of vertices should be 
			///         1		|	N	||	1	|	2	|	3	|	4	|		P		|
			///        / \		-------------------------------------------------
			///       /   \		|	15	||	1	|	1	|	1	|	1	| 4/4*F + 0/4*P	|
			///      /     \	|	14	||	1	|	1	|	1	|	0	| 3/4*F + 1/4*P	|
			///     2 --P-- 3	|	13	||	1	|	1	|	0	|	1	| 3/4*F + 1/4*P	|
			///      \     /	|	12	||	1	|	1	|	0	|	0	| 2/4*F + 2/4*P	|
			///       \   /		|	11	||	1	|	0	|	1	|	1	| 3/4*F + 1/4*P	|
			///        \ /		|	10	||	1	|	0	|	1	|	0	| 2/4*F + 1/4*P	|
			///         4		|	9	||	1	|	0	|	0	|	1	| 2/4*F + 2/4*P	|
			///					|	8	||	1	|	0	|	0	|	0	| 1/4*F + 3/4*P	|
			///					|	7	||	0	|	1	|	1	|	1	| 3/4*F + 1/4*P	|
			///		1 - key		|	6	||	0	|	1	|	1	|	0	| 2/4*F + 2/4*P	|
			///		0 - unkey	|	5	||	0	|	1	|	0	|	1	| 2/4*F + 2/4*P	|
			///					|	4	||	0	|	1	|	0	|	0	| 1/4*F + 3/4*P	|
			///					|	3	||	0	|	0	|	1	|	1	| 2/4*F + 2/4*P	|
			///					|	2	||	0	|	0	|	1	|	0	| 1/4*F + 3/4*P	|
			///					|	1	||	0	|	0	|	0	|	1	| 1/4*F + 3/4*P	|
			///					|	0	||	0	|	0	|	0	|	0	| 0/4*F + 4/4*P	|
			// Carl: within a iteration
			///  12' ---- 1 ---- 31'	|	N	||	1	|	2	|	3	|	12'	|	23'	|	31'	|		12		|		23		|		31		|
			///    \     / \     /		-------------------------------------------------------------------------------------------------
			///     \   12  31  /		|	63	||	1	|	1	|	1	|	1	|	1	|	1	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///      \ /     \ /		|	62	||	1	|	1	|	1	|	1	|	1	|	0	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///       2- 23 - 3			|	61	||	1	|	1	|	1	|	1	|	0	|	1	| 4/4*F + 0/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///        \     /			|	60	||	1	|	1	|	1	|	1	|	0	|	0	| 4/4*F + 0/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///         \   /			|	69	||	1	|	1	|	1	|	0	|	1	|	1	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///          \ /			|	58	||	1	|	1	|	1	|	0	|	1	|	0	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///          23'			|	57	||	1	|	1	|	1	|	0	|	0	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	56	||	1	|	1	|	1	|	0	|	0	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///			1 - key			|	55	||	1	|	1	|	0	|	1	|	1	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///			0 - unkey		|	54	||	1	|	1	|	0	|	1	|	1	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	53	||	1	|	1	|	0	|	1	|	0	|	1	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	52	||	1	|	1	|	0	|	1	|	0	|	0	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	51	||	1	|	1	|	0	|	0	|	1	|	1	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///							|	50	||	1	|	1	|	0	|	0	|	1	|	0	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///							|	59	||	1	|	1	|	0	|	0	|	0	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	48	||	1	|	1	|	0	|	0	|	0	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	47	||	1	|	0	|	1	|	1	|	1	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	46	||	1	|	0	|	1	|	1	|	1	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	45	||	1	|	0	|	1	|	1	|	0	|	1	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	44	||	1	|	0	|	1	|	1	|	0	|	0	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	43	||	1	|	0	|	1	|	0	|	1	|	1	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	42	||	1	|	0	|	1	|	0	|	1	|	0	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	41	||	1	|	0	|	1	|	0	|	0	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	40	||	1	|	0	|	1	|	0	|	0	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	39	||	1	|	0	|	0	|	1	|	1	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	38	||	1	|	0	|	0	|	1	|	1	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	37	||	1	|	0	|	0	|	1	|	0	|	1	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	36	||	1	|	0	|	0	|	1	|	0	|	0	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	35	||	1	|	0	|	0	|	0	|	1	|	1	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	34	||	1	|	0	|	0	|	0	|	1	|	0	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	33	||	1	|	0	|	0	|	0	|	0	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	32	||	1	|	0	|	0	|	0	|	0	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	31	||	0	|	1	|	1	|	1	|	1	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	30	||	0	|	1	|	1	|	1	|	1	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	29	||	0	|	1	|	1	|	1	|	0	|	1	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	28	||	0	|	1	|	1	|	1	|	0	|	0	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	27	||	0	|	1	|	1	|	0	|	1	|	1	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	26	||	0	|	1	|	1	|	0	|	1	|	0	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	25	||	0	|	1	|	1	|	0	|	0	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	24	||	0	|	1	|	1	|	0	|	0	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	23	||	0	|	1	|	0	|	1	|	1	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	22	||	0	|	1	|	0	|	1	|	1	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	21	||	0	|	1	|	0	|	1	|	0	|	1	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	10	||	0	|	1	|	0	|	1	|	0	|	0	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	19	||	0	|	1	|	0	|	0	|	1	|	1	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	18	||	0	|	1	|	0	|	0	|	1	|	0	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	17	||	0	|	1	|	0	|	0	|	0	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	16	||	0	|	1	|	0	|	0	|	0	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	15	||	0	|	0	|	1	|	1	|	1	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	14	||	0	|	0	|	1	|	1	|	1	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	13	||	0	|	0	|	1	|	1	|	0	|	1	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	12	||	0	|	0	|	1	|	1	|	0	|	0	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	11	||	0	|	0	|	1	|	0	|	1	|	1	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	10	||	0	|	0	|	1	|	0	|	1	|	0	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	9	||	0	|	0	|	1	|	0	|	0	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	8	||	0	|	0	|	1	|	0	|	0	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	7	||	0	|	0	|	0	|	1	|	1	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	6	||	0	|	0	|	0	|	1	|	1	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	5	||	0	|	0	|	0	|	1	|	0	|	1	| 1/4*F + 3/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|
			///							|	4	||	0	|	0	|	0	|	1	|	0	|	0	| 1/4*F + 3/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|
			///							|	3	||	0	|	0	|	0	|	0	|	1	|	1	| 0/4*F + 4/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	2	||	0	|	0	|	0	|	0	|	1	|	0	| 0/4*F + 4/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	1	||	0	|	0	|	0	|	0	|	0	|	1	| 0/4*F + 4/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|
			///							|	0	||	0	|	0	|	0	|	0	|	0	|	0	| 0/4*F + 4/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|

			// Carl: point12 weight
			point12FaceWeight = isKeypoints.at(verHandle1.idx()) + isKeypoints.at(verHandle2.idx()) + isKeypoints.at(verHandle3.idx()) + isKeypoints.at(verHandle12Prime.idx());
			point12PointWeight = !isKeypoints.at(verHandle1.idx()) + !isKeypoints.at(verHandle2.idx()) + !isKeypoints.at(verHandle3.idx()) + !isKeypoints.at(verHandle12Prime.idx());

			// Carl: point23 weight
			point23FaceWeight = isKeypoints.at(verHandle1.idx()) + isKeypoints.at(verHandle2.idx()) + isKeypoints.at(verHandle3.idx()) + isKeypoints.at(verHandle23Prime.idx());
			point23PointWeight = !isKeypoints.at(verHandle1.idx()) + !isKeypoints.at(verHandle2.idx()) + !isKeypoints.at(verHandle3.idx()) + !isKeypoints.at(verHandle23Prime.idx());

			// Carl: point31 weight
			point31FaceWeight = isKeypoints.at(verHandle1.idx()) + isKeypoints.at(verHandle2.idx()) + isKeypoints.at(verHandle3.idx()) + isKeypoints.at(verHandle31Prime.idx());
			point31PointWeight = !isKeypoints.at(verHandle1.idx()) + !isKeypoints.at(verHandle2.idx()) + !isKeypoints.at(verHandle3.idx()) + !isKeypoints.at(verHandle31Prime.idx());

			// Carl: get point12, point23, and point31
			point12 = (point12FaceWeight * point12Face + point12PointWeight * point12Point) / 4.0;
			point23 = (point23FaceWeight * point23Face + point23PointWeight * point23Point) / 4.0;
			point31 = (point31FaceWeight * point31Face + point31PointWeight * point31Point) / 4.0;
			

			 // Carl: efface all the repeated points and faces
			 // Carl: make sure that the point is unique
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}/// Carl: point12

			 // Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}/// Carl: point23

			 // Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}/// Carl: point31

			 // Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}
		}/// Face in One Ring

		 // Carl: adjust point positions
		if (isKeypoints.at(verIter.handle().idx())) {
			oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
		}
		else {
			oMesh.point(verIter) = PointNeighborWeightedAdjustment(middleNeighbors, iMesh.point(verIter));
		}
	}/// for each vertex
	
	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();

	// Carl: recalculate position
	iMesh = oMesh;
	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		if (verIter.handle().idx() >= isKeypoints.size()) {
			// Carl: added points
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());
			oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
		}
	}

}

void MeshSubdivisor::MeshIdlingTraverse() {
	// Carl: CPU idling, reference: "MeshSubdivisor Idling.xlsx"
	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;

	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1 will not change as iteration going
			const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
			verHandle1 = faceVerIter.handle(); normal1 = iMesh.normal(verHandle1); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
			verHandle2 = faceVerIter.handle(); normal2 = iMesh.normal(verHandle2); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
			verHandle3 = faceVerIter.handle(); normal3 = iMesh.normal(verHandle3);

			verHandle1 = verHandle1;
		}

	}
}

void MeshSubdivisor::TestMeshSubdivision() {
	// Carl: subdivision with fitting

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;


#if defined(VERSION_2) || defined(VERSION_3)
	std::vector<TriMesh_ArrayKernelT<>::Point> vertexList;
	std::set<std::set<TriMesh_ArrayKernelT<>::VertexHandle>> faceList;
#elif defined(VERSION_4)
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;
#endif // VERSION_2 | VERSION_3 | VERSION_4
		
	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;
		oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(iMesh.point(verIter), verIter.handle()));
		
		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
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

			//faceHandle = verFaceIter;
			//faceVerIter = iMesh.cfv_iter(faceHandle);
			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1 will not change as iteration going
			const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
			verHandle1 = faceVerIter.handle(); normal1 = iMesh.normal(verHandle1); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
			verHandle2 = faceVerIter.handle(); normal2 = iMesh.normal(verHandle2); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
			verHandle3 = faceVerIter.handle(); normal3 = iMesh.normal(verHandle3);


			// Carl: point23 is not related to point1, so it will change every iteration
			// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
#ifdef POINT_VERSION_1
			TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
			TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
			TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);
#endif // MIDPOINT_VERSION_1

#ifdef POINT_VERSION_2
			TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, normal1, point2, normal2);
			TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, normal2, point3, normal3);
			TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, normal3, point1, normal1);
#endif // MIDPOINT_VERSION_2

#ifdef VERSION_1
			// Carl: faster than VERSION_2, VERSION_3, and VERSION_4
			// Carl: didn't efface repeated points.
			// Carl: get handles
			verHandle12 = oMesh.add_vertex(point12);
			verHandle23 = oMesh.add_vertex(point23);
			verHandle31 = oMesh.add_vertex(point31);

			std::vector<TriMesh_ArrayKernelT<>::VertexHandle> faceHandle;

			faceHandle.push_back(verHandle1);
			faceHandle.push_back(verHandle12);
			faceHandle.push_back(verHandle31);
			oMesh.add_face(faceHandle);
			faceHandle.clear();

			faceHandle.push_back(verHandle2);
			faceHandle.push_back(verHandle12);
			faceHandle.push_back(verHandle23);
			oMesh.add_face(faceHandle);
			faceHandle.clear();

			faceHandle.push_back(verHandle3);
			faceHandle.push_back(verHandle23);
			faceHandle.push_back(verHandle31);
			oMesh.add_face(faceHandle);
			faceHandle.clear();

			faceHandle.push_back(verHandle12);
			faceHandle.push_back(verHandle23);
			faceHandle.push_back(verHandle31);
			oMesh.add_face(faceHandle);
			faceHandle.clear();
						

#endif // VERSION_1

#ifdef VERSION_2
			// Carl: slowest algorithm
			// Carl: efface all the repeated points and faces

			// Carl: make sure that the point is unique
			std::vector<TriMesh_ArrayKernelT<>::Point>::iterator iter;
			bool hasMidPoint12 = false, hasMidPoint23 = false, hasMidPoint31 = false;
			int indexMidPoint12 = 0, indexMidPoint23 = 0, indexMidPoint31 = 0;

			for (iter = vertexList.begin(); iter != vertexList.end(); iter++) {
				if (*iter == point12) {
					hasMidPoint12 = true;
					indexMidPoint12 = iter - vertexList.begin();
					verHandle12 = oMesh.vertex_handle(iMesh.n_vertices() + indexMidPoint12);
					// Carl: test if the handle is the point handle
					//TriMesh_ArrayKernelT<>::Point point = oMesh.point(verHandle12);
				}
				if (*iter == point23) {
					hasMidPoint23 = true;
					indexMidPoint23 = iter - vertexList.begin();
					verHandle23 = oMesh.vertex_handle(iMesh.n_vertices() + indexMidPoint23);
					// Carl: test if the handle is the point handle
					//TriMesh_ArrayKernelT<>::Point point = oMesh.point(verHandle23);
				}
				if (*iter == point31) {
					hasMidPoint31 = true;
					indexMidPoint31 = iter - vertexList.begin();
					verHandle31 = oMesh.vertex_handle(iMesh.n_vertices() + indexMidPoint31);
					// Carl: test if the handle is the point handle
					//TriMesh_ArrayKernelT<>::Point point = oMesh.point(verHandle31);
				}
			}
			if (!hasMidPoint12) {
				vertexList.push_back(point12);
				verHandle12 = oMesh.add_vertex(point12);
			}
			if (!hasMidPoint23) {
				vertexList.push_back(point23);
				verHandle23 = oMesh.add_vertex(point23);
			}
			if (!hasMidPoint31) {
				vertexList.push_back(point31);
				verHandle31 = oMesh.add_vertex(point31);
			}
			
			// Carl: get vertexhandle;
 			std::set<TriMesh_ArrayKernelT<>::VertexHandle> vertexSet;

			vertexSet.insert(verHandle1);
			vertexSet.insert(verHandle12);
			vertexSet.insert(verHandle31);
			if(faceList.find(vertexSet) == faceList.end())
				faceList.insert(vertexSet);
 			vertexSet.clear();

			vertexSet.insert(verHandle2);
			vertexSet.insert(verHandle12);
			vertexSet.insert(verHandle23);
			if (faceList.find(vertexSet) == faceList.end())
				faceList.insert(vertexSet);
			vertexSet.clear();

			vertexSet.insert(verHandle3);
			vertexSet.insert(verHandle23);
			vertexSet.insert(verHandle31);
			if (faceList.find(vertexSet) == faceList.end())
				faceList.insert(vertexSet);
			vertexSet.clear();

			vertexSet.insert(verHandle12);
			vertexSet.insert(verHandle23);
			vertexSet.insert(verHandle31);
			if (faceList.find(vertexSet) == faceList.end())
				faceList.insert(vertexSet);
			vertexSet.clear();
#endif // VERSION_2

#ifdef VERSION_3
			// Carl: faster than VERSION_2, slower than VERSION_1
			// Carl: efface repeated faces and points

			// Carl: make sure that the point is unique
			std::vector<TriMesh_ArrayKernelT<>::Point>::iterator iter;
			bool hasMidPoint12 = false, hasMidPoint23 = false, hasMidPoint31 = false;
			int indexMidPoint12 = 0, indexMidPoint23 = 0, indexMidPoint31 = 0;

			for (iter = vertexList.begin(); iter != vertexList.end(); iter++) {
				if (*iter == point12) {
					hasMidPoint12 = true;
					indexMidPoint12 = iter - vertexList.begin();
					verHandle12 = oMesh.vertex_handle(iMesh.n_vertices() + indexMidPoint12);
					// Carl: test if the handle is the point handle
					//TriMesh_ArrayKernelT<>::Point point = oMesh.point(verHandle12);
				}
				if (*iter == point23) {
					hasMidPoint23 = true;
					indexMidPoint23 = iter - vertexList.begin();
					verHandle23 = oMesh.vertex_handle(iMesh.n_vertices() + indexMidPoint23);
					// Carl: test if the handle is the point handle
					//TriMesh_ArrayKernelT<>::Point point = oMesh.point(verHandle23);
				}
				if (*iter == point31) {
					hasMidPoint31 = true;
					indexMidPoint31 = iter - vertexList.begin();
					verHandle31 = oMesh.vertex_handle(iMesh.n_vertices() + indexMidPoint31);
					// Carl: test if the handle is the point handle
					//TriMesh_ArrayKernelT<>::Point point = oMesh.point(verHandle31);
				}
			}
			if (!hasMidPoint12) {
				vertexList.push_back(point12);
				verHandle12 = oMesh.add_vertex(point12);
			}
			if (!hasMidPoint23) {
				vertexList.push_back(point23);
				verHandle23 = oMesh.add_vertex(point23);
			}
			if (!hasMidPoint31) {
				vertexList.push_back(point31);
				verHandle31 = oMesh.add_vertex(point31);
			}

			// Carl: get vertexhandle;
			std::vector<TriMesh_ArrayKernelT<>::VertexHandle> faceHandle;

			faceHandle.push_back(verHandle1);
			faceHandle.push_back(verHandle12);
			faceHandle.push_back(verHandle31);
			oMesh.add_face(faceHandle);
			faceHandle.clear();

			faceHandle.push_back(verHandle2);
			faceHandle.push_back(verHandle23);
			faceHandle.push_back(verHandle12);
			oMesh.add_face(faceHandle);
			faceHandle.clear();

			faceHandle.push_back(verHandle3);
			faceHandle.push_back(verHandle31);
			faceHandle.push_back(verHandle23);
			oMesh.add_face(faceHandle);
			faceHandle.clear();

			faceHandle.push_back(verHandle12);
			faceHandle.push_back(verHandle23);
			faceHandle.push_back(verHandle31);
			oMesh.add_face(faceHandle);
			faceHandle.clear();

#endif // VERIOSN_3

#ifdef VERSION_4
			// Carl: faster than VERSION_2, and VERSION_3, 50% slower than VERSION_1
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
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			iter = oneRingVertexMap.find(point23);
			if(iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			iter = oneRingVertexMap.find(point31);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}


#endif // VERSION_4


		}

		// Carl: adjust point positions
		oMesh.point(verIter) = PointFittingPlaneAdjustment(oneRingVertexMap, iMesh.point(verIter));
		
	}

#ifdef VERSION_2

	// Carl: efface the same face
	for (std::set<std::set<TriMesh_ArrayKernelT<>::VertexHandle>>::iterator iter = faceList.begin(); iter != faceList.end(); iter++) {
		std::vector<TriMesh_ArrayKernelT<>::VertexHandle> faceHandles;
		for (std::set<TriMesh_ArrayKernelT<>::VertexHandle>::iterator i = (*iter).begin(); i != (*iter).end(); i++)
			faceHandles.push_back(*i);
		oMesh.add_face(faceHandles);
	}

#endif // VERSION_2

	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
	
}

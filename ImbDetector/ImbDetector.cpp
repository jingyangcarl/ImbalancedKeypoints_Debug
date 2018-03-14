#include "ImbDetector.h"
#include "Macro.h"

std::vector<bool> ImbDetector::ImbDetection() {

	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexVertexIter verVerIter;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	OpenMesh::TriMesh_ArrayKernelT<>::Point point;
	OpenMesh::TriMesh_ArrayKernelT<>::Normal normal;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle verHandle;
	std::vector<bool> isKeypoints;
	bool isKeypoint;

	double meshScale = GetMeshScale();

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {
		
		verHandle = *verIter;

		if (mesh.is_boundary(verIter.handle())) {
			isKeypoints.push_back(false);
			continue;
		}

		point = mesh.point(*verIter);
		normal = mesh.normal(*verIter);

		float normalX = normal[0] * 1000;
		float normalY = normal[1] * 1000;
		float normalZ = normal[2] * 1000;
		float normalFloat[3] = { normalX, normalY, normalZ };

		float xX = 1.0f;
		float xY = 1.0f;
		float xZ = (0 - (xX*normalX + xY*normalY)) / normalZ;

		float yX = normalY * xZ - xY * normalZ;
		float yY = normalZ * xX - xZ * normalX;
		float yZ = normalX * xY - xX * normalY;

		GetNormalizedVector(xX, xY, xZ);
		GetNormalizedVector(yX, yY, xZ);

		float vectorX[3] = { xX, xY, xZ };
		float vectorY[3] = { yX, yY, yZ };

		OpenMesh::Vec3f grid2D[3][3];

		for(int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++) {
				grid2D[i][j][0] = point[0] + normal[0] * 0.2 + (i - 1) * xX * meshScale + (j - 1) * yX * meshScale;
				grid2D[i][j][1] = point[1] + normal[1] * 0.2 + (i - 1) * xY * meshScale + (j - 1) * yY * meshScale;
				grid2D[i][j][2] = point[2] + normal[2] * 0.2 + (i - 1) * xZ * meshScale + (j - 1) * yZ * meshScale;
			}
		}

		std::vector<OpenMesh::FaceHandle> faceList;

		for (verFaceIter = mesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
			// Carl: One ring
			OpenMesh::TriMesh_ArrayKernelT<>::FaceHandle faceHandle = verFaceIter;
			OpenMesh::TriMesh_ArrayKernelT<>::ConstFaceVertexIter faceVerIter = mesh.cfv_iter(faceHandle);

			const OpenMesh::TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter);	faceVerIter++;
			const OpenMesh::TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter);	faceVerIter++;
			const OpenMesh::TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter);

			faceList.push_back(faceHandle);

#ifdef TWO_RING

			OpenMesh::TriMesh_ArrayKernelT<>::FaceFaceIter faceFaceIter;
			for (faceFaceIter = mesh.ff_iter(faceHandle); faceFaceIter; faceFaceIter++) {
				// Carl: Two ring
				OpenMesh::TriMesh_ArrayKernelT<>::FaceHandle faceHandle2 = faceFaceIter;
				OpenMesh::TriMesh_ArrayKernelT<>::ConstFaceVertexIter faceVerIter2 = mesh.cfv_iter(faceHandle2);

				const OpenMesh::TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter2); faceVerIter2++;
				const OpenMesh::TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter2); faceVerIter2++;
				const OpenMesh::TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter2);

				faceList.push_back(faceHandle2);
			}

#endif // TWO_RING

			// Carl: efface the same elements;
			for (std::vector<OpenMesh::FaceHandle>::iterator iter = faceList.begin(); iter != faceList.end(); iter++) {
				std::vector<OpenMesh::FaceHandle>::const_iterator iterInside = faceList.end();
				iterInside--;
				for (iterInside; iterInside != iter; iterInside--) {
					if ((*iter) == (*iterInside))
						iterInside = faceList.erase(iterInside);
				}
			}

		}

		isKeypoint = ImbThresholdDetection(grid2D, faceList, verHandle, mesh);
		isKeypoints.push_back(isKeypoint);
	}

	return isKeypoints;
}

bool ImbDetector::ImbThresholdDetection(OpenMesh::Vec3f grid2D[3][3], std::vector<OpenMesh::FaceHandle> faceList, OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle vertexHandle, OpenMesh::TriMesh_ArrayKernelT<> &mesh) {
	
	struct point3D{
		float x;
		float y;
		float z;
	};

	typedef OpenMesh::TriMesh_ArrayKernelT<>	MVMesh;
	typedef std::vector<OpenMesh::FaceHandle>	FaceList;
	typedef std::vector<point3D>				ArrayList3;
	typedef std::vector<float>							 ArrayList;

	
	
	float vertexPoint[3];
	float gridPointcenter[3];
	MVMesh::Point pVertex = mesh.point(vertexHandle);
	MVMesh::VertexFaceIter vf_it;
	MVMesh::VertexVertexIter vv_it = mesh.vv_begin(vertexHandle);
	int OneRingVertexNum = 0;


	//当前网格顶点的坐标
	vertexPoint[0] = pVertex[0];
	vertexPoint[1] = pVertex[1];
	vertexPoint[2] = pVertex[2];

	//切平面的中心点
	gridPointcenter[0] = grid2D[1][1][0];
	gridPointcenter[1] = grid2D[1][1][1];
	gridPointcenter[2] = grid2D[1][1][2];

	//计算与网格顶点垂直方向切平面的方程 ax + by +cz + d = 0
	float a, b, c, d;
	float point[9] = { grid2D[0][0][0], grid2D[0][0][1], grid2D[0][0][2],
		grid2D[0][2][0], grid2D[0][2][1], grid2D[0][2][2],
		grid2D[2][2][0], grid2D[2][2][1], grid2D[2][2][2] };
	a = b = c = d = 0;

	//得到且平面的方程
	GetFaceEquation(a, b, c, d, point);
	float pointOfIntersection[3] = { 0, 0, 0 };

	ArrayList3 faceNormalPointList;

	MVMesh::ConstVertexFaceIter v_it = mesh.cvf_iter(vertexHandle);

	for (vv_it; vv_it != mesh.vv_end(vertexHandle); ++vv_it)
		//for(vf_it = mesh_.vf_iter(vertexHandle);vf_it;++vf_it)
	{
		OneRingVertexNum++;
	}

	//计算顶点领域面法向量与切平面的交点
	for (FaceList::iterator it = faceList.begin(); it != faceList.end(); ++it)
	{
		OpenMesh::FaceHandle fh = *it;

		//获取当前三角面上的法向量
		const MVMesh::Normal fn = mesh.calc_face_normal(fh);
		float fnormal[3];
		fnormal[0] = fn[0];
		fnormal[1] = fn[1];
		fnormal[2] = fn[2];

		GetPointofIntersection(a, b, c, d, pointOfIntersection, vertexPoint, fnormal);

		point3D p;
		p.x = pointOfIntersection[0];
		p.y = pointOfIntersection[1];
		p.z = pointOfIntersection[2];

		faceNormalPointList.push_back(p);
	}

#ifdef VERSION_1
	ArrayList faceNormalAngleList;
	for (ArrayList3::iterator it = faceNormalPointList.begin(); it != faceNormalPointList.end(); ++it)
	{
		ArrayList3::iterator it2;
		if (it == faceNormalPointList.end() - 1)
		{
			it2 = faceNormalPointList.begin();
		}
		else
		{
			it2 = it + 1;
		}
		float currentAngle;
		point3D pp1 = *it;
		point3D pp2 = *it2;

		float p1[3], p2[3];
		p1[0] = pp1.x;
		p1[1] = pp1.y;
		p1[2] = pp1.z;
		p2[0] = pp2.x;
		p2[1] = pp2.y;
		p2[2] = pp2.z;

		currentAngle = GetAngle(gridPointcenter, p1, p2);
		faceNormalAngleList.push_back(currentAngle);

	}


	std::sort(faceNormalAngleList.begin(), faceNormalAngleList.end());

	//maxDiff
	float maxDiff = 0;
	int count = 0;
	int countMaxDiff = 0;

	for (ArrayList::iterator it = faceNormalAngleList.begin(); it != faceNormalAngleList.end(); it++)
	{
		if (it == faceNormalAngleList.end() - 1)
		{
			break;
		}
		count += 1;
		ArrayList::iterator it2 = it + 1;
		float Diff = abs(*(it2)-*it);
		if (Diff > maxDiff)
		{
			maxDiff = Diff;
			countMaxDiff = count;
		}
	}

	// ----------------------- 这是修改过后的算法1 --------------------------------------------------------------
	if (countMaxDiff > (faceNormalAngleList.size() / 2) && (maxDiff > 1.3))//这里暂时设为大于90°
	{
		faceNormalAngleList.clear();
		return true;
	}
	else
	{
		faceNormalAngleList.clear();
		return false;
	}

	// ----------------------- 这是修改之前的算法1 --------------------------------------------------------------
	//if(maxDiff > 2.09)//这里暂时设为大于120°
	//{
	//	faceNormalAngleList.clear();
	//	return true;
	//}
	//else
	//{
	//	faceNormalAngleList.clear();
	//	return false;
	//}


#endif 

#ifdef VERSION_2
	ArrayList faceNormalAngleList;
	
	omp_lock_t lock;
	float p1[3], p2[3];

	for (ArrayList3::iterator it = faceNormalPointList.begin(); it != faceNormalPointList.end(); it++)
	{
		ArrayList3::iterator it2;
#pragma omp single nowait 
		{
			if (it == faceNormalPointList.end() - 1)
			{
				it2 = faceNormalPointList.begin();
			}
			else
			{
				it2 = it + 1;
			}
			float currentAngle;
			point3D pp1 = *it;
			point3D pp2 = *it2;

			p1[0] = pp1.x;
			p1[1] = pp1.y;
			p1[2] = pp1.z;
			p2[0] = pp2.x;
			p2[1] = pp2.y;
			p2[2] = pp2.z;

			currentAngle = GetAngle(vertexPoint, gridPointcenter, p1);
			faceNormalAngleList.push_back(currentAngle);
		}
	}
	std::sort(faceNormalAngleList.begin(), faceNormalAngleList.end());
	//maxDiff
	float TMP = 0;
	int count = 0;

	//faceNormalAngleList：夹角的list
	for (ArrayList::iterator it = faceNormalAngleList.begin(); it != faceNormalAngleList.end(); it++)
	{
		if (it == faceNormalAngleList.end() - 1)
		{
			break;
		}
		TMP = *it;

		//如果夹角大于0.5(3.14为π)，进行计数

		//idea：排序后算出最大的maxdiff，然后TMP大于MAXDIFF来计算(这招效果不行)
		//比较好的经验值：0.45
		if (TMP > 0.392)
		{
			count++;
		}
	}

	//夹角大于0.5的数量
	if (count >= (faceNormalAngleList.size() / 2))
	{
		faceNormalAngleList.clear();
		return true;
	}
	else
	{
		faceNormalAngleList.clear();
		return false;
	}

#endif

#ifdef VERSION_3
	// -----------------------------------   第二版方法，使用非平衡策略 --------------------------------------------
	ArrayList faceNormalAngleList;

	omp_lock_t lock;
	float p1[3], p2[3];

	/*#pragma omp parallel private(p1),private(p2)
	{*/
	for (ArrayList3::iterator it = faceNormalPointList.begin(); it != faceNormalPointList.end(); it++)
	{
		ArrayList3::iterator it2;
#pragma omp single nowait 
		{
			//omp_set_lock(&lock);
			if (it == faceNormalPointList.end() - 1)
			{
				it2 = faceNormalPointList.begin();
			}
			else
			{
				it2 = it + 1;
			}
			float currentAngle;
			point3D pp1 = *it;
			point3D pp2 = *it2;

			//float p1[3],p2[3];
			p1[0] = pp1.x;
			p1[1] = pp1.y;
			p1[2] = pp1.z;
			//p2[0] = pp2.x;
			//p2[1] = pp2.y;
			//p2[2] = pp2.z;

			//currentAngle = calAngle(gridPointcenter , p1 , p2);
			currentAngle = GetAngle(vertexPoint, gridPointcenter, p1);
			faceNormalAngleList.push_back(currentAngle);
			//omp_unset_lock(&lock);
		}
	}

	std::sort(faceNormalAngleList.begin(), faceNormalAngleList.end());


	//maxDiff
	float maxDiff = 0;
	int count = 0;
	int countMaxDiff = 0;

	for (ArrayList::iterator it = faceNormalAngleList.begin(); it != faceNormalAngleList.end(); it++)
	{
		if (it == faceNormalAngleList.end() - 1)
		{
			break;
		}
		count += 1;
		ArrayList::iterator it2 = it + 1;
		float Diff = abs(*(it2)-*it);
		if (Diff > maxDiff)
		{
			maxDiff = Diff;
			countMaxDiff = count;
		}
	}
	if (countMaxDiff > (faceNormalAngleList.size() / 2) && (maxDiff > 0.18))
	{
		faceNormalAngleList.clear();
		return true;
	}
	else
	{
		faceNormalAngleList.clear();
		return false;
	}


#endif

#ifdef VERSION_4
	ArrayList projectionLengthList;

	omp_lock_t lock;
	float p1[3], p2[3];


	for (ArrayList3::iterator it = faceNormalPointList.begin(); it != faceNormalPointList.end(); it++)
	{

		float currentAngle;
		point3D pp1 = *it;

		//float p1[3],p2[3];
		p1[0] = pp1.x;
		p1[1] = pp1.y;
		p1[2] = pp1.z;

		float dist = GetEuclidDistance(gridPointcenter, p1);
		projectionLengthList.push_back(dist);

	}

	std::sort(projectionLengthList.begin(), projectionLengthList.end());

	//maxDiff
	float maxDiff = 0;
	int count = 0;
	int countMaxDiff = 0;

	for (ArrayList::iterator it = projectionLengthList.begin(); it != projectionLengthList.end(); it++)
	{
		if (it == projectionLengthList.end() - 1)
		{
			break;
		}
		count += 1;
		ArrayList::iterator it2 = it + 1;
		float Diff = abs(*(it2)-*it);
		if (Diff > maxDiff)
		{
			maxDiff = Diff;
			countMaxDiff = count;
		}
	}
	if (countMaxDiff > (projectionLengthList.size() / 2) && (maxDiff > 0.025))
	{
		projectionLengthList.clear();
		return true;
	}
	else
	{
		projectionLengthList.clear();
		return false;
	}
#endif

#ifdef VERSION_5
	ArrayList faceNormalAngleList;

	omp_lock_t lock;
	float p1[3], p2[3];

	/*#pragma omp parallel private(p1),private(p2)
	{*/
	for (ArrayList3::iterator it = faceNormalPointList.begin(); it != faceNormalPointList.end(); it++)
	{
		ArrayList3::iterator it2;
#pragma omp single nowait 
		{
			//omp_set_lock(&lock);
			if (it == faceNormalPointList.end() - 1)
			{
				it2 = faceNormalPointList.begin();
			}
			else
			{
				it2 = it + 1;
			}
			float currentAngle;
			point3D pp1 = *it;
			point3D pp2 = *it2;

			//float p1[3],p2[3];
			p1[0] = pp1.x;
			p1[1] = pp1.y;
			p1[2] = pp1.z;
			p2[0] = pp2.x;
			p2[1] = pp2.y;
			p2[2] = pp2.z;

			currentAngle = calAngle(gridPointcenter, p1, p2);
			//currentAngle = calAngle(vertexPoint , gridPointcenter , p1 );
			faceNormalAngleList.push_back(currentAngle);
			//omp_unset_lock(&lock);
		}
	}

	std::sort(faceNormalAngleList.begin(), faceNormalAngleList.end());


	//maxDiff
	float maxDiff = 0;
	int count = 0;
	int countMaxDiff = 0;

	for (ArrayList::iterator it = faceNormalAngleList.begin(); it != faceNormalAngleList.end(); it++)
	{
		if (it == faceNormalAngleList.end() - 1)
		{
			break;
		}
		count += 1;
		ArrayList::iterator it2 = it + 1;
		float Diff = abs(*(it2)-*it);
		if (Diff > maxDiff)
		{
			maxDiff = Diff;
			countMaxDiff = count;
		}
	}
	if (countMaxDiff > (faceNormalAngleList.size() / 2))
	{
		faceNormalAngleList.clear();
		return true;
	}
	else
	{
		faceNormalAngleList.clear();
		return false;
	}
#endif
}

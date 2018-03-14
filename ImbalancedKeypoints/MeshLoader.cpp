#include "MeshLoader.h"

MeshLoader::MeshLoader(QString filePath, pcl::PolygonMesh & mesh, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &meshCloud, std::vector<bool> & isKeypoints)
	: mesh(mesh), meshCloud(meshCloud), isKeypoints(isKeypoints) {
	this->meshFilePath = filePath;
}

MeshLoader::~MeshLoader() {

}

void MeshLoader::SetMeshFilePath(QString meshFilePath) {
	this->meshFilePath = meshFilePath;
}

void MeshLoader::SetCloudColor(QColor cloudColor) {
	this->cloudColor = cloudColor;
}

void MeshLoader::run() {
	LoadMesh();
}

int MeshLoader::LoadMesh() {
	QFileInfo fileInfo(meshFilePath);

	if (fileInfo.suffix() == "ply") {
		pcl::io::loadPLYFile(meshFilePath.toStdString(), mesh);
	}
	else if (fileInfo.suffix() == "obj") {
		pcl::io::loadOBJFile(meshFilePath.toStdString(), mesh);
	}

	if (!mesh.cloud.data.empty()) {
		meshCloud.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh.cloud, *meshCloud);
		for (int i = 0; i < meshCloud->points.size(); i++) {
			meshCloud->points[i].r = cloudColor.red();
			meshCloud->points[i].g = cloudColor.green();
			meshCloud->points[i].b = cloudColor.blue();
		}
		isKeypoints.clear();
	}
	else {
		return 0;
	}

	return 1;
}

#include "CloudLoader.h"

CloudLoader::CloudLoader(QString filePath, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud) 
	 : cloud(cloud) {
	this->cloudFilePath = filePath;
}

CloudLoader::~CloudLoader() {

}

void CloudLoader::SetCloudFilePath(QString cloudFilePath) {
	this->cloudFilePath = cloudFilePath;
}

void CloudLoader::SetCloudColor(QColor cloudColor) {
	this->cloudColor = cloudColor;
}

void CloudLoader::run() {
	LoadCloud();
}

int CloudLoader::LoadCloud() {
	QFileInfo fileInfo(cloudFilePath);

	if (fileInfo.suffix() == "pcd") {
		cloud.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
		pcl::io::loadPCDFile(cloudFilePath.toStdString(), *cloud);
	}

	if (cloud != NULL && !cloud->empty()) {
		for (int i = 0; i < cloud->size(); i++) {
			cloud->points[i].r = cloudColor.red();
			cloud->points[i].g = cloudColor.green();
			cloud->points[i].b = cloudColor.blue();
		}
	}
	else {
		return 0;
	}
}

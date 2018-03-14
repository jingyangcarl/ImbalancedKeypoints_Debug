#pragma once

#include <qthread.h>
#include <qfileinfo.h>
#include <qcolor.h>
#include <pcl\io\ply_io.h>
#include <pcl\io\obj_io.h>

class MeshLoader : public QThread
{
public:
	MeshLoader(QString, pcl::PolygonMesh &, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &, std::vector<bool> &);
	~MeshLoader();

	// Carl: set 
	void SetMeshFilePath(QString);
	void SetCloudColor(QColor);

protected:
	void run();

private:
	QString meshFilePath;
	QColor cloudColor;

	pcl::PolygonMesh &mesh;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &meshCloud;
	std::vector<bool> &isKeypoints;

	int LoadMesh();
};
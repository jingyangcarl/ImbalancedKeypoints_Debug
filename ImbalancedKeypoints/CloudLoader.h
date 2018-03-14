#pragma once

#include <qthread.h>
#include <qfileinfo.h>
#include <qcolor.h>
#include <pcl\io\pcd_io.h>

class CloudLoader : public QThread
{
public:
	CloudLoader(QString, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &);
	~CloudLoader();

	// Carl: set
	void SetCloudFilePath(QString);
	void SetCloudColor(QColor);

protected:
	void run();

private:
	QString cloudFilePath;
	QColor cloudColor;

	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &cloud;

	int LoadCloud();
};
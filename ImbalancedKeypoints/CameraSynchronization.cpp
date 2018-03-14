#include "ImbalancedKeypoints.h"
#include "Macro.h"

void ImbalancedKeypoints::CameraSynToQVTKWidget_1() {

#ifndef CAMERA_DEBUG
	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_1->getCameraParameters(camera);

	// Carl: set camera of QVTKWidget_1
	viewer_2->setCameraParameters(camera);
	viewer_2->updateCamera();
	viewer_3->setCameraParameters(camera);
	viewer_3->updateCamera();
#else
	pcl::visualization::Camera camera_1;
	pcl::visualization::Camera camera_2;
	viewer_1->getCameraParameters(camera_1);
	viewer_2->getCameraParameters(camera_2);

	QTextEditGrayOutput("focal_1: [" + QString::number(camera_1.focal[0]) + " " + QString::number(camera_1.focal[1]) + " " + QString::number(camera_1.focal[2]) + "] " + 
		"pos_1: [" + QString::number(camera_1.pos[0]) + " " + QString::number(camera_1.pos[1]) + " " + QString::number(camera_1.pos[2]) + "] " +
		"upvec_1: [" + QString::number(camera_1.view[0]) + " " + QString::number(camera_1.view[1]) + " " + QString::number(camera_1.view[2]) + "]");
	QTextEditGrayOutput("focal_2: [" + QString::number(camera_2.focal[0]) + " " + QString::number(camera_2.focal[1]) + " " + QString::number(camera_2.focal[2]) + "] " + 
		"pos_2: [" + QString::number(camera_2.pos[0]) + " " + QString::number(camera_2.pos[1]) + " " + QString::number(camera_2.pos[2]) + "] " +
		"upvec_2: [" + QString::number(camera_2.view[0]) + " " + QString::number(camera_2.view[1]) + " " + QString::number(camera_2.view[2]) + "]");
#endif // !CAMERA_DEBUG

	return;
}

void ImbalancedKeypoints::CameraSynToQVTKWidget_2() {

#ifndef CAMERA_DEBUG
	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_2->getCameraParameters(camera);

	// Carl: set camera of QVTKWidget_1
	viewer_1->setCameraParameters(camera);
	viewer_1->updateCamera();
	viewer_3->setCameraParameters(camera);
	viewer_3->updateCamera();
#else
	pcl::visualization::Camera camera_1;
	pcl::visualization::Camera camera_2;
	viewer_1->getCameraParameters(camera_1);
	viewer_2->getCameraParameters(camera_2);

	QTextEditGrayOutput("focal_1: [" + QString::number(camera_1.focal[0]) + " " + QString::number(camera_1.focal[1]) + " " + QString::number(camera_1.focal[2]) + "] " +
		"pos_1: [" + QString::number(camera_1.pos[0]) + " " + QString::number(camera_1.pos[1]) + " " + QString::number(camera_1.pos[2]) + "] " +
		"upvec_1: [" + QString::number(camera_1.view[0]) + " " + QString::number(camera_1.view[1]) + " " + QString::number(camera_1.view[2]) + "]");
	QTextEditGrayOutput("focal_2: [" + QString::number(camera_2.focal[0]) + " " + QString::number(camera_2.focal[1]) + " " + QString::number(camera_2.focal[2]) + "] " +
		"pos_2: [" + QString::number(camera_2.pos[0]) + " " + QString::number(camera_2.pos[1]) + " " + QString::number(camera_2.pos[2]) + "] " +
		"upvec_2: [" + QString::number(camera_2.view[0]) + " " + QString::number(camera_2.view[1]) + " " + QString::number(camera_2.view[2]) + "]");
#endif // !CAMERA_DEBUG

	return;
}

void ImbalancedKeypoints::CameraSynToQVTKWidget_3() {

#ifndef CAMERA_DEBUG
	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_3->getCameraParameters(camera);

	// Carl: set camera of QVTKWidget_1
	viewer_1->setCameraParameters(camera);
	viewer_1->updateCamera();
	viewer_2->setCameraParameters(camera);
	viewer_2->updateCamera();
#else
	pcl::visualization::Camera camera_1;
	pcl::visualization::Camera camera_2;
	viewer_1->getCameraParameters(camera_1);
	viewer_2->getCameraParameters(camera_2);

	QTextEditGrayOutput("focal_1: [" + QString::number(camera_1.focal[0]) + " " + QString::number(camera_1.focal[1]) + " " + QString::number(camera_1.focal[2]) + "] " +
		"pos_1: [" + QString::number(camera_1.pos[0]) + " " + QString::number(camera_1.pos[1]) + " " + QString::number(camera_1.pos[2]) + "] " +
		"upvec_1: [" + QString::number(camera_1.view[0]) + " " + QString::number(camera_1.view[1]) + " " + QString::number(camera_1.view[2]) + "]");
	QTextEditGrayOutput("focal_2: [" + QString::number(camera_2.focal[0]) + " " + QString::number(camera_2.focal[1]) + " " + QString::number(camera_2.focal[2]) + "] " +
		"pos_2: [" + QString::number(camera_2.pos[0]) + " " + QString::number(camera_2.pos[1]) + " " + QString::number(camera_2.pos[2]) + "] " +
		"upvec_2: [" + QString::number(camera_2.view[0]) + " " + QString::number(camera_2.view[1]) + " " + QString::number(camera_2.view[2]) + "]");
#endif // !CAMERA_DEBUG

	return;
}
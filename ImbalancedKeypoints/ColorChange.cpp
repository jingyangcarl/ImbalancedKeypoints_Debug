#include "ImbalancedKeypoints.h"

void ImbalancedKeypoints::QVTKWidget_1CloudColorChange() {
	// Carl: change the color the cloud_1
	if (!cloud_1->empty()) {
		srand(time(NULL));
		int oldR = cloud_1Color.red();
		int oldG = cloud_1Color.green();
		int oldB = cloud_1Color.blue();
		int newR = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newG = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newB = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		cloud_1Color.setRed(newR);
		cloud_1Color.setGreen(newG);
		cloud_1Color.setBlue(newB);

		for (int i = 0; i < cloud_1->points.size(); i++) {
			cloud_1->points[i].r = newR;
			cloud_1->points[i].g = newG;
			cloud_1->points[i].b = newB;
		}

		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Cloud_1 color changed from "));
		content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
		content.append(QPair<QColor, QString>(QColor("gray"), " to "));
		content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput("Cloud_1 is empty");
	}

	return;
}

void ImbalancedKeypoints::QVTKWidget_2CloudColorChange() {
	// Carl: change the color the cloud_2
	if (!cloud_2->empty()) {
		srand(time(NULL));
		int oldR = cloud_2Color.red();
		int oldG = cloud_2Color.green();
		int oldB = cloud_2Color.blue();
		int newR = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newG = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newB = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		cloud_2Color.setRed(newR);
		cloud_2Color.setGreen(newG);
		cloud_2Color.setBlue(newB);

		for (int i = 0; i < cloud_2->points.size(); i++) {
			cloud_2->points[i].r = newR;
			cloud_2->points[i].g = newG;
			cloud_2->points[i].b = newB;
		}

		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Cloud_2 color changed from "));
		content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
		content.append(QPair<QColor, QString>(QColor("gray"), " to "));
		content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput("Cloud_2 is empty");
	}

	return;
}

void ImbalancedKeypoints::QVTKWidget_3CloudColorChange() {
	// Carl: change the color the cloud_3
	if (!cloud_3->empty()) {
		srand(time(NULL));
		int oldR = cloud_3Color.red();
		int oldG = cloud_3Color.green();
		int oldB = cloud_3Color.blue();
		int newR = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newG = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newB = (int)(256 * rand() / (RAND_MAX + 1.0f)) % 256;
		cloud_3Color.setRed(newR);
		cloud_3Color.setGreen(newG);
		cloud_3Color.setBlue(newB);

		for (int i = 0; i < cloud_3->points.size(); i++) {
			cloud_3->points[i].r = newR;
			cloud_3->points[i].g = newG;
			cloud_3->points[i].b = newB;
		}

		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Cloud_3 color changed from "));
		content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
		content.append(QPair<QColor, QString>(QColor("gray"), " to "));
		content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput("Cloud_3 is empty");
	}

	return;
}

void ImbalancedKeypoints::QVTKWidget_1CloudColorSwitch() {
	// Carl: switch color
	for (int i = 0; i < cloud_1->points.size(); i++) {
		if (isAlive_1.at(i)) {
			cloud_1->points[i].r = cloud_1Color.red();
			cloud_1->points[i].g = cloud_1Color.green();
			cloud_1->points[i].b = cloud_1Color.blue();
		}
		else {
			cloud_1->points[i].r = 0;
			cloud_1->points[i].g = 0;
			cloud_1->points[i].b = 0;
		}
	}
}

void ImbalancedKeypoints::QVTKWidget_2CloudColorSwitch() {
	// Carl: switch color
	for (int i = 0; i < cloud_2->points.size(); i++) {
		if (isAlive_2.at(i)) {
			cloud_2->points[i].r = cloud_2Color.red();
			cloud_2->points[i].g = cloud_2Color.green();
			cloud_2->points[i].b = cloud_2Color.blue();
		}
		else {
			cloud_2->points[i].r = 0;
			cloud_2->points[i].g = 0;
			cloud_2->points[i].b = 0;
		}
	}
}

void ImbalancedKeypoints::QVTKWidget_3CloudColorSwitch() {
	// Carl: switch color
	for (int i = 0; i < cloud_3->points.size(); i++) {
		if (isAlive_3.at(i)) {
			cloud_3->points[i].r = cloud_3Color.red();
			cloud_3->points[i].g = cloud_3Color.green();
			cloud_3->points[i].b = cloud_3Color.blue();
		}
		else {
			cloud_3->points[i].r = 0;
			cloud_3->points[i].g = 0;
			cloud_3->points[i].b = 0;
		}
	}
}

void ImbalancedKeypoints::QVTKWidget_1MeshCloudColorChange() {
	// Carl: change the color the mesh_1Cloud
	if (!mesh_1Cloud->empty()) {
		srand(time(NULL));
		int oldR = mesh_1CloudColor.red();
		int oldG = mesh_1CloudColor.green();
		int oldB = mesh_1CloudColor.blue();
		int newR = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newG = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newB = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		mesh_1CloudColor.setRed(newR);
		mesh_1CloudColor.setGreen(newG);
		mesh_1CloudColor.setBlue(newB);

		for (int i = 0; i < mesh_1Cloud->points.size(); i++) {
			mesh_1Cloud->points[i].r = newR;
			mesh_1Cloud->points[i].g = newG;
			mesh_1Cloud->points[i].b = newB;
		}

		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Mesh_1Cloud color changed from "));
		content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
		content.append(QPair<QColor, QString>(QColor("gray"), " to "));
		content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput("Mesh_1Cloud is empty");
	}

	return;
}

void ImbalancedKeypoints::QVTKWidget_2MeshCloudColorChange() {
	// Carl: change the color the mesh_2Cloud
	if (!mesh_2Cloud->empty()) {
		srand(time(NULL));
		int oldR = mesh_2CloudColor.red();
		int oldG = mesh_2CloudColor.green();
		int oldB = mesh_2CloudColor.blue();
		int newR = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newG = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newB = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		mesh_2CloudColor.setRed(newR);
		mesh_2CloudColor.setGreen(newG);
		mesh_2CloudColor.setBlue(newB);

		for (int i = 0; i < mesh_2Cloud->points.size(); i++) {
			mesh_2Cloud->points[i].r = newR;
			mesh_2Cloud->points[i].g = newG;
			mesh_2Cloud->points[i].b = newB;
		}

		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Mesh_2Cloud color changed from "));
		content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
		content.append(QPair<QColor, QString>(QColor("gray"), " to "));
		content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput("Mesh_2Cloud is empty");
	}

	return;
}

void ImbalancedKeypoints::QVTKWidget_3MeshCloudColorChange() {
	// Carl: change the color the mesh_3Cloud
	if (!mesh_3Cloud->empty()) {
		srand(time(NULL));
		int oldR = mesh_3CloudColor.red();
		int oldG = mesh_3CloudColor.green();
		int oldB = mesh_3CloudColor.blue();
		int newR = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newG = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		int newB = (int)(512 * rand() / (RAND_MAX + 1.0f)) % 256;
		mesh_3CloudColor.setRed(newR);
		mesh_3CloudColor.setGreen(newG);
		mesh_3CloudColor.setBlue(newB);

		for (int i = 0; i < mesh_3Cloud->points.size(); i++) {
			mesh_3Cloud->points[i].r = newR;
			mesh_3Cloud->points[i].g = newG;
			mesh_3Cloud->points[i].b = newB;
		}

		QVector<QPair<QColor, QString>> content;
		content.append(QPair<QColor, QString>(QColor("gray"), "Mesh_3Cloud color changed from "));
		content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
		content.append(QPair<QColor, QString>(QColor("gray"), " to "));
		content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
		QTextEditColoredOutput(content);
	}
	else {
		QTextEditRedOutput("Mesh_3Cloud is empty");
	}

	return;
}

void ImbalancedKeypoints::QVTKWidget_1MeshKeypointColorChange() {
	// Carl: change the color of keypoints in mesh_1
	if (!mesh_1Cloud->empty()) {
		if (!isKeypoints_1Empty()) {
			srand(time(NULL));
			int oldR = mesh_1KeypointColor.red();
			int oldG = mesh_1KeypointColor.green();
			int oldB = mesh_1KeypointColor.blue();
			int newR = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newG = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newB = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			mesh_1KeypointColor.setRed(newR);
			mesh_1KeypointColor.setGreen(newG);
			mesh_1KeypointColor.setBlue(newB);

			for (int i = 0; i < mesh_1Cloud->points.size(); i++) {
				if (isKeypoints_1.at(i)) {
					mesh_1Cloud->points[i].r = newR;
					mesh_1Cloud->points[i].g = newG;
					mesh_1Cloud->points[i].b = newB;
				}
			}

			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Keypoints_1 color changed from "));
			content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
			content.append(QPair<QColor, QString>(QColor("gray"), " to "));
			content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
			QTextEditColoredOutput(content);
		}
		else
			QTextEditRedOutput("Keypoints_1 hasn't detected");
	}
	else {
		QTextEditRedOutput("Mesh_1Cloud is empty");
	}
}

void ImbalancedKeypoints::QVTKWidget_2MeshKeypointColorChange() {
	// Carl: change the color of keypoints in mesh_2
	if (!mesh_2Cloud->empty()) {
		if (!isKeypoints_2Empty()) {
			srand(time(NULL));
			int oldR = mesh_2KeypointColor.red();
			int oldG = mesh_2KeypointColor.green();
			int oldB = mesh_2KeypointColor.blue();
			int newR = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newG = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newB = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			mesh_2KeypointColor.setRed(newR);
			mesh_2KeypointColor.setGreen(newG);
			mesh_2KeypointColor.setBlue(newB);

			for (int i = 0; i < mesh_2Cloud->points.size(); i++) {
				if (isKeypoints_2.at(i)) {
					mesh_2Cloud->points[i].r = newR;
					mesh_2Cloud->points[i].g = newG;
					mesh_2Cloud->points[i].b = newB;
				}
			}

			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Keypoints_2 color changed from "));
			content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
			content.append(QPair<QColor, QString>(QColor("gray"), " to "));
			content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
			QTextEditColoredOutput(content);
		}
		else
			QTextEditRedOutput("Keypoints_2 hasn't detected");
	}
	else {
		QTextEditRedOutput("Mesh_2Cloud is empty");
	}
}

void ImbalancedKeypoints::QVTKWidget_3MeshKeypointColorChange() {
	// Carl: change the color of keypoints in mesh_3
	if (!mesh_3Cloud->empty()) {
		if (!isKeypoints_3Empty()) {
			srand(time(NULL));
			int oldR = mesh_3KeypointColor.red();
			int oldG = mesh_3KeypointColor.green();
			int oldB = mesh_3KeypointColor.blue();
			int newR = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newG = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newB = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			mesh_3KeypointColor.setRed(newR);
			mesh_3KeypointColor.setGreen(newG);
			mesh_3KeypointColor.setBlue(newB);

			for (int i = 0; i < mesh_3Cloud->points.size(); i++) {
				if (isKeypoints_3.at(i)) {
					mesh_3Cloud->points[i].r = newR;
					mesh_3Cloud->points[i].g = newG;
					mesh_3Cloud->points[i].b = newB;
				}
			}

			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Keypoints_3 color changed from "));
			content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
			content.append(QPair<QColor, QString>(QColor("gray"), " to "));
			content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
			QTextEditColoredOutput(content);
		}
		else
			QTextEditRedOutput("Keypoints_3 hasn't detected");
	}
	else {
		QTextEditRedOutput("Mesh_3Cloud is empty");
	}
}

void ImbalancedKeypoints::QVTKWidget_1MeshMatchedPointColorChange() {
	// Carl: change the color of matched point in mesh_1
	if (!mesh_1Cloud->empty()) {
		if (!isMatched_1.empty()) {
			srand(time(NULL));
			int oldR = mesh_1KeypointColor.red();
			int oldG = mesh_1KeypointColor.green();
			int oldB = mesh_1KeypointColor.blue();
			int newR = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newG = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newB = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			mesh_1KeypointColor.setRed(newR);
			mesh_1KeypointColor.setGreen(newG);
			mesh_1KeypointColor.setBlue(newB);

			for (int i = 0; i < mesh_1Cloud->points.size(); i++) {
				if (isMatched_1.at(i)) {
					mesh_1Cloud->points[i].r = newR;
					mesh_1Cloud->points[i].g = newG;
					mesh_1Cloud->points[i].b = newB;
				}
			}

			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Matched point color changed from "));
			content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
			content.append(QPair<QColor, QString>(QColor("gray"), " to "));
			content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
			QTextEditColoredOutput(content);
		}
		else
			QTextEditRedOutput("Point 1 hasn't be matched");
	}
	else {
		QTextEditRedOutput("Mesh_1Cloud is empty");
	}
}

void ImbalancedKeypoints::QVTKWidget_2MeshMatchedPointColorChange() {
	// Carl: change the color of matched point in mesh_2
	if (!mesh_2Cloud->empty()) {
		if (!isMatched_2.empty()) {
			srand(time(NULL));
			int oldR = mesh_2KeypointColor.red();
			int oldG = mesh_2KeypointColor.green();
			int oldB = mesh_2KeypointColor.blue();
			int newR = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newG = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newB = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			mesh_2KeypointColor.setRed(newR);
			mesh_2KeypointColor.setGreen(newG);
			mesh_2KeypointColor.setBlue(newB);

			for (int i = 0; i < mesh_2Cloud->points.size(); i++) {
				if (isMatched_2.at(i)) {
					mesh_2Cloud->points[i].r = newR;
					mesh_2Cloud->points[i].g = newG;
					mesh_2Cloud->points[i].b = newB;
				}
			}

			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Matched point color changed from "));
			content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
			content.append(QPair<QColor, QString>(QColor("gray"), " to "));
			content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
			QTextEditColoredOutput(content);
		}
		else
			QTextEditRedOutput("Point 2 hasn't be matched");
	}
	else {
		QTextEditRedOutput("Mesh_2Cloud is empty");
	}
}

void ImbalancedKeypoints::QVTKWidget_3MeshMatchedPointColorChange() {
	// Carl: change the color of matched point in mesh_3
	if (!mesh_3Cloud->empty()) {
		if (!isMatched_3.empty()) {
			srand(time(NULL));
			int oldR = mesh_3KeypointColor.red();
			int oldG = mesh_3KeypointColor.green();
			int oldB = mesh_3KeypointColor.blue();
			int newR = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newG = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			int newB = (int)(1024 * rand() / (RAND_MAX + 1.0f)) % 256;
			mesh_3KeypointColor.setRed(newR);
			mesh_3KeypointColor.setGreen(newG);
			mesh_3KeypointColor.setBlue(newB);

			for (int i = 0; i < mesh_3Cloud->points.size(); i++) {
				if (isMatched_3.at(i)) {
					mesh_3Cloud->points[i].r = newR;
					mesh_3Cloud->points[i].g = newG;
					mesh_3Cloud->points[i].b = newB;
				}
			}

			QVector<QPair<QColor, QString>> content;
			content.append(QPair<QColor, QString>(QColor("gray"), "Matched point color changed from "));
			content.append(QPair<QColor, QString>(QColor(oldR, oldG, oldB), "[" + QString::number(oldR) + ", " + QString::number(oldG) + ", " + QString::number(oldB) + "]"));
			content.append(QPair<QColor, QString>(QColor("gray"), " to "));
			content.append(QPair<QColor, QString>(QColor(newR, newG, newB), "[" + QString::number(newR) + ", " + QString::number(newG) + ", " + QString::number(newB) + "]"));
			QTextEditColoredOutput(content);
		}
		else
			QTextEditRedOutput("Point 3 hasn't be matched");
	}
	else {
		QTextEditRedOutput("Mesh_3Cloud is empty");
	}
}

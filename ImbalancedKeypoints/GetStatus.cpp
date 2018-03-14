#include "ImbalancedKeypoints.h"

QString ImbalancedKeypoints::getQVTKWidget_1CloudStatus() {
	QString object = "View 1 cloud:\t";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_1CloudEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_1CloudConnected()) + "]\t";
	return object + loadStatus + connectStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_2CloudStatus() {
	QString object = "View 2 cloud:\t";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_2CloudEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_2CloudConnected()) + "]\t";
	return object + loadStatus + connectStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_3CloudStatus() {
	QString object = "View 3 cloud:\t";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_3CloudEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_3CloudConnected()) + "]\t";
	return object + loadStatus + connectStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_1MeshStatus() {
	QString object = "View 1 mesh: ";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_1MeshEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_1MeshConnected()) + "]\t";
	QString detectStatus = "[Detect status: " + QString::number(!isKeypoints_1Empty()) + "]\t";
	QString pointStatus = "[Total points: " + QString::number(mesh_1.cloud.height*mesh_1.cloud.width) + "]\t";
	QString faceStatus = "[Total faces: " + QString::number(mesh_1.polygons.size()) + "]\t";
	return object + loadStatus + connectStatus + detectStatus + pointStatus + faceStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_2MeshStatus() {
	QString object = "View 2 mesh: ";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_2MeshEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_2MeshConnected()) + "]\t";
	QString detectStatus = "[Detect status: " + QString::number(!isKeypoints_2Empty()) + "]\t";
	QString pointStatus = "[Total points: " + QString::number(mesh_2.cloud.height*mesh_2.cloud.width) + "]\t";
	QString faceStatus = "[Total faces: " + QString::number(mesh_2.polygons.size()) + "]\t";
	return object + loadStatus + connectStatus + detectStatus + pointStatus + faceStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_3MeshStatus() {
	QString object = "View 3 mesh: ";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_3MeshEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_3MeshConnected()) + "]\t";
	QString detectStatus = "[Detect status: " + QString::number(!isKeypoints_3Empty()) + "]\t";
	QString pointStatus = "[Total points: " + QString::number(mesh_3.cloud.height*mesh_3.cloud.width) + "]\t";
	QString faceStatus = "[Total faces: " + QString::number(mesh_3.polygons.size()) + "]\t";
	return object + loadStatus + connectStatus + detectStatus + pointStatus + faceStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_1MeshCloudStatus() {
	QString object = "View 1 meshcloud:\t";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_1MeshCloudEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_1MeshCloudConnected()) + "]\t";
	QString detectStatus = "[Detect status: " + QString::number(!isKeypoints_1Empty()) + "]\t";
	return object + loadStatus + connectStatus + detectStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_2MeshCloudStatus() {
	QString object = "View 2 meshcloud:\t";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_2MeshCloudEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_2MeshCloudConnected()) + "]\t";
	QString detectStatus = "[Detect status: " + QString::number(!isKeypoints_2Empty()) + "]\t";
	return object + loadStatus + connectStatus + detectStatus;
}

QString ImbalancedKeypoints::getQVTKWidget_3MeshCloudStatus() {
	QString object = "View 3 meshcloud:\t";
	QString loadStatus = "[Load status: " + QString::number(!isQVTKWidget_3MeshCloudEmpty()) + "]\t";
	QString connectStatus = "[Connection status: " + QString::number(isQVTKWidget_3MeshCloudConnected()) + "]\t";
	QString detectStatus = "[Detect status: " + QString::number(!isKeypoints_3Empty()) + "]\t";
	return object + loadStatus + connectStatus + detectStatus;
}

QString ImbalancedKeypoints::getKeypoints_1Status() {

	QString object = "Mesh 1 KeyPoints:\t";

	if (!isKeypoints_1Empty()) {
		double totalPoints = isKeypoints_1.size();
		double keyPoints = std::count(isKeypoints_1.begin(), isKeypoints_1.end(), true);
		double ratio = keyPoints / totalPoints * 100;
		QString totalPointsStr = "[Total Points: " + QString::number(totalPoints) + "]\t";
		QString keyPointsStr = "[Key Points: " + QString::number(keyPoints) + "]\t";
		QString ratioStr = "[Key Ratio: " + QString::number(ratio) + "%]\t";
		return object + totalPointsStr + keyPointsStr + ratioStr;
	}
	else
		return object + "[No Status]";
}

QString ImbalancedKeypoints::getKeypoints_2Status() {

	QString object = "Mesh 2 KeyPoints:\t";

	if (!isKeypoints_2Empty()) {
		double totalPoints = isKeypoints_2.size();
		double keyPoints = std::count(isKeypoints_2.begin(), isKeypoints_2.end(), true);
		double ratio = keyPoints / totalPoints * 100;
		QString totalPointsStr = "[Total Points: " + QString::number(totalPoints) + "]\t";
		QString keyPointsStr = "[Key Points: " + QString::number(keyPoints) + "]\t";
		QString ratioStr = "[Key Ratio: " + QString::number(ratio) + "%]\t";
		return object + totalPointsStr + keyPointsStr + ratioStr;
	}
	else
		return object + "[No Status]";
}

QString ImbalancedKeypoints::getKeypoints_3Status() {

	QString object = "Mesh 3 KeyPoints:\t";

	if (!isKeypoints_3Empty()) {
		double totalPoints = isKeypoints_3.size();
		double keyPoints = std::count(isKeypoints_3.begin(), isKeypoints_3.end(), true);
		double ratio = keyPoints / totalPoints * 100;
		QString totalPointsStr = "[Total Points: " + QString::number(totalPoints) + "]\t";
		QString keyPointsStr = "[Key Points: " + QString::number(keyPoints) + "]\t";
		QString ratioStr = "[Key Ratio: " + QString::number(ratio) + "%]\t";
		return object + totalPointsStr + keyPointsStr + ratioStr;
	}
	else
		return object + "[No Status]";
}

QString ImbalancedKeypoints::getPointMatched_1Status() {

	QString object = "Mesh 1 Point Matching:\t";

	if (!isMatched_1.empty()) {
		double totalPoints = isMatched_1.size();
		double matchedPoints = std::count(isMatched_1.begin(), isMatched_1.end(), true);
		double ratio = matchedPoints / totalPoints * 100;
		QString totalPointsStr = "[Total Points: " + QString::number(totalPoints) + "]\t";
		QString matchedPointsStr = "[Matched Points: " + QString::number(matchedPoints) + "]\t";
		QString ratioStr = "[Matching Ratio: " + QString::number(ratio) + "%]\t";
		return object + totalPointsStr + matchedPointsStr + ratioStr;
	}
	else
		return object + "[No Status]";
}

QString ImbalancedKeypoints::getPointMatched_2Status() {

	QString object = "Mesh 2 Point Matching:\t";

	if (!isMatched_2.empty()) {
		double totalPoints = isMatched_2.size();
		double matchedPoints = std::count(isMatched_2.begin(), isMatched_2.end(), true);
		double ratio = matchedPoints / totalPoints * 100;
		QString totalPointsStr = "[Total Points: " + QString::number(totalPoints) + "]\t";
		QString matchedPointsStr = "[Matched Points: " + QString::number(matchedPoints) + "]\t";
		QString ratioStr = "[Matching Ratio: " + QString::number(ratio) + "%]\t";
		return object + totalPointsStr + matchedPointsStr + ratioStr;
	}
	else
		return object + "[No Status]";
}

QString ImbalancedKeypoints::getPointMatched_3Status() {

	QString object = "Mesh 3 Point Matching:\t";

	if (!isMatched_3.empty()) {
		double totalPoints = isMatched_3.size();
		double matchedPoints = std::count(isMatched_3.begin(), isMatched_3.end(), true);
		double ratio = matchedPoints / totalPoints * 100;
		QString totalPointsStr = "[Total Points: " + QString::number(totalPoints) + "]\t";
		QString matchedPointsStr = "[Matched Points: " + QString::number(matchedPoints) + "]\t";
		QString ratioStr = "[Matching Ratio: " + QString::number(ratio) + "%]\t";
		return object + totalPointsStr + matchedPointsStr + ratioStr;
	}
	else
		return object + "[No Status]";
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getProcesssorNumber() {

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("grey"), "Processor Number:\t"));
	content.append(QPair<QColor, QString>(QColor("green"), QString::number(sysInfo.dwNumberOfProcessors) + " cores"));

	return content;
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getProcesssorType() {

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("grey"), "Processor Type:\t"));
	content.append(QPair<QColor, QString>(QColor("green"), QString::number(sysInfo.dwProcessorType)));

	return content;
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getProcesssorLevel() {

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("grey"), "Processor Level:\t"));
	content.append(QPair<QColor, QString>(QColor("green"), QString::number(sysInfo.wProcessorLevel) + " level"));

	return content;
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getProcesssorArchitecture() {

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("grey"), "Processor Architecture:\t"));
	content.append(QPair<QColor, QString>(QColor("green"), QString::number(sysInfo.wProcessorArchitecture)));

	return content;
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getProcesssorCurrentUsage() {

	FILETIME ftime, fsys, fuser;
	ULARGE_INTEGER now, sys, user;
	double percent;

	GetSystemTimeAsFileTime(&ftime);
	memcpy(&now, &ftime, sizeof(FILETIME));

	GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
	memcpy(&sys, &fsys, sizeof(FILETIME));
	memcpy(&user, &fuser, sizeof(FILETIME));
	percent = (sys.QuadPart - lastSysCPU.QuadPart) +
		(user.QuadPart - lastUserCPU.QuadPart);
	percent /= (now.QuadPart - lastCPU.QuadPart);
	percent /= numProcessors;
	lastCPU = now;
	lastUserCPU = user;
	lastSysCPU = sys;

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("grey"), "Processor Usage:\t"));
	content.append(QPair<QColor, QString>(QColor("green"), QString::number(percent * 100) + " %"));

	return content;
}

double ImbalancedKeypoints::getProcesssorCurrentUsageDouble() {
	FILETIME ftime, fsys, fuser;
	ULARGE_INTEGER now, sys, user;
	double percent;

	GetSystemTimeAsFileTime(&ftime);
	memcpy(&now, &ftime, sizeof(FILETIME));

	GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
	memcpy(&sys, &fsys, sizeof(FILETIME));
	memcpy(&user, &fuser, sizeof(FILETIME));
	percent = (sys.QuadPart - lastSysCPU.QuadPart) +
		(user.QuadPart - lastUserCPU.QuadPart);
	percent /= (now.QuadPart - lastCPU.QuadPart);
	percent /= numProcessors;
	lastCPU = now;
	lastUserCPU = user;
	lastSysCPU = sys;

	return percent * 100;
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getQVTKWidget_1ColorStatus() {

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("green"), "Color of 1:\t"));
	content.append(QPair<QColor, QString>(cloud_1Color, "[Cloud: " + QString::number(cloud_1Color.red()) + ", " + QString::number(cloud_1Color.green()) + ", " + QString::number(cloud_1Color.blue()) + "]\t"));
	content.append(QPair<QColor, QString>(mesh_1CloudColor, "[MeshCloud: " + QString::number(mesh_1CloudColor.red()) + ", " + QString::number(mesh_1CloudColor.green()) + ", " + QString::number(mesh_1CloudColor.blue()) + "]\t"));
	content.append(QPair<QColor, QString>(mesh_1KeypointColor, "[Meshkp/Meshmp: " + QString::number(mesh_1KeypointColor.red()) + ", " + QString::number(mesh_1KeypointColor.green()) + ", " + QString::number(mesh_1KeypointColor.blue()) + "]"));

	return content;
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getQVTKWidget_2ColorStatus() {

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("green"), "Color of 2:\t"));
	content.append(QPair<QColor, QString>(cloud_2Color, "[Cloud: " + QString::number(cloud_2Color.red()) + ", " + QString::number(cloud_2Color.green()) + ", " + QString::number(cloud_2Color.blue()) + "]\t"));
	content.append(QPair<QColor, QString>(mesh_2CloudColor, "[MeshCloud: " + QString::number(mesh_2CloudColor.red()) + ", " + QString::number(mesh_2CloudColor.green()) + ", " + QString::number(mesh_2CloudColor.blue()) + "]\t"));
	content.append(QPair<QColor, QString>(mesh_2KeypointColor, "[Meshkp/Meshmp: " + QString::number(mesh_2KeypointColor.red()) + ", " + QString::number(mesh_2KeypointColor.green()) + ", " + QString::number(mesh_2KeypointColor.blue()) + "]"));

	return content;
}

QVector<QPair<QColor, QString>> ImbalancedKeypoints::getQVTKWidget_3ColorStatus() {

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("green"), "Color of 3:\t"));
	content.append(QPair<QColor, QString>(cloud_3Color, "[Cloud: " + QString::number(cloud_3Color.red()) + ", " + QString::number(cloud_3Color.green()) + ", " + QString::number(cloud_3Color.blue()) + "]\t"));
	content.append(QPair<QColor, QString>(mesh_3CloudColor, "[Meshkp/Meshmp: " + QString::number(mesh_3CloudColor.red()) + ", " + QString::number(mesh_3CloudColor.green()) + ", " + QString::number(mesh_3CloudColor.blue()) + "]\t"));

	return content;
}

bool ImbalancedKeypoints::isQVTKWidget_1CloudEmpty() {
	return cloud_1->empty();
}

bool ImbalancedKeypoints::isQVTKWidget_2CloudEmpty() {
	return cloud_2->empty();
}

bool ImbalancedKeypoints::isQVTKWidget_3CloudEmpty() {
	return cloud_3->empty();
}

bool ImbalancedKeypoints::isQVTKWidget_1MeshEmpty() {
	return mesh_1.cloud.data.empty();
}

bool ImbalancedKeypoints::isQVTKWidget_2MeshEmpty() {
	return mesh_2.cloud.data.empty();
}

bool ImbalancedKeypoints::isQVTKWidget_3MeshEmpty() {
	return mesh_3.cloud.data.empty();
}

bool ImbalancedKeypoints::isQVTKWidget_1MeshCloudEmpty() {
	return mesh_1Cloud->empty();
}

bool ImbalancedKeypoints::isQVTKWidget_2MeshCloudEmpty() {
	return mesh_2Cloud->empty();
}

bool ImbalancedKeypoints::isQVTKWidget_3MeshCloudEmpty() {
	return mesh_3Cloud->empty();
}

bool ImbalancedKeypoints::isKeypoints_1Empty() {
	return isKeypoints_1.empty();
}

bool ImbalancedKeypoints::isKeypoints_2Empty() {
	return isKeypoints_2.empty();
}

bool ImbalancedKeypoints::isKeypoints_3Empty() {
	return isKeypoints_3.empty();
}

bool ImbalancedKeypoints::isQVTKWidget_1CloudConnected() {
	return qVTKWidget_1CloudConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_2CloudConnected() {
	return qVTKWidget_2CloudConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_3CloudConnected() {
	return qVTKWidget_3CloudConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_1MeshConnected() {
	return qVTKWidget_1MeshConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_2MeshConnected() {
	return qVTKWidget_2MeshConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_3MeshConnected() {
	return qVTKWidget_3MeshConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_1MeshCloudConnected() {
	return qVTKWidget_1MeshCloudConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_2MeshCloudConnected() {
	return qVTKWidget_2MeshCloudConnection;
}

bool ImbalancedKeypoints::isQVTKWidget_3MeshCloudConnected() {
	return qVTKWidget_3MeshCloudConnection;
}

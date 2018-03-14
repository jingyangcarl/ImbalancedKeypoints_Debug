#include "InstructionProcessor.h"
#include "ImbDetector.h"
#include "MeshSubdivisor.h"

void InstructionProcessor::InstructionCategorySubdivide() {

	if (instruction == "subdivide") {

		MeshSubdivisor meshSubdivisor;

		// Carl: subdivide mesh_1
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivision();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_2
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivision();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_3
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivision();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivision();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivision();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivision();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane2") {
		MeshSubdivisor meshSubdivisor;

		// Carl: subdivide mesh_1 and fit mesh
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MiddlePointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_2 and fit mesh
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MiddlePointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_3 and fit mesh
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MiddlePointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane2 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MiddlePointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane2 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MiddlePointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane2 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MiddlePointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane3 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.BottomPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane3 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.BottomPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane3 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.BottomPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane5 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.NeighborPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane5 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.NeighborPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane5 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.NeighborPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane6 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.AllPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane6 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.AllPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self plane6 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.AllPointsFittingPlaneGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self weight2 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.NeighborWeightedPointGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self weight2 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.NeighborWeightedPointGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self weight2 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.NeighborWeightedPointGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self weight4 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.NeighborWeightedFaceGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self weight4 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.NeighborWeightedFaceGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self weight4 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.NeighborWeightedFaceGuiding();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self kpw 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		// Carl: keypoint detection
		ImbDetector imbDetector;

		// Carl: ImbDetector load data
		if (imbDetector.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			// Carl: keypoint detection;
			if (isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			}/// Carl: keypoint detection;
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				MeshSubdivisor meshSubdivisor;
				// Carl: MeshSubdivisor load data
				if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
					meshSubdivisor.NeighborWeightedGuiding(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					// Carl: write mesh
					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}/// Carl: MeshSubdivisor load data
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}/// Carl: keypoint detection;
		}/// Carl: ImbDetector load data
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self kpw 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		// Carl: keypoint detection
		ImbDetector imbDetector;

		// Carl: ImbDetector load data
		if (imbDetector.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			// Carl: keypoint detection;
			if (isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			}/// Carl: keypoint detection;
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				MeshSubdivisor meshSubdivisor;
				// Carl: MeshSubdivisor load data
				if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
					meshSubdivisor.NeighborWeightedGuiding(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					// Carl: write mesh
					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}/// Carl: MeshSubdivisor load data
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}/// Carl: keypoint detection;
		}/// Carl: ImbDetector load data
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide self kpw 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		// Carl: keypoint detection
		ImbDetector imbDetector;

		// Carl: ImbDetector load data
		if (imbDetector.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			// Carl: keypoint detection;
			if (isKeypoints.empty()) {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			}/// Carl: keypoint detection;
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				MeshSubdivisor meshSubdivisor;
				// Carl: MeshSubdivisor load data
				if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
					meshSubdivisor.NeighborWeightedGuiding(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					// Carl: write mesh
					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}/// Carl: MeshSubdivisor load data
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}/// Carl: keypoint detection;
		}/// Carl: ImbDetector load data
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide keypoint") {

		ImbDetector imbDetector;
		MeshSubdivisor meshSubdivisor;

		// Carl: mesh 1
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));
		if (imbDetector.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			// Carl: keypoint detection
			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (isKeypoints.empty())
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
					meshSubdivisor.MeshSubdivision(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		// Carl: mesh 2
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		// Carl: keypoint detection
		if (imbDetector.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (isKeypoints.empty())
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
					meshSubdivisor.MeshSubdivision(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));

		// Carl: mesh 3
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		// Carl: keypoint detection
		if (imbDetector.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (isKeypoints.empty())
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
					meshSubdivisor.MeshSubdivision(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide keypoint 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		// Carl: keypoint detection
		ImbDetector imbDetector;
		if (imbDetector.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (isKeypoints.empty())
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				MeshSubdivisor meshSubdivisor;
				if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
					meshSubdivisor.MeshSubdivision(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide keypoint 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		// Carl: keypoint detection
		ImbDetector imbDetector;
		if (imbDetector.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (isKeypoints.empty())
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				MeshSubdivisor meshSubdivisor;
				if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
					meshSubdivisor.MeshSubdivision(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide keypoint 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		// Carl: keypoint detection
		ImbDetector imbDetector;
		if (imbDetector.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_SUCCESS));

			std::vector<bool> isKeypoints = imbDetector.ImbDetection();
			if (isKeypoints.empty())
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_FAILED));
			else {
				returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_DETECT_SUCCESS));

				// Carl: subdividsion
				MeshSubdivisor meshSubdivisor;
				if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

					meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
					meshSubdivisor.MeshSubdivision(isKeypoints);
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

					QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
				}
				else
					returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
			}
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::DETECT, ReturnMsg::IMB_DETECTOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool catmull") {

		MeshSubdivisor meshSubdivisor;

		// Carl: subdivide mesh_1
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivisionToolCatmull();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_2
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivisionToolCatmull();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_3
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivisionToolCatmull();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool catmull 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivisionToolCatmull();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool catmull 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivisionToolCatmull();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool catmull 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivisionToolCatmull();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool butterfly") {

		MeshSubdivisor meshSubdivisor;

		// Carl: subdivide mesh_1
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivisionToolButterfly();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_2
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivisionToolButterfly();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_3
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivisionToolButterfly();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool butterfly 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivisionToolButterfly();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool butterfly 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivisionToolButterfly();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool butterfly 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivisionToolButterfly();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool loop") {

		MeshSubdivisor meshSubdivisor;

		// Carl: subdivide mesh_1
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivisionToolLoop();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_2
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivisionToolLoop();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_3
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivisionToolLoop();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool loop 1") {

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshSubdivisionToolLoop();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool loop 2") {

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshSubdivisionToolLoop();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide tool loop 3") {

		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshSubdivisionToolLoop();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide idling") {

		MeshSubdivisor meshSubdivisor;

		// Carl: subdivide mesh_1 in a idling way
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshIdlingTraverse();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_2 in a idling way
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshIdlingTraverse();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));

		// Carl: subdivide mesh_3 in a idling way
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshIdlingTraverse();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide idling 1") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_1_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_1.ply");
			meshSubdivisor.MeshIdlingTraverse();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_1_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide idling 2") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_2_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_2.ply");
			meshSubdivisor.MeshIdlingTraverse();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_2_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else if (instruction == "subdivide idling 3") {
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH));

		MeshSubdivisor meshSubdivisor;
		if (meshSubdivisor.LoadMeshFile(mesh_3_path.toStdString())) {
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_SUCCESS));

			// Carl: subdividsion
			meshSubdivisor.SetOutputoMeshPath("./oMesh_3.ply");
			meshSubdivisor.MeshIdlingTraverse();
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_SUBDIVISION_SUCCESS));

			// Carl: write mesh
			QString filePath = QString::fromStdString(meshSubdivisor.OutputoMesh());
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::Q_VTK_WIDGET_3_MESH_USERDEFINE));
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::USERDEFINE, filePath));
		}
		else
			returnMsgList.append(QPair<QString, QString>(ReturnMsg::SUBDIVIDE, ReturnMsg::MESH_SUBDIVISOR_LOAD_FAILED));
	}
	else
		returnMsgList.append(QPair<QString, QString>(ReturnMsg::UNKNOWN, instruction));

}

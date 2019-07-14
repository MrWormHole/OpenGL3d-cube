#include "OBJModel.h"

OBJModel::OBJModel(const string& fileName)
{
	printf("Object model started loading %s...\n", fileName.c_str());
	vector<OBJIndex> OBJIndices;
	vector<vec3> temp_vertices;
	vector<vec2> temp_uvs;
	vector<vec3> temp_normals;

	this->fileName = fileName;
	FILE* file = fopen(fileName.c_str(), "r");

	if (file == NULL) {
		printf("Error occured while loading\n");
	}

	while (true) {
		char lineHeader[128];
		
		int res = fscanf(file, "%s", lineHeader);

		if (res == EOF) {
			break;
		}

		if (strcmp(lineHeader, "v") == 0) {
			vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			hasUVs = true;
			vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			hasNormals = true;
			vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			OBJIndex objIndex[3];
			if (hasUVs && !hasNormals) {
				int matches = fscanf(file, "%d/%d %d/%d %d/%d\n", 
											&objIndex[0].vertexIndex, &objIndex[0].uvIndex,
											&objIndex[1].vertexIndex, &objIndex[1].uvIndex,
											&objIndex[2].vertexIndex, &objIndex[2].uvIndex);
				if (matches != 6) {
					printf("Object reading has failed.Try exporting with other options\n");
					fclose(file);
					break;
				}
				for (int i = 0; i < 3; i++) {
					objIndex[i].vertexIndex--;
					objIndex[i].uvIndex--;
				}
				for (int i = 0; i < 3; i++) {
					OBJIndices.push_back(objIndex[i]);
				}
			}
			else if (!hasUVs && hasNormals) {
				int matches = fscanf(file, "%d//%d %d//%d %d//%d\n",
					&objIndex[0].vertexIndex, &objIndex[0].normalIndex,
					&objIndex[1].vertexIndex, &objIndex[1].normalIndex,
					&objIndex[2].vertexIndex, &objIndex[2].normalIndex);
				if (matches != 6) {
					printf("Object reading has failed. Try exporting with other options\n");
					fclose(file);
					break;
				}
				for (int i = 0; i < 3; i++) {
					objIndex[i].vertexIndex--;
					objIndex[i].normalIndex--;
				}
				for (int i = 0; i < 3; i++) {
					OBJIndices.push_back(objIndex[i]);
				}
			}
			else if (!hasUVs && !hasNormals) {
				int matches = fscanf(file, "%d %d %d\n",
					&objIndex[0].vertexIndex,
					&objIndex[1].vertexIndex,
					&objIndex[2].vertexIndex);
				if (matches != 3) {
					printf("Object reading has failed. Try exporting with other options\n");
					fclose(file);
					break;
				}
				for (int i = 0; i < 3; i--) {
					objIndex[i].vertexIndex--;
				}
				for (int i = 0; i < 3; i++) {
					OBJIndices.push_back(objIndex[i]);
				}
			}
			else if (hasUVs && hasNormals) {
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", 
					&objIndex[0].vertexIndex, &objIndex[0].uvIndex, &objIndex[0].normalIndex,
					&objIndex[1].vertexIndex, &objIndex[1].uvIndex, &objIndex[1].normalIndex,
					&objIndex[2].vertexIndex, &objIndex[2].uvIndex, &objIndex[2].normalIndex);
				if (matches != 9) {
					printf("Object reading has failed. Try exporting with other options\n");
					fclose(file);
					break;
				}
				for (int i = 0; i < 3; i++) {
					objIndex[i].vertexIndex--;
					objIndex[i].uvIndex--;
					objIndex[i].normalIndex--;
				}
				for (int i = 0; i < 3; i++) {
					OBJIndices.push_back(objIndex[i]);
				}
			}
		}
		else {
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
		
	}

	for (int i = 0; i < OBJIndices.size(); i++) {
		unsigned int vertexIndex = OBJIndices[i].vertexIndex;
		unsigned int uvIndex = 0;
		unsigned int normalIndex = 0;
		if (hasUVs) {
			uvIndex = OBJIndices[i].uvIndex;
		}
		if (hasNormals) {
			normalIndex = OBJIndices[i].normalIndex;
		}

		vec3 vertex = temp_vertices[vertexIndex];
		vec2 uv = vec2();
		vec3 normal = vec3();
		if (hasUVs) {
			uv = temp_uvs[uvIndex];
		}
		if (hasNormals) {
			normal = temp_normals[normalIndex];
		}

		vertices.push_back(vertex);
		uvs.push_back(uv);
		if (hasUVs) {
			uvs.push_back(uv);
		}
		normals.push_back(normal);
		if (hasNormals) {
			normals.push_back(normal);
		}
	}
	totalVertexCount = vertices.size();
	printf("total vertex count %d\n", totalVertexCount);
	fclose(file);
}


OBJModel::~OBJModel()
{
	printf("Object model started deleting %s...\n", fileName);
}

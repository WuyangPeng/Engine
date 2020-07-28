// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:16)

#ifndef ASSIST_TOOLS_FEATURES_IMPORTER_OBJ_LOADER_H
#define ASSIST_TOOLS_FEATURES_IMPORTER_OBJ_LOADER_H

#include "AssistTools/AssistToolsDll.h"

#include "MtlLoader.h"

namespace AssistTools
{
	class ObjLoader
	{
	public:
		ObjLoader(const std::string& path, const std::string& filename);


		enum class ErrorCode
		{
			EC_SUCCESSFUL,
			EC_LOGFILE_OPEN_FAILED,
			EC_FILE_OPEN_FAILED,
			EC_NO_TOKENS,
			EC_TOO_FEW_TOKENS,
			EC_TOO_MANY_TOKENS,
			EC_UNEXPECTED_TOKEN,
			EC_NOT_YET_IMPLEMENTED,
			EC_FAILED_TO_LOAD_MATERIALS,
			EC_FAILED_TO_FIND_MATERIAL,
			EC_INVALID_VERTEX,
			EC_MAX_ERROR_CODES
		};

		class Float2
		{
		public:
			float x, y;
		};

		class Float3
		{
		public:
			float x, y, z;
		};

		class Vertex
		{
		public:
			Vertex() noexcept
				:
				PosIndex(-1),
				TcdIndex(-1),
				NorIndex(-1)
			{
			}

			bool operator< (const Vertex& vertex) const noexcept
			{
				if (PosIndex < vertex.PosIndex)
				{
					return true;
				}
				if (PosIndex > vertex.PosIndex)
				{
					return false;
				}
				if (TcdIndex < vertex.TcdIndex)
				{
					return true;
				}
				if (TcdIndex > vertex.TcdIndex)
				{
					return false;
				}
				if (NorIndex < vertex.NorIndex)
				{
					return true;
				}
				return false;
			}

			int PosIndex, TcdIndex, NorIndex;
		};

		class Face
		{
		public:
			std::vector<Vertex> Vertices;
		};

		class Mesh
		{
		public:
			int MtlIndex = 0;
			std::vector<Face> Faces;
		};

		class Group
		{
		public:
			std::string Name;
			int PosStart = 0, TcdStart = 0, NorStart = 0;
			std::vector<Mesh> Meshes;
		};

		 ErrorCode GetCode() const noexcept;
		 const std::vector<MtlLoader::Material>& GetMaterials() const noexcept;
		 const std::vector<Group>& GetGroups() const noexcept;
		 const std::vector<Float3>& GetPositions() const noexcept;
		 const std::vector<Float2>& GetTCoords() const noexcept;
		 const std::vector<Float3>& GetNormals() const noexcept;

	private:
		void GetTokens(const std::string& line, std::vector<std::string>& tokens);
		bool GetMaterialLibrary(const std::string& path, const std::vector<std::string>& tokens);
		bool GetDefaultGroup(const std::vector<std::string>& tokens);
		bool GetPosition(const std::vector<std::string>& tokens);
		bool GetTCoord(const std::vector<std::string>& tokens);
		bool GetNormal(const std::vector<std::string>& tokens);
		bool GetGroup(const std::vector<std::string>& tokens);
		bool GetMaterialAndMesh(const std::vector<std::string>& tokens);
		bool GetFace(const std::vector<std::string>& tokens);

		ErrorCode mCode;
		FILE* mLogFile;
		std::vector<MtlLoader::Material> mMaterials;
		int mCurrentGroup, mCurrentPos, mCurrentTcd, mCurrentNor;
		int mCurrentMtl, mCurrentMesh;
		std::vector<Group> mGroups;
		std::vector<Float3> mPositions;
		std::vector<Float2> mTCoords;
		std::vector<Float3> mNormals;
		static const char* msCodeString[System::EnumCastUnderlying(ErrorCode::EC_MAX_ERROR_CODES)];
	};

}

#endif // ASSIST_TOOLS_FEATURES_IMPORTER_OBJ_LOADER_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:16)

#ifndef ASSIST_TOOLS_FEATURES_IMPORTER_MTL_LOADER_H
#define ASSIST_TOOLS_FEATURES_IMPORTER_MTL_LOADER_H

#include "AssistTools/AssistToolsDll.h"

#include <cstdio>
#include <string>
#include <vector>
 
namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE MtlLoader
	{
	public:
		MtlLoader(const std::string& path, const std::string& filename);
		~MtlLoader();

		enum ErrorCode
		{
			EC_SUCCESSFUL,
			EC_LOGFILE_OPEN_FAILED,
			EC_FILE_OPEN_FAILED,
			EC_NO_TOKENS,
			EC_TOO_FEW_TOKENS,
			EC_TOO_MANY_TOKENS,
			EC_UNEXPECTED_TOKEN,
			EC_NOT_YET_IMPLEMENTED,
			EC_VALUE_OUT_OF_RANGE,
			EC_MISSING_MAP_FILENAME,
			EC_INVALID_OPTION,
			EC_TOO_FEW_OPTION_TOKENS,
			EC_INVALID_OPTION_ARGUMENT,
			EC_MAX_ERROR_CODES
		};

		class Texture
		{
		public:
			Texture();

			std::string Filename;
			bool BlendU;            // -blendv          on|off
			bool BlendV;            // -blendu          on|off
			float BumpMultiplier;   // -bm value        any
			float Boost;            // -boost value     nonneg
			bool ColorCorrection;   // -cc              on|off
			bool Clamp;             // -clamp           on|off
			char IMFChannel;        // -imfchan         r|g|b|m|l|z
			float Base, Gain;       // -mm base gain    any, any
			float Offset[3];        // -o u [v] [w]     any, any, any
			float Scale[3];         // -s u [v] [w]     pos, pos, pos
			float Turbulence[3];    // -t u [v] [w]     nonneg, nonneg, nonneg
			float TexResolution;    // -texres value    [What is this?]
		};

		class Material
		{
		public:
			Material();

			std::string Name;
			int IlluminationModel;          // illum
			float AmbientColor[3];          // Ka
			float DiffuseColor[3];          // Kd
			float SpecularColor[3];         // Ks
			float TransmissionFilter[3];    // Tf
			float OpticalDensity;           // Ni
			float SpecularExponent;         // Ns
			Texture AmbientMap;             // map_Ka
			Texture DiffuseMap;             // map_Kd
			Texture SpecularMap;            // map_Ks
		};

		ErrorCode GetCode() const;
		const std::vector<Material>& GetMaterials() const;

	private:
		void GetTokens(const std::string& line, std::vector<std::string>& tokens);
		bool GetColor(const std::vector<std::string>& tokens, float color[3]);
		bool GetTexture(const std::vector<std::string>& tokens, Texture& texture);
		bool GetBoolArg(const std::vector<std::string>& tokens, int imax, int& i, bool& value);
		bool GetCharArg(const std::vector<std::string>& tokens, int imax, const char* valid, int& i, char& value);
		bool GetFloatArg(const std::vector<std::string>& tokens, int imax, float vmin, float vmax, int& i, float& value);
		bool GetFloatArg2(const std::vector<std::string>& tokens, int imax, float vmin0, float vmax0, float vmin1, float vmax1, int& i, float& value0,float& value1);
		bool GetFloatArg3Opt2(const std::vector<std::string>& tokens, int imax, float vmin0, float vmax0, float vmin1, float vmax1, float vmin2, float vmax2, int& i, float values[3]);
		bool GetNewMaterial(const std::vector<std::string>& tokens);
		bool GetIlluminationModel(const std::vector<std::string>& tokens);
		bool GetAmbientColor(const std::vector<std::string>& tokens);
		bool GetDiffuseColor(const std::vector<std::string>& tokens);
		bool GetSpecularColor(const std::vector<std::string>& tokens);
		bool GetTransmissionFilter(const std::vector<std::string>& tokens);
		bool GetOpticalDensity(const std::vector<std::string>& tokens);
		bool GetSpecularExponent(const std::vector<std::string>& tokens);
		bool GetAmbientTexture(const std::vector<std::string>& tokens);
		bool GetDiffuseTexture(const std::vector<std::string>& tokens);
		bool GetSpecularTexture(const std::vector<std::string>& tokens);

		ErrorCode mCode;
		FILE* mLogFile;
		int mCurrent;
		std::vector<Material> mMaterials;
		static const char* msCodeString[EC_MAX_ERROR_CODES];
	};
}

#endif // ASSIST_TOOLS_FEATURES_IMPORTER_MTL_LOADER_H

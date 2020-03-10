// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:17)

#ifndef ASSIST_TOOLS_WMFX_COMPILER_FX_COMPILER_H
#define ASSIST_TOOLS_WMFX_COMPILER_FX_COMPILER_H

#include "AssistTools/AssistToolsDll.h"

#include "Rendering/Shaders/ShaderBase.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/VisualEffect.h"
#include "Rendering/Shaders/VertexShader.h"
#include "Mathematics/Base/Float4.h"

#include <string>
#include <vector> 
#include <map>
#include "System/EnumOperator/EnumCastDetail.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE FxCompiler
	{
	public:
		// Construction and destruction.  There are times that special profiles
		// are needed that require running cgc manually to produce the compiled
		// shaders.  In this case, 'alreadyCompiled' should be set to 'true'
		// so that FxCompiler skips the compilation phase.  It will still load
		// the compiled files and create a *.wmfx file.
		FxCompiler(const std::string& fxName, bool alreadyCompiled = false);
		~FxCompiler();

		std::vector<std::string> Messages;

	private:
		typedef std::vector<std::string> TokenArray;
		typedef std::vector<TokenArray> TokenArrays;

		class Program
		{
		public:
			Program();

			std::string Name;
			std::string Text;
			TokenArrays Variables;
		};

		class Input
		{
		public:
			std::string Name;
			Rendering::ShaderFlags::VariableType Type;
			Rendering::ShaderFlags::VariableSemantic Semantic;
		};
		typedef std::vector<Input> InputArray;

		class Output
		{
		public:
			std::string Name;
			Rendering::ShaderFlags::VariableType Type;
			Rendering::ShaderFlags::VariableSemantic Semantic;
		};
		typedef std::vector<Output> OutputArray;

		class Constant
		{
		public:
			std::string Name;
			Rendering::ShaderFlags::VariableType Type;
			int BaseRegister;
			int NumRegistersUsed;
		};
		typedef std::vector<Constant> ConstantArray;

		class Sampler
		{
		public:
			std::string Name;
			Rendering::ShaderFlags::SamplerType Type;
			int Unit;
			Rendering::ShaderFlags::SamplerFilter Filter;
			Rendering::ShaderFlags::SamplerCoordinate Coordinate[3];
			float LodBias;
			float Anisotropy;
			Mathematics::Float4 BorderColor;
		};
		typedef std::vector<Sampler> SamplerArray;

		void InitializeMaps();

		bool Parse(const std::string& fileName, const std::string& profileName, Program& program);

		void GetTokens(const std::string& line, std::string::size_type begin, std::vector<std::string>& tokens);

		bool CreateEffect(const Program& vProgram, const Program& pProgram);
		bool UpdateEffect(const Program& vProgram, const Program& pProgram);

		bool Process(const Program& program, InputArray& inputs, OutputArray& outputs, ConstantArray& constants, SamplerArray& samplers);

		bool GetInput(const TokenArray& tokens, const std::string& name, Rendering::ShaderFlags::VariableType type, InputArray& inputs);

		bool GetOutput(const TokenArray& tokens, const std::string& name, Rendering::ShaderFlags::VariableType type, OutputArray& outputs);

		bool GetConstant(const TokenArray& tokens, const std::string& name, Rendering::ShaderFlags::VariableType type, ConstantArray& constants);

		bool GetSampler(const TokenArray& tokens, const std::string& name, Rendering::ShaderFlags::SamplerType type, SamplerArray& samplers);

		Rendering::ShaderBaseSmartPointer CreateShader(bool isVShader, const Program& program, InputArray& inputs, OutputArray& outputs, ConstantArray& constants,  SamplerArray& samplers);

		bool UpdateShader(Rendering::ShaderBase* shader, const Program& program, InputArray& inputs, OutputArray& outputs, ConstantArray& constants, SamplerArray& samplers);

		void ReportError(const std::string& message, const TokenArray* tokens = 0);

		typedef std::map<std::string, Rendering::ShaderFlags::VariableType> VariableTypeMap;
		VariableTypeMap mVariableTypes;

		typedef std::map<std::string, Rendering::ShaderFlags::VariableSemantic> SemanticMap;
		SemanticMap mSemantics;

		typedef std::map<std::string, Rendering::ShaderFlags::SamplerType> SamplerTypeMap;
		SamplerTypeMap mSamplerTypes;

		int mActiveProfile;
		Rendering::VisualEffect* mEffect;
		Rendering::VertexShaderSmartPointer mVShader;
		Rendering::PixelShaderSmartPointer mPShader;
		bool mAlreadyCompiled;

		static const std::string msVProfileName[Rendering::ShaderFlags::MaxProfiles];
		static const std::string msPProfileName[Rendering::ShaderFlags::MaxProfiles];
		static const std::string msVTName[System::EnumCastUnderlying(Rendering::ShaderFlags::VariableType::Quantity)];
		static const std::string msVSName[System::EnumCastUnderlying(Rendering::ShaderFlags::VariableSemantic::Quantity)];
		static const std::string msSTName[System::EnumCastUnderlying(Rendering::ShaderFlags::SamplerType::Quantity)];
	};
}

#endif // ASSIST_TOOLS_WMFX_COMPILER_FX_COMPILER_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 14:35)

#ifndef RENDERING_SHADERS_SHADER_IMPL_H
#define RENDERING_SHADERS_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/ShaderBaseData.h"
#include "Rendering/Shaders/ShaderConstantsData.h"
#include "Rendering/Shaders/ShaderSamplerData.h"
#include "Rendering/Shaders/ShaderProfileData.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <string>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;	
	class WriteFileManager;
	class ObjectLink;
	class ObjectRegister;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ShaderBaseImpl 
	{	
	public:
		using ClassType = ShaderBaseImpl;
		using Colour = Colour<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ReadFileManager = CoreTools::ReadFileManager;
		// 默认 lodBias 是 0.
		// 默认 anisotropy 是 1.
		// 默认 borderColor 是 (0,0,0,0).
	
	public:
		ShaderBaseImpl();
		ShaderBaseImpl (int numInputs,int numOutputs,int numConstants,int numSamplers);		

		CLASS_INVARIANT_DECLARE;
		
		// 支持延迟构造
		void SetInput (int index, const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);
		
		void SetOutput (int index, const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);
		
		void SetConstant (int index, const std::string& name,int numRegistersUsed);
		
		void SetSampler (int index, const std::string& name,ShaderFlags::SamplerType type);
		void SetFilter (int index, ShaderFlags::SamplerFilter filter);
		void SetCoordinate(int index, int dimension,ShaderFlags::SamplerCoordinate coordinate);
		void SetLodBias (int index, float lodBias);
		void SetAnisotropy (int index, float anisotropy);
		void SetBorderColor (int index, const Colour& borderColor);	
			
		// 配置文件无关的数据。
		int GetNumInputs () const;
		const std::string GetInputName (int index) const;
		ShaderFlags::VariableType GetInputType (int index) const;
		ShaderFlags::VariableSemantic GetInputSemantic (int index) const;
		
		int GetNumOutputs () const;
		const std::string GetOutputName (int index) const;
		ShaderFlags::VariableType GetOutputType (int index) const;
		ShaderFlags::VariableSemantic GetOutputSemantic (int index) const;
		
		int GetNumConstants () const;
		const std::string GetConstantName (int index) const;
		int GetNumRegistersUsed (int index) const;
		
		int GetNumSamplers () const;
		const std::string GetSamplerName (int index) const;
		ShaderFlags::SamplerType GetSamplerType (int index) const;
		ShaderFlags::SamplerFilter GetFilter (int index) const;
		ShaderFlags::SamplerCoordinate GetCoordinate(int index, int dimension) const;
		float GetLodBias (int index) const;
		float GetAnisotropy (int index) const;
		Colour GetBorderColor (int index) const;

		void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
		void Link(ObjectLink& source);
		void Register(ObjectRegister& target) const;

		void SaveShader(WriteFileManager& manager) const;
		void LoadShader(ReadFileManager& manager, int numProfiles);

		void SetProfile(const ShaderProfileDataSmartPointer& profile);
		const ConstShaderProfileDataSmartPointer GetProfile() const;
		ShaderProfileDataSmartPointer GetProfile();

	private:
		ShaderBaseData m_Input;
		ShaderBaseData m_Output;
		ShaderConstantsData m_Constants;
		ShaderSamplerData m_Sampler;	
		ShaderProfileDataSmartPointer m_Profile;
	};
}

#endif // RENDERING_SHADERS_SHADER_IMPL_H

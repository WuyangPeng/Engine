// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 14:52)

#ifndef RENDERING_SHADERS_SHADER_PROFILE_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_PROFILE_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/SingleShaderProfileData.h"

#include <array>
#include <string>
#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ShaderProfileDataImpl 
	{	
	public:
		using ClassType = ShaderProfileDataImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;

	public:		
		ShaderProfileDataImpl();
		ShaderProfileDataImpl (int numConstants,int numSamplers);	

		CLASS_INVARIANT_DECLARE;
	
		void SetBaseRegister (int profile, int index, int baseRegister);
		void SetTextureUnit (int profile, int index, int textureUnit);
		void SetProgram (int profile, const std::string& program);

		// 配置文件相关的数据。
		int GetBaseRegister (int profile, int index) const;
		int GetTextureUnit (int profile, int index) const;
		const std::string GetProgram (int profile) const;

		int GetBaseRegisterSize() const;
		int GetTextureUnitSize() const;

		void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
	
	private:
		std::array<SingleShaderProfileData, ShaderFlags::MaxProfiles> m_ShaderProfileData;
		int m_NumConstants;
		int m_NumSamplers;
	};
}

#endif // RENDERING_SHADERS_SHADER_PROFILE_DATA_IMPL_H

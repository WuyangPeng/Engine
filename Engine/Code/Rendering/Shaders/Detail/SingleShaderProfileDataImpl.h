// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:00)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include <string>
#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE SingleShaderProfileDataImpl 
	{	
	public:
		using ClassType = SingleShaderProfileDataImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;

	public:		
		SingleShaderProfileDataImpl (int numConstants,int numSamplers);	

		CLASS_INVARIANT_DECLARE;

		void ResetData(int numConstants, int numSamplers);
		
		void SetBaseRegister ( int index, int baseRegister);
		void SetTextureUnit (int index, int textureUnit);
		void SetProgram (const std::string& program);

		// 配置文件相关的数据。
		int GetBaseRegister (int index) const;
		int GetTextureUnit (int index) const;
		const std::string GetProgram () const;

		int GetBaseRegisterSize() const;
		int GetTextureUnitSize() const;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;
	
	private:
		std::vector<int> m_BaseRegister;
		std::vector<int> m_TextureUnit;
		std::string m_Program;
	};
}

#endif // RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_IMPL_H

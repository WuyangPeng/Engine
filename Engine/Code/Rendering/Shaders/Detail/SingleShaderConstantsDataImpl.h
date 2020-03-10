// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:00)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include <string>
#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE SingleShaderConstantsDataImpl
	{	
	public:
		using ClassType = SingleShaderConstantsDataImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		SingleShaderConstantsDataImpl();
		explicit SingleShaderConstantsDataImpl(const std::string& name,int numRegistersUsed);

		CLASS_INVARIANT_DECLARE;
		
		void SetConstant (const std::string& name,int numRegistersUsed);

		const std::string GetConstantName () const;
		int GetNumRegistersUsed () const;	

		void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
		
	private:	
		std::string m_Name;
		int m_NumRegistersUsed;
	};
}

#endif // RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H

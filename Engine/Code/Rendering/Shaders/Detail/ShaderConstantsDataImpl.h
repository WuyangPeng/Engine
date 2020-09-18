// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 14:37)

#ifndef RENDERING_SHADERS_SHADER_CONSTANTS_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_CONSTANTS_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/SingleShaderConstantsData.h"

#include <string>
#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ShaderConstantsDataImpl
	{	
	public:
		using ClassType = ShaderConstantsDataImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		ShaderConstantsDataImpl() noexcept;
		explicit ShaderConstantsDataImpl(int number);

		CLASS_INVARIANT_DECLARE;

		void Resize(int number);
		
		void SetConstant (int index, const std::string& name,int numRegistersUsed);

		void InsertData(const std::string& name,int numRegistersUsed);	
	
		int GetNumConstants() const;
		const std::string GetConstantName(int index) const;
		int GetNumRegistersUsed(int index) const;

		void Load(BufferSource& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
		
	private:	
		std::vector<SingleShaderConstantsData> m_SingleShaderConstantsData;
	};
}

#endif // RENDERING_SHADERS_SHADER_CONSTANTS_DATA_IMPL_H

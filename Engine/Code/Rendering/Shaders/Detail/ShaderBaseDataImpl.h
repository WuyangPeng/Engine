// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 14:34)

#ifndef RENDERING_SHADERS_SHADER_BASE_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_BASE_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/SingleShaderBaseData.h"

#include <string>
#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ShaderBaseDataImpl
	{	
	public:
		using ClassType = ShaderBaseDataImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		ShaderBaseDataImpl() noexcept;
		explicit ShaderBaseDataImpl(int number);

		CLASS_INVARIANT_DECLARE;

		void Resize(int number);
		
		void SetData (int index, const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);	

		void InsertData(const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);	
	
		int GetNumber () const;
		const std::string GetName (int index) const;
		ShaderFlags::VariableType GetType (int index) const;
		ShaderFlags::VariableSemantic GetSemantic (int index) const;	

		void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
		
	private:	
		std::vector<SingleShaderBaseData> m_SingleShaderBaseData;
	};
}

#endif // RENDERING_SHADERS_SHADER_BASE_DATA_IMPL_H

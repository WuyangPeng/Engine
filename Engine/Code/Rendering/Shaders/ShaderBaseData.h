// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:24) 

#ifndef RENDERING_SHADERS_SHADER_BASE_DATA_H
#define RENDERING_SHADERS_SHADER_BASE_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>
#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

RENDERING_EXPORT_SHARED_PTR(ShaderBaseDataImpl);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ShaderBaseData 
	{	
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ShaderBaseData);
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:	
		ShaderBaseData();
		explicit ShaderBaseData (int number);	

		CLASS_INVARIANT_DECLARE;

		void Resize(int number);

		void InsertData(const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);	
		
		void SetData (int index, const std::string& name, ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);		
	
		int GetNumber () const;
		const std::string GetName (int index) const;
		ShaderFlags::VariableType GetType (int index) const;
		ShaderFlags::VariableSemantic GetSemantic (int index) const;	

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;
		
	private:
		IMPL_TYPE_DECLARE(ShaderBaseData);
	};
}

#endif // RENDERING_SHADERS_SHADER_BASE_DATA_H

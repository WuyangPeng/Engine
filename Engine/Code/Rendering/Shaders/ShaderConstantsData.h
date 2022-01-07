// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:24)

#ifndef RENDERING_SHADERS_SHADER_CONSTANTS_DATA_H
#define RENDERING_SHADERS_SHADER_CONSTANTS_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>
#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(ShaderConstantsData,ShaderConstantsDataImpl);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ShaderConstantsData 
	{	
	public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(ShaderConstantsData);
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		ShaderConstantsData();
		explicit ShaderConstantsData (int numConstants);	

		CLASS_INVARIANT_DECLARE;

		void Resize(int number);
		
		void SetConstant (int index, const std::string& name,int numRegistersUsed);

		void InsertData(const std::string& name,int numRegistersUsed);	

		int GetNumConstants () const;
		const std::string GetConstantName (int index) const;
		int GetNumRegistersUsed (int index) const;	

		void Load(CoreTools::BufferSource& source);
		void Save (CoreTools::BufferTarget& target) const;
		int GetStreamingSize () const;
		
	private:
                PackageType impl;
	};
}

#endif // RENDERING_SHADERS_SHADER_CONSTANTS_DATA_H

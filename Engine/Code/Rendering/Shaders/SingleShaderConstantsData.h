// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:28)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_H
#define RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(SingleShaderConstantsData,SingleShaderConstantsDataImpl);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SingleShaderConstantsData
	{	
	public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(SingleShaderConstantsData);
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		SingleShaderConstantsData();
		explicit SingleShaderConstantsData(const std::string& name,int numRegistersUsed);

		CLASS_INVARIANT_DECLARE;
		
		void SetConstant (const std::string& name,int numRegistersUsed);

		const std::string GetConstantName () const;
		int GetNumRegistersUsed () const noexcept;	

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;
		
	private:
                PackageType impl;
	};
}

#endif // RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:19)

#ifndef RENDERING_SHADERS_PIXEL_SHADER_H
#define RENDERING_SHADERS_PIXEL_SHADER_H

#include "ShaderBase.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PixelShader : public ShaderBase
    {
    public:
		using ClassType = PixelShader;
		using ParentType = ShaderBase;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
        
    public:
        PixelShader (const std::string& programName,int numInputs,int numOutputs,int numConstants,int numSamplers);
         virtual ~PixelShader ();        

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(PixelShader);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 
    };
    
	CORE_TOOLS_STREAM_REGISTER(PixelShader);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, PixelShader);
}

#endif // RENDERING_SHADERS_PIXEL_SHADER_H

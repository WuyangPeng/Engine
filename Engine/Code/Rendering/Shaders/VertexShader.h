// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:31)

#ifndef RENDERING_SHADERS_VERTEX_SHADER_H
#define RENDERING_SHADERS_VERTEX_SHADER_H

#include "ShaderBase.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexShader : public ShaderBase
    {
    public:
		using ClassType = VertexShader;
		using ParentType = ShaderBase;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
        
    public:
        VertexShader (const std::string& programName,int numInputs,int numOutputs,int numConstants,int numSamplers);
        virtual ~VertexShader ();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
        
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(VertexShader);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 
    };
    
	CORE_TOOLS_STREAM_REGISTER(VertexShader);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, VertexShader);
}

#endif // RENDERING_SHADERS_VERTEX_SHADER_H
 
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:57)

#include "Rendering/RenderingExport.h"

#include "PixelShader.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;

CORE_TOOLS_RTTI_DEFINE(Rendering,PixelShader);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,PixelShader);
CORE_TOOLS_FACTORY_DEFINE(Rendering,PixelShader); 
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, PixelShader);

Rendering::PixelShader
    ::PixelShader (const string& programName, int numInputs,int numOutputs,int numConstants,int numSamplers)
	:ParentType{ programName,numInputs,numOutputs,numConstants,numSamplers }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PixelShader
    ::~PixelShader()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
    
	RENDERER_MANAGE_SINGLETON.UnbindAll(this); 
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,PixelShader)

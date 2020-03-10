// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:27)

#include "Rendering/RenderingExport.h"

#include "VertexShader.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/FirstSubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering,VertexShader);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,VertexShader);
CORE_TOOLS_FACTORY_DEFINE(Rendering,VertexShader); 
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, VertexShader);

using std::string;

Rendering::VertexShader
    ::VertexShader (const string& programName, int numInputs,int numOutputs,int numConstants,int numSamplers)
    :ParentType(programName,numInputs,numOutputs,numConstants,numSamplers)
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexShader
    ::~VertexShader()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
    
    RENDERER_MANAGE_SINGLETON.UnbindAll(this);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,VertexShader)

 
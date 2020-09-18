// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:57)

#include "Rendering/RenderingExport.h"

#include "PixelShader.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Renderers/RendererManager.h"

using std::string;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, PixelShader);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PixelShader);
CORE_TOOLS_FACTORY_DEFINE(Rendering, PixelShader);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, PixelShader);

Rendering::PixelShader ::PixelShader(const string& programName, int numInputs, int numOutputs, int numConstants, int numSamplers)
    : ParentType{ programName, numInputs, numOutputs, numConstants, numSamplers }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PixelShader ::~PixelShader()
{
    RENDERING_SELF_CLASS_IS_VALID_1;

    EXCEPTION_TRY
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PixelShader)

CoreTools::ObjectInterfaceSharedPtr Rendering::PixelShader::CloneObject() const 
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP
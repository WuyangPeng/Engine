///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 21:11)

#include "Rendering/RenderingExport.h"

#include "VisualTechnique.h"
#include "Detail/VisualTechniqueImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VisualTechnique)

CORE_TOOLS_RTTI_DEFINE(Rendering, VisualTechnique);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualTechnique);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualTechnique);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualTechnique);

Rendering::VisualTechnique::VisualTechnique(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, VisualTechnique)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, VisualTechnique)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, VisualTechnique)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, VisualTechnique)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, VisualTechnique)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, VisualTechnique)

Rendering::VisualTechnique::VisualTechnique(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType("VisualTechnique"), impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualTechnique)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualTechnique, InsertPass, VisualPassSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualTechnique, GetNumPasses, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetPass, int, Rendering::ConstVisualPassSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetVertexShader, int, Rendering::ConstVertexShaderSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetPixelShader, int, Rendering::ConstPixelShaderSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetAlphaState, int, Rendering::ConstAlphaStateSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetCullState, int, Rendering::ConstCullStateSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetDepthState, int, Rendering::ConstDepthStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetOffsetState, int, Rendering::ConstOffsetStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetStencilState, int, Rendering::ConstStencilStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, GetWireState, int, Rendering::ConstWireStateSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, SaveVisualPass, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique, LoadVisualPass, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualTechnique::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

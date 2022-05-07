///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 18:34)

#include "Rendering/RenderingExport.h"

#include "VisualEffect.h"
#include "Detail/VisualEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VisualEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualEffect);

Rendering::VisualEffect::VisualEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, VisualEffect)

Rendering::VisualEffect::VisualEffect(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "VisualEffect" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualEffect)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualEffect, InsertTechnique, VisualTechniqueSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffect, GetNumTechniques, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect, GetTechnique, int, Rendering::ConstVisualTechniqueSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect, GetNumPasses, int, int)

Rendering::ConstVertexShaderSharedPtr Rendering::VisualEffect::GetVertexShader(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertexShader(techniqueIndex, passIndex);
}

Rendering::ConstPixelShaderSharedPtr Rendering::VisualEffect::GetPixelShader(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPixelShader(techniqueIndex, passIndex);
}

Rendering::ConstAlphaStateSharedPtr Rendering::VisualEffect::GetAlphaState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetAlphaState(techniqueIndex, passIndex);
}

Rendering::ConstCullStateSharedPtr Rendering::VisualEffect::GetCullState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetCullState(techniqueIndex, passIndex);
}

Rendering::ConstDepthStateSharedPtr Rendering::VisualEffect::GetDepthState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDepthState(techniqueIndex, passIndex);
}

Rendering::ConstOffsetStateSharedPtr Rendering::VisualEffect::GetOffsetState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetOffsetState(techniqueIndex, passIndex);
}

Rendering::ConstStencilStateSharedPtr Rendering::VisualEffect::GetStencilState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetStencilState(techniqueIndex, passIndex);
}

Rendering::ConstWireStateSharedPtr Rendering::VisualEffect::GetWireState(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWireState(techniqueIndex, passIndex);
}

Rendering::ConstVisualPassSharedPtr Rendering::VisualEffect::GetPass(int techniqueIndex, int passIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPass(techniqueIndex, passIndex);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect, SaveVisualTechnique, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect, LoadVisualTechnique, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

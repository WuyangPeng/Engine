///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 09:19)

#include "Rendering/RenderingExport.h"

#include "Detail/VisualEffectImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/LocalEffects/VisualEffect.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VisualEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualEffect)

Rendering::VisualEffect::VisualEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, VisualEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, VisualEffect)

Rendering::VisualEffect::VisualEffect(const VisualProgramSharedPtr& visualProgram)
    : ParentType{ "VisualEffect" }, impl{ visualProgram }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "VisualEffect" }, impl{ disableNotThrow }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(const BaseRendererSharedPtr& baseRenderer)
    : ParentType{ "VisualEffect" }, impl{ baseRenderer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(const BaseRendererSharedPtr& baseRenderer, const VisualProgramSharedPtr& visualProgram)
    : ParentType{ "VisualEffect" }, impl{ baseRenderer, visualProgram }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(ProgramFactory& factory, const BaseRendererSharedPtr& baseRenderer, const std::string& vertexShaderFile, const std::string& pixelShaderFile)
    : ParentType{ "VisualEffect" }, impl{ factory, baseRenderer, vertexShaderFile, pixelShaderFile }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualEffect)

void Rendering::VisualEffect::SetBaseRenderer(const BaseRendererSharedPtr& baseRenderer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBaseRenderer(baseRenderer);
}

Rendering::VisualEffect::BaseRendererSharedPtr Rendering::VisualEffect::GetBaseRenderer()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetBaseRenderer();
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::VisualEffect::VisualEffectSharedPtr Rendering::VisualEffect::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetProgram, Rendering::VisualEffect::ConstVisualProgramSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetProgram, Rendering::VisualEffect::VisualProgramSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetVertexShader, Rendering::VisualEffect::ConstShaderSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetPixelShader, Rendering::VisualEffect::ConstShaderSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetGeometryShader, Rendering::VisualEffect::ConstShaderSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetVertexShader, Rendering::VisualEffect::ShaderSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetPixelShader, Rendering::VisualEffect::ShaderSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetGeometryShader, Rendering::VisualEffect::ShaderSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualEffect, SetProjectionViewWorldMatrixConstant, ConstantBufferSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetProjectionViewWorldMatrixConstant, Rendering::VisualEffect::ConstConstantBufferSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualEffect, GetProjectionViewWorldMatrixConstant, Rendering::VisualEffect::ConstantBufferSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualEffect, SetProjectionViewWorldMatrix, Matrix4, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffect, GetProjectionViewWorldMatrix, Rendering::VisualEffect::Matrix4)

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

Rendering::VisualEffect::VisualEffect(const std::string& name, const VisualProgramSharedPtr& visualProgram)
    : ParentType{ name }, impl{ visualProgram }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(const std::string& name)
    : ParentType{ name }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(const std::string& name, const BaseRendererSharedPtr& baseRenderer)
    : ParentType{ name }, impl{ baseRenderer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(const std::string& name, const BaseRendererSharedPtr& baseRenderer, const VisualProgramSharedPtr& visualProgram)
    : ParentType{ name }, impl{ baseRenderer, visualProgram }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffect::VisualEffect(const std::string& name, ProgramFactory& factory, const BaseRendererSharedPtr& baseRenderer, const std::string& vertexShaderFile, const std::string& pixelShaderFile)
    : ParentType{ name }, impl{ factory, baseRenderer, vertexShaderFile, pixelShaderFile }
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

Rendering::VisualEffect::ConstVisualProgramSharedPtr Rendering::VisualEffect::GetProgram() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProgram();
}

Rendering::VisualEffect::VisualProgramSharedPtr Rendering::VisualEffect::GetProgram() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetProgram();
}

Rendering::VisualEffect::ConstShaderSharedPtr Rendering::VisualEffect::GetVertexShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetVertexShader();
}

Rendering::VisualEffect::ConstShaderSharedPtr Rendering::VisualEffect::GetPixelShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPixelShader();
}

Rendering::VisualEffect::ConstShaderSharedPtr Rendering::VisualEffect::GetGeometryShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetGeometryShader();
}

Rendering::VisualEffect::ShaderSharedPtr Rendering::VisualEffect::GetVertexShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetVertexShader();
}

Rendering::VisualEffect::ShaderSharedPtr Rendering::VisualEffect::GetPixelShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetPixelShader();
}

Rendering::VisualEffect::ShaderSharedPtr Rendering::VisualEffect::GetGeometryShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetGeometryShader();
}

void Rendering::VisualEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetProjectionViewWorldMatrixConstant(buffer);
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::VisualEffect::GetProjectionViewWorldMatrixConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectionViewWorldMatrixConstant();
}

Rendering::VisualEffect::ConstantBufferSharedPtr Rendering::VisualEffect::GetProjectionViewWorldMatrixConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectionViewWorldMatrixConstant();
}

void Rendering::VisualEffect::SetProjectionViewWorldMatrix(const Matrix4& projectionViewWorldMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetProjectionViewWorldMatrix(projectionViewWorldMatrix);
}

Rendering::VisualEffect::Matrix4 Rendering::VisualEffect::GetProjectionViewWorldMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProjectionViewWorldMatrix();
}

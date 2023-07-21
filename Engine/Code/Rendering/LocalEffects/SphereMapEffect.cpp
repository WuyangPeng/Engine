///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 16:18)

#include "Rendering/RenderingExport.h"

#include "Light.h"
#include "LightCameraGeometry.h"
#include "Material.h"
#include "SphereMapEffect.h"
#include "Detail/ProjectedTextureEffectImpl.h"
#include "Detail/SphereMapEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SphereMapEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, SphereMapEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SphereMapEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SphereMapEffect);

Rendering::SphereMapEffect::SphereMapEffect(ProgramFactory& factory,
                                            const BaseRendererSharedPtr& baseRenderer,
                                            const Texture2DSharedPtr& texture,
                                            SamplerStateFilter filter,
                                            SamplerStateMode mode0,
                                            SamplerStateMode mode1)
    : ParentType{ factory,
                  baseRenderer,
                  "Resource/Shader/SphereMapEffect.vs",
                  "Resource/Shader/SphereMapEffect.ps" },
      impl{ texture, filter, mode0, mode1, Rendering::GetStreamSize<Matrix4>() }
{
    const auto vertexShader = GetVertexShader();
    vertexShader->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
    vertexShader->Set("viewWorldMatrixConstant", GetViewWorldMatrixConstant());
    GetPixelShader()->Set("baseTexture", texture, "baseSampler", impl->GetSamplerState());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::SphereMapEffect::SphereMapEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SphereMapEffect)

Rendering::SphereMapEffect::Texture2DSharedPtr Rendering::SphereMapEffect::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetTexture();
}

Rendering::SphereMapEffect::SamplerStateSharedPtr Rendering::SphereMapEffect::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetSamplerState();
}

Rendering::SphereMapEffect::ConstantBufferSharedPtr Rendering::SphereMapEffect::GetViewWorldMatrixConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetViewWorldMatrixConstant();
}

void Rendering::SphereMapEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}

void Rendering::SphereMapEffect::SetViewWorldMatrix(const Matrix4& viewWorldMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto projectorMatrixConstant = GetViewWorldMatrixConstant();

    auto data = projectorMatrixConstant->GetData();

    for (const auto value : viewWorldMatrix.GetContainer())
    {
        data.Increase(value);
    }
}

Rendering::VisualEffect::Matrix4 Rendering::SphereMapEffect::GetViewWorldMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto projectorMatrixConstant = impl->GetViewWorldMatrixConstant();

    auto data = projectorMatrixConstant->GetData();

    Matrix4::ContainerType matrix4{};
    for (auto& value : matrix4)
    {
        value = data.Increase<float>();
    }

    return Matrix4{ matrix4, Mathematics::MatrixMajorFlags::Row };
}

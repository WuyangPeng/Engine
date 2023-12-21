﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/10 14:55)

#include "Rendering/RenderingExport.h"

#include "ConstantColorEffect.h"
#include "Detail/ConstantColorEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ConstantColorEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, ConstantColorEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConstantColorEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConstantColorEffect);

Rendering::ConstantColorEffect::ConstantColorEffect(ProgramFactory& factory, const BaseRendererSharedPtr& baseRenderer, const Colour& color)
    : ParentType{ factory, baseRenderer, "Resource/Shader/ConstantColorEffect.vs", "Resource/Shader/ConstantColorEffect.ps" },
      impl{ Rendering::GetStreamSize<Colour>() }
{
    const auto colorConstant = impl->GetColorConstant();

    auto data = colorConstant->GetStorage();
    data.Increase<float>(color.GetRed());
    data.Increase<float>(color.GetGreen());
    data.Increase<float>(color.GetBlue());
    data.Increase<float>(color.GetAlpha());

    GetVertexShader()->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
    GetVertexShader()->Set("ConstantColor", colorConstant);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ConstantColorEffect::ConstantColorEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ConstantColorEffect)

void Rendering::ConstantColorEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}

Rendering::VisualEffect::ConstantBufferSharedPtr Rendering::ConstantColorEffect::GetColorConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetColorConstant();
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::ConstantColorEffect::GetColorConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetColorConstant();
}

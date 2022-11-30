///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/04 11:54)

#include "Rendering/RenderingExport.h"

#include "TextEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/ShaderDetail.h"
#include "Rendering/Shaders/VisualProgram.h"
#include "Rendering/State/SamplerState.h"

Rendering::TextEffectImpl::TextEffectImpl(const Texture2DSharedPtr& texture, VisualProgram& visualProgram)
    : translate{ std::make_shared<ConstantBuffer>(boost::numeric_cast<int>(Mathematics::Vector3<float>::pointSize * sizeof(float)), true) },
      color{ std::make_shared<ConstantBuffer>(boost::numeric_cast<int>(Colour::arraySize * sizeof(float)), true) },
      samplerState{ std::make_shared<SamplerState>("SamplerState") }
{
    SetTranslate(0.0f, 0.0f);
    SetNormalizedZ(-1.0f);
    visualProgram.GetVertexShader()->Set("Translate", translate);

    SetColor({ 0.0f, 0.0f, 0.0f, 0.0f });
    auto pshader = visualProgram.GetPixelShader();
    pshader->Set("TextColor", color);
    pshader->Set("baseTexture", texture, "baseSampler", samplerState);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextEffectImpl::TextEffectImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow) noexcept
    : translate{},
      color{},
      samplerState{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TextEffectImpl)

Rendering::TextEffectImpl::ConstConstantBufferSharedPtr Rendering::TextEffectImpl::GetTranslate() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return translate;
}

Rendering::TextEffectImpl::ConstConstantBufferSharedPtr Rendering::TextEffectImpl::GetColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return color;
}

void Rendering::TextEffectImpl::SetTranslate(float x, float y)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = translate->GetData();
    data.Increase(x);
    data.Increase(y);
}

void Rendering::TextEffectImpl::SetNormalizedZ(float z)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = translate->GetData(sizeof(float) * 2);
    data.Increase(z);
}

void Rendering::TextEffectImpl::SetColor(const Colour& aColor)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = translate->GetData();
    data.Increase(aColor.GetRed());
    data.Increase(aColor.GetBlue());
    data.Increase(aColor.GetGreen());
    data.Increase(aColor.GetAlpha());
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 19:20)

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

Rendering::TextEffectImpl::TextEffectImpl(ShaderAPIType shaderAPIType, int numTranslateConstantBytes, int numColorConstantBytes)
    : translate{ std::make_shared<ConstantBuffer>("translate", numTranslateConstantBytes, true) },
      color{ std::make_shared<ConstantBuffer>("color", numColorConstantBytes, true) },
      samplerState{ std::make_shared<SamplerState>("SamplerState") }
{
    SetTranslate(0.0f, 0.0f);
    SetNormalizedZ(shaderAPIType == ShaderAPIType::GLSL ? -1.0f : 0.0f);
    SetColor({ 0.0f, 0.0f, 0.0f, 0.0f });

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextEffectImpl::TextEffectImpl() noexcept
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

Rendering::TextEffectImpl::ConstantBufferSharedPtr Rendering::TextEffectImpl::GetTranslate() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return translate;
}

Rendering::TextEffectImpl::ConstantBufferSharedPtr Rendering::TextEffectImpl::GetColor() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return color;
}

Rendering::TextEffectImpl::SamplerStateSharedPtr Rendering::TextEffectImpl::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return samplerState;
}

void Rendering::TextEffectImpl::SetTranslate(float x, float y)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = translate->GetStorage();
    data.Increase(x);
    data.Increase(y);
}

void Rendering::TextEffectImpl::SetNormalizedZ(float z)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = translate->GetStorage(sizeof(float) * 2);
    data.Increase(z);
}

void Rendering::TextEffectImpl::SetColor(const ColourType& aColor)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = color->GetStorage();
    data.Increase(aColor.GetRed());
    data.Increase(aColor.GetBlue());
    data.Increase(aColor.GetGreen());
    data.Increase(aColor.GetAlpha());
}

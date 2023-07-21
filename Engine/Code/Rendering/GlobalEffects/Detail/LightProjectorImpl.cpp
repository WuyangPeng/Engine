///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 17:00)

#include "Rendering/RenderingExport.h"

#include "LightProjectorImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::LightProjectorImpl::LightProjectorImpl() noexcept
    : position{ 0.0f, 0.0f, 0.0f, 0.0f },
      direction{ 0.0f, 0.0f, 0.0f, 0.0f },
      isPointLight{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightProjectorImpl)

Mathematics::Vector4<float> Rendering::LightProjectorImpl::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return position;
}

void Rendering::LightProjectorImpl::SetPosition(const Vector4& aPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->position = aPosition;
}

Mathematics::Vector4<float> Rendering::LightProjectorImpl::GetDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return direction;
}

void Rendering::LightProjectorImpl::SetDirection(const Vector4& aDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->direction = aDirection;
}

bool Rendering::LightProjectorImpl::IsPointLight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isPointLight;
}

void Rendering::LightProjectorImpl::SetIsPointLight(const bool aIsPointLight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->isPointLight = aIsPointLight;
}
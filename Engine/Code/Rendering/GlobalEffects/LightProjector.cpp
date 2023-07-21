///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 14:23)

#include "Rendering/RenderingExport.h"

#include "LightProjector.h"
#include "Detail/LightProjectorImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, LightProjector)

Rendering::LightProjector::LightProjector(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightProjector)

Rendering::LightProjector::Vector4 Rendering::LightProjector::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPosition();
}

void Rendering::LightProjector::SetPosition(const Vector4& aPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetPosition(aPosition);
}

Rendering::LightProjector::Vector4 Rendering::LightProjector::GetDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDirection();
}

void Rendering::LightProjector::SetDirection(const Vector4& aDirection) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDirection(aDirection);
}

bool Rendering::LightProjector::IsPointLight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsPointLight();
}

void Rendering::LightProjector::SetIsPointLight(const bool aIsPointLight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsPointLight(aIsPointLight);
}

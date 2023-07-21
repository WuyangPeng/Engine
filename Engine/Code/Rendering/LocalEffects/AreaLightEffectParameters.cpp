///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/07 10:49)

#include "Rendering/RenderingExport.h"

#include "AreaLightEffectParameters.h"
#include "Detail/AreaLightEffectParametersImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, AreaLightEffectParameters)

Rendering::AreaLightEffectParameters Rendering::AreaLightEffectParameters::Create()
{
    return AreaLightEffectParameters{ CoreTools::DisableNotThrow::Disable };
}

Rendering::AreaLightEffectParameters::AreaLightEffectParameters(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, AreaLightEffectParameters)

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAmbient();
}

void Rendering::AreaLightEffectParameters::SetAmbient(const Colour& ambient) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAmbient(ambient);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDiffuse();
}

void Rendering::AreaLightEffectParameters::SetDiffuse(const Colour& diffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDiffuse(diffuse);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetSpecular();
}

void Rendering::AreaLightEffectParameters::SetSpecular(const Colour& specular) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetSpecular(specular);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetAttenuation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAttenuation();
}

void Rendering::AreaLightEffectParameters::SetAttenuation(const Colour& attenuation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAttenuation(attenuation);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPosition();
}

void Rendering::AreaLightEffectParameters::SetPosition(const Colour& position) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetPosition(position);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetNormal() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNormal();
}

void Rendering::AreaLightEffectParameters::SetNormal(const Colour& normal) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetNormal(normal);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetAxis0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAxis0();
}

void Rendering::AreaLightEffectParameters::SetAxis0(const Colour& axis0) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAxis0(axis0);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetAxis1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAxis1();
}

void Rendering::AreaLightEffectParameters::SetAxis1(const Colour& axis1) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAxis1(axis1);
}

Rendering::AreaLightEffectParameters::Colour Rendering::AreaLightEffectParameters::GetExtent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetExtent();
}

void Rendering::AreaLightEffectParameters::SetExtent(const Colour& extent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetExtent(extent);
}

int Rendering::AreaLightEffectParameters::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamingSize();
}

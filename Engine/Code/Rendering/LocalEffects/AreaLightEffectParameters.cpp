/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:17)

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

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAmbient();
}

void Rendering::AreaLightEffectParameters::SetAmbient(const ColourType& ambient) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAmbient(ambient);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDiffuse();
}

void Rendering::AreaLightEffectParameters::SetDiffuse(const ColourType& diffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDiffuse(diffuse);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetSpecular();
}

void Rendering::AreaLightEffectParameters::SetSpecular(const ColourType& specular) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetSpecular(specular);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetAttenuation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAttenuation();
}

void Rendering::AreaLightEffectParameters::SetAttenuation(const ColourType& attenuation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAttenuation(attenuation);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPosition();
}

void Rendering::AreaLightEffectParameters::SetPosition(const ColourType& position) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetPosition(position);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetNormal() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNormal();
}

void Rendering::AreaLightEffectParameters::SetNormal(const ColourType& normal) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetNormal(normal);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetAxis0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAxis0();
}

void Rendering::AreaLightEffectParameters::SetAxis0(const ColourType& axis0) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAxis0(axis0);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetAxis1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAxis1();
}

void Rendering::AreaLightEffectParameters::SetAxis1(const ColourType& axis1) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAxis1(axis1);
}

Rendering::AreaLightEffectParameters::ColourType Rendering::AreaLightEffectParameters::GetExtent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetExtent();
}

void Rendering::AreaLightEffectParameters::SetExtent(const ColourType& extent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetExtent(extent);
}

int Rendering::AreaLightEffectParameters::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamingSize();
}

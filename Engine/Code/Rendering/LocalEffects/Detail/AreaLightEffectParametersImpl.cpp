/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:17)

#include "Rendering/RenderingExport.h"

#include "AreaLightEffectParametersImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::AreaLightEffectParametersImpl::AreaLightEffectParametersImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, AreaLightEffectParametersImpl)

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ambient;
}

void Rendering::AreaLightEffectParametersImpl::SetAmbient(const ColourType& aAmbient) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->ambient = aAmbient;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return diffuse;
}

void Rendering::AreaLightEffectParametersImpl::SetDiffuse(const ColourType& aDiffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->diffuse = aDiffuse;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return specular;
}

void Rendering::AreaLightEffectParametersImpl::SetSpecular(const ColourType& aSpecular) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->specular = aSpecular;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetAttenuation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return attenuation;
}

void Rendering::AreaLightEffectParametersImpl::SetAttenuation(const ColourType& aAttenuation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->attenuation = aAttenuation;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return position;
}

void Rendering::AreaLightEffectParametersImpl::SetPosition(const ColourType& aPosition) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->position = aPosition;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetNormal() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return normal;
}

void Rendering::AreaLightEffectParametersImpl::SetNormal(const ColourType& aNormal) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->normal = aNormal;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetAxis0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return axis0;
}

void Rendering::AreaLightEffectParametersImpl::SetAxis0(const ColourType& aAxis0) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->axis0 = aAxis0;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetAxis1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return axis1;
}

void Rendering::AreaLightEffectParametersImpl::SetAxis1(const ColourType& aAxis1) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->axis1 = aAxis1;
}

Rendering::AreaLightEffectParametersImpl::ColourType Rendering::AreaLightEffectParametersImpl::GetExtent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return extent;
}

void Rendering::AreaLightEffectParametersImpl::SetExtent(const ColourType& aExtent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    this->extent = aExtent;
}

int Rendering::AreaLightEffectParametersImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = Rendering::GetStreamSize(ambient);

    size += Rendering::GetStreamSize(diffuse);
    size += Rendering::GetStreamSize(specular);
    size += Rendering::GetStreamSize(attenuation);
    size += Rendering::GetStreamSize(position);
    size += Rendering::GetStreamSize(normal);
    size += Rendering::GetStreamSize(axis0);
    size += Rendering::GetStreamSize(axis1);
    size += Rendering::GetStreamSize(extent);

    return size;
}

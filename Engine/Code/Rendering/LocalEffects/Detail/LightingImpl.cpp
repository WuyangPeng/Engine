/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 20:31)

#include "Rendering/RenderingExport.h"

#include "LightingImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::LightingImpl::LightingImpl(float epsilon) noexcept
    : ambient{ 1.0f, 1.0f, 1.0f, 1.0f },
      diffuse{ 1.0f, 1.0f, 1.0f, 1.0f },
      specular{ 1.0f, 1.0f, 1.0f, 1.0f },
      angle{ Math::GetPI() / 2 },
      cosAngle{ 0.0f },
      sinAngle{ 1.0f },
      exponent{ 1.0f },
      constant{ 1.0f },
      linear{ 0.0f },
      quadratic{ 0.0f },
      intensity{ 1.0f },
      epsilon{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::LightingImpl::IsValid() const noexcept
{
    try
    {
        if (0 < angle && angle <= Math::GetPI() &&
            0 <= constant && 0 <= linear &&
            0 <= quadratic && 0 <= intensity &&
            Math::Approximate(cosAngle, Math::Cos(angle), epsilon) &&
            Math::Approximate(sinAngle, Math::Sin(angle), epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::LightingImpl::SetAngle(float aAngle)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0.0f < aAngle && aAngle <= Math::GetPI(), "Angle超出范围在SetAngle。\n");

    angle = aAngle;
    cosAngle = Math::Cos(aAngle);
    sinAngle = Math::Sin(aAngle);
}

void Rendering::LightingImpl::SetExponent(float aExponent) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    exponent = aExponent;
}

float Rendering::LightingImpl::GetAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return angle;
}

float Rendering::LightingImpl::GetCosAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return cosAngle;
}

float Rendering::LightingImpl::GetSinAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return sinAngle;
}

float Rendering::LightingImpl::GetExponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return exponent;
}

void Rendering::LightingImpl::SetAmbient(const Colour& aAmbient) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    ambient = aAmbient;
}

void Rendering::LightingImpl::SetDiffuse(const Colour& aDiffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    diffuse = aDiffuse;
}

void Rendering::LightingImpl::SetSpecular(const Colour& aSpecular) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    specular = aSpecular;
}

Rendering::LightingImpl::Colour Rendering::LightingImpl::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ambient;
}

Rendering::LightingImpl::Colour Rendering::LightingImpl::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return diffuse;
}

Rendering::LightingImpl::Colour Rendering::LightingImpl::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return specular;
}

float Rendering::LightingImpl::GetConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return constant;
}

float Rendering::LightingImpl::GetLinear() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return linear;
}

float Rendering::LightingImpl::GetQuadratic() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return quadratic;
}

float Rendering::LightingImpl::GetIntensity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return intensity;
}

void Rendering::LightingImpl::SetAttenuation(float aConstant, float aLinear, float aQuadratic, float aIntensity) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    constant = aConstant;
    linear = aLinear;
    quadratic = aQuadratic;
    intensity = aIntensity;
}

void Rendering::LightingImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadAggregate(ambient);
    source.ReadAggregate(diffuse);
    source.ReadAggregate(specular);
    source.Read(angle);
    source.Read(cosAngle);
    source.Read(sinAngle);
    source.Read(exponent);
    source.Read(constant);
    source.Read(linear);
    source.Read(quadratic);
    source.Read(intensity);
}

void Rendering::LightingImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregate(ambient);
    target.WriteAggregate(diffuse);
    target.WriteAggregate(specular);
    target.Write(angle);
    target.Write(cosAngle);
    target.Write(sinAngle);
    target.Write(exponent);
    target.Write(constant);
    target.Write(linear);
    target.Write(quadratic);
    target.Write(intensity);
}

int Rendering::LightingImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = GetStreamSize(ambient);

    size += GetStreamSize(diffuse);
    size += GetStreamSize(specular);
    size += GetStreamSize(angle);
    size += GetStreamSize(cosAngle);
    size += GetStreamSize(sinAngle);
    size += GetStreamSize(exponent);
    size += GetStreamSize(constant);
    size += GetStreamSize(linear);
    size += GetStreamSize(quadratic);
    size += GetStreamSize(intensity);

    return size;
}

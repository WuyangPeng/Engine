///	Copyright (c) 2010-2023
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 16:33)

#include "Rendering/RenderingExport.h"

#include "LightImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::LightImpl::LightImpl(float epsilon) noexcept
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

bool Rendering::LightImpl::IsValid() const noexcept
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

void Rendering::LightImpl::SetAngle(float aAngle)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0.0f < aAngle && aAngle <= Math::GetPI(), "Angle������Χ��SetAngle��\n");

    angle = aAngle;
    cosAngle = Math::Cos(aAngle);
    sinAngle = Math::Sin(aAngle);
}

void Rendering::LightImpl::SetExponent(float aExponent) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    exponent = aExponent;
}

float Rendering::LightImpl::GetAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return angle;
}

float Rendering::LightImpl::GetCosAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return cosAngle;
}

float Rendering::LightImpl::GetSinAngle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return sinAngle;
}

float Rendering::LightImpl::GetExponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return exponent;
}

void Rendering::LightImpl::SetAmbient(const Colour& aAmbient) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    ambient = aAmbient;
}

void Rendering::LightImpl::SetDiffuse(const Colour& aDiffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    diffuse = aDiffuse;
}

void Rendering::LightImpl::SetSpecular(const Colour& aSpecular) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    specular = aSpecular;
}

Rendering::LightImpl::Colour Rendering::LightImpl::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ambient;
}

Rendering::LightImpl::Colour Rendering::LightImpl::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return diffuse;
}

Rendering::LightImpl::Colour Rendering::LightImpl::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return specular;
}

float Rendering::LightImpl::GetConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return constant;
}

float Rendering::LightImpl::GetLinear() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return linear;
}

float Rendering::LightImpl::GetQuadratic() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return quadratic;
}

float Rendering::LightImpl::GetIntensity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return intensity;
}

void Rendering::LightImpl::SetAttenuation(float aConstant, float aLinear, float aQuadratic, float aIntensity) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    constant = aConstant;
    linear = aLinear;
    quadratic = aQuadratic;
    intensity = aIntensity;
}

void Rendering::LightImpl::Load(CoreTools::BufferSource& source)
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

void Rendering::LightImpl::Save(CoreTools::BufferTarget& target) const
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

int Rendering::LightImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = Rendering::GetStreamSize(ambient);

    size += Rendering::GetStreamSize(diffuse);
    size += Rendering::GetStreamSize(specular);
    size += CoreTools::GetStreamSize(angle);
    size += CoreTools::GetStreamSize(cosAngle);
    size += CoreTools::GetStreamSize(sinAngle);
    size += CoreTools::GetStreamSize(exponent);
    size += CoreTools::GetStreamSize(constant);
    size += CoreTools::GetStreamSize(linear);
    size += CoreTools::GetStreamSize(quadratic);
    size += CoreTools::GetStreamSize(intensity);

    return size;
}
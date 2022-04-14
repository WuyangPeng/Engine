///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 14:47)

#include "Rendering/RenderingExport.h"

#include "LightImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::LightImpl::LightImpl(LightType type, float epsilon) noexcept
    : ambient{ 0.0f, 0.0f, 0.0f, 1.0f },
      diffuse{ 0.0f, 0.0f, 0.0f, 1.0f },
      specular{ 0.0f, 0.0f, 0.0f, 1.0f },
      constant{ 1.0f },
      linear{ 0.0f },
      quadratic{ 0.0f },
      intensity{ 1.0f },
      angle{ Math::GetPI() },
      cosAngle{ -1.0f },
      sinAngle{ 0.0f },
      exponent{ 1.0f },
      position{ Mathematics::APointF::GetOrigin() },
      directionVector{ -Mathematics::AVectorF::GetUnitZ() },
      upVector{ Mathematics::AVectorF::GetUnitY() },
      rightVector{ Mathematics::AVectorF::GetUnitX() },
      lightType{ type },
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
            Math::Approximate(sinAngle, Math::Sin(angle), epsilon) &&
            Math::FAbs(Dot(directionVector, rightVector)) <= epsilon &&
            Math::FAbs(Dot(rightVector, upVector)) <= epsilon &&
            Math::FAbs(Dot(upVector, directionVector)) <= epsilon &&
            directionVector.IsNormalize(epsilon) &&
            rightVector.IsNormalize(epsilon) &&
            upVector.IsNormalize(epsilon))
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

void Rendering::LightImpl::SetType(LightType type) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    lightType = type;
}

Rendering::LightType Rendering::LightImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return lightType;
}

void Rendering::LightImpl::SetAngle(float aAngle)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0.0f < aAngle && aAngle <= Math::GetPI(), "Angle超出范围在SetAngle。\n");

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

Rendering::LightImpl::APoint Rendering::LightImpl::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return position;
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

void Rendering::LightImpl::SetPosition(const APoint& point) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    position = point;
}

void Rendering::LightImpl::SetVector(const AVector& up, const AVector& right, const AVector& direction) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    upVector = up;
    rightVector = right;
    directionVector = direction;
}

Rendering::LightImpl::AVector Rendering::LightImpl::GetDirectionVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return directionVector;
}

Rendering::LightImpl::AVector Rendering::LightImpl::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return upVector;
}

Rendering::LightImpl::AVector Rendering::LightImpl::GetRightVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return rightVector;
}

void Rendering::LightImpl::SetDirection(const AVector& direction)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto orthonormalBasis = GenerateOrthonormalBasis(direction, epsilon);

    upVector = orthonormalBasis.GetUVector();
    rightVector = orthonormalBasis.GetVVector();
    directionVector = orthonormalBasis.GetWVector();
}

void Rendering::LightImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadEnum(lightType);
    source.ReadAggregate(ambient);
    source.ReadAggregate(diffuse);
    source.ReadAggregate(specular);
    source.Read(constant);
    source.Read(linear);
    source.Read(quadratic);
    source.Read(intensity);
    source.Read(angle);
    source.Read(cosAngle);
    source.Read(sinAngle);
    source.Read(exponent);
    source.ReadAggregate(position);
    source.ReadAggregate(directionVector);
    source.ReadAggregate(upVector);
    source.ReadAggregate(rightVector);
}

void Rendering::LightImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteEnum(lightType);
    target.WriteAggregate(ambient);
    target.WriteAggregate(diffuse);
    target.WriteAggregate(specular);
    target.Write(constant);
    target.Write(linear);
    target.Write(quadratic);
    target.Write(intensity);
    target.Write(angle);
    target.Write(cosAngle);
    target.Write(sinAngle);
    target.Write(exponent);
    target.WriteAggregate(position);
    target.WriteAggregate(directionVector);
    target.WriteAggregate(upVector);
    target.WriteAggregate(rightVector);
}

int Rendering::LightImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(lightType);

    size += RENDERING_STREAM_SIZE(ambient);
    size += RENDERING_STREAM_SIZE(diffuse);
    size += RENDERING_STREAM_SIZE(specular);
    size += CORE_TOOLS_STREAM_SIZE(constant);
    size += CORE_TOOLS_STREAM_SIZE(linear);
    size += CORE_TOOLS_STREAM_SIZE(quadratic);
    size += CORE_TOOLS_STREAM_SIZE(intensity);
    size += CORE_TOOLS_STREAM_SIZE(angle);
    size += CORE_TOOLS_STREAM_SIZE(cosAngle);
    size += CORE_TOOLS_STREAM_SIZE(sinAngle);
    size += CORE_TOOLS_STREAM_SIZE(exponent);
    size += MATHEMATICS_STREAM_SIZE(position);
    size += MATHEMATICS_STREAM_SIZE(directionVector);
    size += MATHEMATICS_STREAM_SIZE(upVector);
    size += MATHEMATICS_STREAM_SIZE(rightVector);

    return size;
}

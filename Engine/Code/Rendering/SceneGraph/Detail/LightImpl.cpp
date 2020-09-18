// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 16:04)

#include "Rendering/RenderingExport.h"

#include "LightImpl.h"
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
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26440)
 
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::LightImpl ::LightImpl(LightType type, float epsilon) 
    : m_Ambient{ Colour{ 0.0f, 0.0f, 0.0f, 1.0f } }, m_Diffuse{ Colour{ 0.0f, 0.0f, 0.0f, 1.0f } }, m_Specular{ Colour{ 0.0f, 0.0f, 0.0f, 1.0f } },
      m_Constant{ 1.0f }, m_Linear{ 0.0f }, m_Quadratic{ 0.0f },
      m_Intensity{ 1.0f }, m_Angle{ Math::GetPI() }, m_CosAngle{ -1.0f },
      m_SinAngle{ 0.0f }, m_Exponent{ 1.0f }, m_Position{ Mathematics::Float::g_Origin },
      m_DirectionVector{ -Mathematics::Float::g_UnitZ }, m_UpVector{ Mathematics::Float::g_UnitY }, m_RightVector{ Mathematics::Float::g_UnitX },
      m_LightType{ type }, m_Epsilon{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::LightImpl ::IsValid() const noexcept
{
    try
    {
        if (0 < m_Angle && m_Angle <= Math::GetPI() &&
            0 <= m_Constant && 0 <= m_Linear &&
            0 <= m_Quadratic && 0 <= m_Intensity &&
            Math::Approximate(m_CosAngle, Math::Cos(m_Angle), m_Epsilon) &&
            Math::Approximate(m_SinAngle, Math::Sin(m_Angle), m_Epsilon) &&
            Math::FAbs(Dot(m_DirectionVector, m_RightVector)) <= m_Epsilon &&
            Math::FAbs(Dot(m_RightVector, m_UpVector)) <= m_Epsilon &&
            Math::FAbs(Dot(m_UpVector, m_DirectionVector)) <= m_Epsilon &&
            m_DirectionVector.IsNormalize(m_Epsilon) &&
            m_RightVector.IsNormalize(m_Epsilon) &&
            m_UpVector.IsNormalize(m_Epsilon))
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

void Rendering::LightImpl ::SetType(LightType type)
{
    RENDERING_CLASS_IS_VALID_1;

    m_LightType = type;
}

Rendering::LightType Rendering::LightImpl ::GetType() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_LightType;
}

void Rendering::LightImpl ::SetAngle(float angle)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(0.0f < angle && angle <= Math::GetPI(), "Angle≥¨≥ˆ∑∂Œß‘⁄SetAngle°£\n");

    m_Angle = angle;
    m_CosAngle = Math::Cos(angle);
    m_SinAngle = Math::Sin(angle);
}

void Rendering::LightImpl ::SetExponent(float exponent)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Exponent = exponent;
}

float Rendering::LightImpl ::GetAngle() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Angle;
}

float Rendering::LightImpl ::GetCosAngle() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_CosAngle;
}

float Rendering::LightImpl ::GetSinAngle() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_SinAngle;
}

float Rendering::LightImpl ::GetExponent() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Exponent;
}

void Rendering::LightImpl ::SetAmbient(const Colour& ambient)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Ambient = ambient;
}

void Rendering::LightImpl ::SetDiffuse(const Colour& diffuse)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Diffuse = diffuse;
}

void Rendering::LightImpl ::SetSpecular(const Colour& specular)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Specular = specular;
}

const Rendering::LightImpl::Colour Rendering::LightImpl ::GetAmbient() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Ambient;
}

const Rendering::LightImpl::Colour Rendering::LightImpl ::GetDiffuse() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Diffuse;
}

const Rendering::LightImpl::Colour Rendering::LightImpl ::GetSpecular() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Specular;
}

const Rendering::LightImpl::APoint Rendering::LightImpl::GetPosition() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Position;
}

float Rendering::LightImpl ::GetConstant() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Constant;
}

float Rendering::LightImpl ::GetLinear() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Linear;
}

float Rendering::LightImpl ::GetQuadratic() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Quadratic;
}

float Rendering::LightImpl ::GetIntensity() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Intensity;
}

void Rendering::LightImpl ::SetAttenuation(float constant, float linear, float quadratic, float intensity)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Constant = constant;
    m_Linear = linear;
    m_Quadratic = quadratic;
    m_Intensity = intensity;
}

void Rendering::LightImpl ::SetPosition(const APoint& point)
{
    RENDERING_CLASS_IS_VALID_1;

    m_Position = point;
}

void Rendering::LightImpl ::SetVector(const AVector& up, const AVector& right, const AVector& direction)
{
    RENDERING_CLASS_IS_VALID_1;

    m_UpVector = up;
    m_RightVector = right;
    m_DirectionVector = direction;
}

const Rendering::LightImpl::AVector Rendering::LightImpl ::GetDirectionVector() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_DirectionVector;
}

const Rendering::LightImpl::AVector Rendering::LightImpl ::GetUpVector() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_UpVector;
}

const Rendering::LightImpl::AVector Rendering::LightImpl ::GetRightVector() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_RightVector;
}

void Rendering::LightImpl ::SetDirection(const AVector& direction)
{
    RENDERING_CLASS_IS_VALID_1;

const auto orthonormalBasis = GenerateOrthonormalBasis(direction, m_Epsilon);

    m_UpVector = orthonormalBasis.GetUVector();
    m_RightVector = orthonormalBasis.GetVVector();
    m_DirectionVector = orthonormalBasis.GetWVector();
}

void Rendering::LightImpl ::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadEnum(m_LightType);
    source.ReadAggregate(m_Ambient);
    source.ReadAggregate(m_Diffuse);
    source.ReadAggregate(m_Specular);
    source.Read(m_Constant);
    source.Read(m_Linear);
    source.Read(m_Quadratic);
    source.Read(m_Intensity);
    source.Read(m_Angle);
    source.Read(m_CosAngle);
    source.Read(m_SinAngle);
    source.Read(m_Exponent);
    source.ReadAggregate(m_Position);
    source.ReadAggregate(m_DirectionVector);
    source.ReadAggregate(m_UpVector);
    source.ReadAggregate(m_RightVector);
}

void Rendering::LightImpl ::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target->WriteEnum(m_LightType);
    target->WriteAggregate(m_Ambient);
    target->WriteAggregate(m_Diffuse);
    target->WriteAggregate(m_Specular);
    target->Write(m_Constant);
    target->Write(m_Linear);
    target->Write(m_Quadratic);
    target->Write(m_Intensity);
    target->Write(m_Angle);
    target->Write(m_CosAngle);
    target->Write(m_SinAngle);
    target->Write(m_Exponent);
    target->WriteAggregate(m_Position);
    target->WriteAggregate(m_DirectionVector);
    target->WriteAggregate(m_UpVector);
    target->WriteAggregate(m_RightVector);
}

int Rendering::LightImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(m_LightType);

    size += RENDERING_STREAM_SIZE(m_Ambient);
    size += RENDERING_STREAM_SIZE(m_Diffuse);
    size += RENDERING_STREAM_SIZE(m_Specular);
    size += CORE_TOOLS_STREAM_SIZE(m_Constant);
    size += CORE_TOOLS_STREAM_SIZE(m_Linear);
    size += CORE_TOOLS_STREAM_SIZE(m_Quadratic);
    size += CORE_TOOLS_STREAM_SIZE(m_Intensity);
    size += CORE_TOOLS_STREAM_SIZE(m_Angle);
    size += CORE_TOOLS_STREAM_SIZE(m_CosAngle);
    size += CORE_TOOLS_STREAM_SIZE(m_SinAngle);
    size += CORE_TOOLS_STREAM_SIZE(m_Exponent);
    size += MATHEMATICS_STREAM_SIZE(m_Position);
    size += MATHEMATICS_STREAM_SIZE(m_DirectionVector);
    size += MATHEMATICS_STREAM_SIZE(m_UpVector);
    size += MATHEMATICS_STREAM_SIZE(m_RightVector);

    return size;
}
#include STSTEM_WARNING_POP
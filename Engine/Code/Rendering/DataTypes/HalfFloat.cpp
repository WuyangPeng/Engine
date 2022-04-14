///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 13:56)

#include "Rendering/RenderingExport.h"

#include "HalfFloat.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/util>
#include <iostream>

using std::ostream;

Rendering::HalfFloat::HalfFloat(float value) noexcept
    : halfFloat{ ConvertHalfFloat(value) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::HalfFloat::HalfFloat(int value)
    : halfFloat{ ConvertHalfFloat(boost::numeric_cast<float>(value)) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

// static
Rendering::HalfFloat::OriginalType Rendering::HalfFloat::ConvertHalfFloat(float value) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)  // 这里必须使用reinterpret_cast

    const auto bits = reinterpret_cast<FloatIntegerType&>(value);

#include STSTEM_WARNING_POP

    auto halfExponent = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::exponent) >> FloatTraitsType::exponentShifting);
    if (exponentDifference < halfExponent)
    {
        constexpr auto maxExponent = exponentDifference + ((1 << exponentDigits) - 1);
        if (halfExponent < maxExponent)
        {
            if (halfExponent != 0)
            {
                // 截断23位小数到10位。
                const auto sign = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::symbol) >> symbolShiftingDifference);
                const auto halfMantissa = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::mantissa) >> exponentShiftingDifference);
                halfExponent = (halfExponent - exponentDifference) << exponentShifting;
                return sign | halfExponent | halfMantissa;
            }
            else
            {
                // E = 0 (替代编码为0,, M并不重要)
                return OriginalType{ 0 };
            }
        }
        else
        {
            // E = 30, M = 1023 (半浮点数的最大量级)
            const auto sign = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::symbol) >> symbolShiftingDifference);
            return sign | gsl::narrow_cast<OriginalType>(exponent - 1);
        }
    }
    else
    {
        // E = 1, M = 0 (半浮点数的最小量级)
        const auto sign = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::symbol) >> symbolShiftingDifference);
        return sign | gsl::narrow_cast<OriginalType>(1 << exponentShifting);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, HalfFloat)

float Rendering::HalfFloat::ToFloat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto halfExponent = gsl::narrow_cast<FloatIntegerType>(halfFloat & exponent) >> exponentShifting;
    if (halfExponent != 0)
    {
        const auto sign = gsl::narrow_cast<FloatIntegerType>(halfFloat & symbol) << symbolShiftingDifference;
        const auto halfMantissa = gsl::narrow_cast<FloatIntegerType>(halfFloat & mantissa) << exponentShiftingDifference;
        halfExponent = (halfExponent + exponentDifference) << FloatTraitsType::exponentShifting;
        const auto result = sign | halfExponent | halfMantissa;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)  // 这里必须使用reinterpret_cast

        return reinterpret_cast<const float&>(result);

#include STSTEM_WARNING_POP
    }
    else
    {
        // E = 0 (替代编码为0,, M并不重要)
        return 0.0f;
    }
}

Rendering::HalfFloat::OriginalType Rendering::HalfFloat::ToOriginalType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return halfFloat;
}

Rendering::HalfFloat Rendering::HalfFloat::operator-() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto value = -ToFloat();

    return HalfFloat{ value };
}

Rendering::HalfFloat& Rendering::HalfFloat::operator+=(const HalfFloat& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto value = ToFloat();

    value += rhs.ToFloat();

    halfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat::operator-=(const HalfFloat& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto value = ToFloat();

    value -= rhs.ToFloat();

    halfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat::operator*=(const HalfFloat& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto value = ToFloat();

    value *= rhs.ToFloat();

    halfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat::operator/=(const HalfFloat& rhs)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (halfFloat != 0)
    {
        auto value = ToFloat();

        value /= rhs.ToFloat();

        halfFloat = ConvertHalfFloat(value);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    return *this;
}

bool Rendering::operator==(const HalfFloat& lhs, const HalfFloat& rhs) noexcept
{
    if (lhs.ToOriginalType() == rhs.ToOriginalType())
        return true;
    else
        return false;
}

bool Rendering::operator<(const HalfFloat& lhs, const HalfFloat& rhs) noexcept
{
    if (lhs.ToFloat() < rhs.ToFloat())
        return true;
    else
        return false;
}

bool Rendering::Approximate(const HalfFloat& lhs, const HalfFloat& rhs, const float epsilon) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    if (Mathematics::MathF::Approximate(lhs.ToFloat(), rhs.ToFloat(), epsilon))
        return true;
    else
        return false;
}

ostream& Rendering::operator<<(ostream& outFile, const HalfFloat& halfFloat)
{
    outFile << halfFloat.ToFloat();

    return outFile;
}

float Rendering::operator*(float lhs, const HalfFloat& rhs) noexcept
{
    return lhs * rhs.ToFloat();
}

float Rendering::operator*(const HalfFloat& lhs, float rhs) noexcept
{
    return lhs.ToFloat() * rhs;
}

float Rendering::operator/(float lhs, const HalfFloat& rhs)
{
    if (rhs.ToOriginalType() != 0)
    {
        return lhs / rhs.ToFloat();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }
}

Rendering::HalfFloat Rendering::FAbs(const HalfFloat& value) noexcept
{
    return Rendering::HalfFloat{ Mathematics::MathF::FAbs(value.ToFloat()) };
}

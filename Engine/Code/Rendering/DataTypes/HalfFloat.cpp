//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/23 21:11)

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
    : m_HalfFloat{ ConvertHalfFloat(value) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::HalfFloat::HalfFloat(int value)
    : m_HalfFloat{ ConvertHalfFloat(boost::numeric_cast<float>(value)) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

// static
Rendering::HalfFloat::OriginalType Rendering::HalfFloat::ConvertHalfFloat(float value) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)  // 这里必须使用reinterpret_cast
    const auto bits = reinterpret_cast<IntegerType&>(value);
#include STSTEM_WARNING_POP

    auto exponent = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::exponent) >> FloatTraitsType::exponentShifting);
    if (g_ExponentDifference < exponent)
    {
        constexpr auto maxExponent = g_ExponentDifference + ((1 << g_ExponentDigits) - 1);
        if (exponent < maxExponent)
        {
            if (exponent != 0)
            {
                // 截断23位小数到10位。
                const auto sign = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::symbol) >> g_SymbolShiftingDifference);
                const auto mantissa = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::mantissa) >> g_ExponentShiftingDifference);
                exponent = (exponent - g_ExponentDifference) << g_ExponentShifting;
                return sign | exponent | mantissa;
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
            const auto sign = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::symbol) >> g_SymbolShiftingDifference);
            return sign | gsl::narrow_cast<OriginalType>(g_Exponent - 1);
        }
    }
    else
    {
        // E = 1, M = 0 (半浮点数的最小量级)
        const auto sign = gsl::narrow_cast<OriginalType>((bits & FloatTraitsType::symbol) >> g_SymbolShiftingDifference);
        return sign | gsl::narrow_cast<OriginalType>(1 << g_ExponentShifting);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, HalfFloat)

float Rendering::HalfFloat::ToFloat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto exponent = gsl::narrow_cast<FloatIntegerType>(m_HalfFloat & g_Exponent) >> g_ExponentShifting;
    if (exponent != 0)
    {
        const auto sign = gsl::narrow_cast<FloatIntegerType>(m_HalfFloat & g_Symbol) << g_SymbolShiftingDifference;
        const auto mantissa = gsl::narrow_cast<FloatIntegerType>(m_HalfFloat & g_Mantissa) << g_ExponentShiftingDifference;
        exponent = (exponent + g_ExponentDifference) << FloatTraitsType::exponentShifting;
        const auto result = sign | exponent | mantissa;

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

    return m_HalfFloat;
}

const Rendering::HalfFloat Rendering::HalfFloat::operator-() const noexcept
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

    m_HalfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat::operator-=(const HalfFloat& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto value = ToFloat();

    value -= rhs.ToFloat();

    m_HalfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat::operator*=(const HalfFloat& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto value = ToFloat();

    value *= rhs.ToFloat();

    m_HalfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat::operator/=(const HalfFloat& rhs)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (m_HalfFloat != 0)
    {
        auto value = ToFloat();

        value /= rhs.ToFloat();

        m_HalfFloat = ConvertHalfFloat(value);
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

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 16:36)

#include "Mathematics/MathematicsExport.h"

#include "Constants.h"
#include "Functions.h"

#include <cmath>

float Mathematics::AtanDivPi(float x) noexcept
{
    return std::atan(x) * invPi<float>;
}

float Mathematics::Atan2DivPi(float y, float x) noexcept
{
    return std::atan2(y, x) * invPi<float>;
}

float Mathematics::CosPi(float x) noexcept
{
    return std::cos(x * pi<float>);
}

float Mathematics::Exp10(float x) noexcept
{
    return std::exp(x * ln10<float>);
}

float Mathematics::InvSqrt(float x) noexcept
{
    return 1.0f / std::sqrt(x);
}

float Mathematics::SinPi(float x) noexcept
{
    return std::sin(x * pi<float>);
}

float Mathematics::Fma(float u, float v, float w) noexcept
{
#if defined(MATHEMATICS_DISCARD_FMA)

    return u * v + w;

#else  // !MATHEMATICS_DISCARD_FMA

    return std::fma(u, v, w);

#endif  // MATHEMATICS_DISCARD_FMA
}

float Mathematics::RobustSop(float u, float v, float w, float z) noexcept
{
#if defined(MATHEMATICS_DISCARD_FMA)

    return u * v + w * z;

#else  // !MATHEMATICS_DISCARD_FMA

    const auto productWz = w * z;
    const auto roundingError = std::fma(w, z, -productWz);
    const auto result = std::fma(u, v, productWz) + roundingError;

    return result;

#endif  // MATHEMATICS_DISCARD_FMA
}

float Mathematics::RobustDop(float u, float v, float w, float z) noexcept
{
#if defined(MATHEMATICS_DISCARD_FMA)

    return u * v - w * z.

#else  // !MATHEMATICS_DISCARD_FMA

    const auto productWz = w * z;
    const auto roundingError = std::fma(-w, z, productWz);
    const auto result = std::fma(u, v, -productWz) + roundingError;

    return result;

#endif  // MATHEMATICS_DISCARD_FMA
}

double Mathematics::AtanDivPi(double x) noexcept
{
    return std::atan(x) * invPi<double>;
}

double Mathematics::Atan2DivPi(double y, double x) noexcept
{
    return std::atan2(y, x) * invPi<double>;
}

double Mathematics::CosPi(double x) noexcept
{
    return std::cos(x * pi<double>);
}

double Mathematics::Exp10(double x) noexcept
{
    return std::exp(x * ln10<double>);
}

double Mathematics::InvSqrt(double x) noexcept
{
    return 1.0f / std::sqrt(x);
}

double Mathematics::SinPi(double x) noexcept
{
    return std::sin(x * pi<double>);
}

double Mathematics::Fma(double u, double v, double w) noexcept
{
#if defined(MATHEMATICS_DISCARD_FMA)

    return u * v + w;

#else  // !MATHEMATICS_DISCARD_FMA

    return std::fma(u, v, w);

#endif  // MATHEMATICS_DISCARD_FMA
}

double Mathematics::RobustSop(double u, double v, double w, double z) noexcept
{
#if defined(MATHEMATICS_DISCARD_FMA)

    return u * v + w * z;

#else  // !MATHEMATICS_DISCARD_FMA

    const auto productWz = w * z;
    const auto roundingError = std::fma(w, z, -productWz);
    const auto result = std::fma(u, v, productWz) + roundingError;

    return result;

#endif  // MATHEMATICS_DISCARD_FMA
}

double Mathematics::RobustDop(double u, double v, double w, double z) noexcept
{
#if defined(MATHEMATICS_DISCARD_FMA)

    return u * v - w * z.

#else  // !MATHEMATICS_DISCARD_FMA

    const auto productWz = w * z;
    const auto roundingError = std::fma(-w, z, productWz);
    const auto result = std::fma(u, v, -productWz) + roundingError;

    return result;

#endif  // MATHEMATICS_DISCARD_FMA
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 16:35)

#ifndef MATHEMATICS_BASE_FUNCTIONS_H
#define MATHEMATICS_BASE_FUNCTIONS_H

#include "Mathematics/MathematicsDll.h"

/// 这些功能对某些应用程序来说很方便。
/// 类BSNumber、BSRational和IEEEBinary16的实现（目前）使用类型转换来调用“float”或“double”版本。
namespace Mathematics
{
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE AtanDivPi(float x) noexcept;

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE Atan2DivPi(float y, float x) noexcept;

    NODISCARD constexpr float Clamp(float x, float xMin, float xMax) noexcept
    {
        return (x <= xMin ? xMin : (xMax <= x ? xMax : x));
    }

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE CosPi(float x) noexcept;

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE Exp10(float x) noexcept;

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE InvSqrt(float x) noexcept;

    NODISCARD constexpr int SignToInt(float x) noexcept
    {
        return (0.0f < x ? 1 : (x < 0.0f ? -1 : 0));
    }

    NODISCARD constexpr float Saturate(float x) noexcept
    {
        return (x <= 0.0f ? 0.0f : (1.0f <= x ? 1.0f : x));
    }

    NODISCARD constexpr float Sign(float x) noexcept
    {
        return (0.0f < x ? 1.0f : (x < 0.0f ? -1.0f : 0.0f));
    }

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE SinPi(float x) noexcept;

    NODISCARD constexpr float Sqr(float x) noexcept
    {
        return x * x;
    }

    /// 将 x * y + z计算为单个运算。
    /// 如果浮点硬件支持融合乘加（fma）指令，则会调用std:：fma函数。
    /// 如果您的硬件不支持fma指令，并且编译器将其映射到软件实现，
    /// 则可以定义MATHEMATICS_DISCARD_FMA以避免软件中的计算成本。
    /// 如果编译器忽略该指令并使用2个浮点运算计算表达式，
    /// 则是否定义GTE_DISCARD_FMA无关紧要。
    /// TODO:使用BSNumber的思想为fma添加预处理器选择的软件实现，
    /// 整数类型为UIntegerFP32，N足够大。
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE Fma(float u, float v, float w) noexcept;

    /// 稳健乘积和(SOP) u * v + w * z。
    /// 只有当暴露std::fma时（未定义MATHEMATICS_DISCARD_FMA），才会出现稳健。
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE RobustSop(float u, float v, float w, float z) noexcept;

    /// 稳健乘积差(DOP) u * v - w * z。
    /// 只有当暴露std::fma时（未定义MATHEMATICS_DISCARD_FMA），才会出现稳健。
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE RobustDop(float u, float v, float w, float z) noexcept;

    NODISCARD double MATHEMATICS_DEFAULT_DECLARE AtanDivPi(double x) noexcept;

    NODISCARD double MATHEMATICS_DEFAULT_DECLARE Atan2DivPi(double y, double x) noexcept;

    NODISCARD constexpr double Clamp(double x, double xMin, double xMax) noexcept
    {
        return (x <= xMin ? xMin : (xMax <= x ? xMax : x));
    }

    NODISCARD double MATHEMATICS_DEFAULT_DECLARE CosPi(double x) noexcept;

    NODISCARD double MATHEMATICS_DEFAULT_DECLARE Exp10(double x) noexcept;

    NODISCARD double MATHEMATICS_DEFAULT_DECLARE InvSqrt(double x) noexcept;

    NODISCARD constexpr int SignToInt(double x) noexcept
    {
        return (0.0f < x ? 1 : (x < 0.0f ? -1 : 0));
    }

    NODISCARD constexpr double Saturate(double x) noexcept
    {
        return (x <= 0.0f ? 0.0f : (1.0f <= x ? 1.0f : x));
    }

    NODISCARD constexpr double Sign(double x) noexcept
    {
        return (0.0f < x ? 1.0f : (x < 0.0f ? -1.0f : 0.0f));
    }

    NODISCARD double MATHEMATICS_DEFAULT_DECLARE SinPi(double x) noexcept;

    NODISCARD constexpr double Sqr(double x) noexcept
    {
        return x * x;
    }

    /// 将 x * y + z计算为单个运算。
    /// 如果浮点硬件支持融合乘加（fma）指令，则会调用std:：fma函数。
    /// 如果您的硬件不支持fma指令，并且编译器将其映射到软件实现，
    /// 则可以定义MATHEMATICS_DISCARD_FMA以避免软件中的计算成本。
    /// 如果编译器忽略该指令并使用2个浮点运算计算表达式，
    /// 则是否定义GTE_DISCARD_FMA无关紧要。
    /// TODO:使用BSNumber的思想为fma添加预处理器选择的软件实现，
    /// 整数类型为UIntegerFP32，N足够大。
    NODISCARD double MATHEMATICS_DEFAULT_DECLARE Fma(double u, double v, double w) noexcept;

    /// 稳健乘积和(SOP) u * v + w * z。
    /// 只有当暴露std::fma时（未定义MATHEMATICS_DISCARD_FMA），才会出现稳健。
    NODISCARD double MATHEMATICS_DEFAULT_DECLARE RobustSop(double u, double v, double w, double z) noexcept;

    /// 稳健乘积差(DOP) u * v - w * z。
    /// 只有当暴露std::fma时（未定义MATHEMATICS_DISCARD_FMA），才会出现稳健。
    NODISCARD double MATHEMATICS_DEFAULT_DECLARE RobustDop(double u, double v, double w, double z) noexcept;
}

#endif  // MATHEMATICS_BASE_FUNCTIONS_H

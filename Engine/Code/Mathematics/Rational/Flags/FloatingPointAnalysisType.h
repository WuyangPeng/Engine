/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:28)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H

namespace Mathematics
{
    enum class FloatingPointAnalysisType
    {
        Valid,  // (1 <= exponent) && (exponent <= 254)
        Zero,  // (exponent == 0)
        Infinity,  // (exponent == 255) && (mantissa == 0)
        QuietNaN,  //(exponent == 255) && (mantissa & 0x00400000)
        SignalingNaN,  // (exponent == 255) && (mantissa & 0x003FFFFF)
    };

    /// 数字的类型。
    enum class Classification
    {
        NegInfinity,
        NegSubnormal,
        NegNormal,
        NegZero,
        PosZero,
        PosSubnormal,
        PosNormal,
        PosInfinity,
        QuietNan,
        SignalingNan
    };

    enum class BinaryScientificPrecisionType
    {
        IsFloat,
        IsDouble,
        IsInt32,
        IsInt64,
        IsUInt32,
        IsUInt64,
    };
}

#endif  // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H

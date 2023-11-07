///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 20:04)

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
}

#endif  // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_TYPE_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:03)

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

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 18:48)

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

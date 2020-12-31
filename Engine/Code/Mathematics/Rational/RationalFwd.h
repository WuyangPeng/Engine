///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 13:56)

#ifndef MATHEMATICS_RATIONAL_FWD_H
#define MATHEMATICS_RATIONAL_FWD_H

namespace Mathematics
{
    template <typename T>
    class FloatingPointAnalysis;

    template <typename T>
    class ConversionInteger;

    template <int N>
    class IntegerData;

    template <int N>
    class IntegerDataAnalysis;

    template <int N>
    class IntegerDataOperator;

    template <int N>
    class IntegerDivisionModulo;

    template <int N>
    class IntegerMultiplication;

    template <int N, typename T>
    class IntegerDataConversion;

    template <int N>
    class Integer;

    template <int N, typename T>
    class RationalConversion;

    template <int N, typename T>
    class RationalConversion;

    template <int N>
    class SignRational;

    template <int VectorSize>
    class Int64Vector;

    class Int64Vector2;
    class Int64Vector3;

    template <int VectorSize, int IntSize>
    class RationalVector;

    template <int IntSize>
    class RationalVector2;

    template <int IntSize>
    class RationalVector3;

    enum class FloatingPointAnalysisType;
}

#endif  // MATHEMATICS_RATIONAL_FWD_H
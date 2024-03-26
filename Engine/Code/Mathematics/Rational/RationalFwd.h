/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:29)

#ifndef MATHEMATICS_RATIONAL_FWD_H
#define MATHEMATICS_RATIONAL_FWD_H

#include "CoreTools/MemoryTools/TypeTraits.h"

namespace Mathematics
{
    enum class FloatingPointAnalysisType;
    enum class Classification;
    enum class BinaryScientificPrecisionType;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FloatingPointAnalysis;

    template <typename T>
    class ConversionInteger;

    template <typename T>
    class ConversionRational;

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

    template <int N>
    class IntegerDivisionMultiple;

    template <int N>
    class IntegerDataAmend;

    template <int N, typename T>
    class IntegerDataConversion;

    template <int N>
    class Integer;

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

    template <typename T>
    class SortPointsOnCircle;

    template <typename T>
    class CircleSortObject;

    template <typename Real, int N>
    requires(0 < N)
    class QuadraticFieldsNumber;

    template <typename Float, typename UInt, int NumBits, int Precision>
    requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
    class IeeeBinary;

    class IeeeBinary16;

    template <typename UInteger>
    class UIntegerArithmeticLogicUnit32;

    class UIntegerArbitraryPrecision32;

    template <int N>
    requires(0 < N)
    class UIntegerFixedPrecision32;

    template <typename UInteger>
    class BinaryScientificNumber;

    template <typename UInteger>
    class BinaryScientificRational;

    class PrecisionParameters;
    class BinaryScientificPrecision;

    template <typename ArbitraryPrecisionType>
    requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
    class ArbitraryPrecisionInterval;

    template <typename FloatingPointType>
    requires(std::is_floating_point_v<FloatingPointType>)
    class FloatingPointInterval;

    template <typename T>
    requires(std::is_floating_point_v<T>)
    class SwInterval;

    template <typename Rational>
    class ArbitraryPrecisionConversion;
}

#endif  // MATHEMATICS_RATIONAL_FWD_H
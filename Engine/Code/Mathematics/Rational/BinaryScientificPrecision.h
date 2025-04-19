/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 16:09)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_BINARY_SCIENTIFIC_PRECISION_H
#define MATHEMATICS_RATIONAL_RATIONAL_BINARY_SCIENTIFIC_PRECISION_H

#include "Mathematics/MathematicsDll.h"

#include "PrecisionParameters.h"
#include "RationalFwd.h"

#include <algorithm>

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BinaryScientificPrecision
    {
    public:
        using ClassType = BinaryScientificPrecision;

    public:
        BinaryScientificPrecision() noexcept;
        BinaryScientificPrecision(int minExponent, int maxExponent, int maxBits) noexcept;
        explicit BinaryScientificPrecision(BinaryScientificPrecisionType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD PrecisionParameters GetBsn() const noexcept;
        NODISCARD PrecisionParameters GetBsr() const noexcept;
        void SetBsn(const PrecisionParameters& aBsn) noexcept;
        void SetBsr(const PrecisionParameters& aBsr) noexcept;
        void SetBsn(int minExponent, int maxExponent, int maxBits) noexcept;
        void SetBsr(int minExponent, int maxExponent, int maxBits) noexcept;

    private:
        PrecisionParameters bsn;
        PrecisionParameters bsr;
    };

    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator+(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator-(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator*(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator/(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;

    /// BinaryScientificNumber的比较不涉及动态分配，
    /// 因此结果是输入的极端值。
    /// BinaryScientificRational的比较涉及分子和分母的乘积。
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator==(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator!=(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator<(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator<=(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator>(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
    NODISCARD BinaryScientificPrecision MATHEMATICS_DEFAULT_DECLARE operator>=(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_BINARY_SCIENTIFIC_PRECISION_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:29)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "SignRational.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <iosfwd>

namespace Mathematics
{
    template <int VectorSize, int IntSize>
    class RationalVector final : private boost::additive<RationalVector<VectorSize, IntSize>, boost::totally_ordered<RationalVector<VectorSize, IntSize>, boost::multiplicative<RationalVector<VectorSize, IntSize>, SignRational<IntSize>>>>
    {
    public:
        using ClassType = RationalVector<VectorSize, IntSize>;

        using Rational = SignRational<IntSize>;

    public:
        RationalVector() noexcept;
        RationalVector(Rational x, Rational y) noexcept;
        RationalVector(Rational x, Rational y, Rational z) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Rational& operator[](int index) const;
        NODISCARD Rational& operator[](int index);

        NODISCARD RationalVector operator-() const;
        RationalVector& operator+=(const RationalVector& rhs);
        RationalVector& operator-=(const RationalVector& rhs);
        RationalVector& operator*=(const Rational& scalar);
        RationalVector& operator/=(const Rational& scalar);

        NODISCARD Rational SquaredLength() const;

    private:
        using ArrayType = std::array<Rational, VectorSize>;

    private:
        ArrayType tuple;
    };

    template <int VectorSize, int IntSize>
    NODISCARD SignRational<IntSize> Dot(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs);

    template <int VectorSize, int IntSize>
    NODISCARD bool operator==(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs);

    template <int VectorSize, int IntSize>
    NODISCARD bool operator<(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs);

    template <int VectorSize, int IntSize>
    std::ostream& operator<<(std::ostream& os, const RationalVector<VectorSize, IntSize>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_VECTOR_H

///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:44)

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

        [[nodiscard]] const Rational& operator[](int index) const;
        [[nodiscard]] Rational& operator[](int index);

        [[nodiscard]] const RationalVector operator-() const;
        RationalVector& operator+=(const RationalVector& rhs);
        RationalVector& operator-=(const RationalVector& rhs);
        RationalVector& operator*=(const Rational& scalar);
        RationalVector& operator/=(const Rational& scalar);

        [[nodiscard]] Rational SquaredLength() const;

    private:
        using ArrayType = std::array<Rational, VectorSize>;

    private:
        ArrayType m_Tuple;
    };

    template <int VectorSize, int IntSize>
    [[nodiscard]] SignRational<IntSize> Dot(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs);

    template <int VectorSize, int IntSize>
    [[nodiscard]] bool operator==(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs);

    template <int VectorSize, int IntSize>
    [[nodiscard]] bool operator<(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs);

    template <int VectorSize, int IntSize>
    std::ostream& operator<<(std::ostream& os, const RationalVector<VectorSize, IntSize>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_VECTOR_H

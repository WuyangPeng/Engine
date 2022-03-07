///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 17:14)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_H

#include "Mathematics/MathematicsDll.h"

#include "RationalVector.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <iosfwd>

namespace Mathematics
{
    template <int IntSize>
    class RationalVector3 final : private boost::additive<RationalVector3<IntSize>, boost::totally_ordered<RationalVector3<IntSize>, boost::multiplicative<RationalVector3<IntSize>, SignRational<IntSize>>>>
    {
    public:
        using ClassType = RationalVector3<IntSize>;
        using Rational = SignRational<IntSize>;
        using RationalVector = RationalVector<3, IntSize>;

    public:
        RationalVector3() noexcept;

        explicit RationalVector3(const RationalVector& rhs) noexcept;
        RationalVector3(const Rational& x, const Rational& y, const Rational& z) noexcept;

        RationalVector3& operator=(const RationalVector& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Rational GetX() const;
        void SetX(const Rational& x);
        NODISCARD Rational GetY() const;
        void SetY(const Rational& y);
        NODISCARD Rational GetZ() const;
        void SetZ(const Rational& z);

        NODISCARD RationalVector3 operator-() const;

        RationalVector3& operator+=(const RationalVector3& rhs);
        RationalVector3& operator-=(const RationalVector3& rhs);
        RationalVector3& operator*=(const Rational& rational);
        RationalVector3& operator/=(const Rational& rational);

        NODISCARD Rational SquaredLength() const;

    private:
        RationalVector tuple;
    };

    // 返回 Dot(lhs,rhs).
    template <int IntSize>
    NODISCARD SignRational<IntSize> Dot(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs);

    // 返回 Cross(lhs,rhs).
    template <int IntSize>
    NODISCARD RationalVector3<IntSize> Cross(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs);

    // 返回 Dot(lhs,Cross(mhs,rhs)).
    template <int IntSize>
    NODISCARD SignRational<IntSize> TripleScalar(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& mhs, const RationalVector3<IntSize>& rhs);

    template <int IntSize>
    NODISCARD bool operator==(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs);

    template <int IntSize>
    NODISCARD bool operator<(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs);

    template <int IntSize>
    std::ostream& operator<<(std::ostream& os, const RationalVector3<IntSize>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_H

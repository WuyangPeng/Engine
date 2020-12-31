///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 11:04)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "RationalVector.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <iosfwd>

namespace Mathematics
{
    template <int IntSize>
    class RationalVector2 final : private boost::additive<RationalVector2<IntSize>, boost::totally_ordered<RationalVector2<IntSize>, boost::multiplicative<RationalVector2<IntSize>, SignRational<IntSize>>>>
    {
    public:
        using ClassType = RationalVector2<IntSize>;
        using Rational = SignRational<IntSize>;
        using RationalVector = RationalVector<2, IntSize>;

    public:
        RationalVector2() noexcept;

        explicit RationalVector2(const RationalVector& rhs) noexcept;
        RationalVector2(const Rational& x, const Rational& y) noexcept;

        RationalVector2& operator=(const RationalVector& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Rational GetX() const;
        void SetX(const Rational& x);
        [[nodiscard]] const Rational GetY() const;
        void SetY(const Rational& y);

        [[nodiscard]] const RationalVector2 operator-() const;

        RationalVector2& operator+=(const RationalVector2& rhs);
        RationalVector2& operator-=(const RationalVector2& rhs);
        RationalVector2& operator*=(const Rational& rational);
        RationalVector2& operator/=(const Rational& rational);

        // ���� (y,-x).
        [[nodiscard]] const RationalVector2 Perp() const;

        [[nodiscard]] const Rational SquaredLength() const;

    private:
        RationalVector m_Tuple;
    };

    // ���� Dot(lhs,rhs).
    template <int IntSize>
    [[nodiscard]] const SignRational<IntSize> Dot(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs);

    // ���� Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x
    template <int IntSize>
    [[nodiscard]] const SignRational<IntSize> DotPerp(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs);

    template <int IntSize>
    [[nodiscard]] bool operator==(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs);

    template <int IntSize>
    [[nodiscard]] bool operator<(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs);

    template <int IntSize>
    std::ostream& operator<<(std::ostream& os, const RationalVector2<IntSize>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_H

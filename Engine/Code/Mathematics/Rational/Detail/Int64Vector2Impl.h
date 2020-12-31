///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 13:57)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/ConfigMacro.h"
#include "Mathematics/Rational/Int64Vector.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE Int64Vector2Impl final
    {
    public:
        using ClassType = Int64Vector2Impl;

    public:
        Int64Vector2Impl() noexcept;
        explicit Int64Vector2Impl(const Int64Vector<2>& rhs) noexcept;
        Int64Vector2Impl(int64_t x, int64_t y) noexcept;

        Int64Vector2Impl& operator=(const Int64Vector<2>& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int64_t GetX() const;
        void SetX(int64_t x);
        [[nodiscard]] int64_t GetY() const;
        void SetY(int64_t y);

        // 返回 (y,-x).
        [[nodiscard]] const Int64Vector2Impl Perp() const;

        [[nodiscard]] const Int64Vector2Impl operator-() const noexcept;

        Int64Vector2Impl& operator+=(const Int64Vector2Impl& rhs) noexcept;
        Int64Vector2Impl& operator-=(const Int64Vector2Impl& rhs) noexcept;
        Int64Vector2Impl& operator*=(int64_t scalar) noexcept;
        Int64Vector2Impl& operator/=(int64_t scalar);

        [[nodiscard]] int64_t SquaredLength() const noexcept;

    private:
        Int64Vector<2> m_Tuple;
    };

    // 返回 Dot(lhs,rhs).
    [[nodiscard]] int64_t Dot(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);

    // 返回 Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x.
    [[nodiscard]] int64_t DotPerp(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);

    [[nodiscard]] bool operator==(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);

    [[nodiscard]] bool operator<(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H

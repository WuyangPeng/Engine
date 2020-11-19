///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 13:59)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR3_IMPL_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/ConfigMacro.h"
#include "Mathematics/Rational/Int64Vector.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE Int64Vector3Impl final
    {
    public:
        using ClassType = Int64Vector3Impl;

    public:
        Int64Vector3Impl() noexcept;
        explicit Int64Vector3Impl(const Int64Vector<3>& rhs) noexcept;
        Int64Vector3Impl(int64_t x, int64_t y, int64_t z) noexcept;

        Int64Vector3Impl& operator=(const Int64Vector<3>& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int64_t GetX() const;
        void SetX(int64_t x);
        [[nodiscard]] int64_t GetY() const;
        void SetY(int64_t y);
        [[nodiscard]] int64_t GetZ() const;
        void SetZ(int64_t y);

        const Int64Vector3Impl operator-() const noexcept;

        Int64Vector3Impl& operator+=(const Int64Vector3Impl& rhs) noexcept;
        Int64Vector3Impl& operator-=(const Int64Vector3Impl& rhs) noexcept;
        Int64Vector3Impl& operator*=(int64_t scalar) noexcept;
        Int64Vector3Impl& operator/=(int64_t scalar);

        [[nodiscard]] int64_t SquaredLength() const noexcept;

    private:
        Int64Vector<3> m_Tuple;
    };

    // 返回 Dot(lhs,rhs).
    [[nodiscard]] int64_t Dot(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);

    // 返回 Cross(this,V)
    [[nodiscard]] Int64Vector3Impl Cross(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);

    // 返回 Dot(this,Cross(U,V))
    [[nodiscard]] int64_t TripleScalar(const Int64Vector3Impl& lhs, const Int64Vector3Impl& mhs, const Int64Vector3Impl& rhs);

    [[nodiscard]] bool operator==(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);

    [[nodiscard]] bool operator<(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR3_IMPL_H

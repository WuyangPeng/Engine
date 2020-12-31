///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 17:09)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning/Operators.h"

#include <iosfwd>
#include <array>

namespace Mathematics
{
    template <int VectorSize>
    class Int64Vector final : private boost::additive<Int64Vector<VectorSize>, boost::totally_ordered<Int64Vector<VectorSize>, boost::multiplicative<Int64Vector<VectorSize>, int64_t>>>
    {
    public:
        using ClassType = Int64Vector<VectorSize>;

    public:
        Int64Vector() noexcept;
        Int64Vector(int64_t x, int64_t y) noexcept;
        Int64Vector(int64_t x, int64_t y, int64_t z) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        [[nodiscard]] const int64_t& operator[](int index) const;
        [[nodiscard]] int64_t& operator[](int index);

        [[nodiscard]] const Int64Vector operator-() const noexcept;

        Int64Vector& operator+=(const Int64Vector& rhs) noexcept;
        Int64Vector& operator-=(const Int64Vector& rhs) noexcept;
        Int64Vector& operator*=(const int64_t& scalar) noexcept;
        Int64Vector& operator/=(const int64_t& scalar);

        [[nodiscard]] int64_t SquaredLength() const noexcept;

    private:
        using ArrayType = std::array<int64_t, VectorSize>;

    private:
        ArrayType m_Tuple;
    };

    template <int VectorSize>
    [[nodiscard]] bool operator==(const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs);

    template <int VectorSize>
    [[nodiscard]] bool operator<(const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs);

    template <int VectorSize>
    [[nodiscard]] int64_t Dot(const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs);

    template <int VectorSize>
    std::ostream& operator<<(std::ostream& os, const Int64Vector<VectorSize>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR_H

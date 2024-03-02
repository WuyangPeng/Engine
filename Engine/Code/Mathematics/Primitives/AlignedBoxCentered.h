///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/23 10:12)

#ifndef MATHEMATICS_PRIMITIVES_ALIGNED_BOX_CENTERED_H
#define MATHEMATICS_PRIMITIVES_ALIGNED_BOX_CENTERED_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class AlignedBoxCentered
    {
    public:
        using ClassType = AlignedBoxCentered<N, Real>;

        using Vector = Algebra::Vector<N, Real>;

    public:
        AlignedBoxCentered(const Vector& center, const Vector& extent) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetCenter() const noexcept;
        NODISCARD Vector GetExtent() const noexcept;

    private:
        Vector center;
        Vector extent;
    };
}

#endif  // MATHEMATICS_PRIMITIVES_ALIGNED_BOX_CENTERED_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:42)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    template <typename Real>
    class ContMinCircle2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContMinCircle2<Real>;

    public:
        ContMinCircle2(const std::vector<Vector2<Real>>& points, Circle2<Real>& minimal, Real epsilon = static_cast<Real>(1e-05));

        CLASS_INVARIANT_DECLARE;

    private:
        class Support
        {
        public:
            bool Contains(int index, const std::vector<Vector2<Real>>& points, Real epsilon) const;

            int quantity;
            std::array<int, 3> index;
        };

        NODISCARD bool Contains(const Vector2<Real>& point, const Circle2<Real>& circle, Real& distDiff);

        NODISCARD Circle2<Real> ExactCircle1(const Vector2<Real>& p) noexcept;
        NODISCARD Circle2<Real> ExactCircle2(const Vector2<Real>& p0, const Vector2<Real>& p1);
        NODISCARD Circle2<Real> ExactCircle3(const Vector2<Real>& p0, const Vector2<Real>& p1, const Vector2<Real>& p2);

        NODISCARD Circle2<Real> UpdateSupport1(int i, const std::vector<Vector2<Real>>& permuted, Support& support);
        NODISCARD Circle2<Real> UpdateSupport2(int i, const std::vector<Vector2<Real>>& permuted, Support& support);
        NODISCARD Circle2<Real> UpdateSupport3(int i, const std::vector<Vector2<Real>>& permuted, Support& support);

        using UpdateFunction = Circle2<Real> (ClassType::*)(int, const std::vector<Vector2<Real>>&, Support&);

    private:
        Real epsilon;
        std::array<UpdateFunction, 4> update;
    };

    using MinCircle2F = ContMinCircle2<float>;
    using MinCircle2D = ContMinCircle2<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_H

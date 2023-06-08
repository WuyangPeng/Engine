///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:17)

#ifndef MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
    /// 确定三角形和直线如何相交（如果有的话）。
    template <typename Real>
    class Line2Triangle2 final
    {
    public:
        using ClassType = Line2Triangle2<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        Line2Triangle2(const Vector2& origin, const Vector2& direction, const Triangle2& triangle);

        CLASS_INVARIANT_DECLARE;

        // 当三角形与直线相交时，计算相交线段的参数间隔。
        NODISCARD Vector2 GetInterval() const;

        NODISCARD int GetPositive() const noexcept;
        NODISCARD int GetNegative() const noexcept;

    private:
        static constexpr auto size = 3;
        using DistanceType = std::array<Real, size>;
        using SignType = std::array<NumericalValueSymbol, size>;

    private:
        void TriangleLineRelations();

    private:
        DistanceType distance;
        SignType sign;
        int positive;
        int negative;
        int zero;
        Vector2 origin;
        Vector2 direction;
        Triangle2 triangle;
    };
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_H

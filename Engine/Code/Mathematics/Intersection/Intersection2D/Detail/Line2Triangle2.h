///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 10:43)

#ifndef MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
    /// 确定三角形和直线如何相交（如果有的话）。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Line2Triangle2 final
    {
    public:
        using ClassType = Line2Triangle2<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        Line2Triangle2(const Vector2D& origin, const Vector2D& direction, const Triangle2& triangle);

        CLASS_INVARIANT_DECLARE;

        // 当三角形与直线相交时，计算相交线段的参数间隔。
        [[nodiscard]] Vector2D GetInterval() const;

        [[nodiscard]] int GetPositive() const noexcept;
        [[nodiscard]] int GetNegative() const noexcept;

    private:
        static constexpr auto sm_Size = 3;
        using DistanceType = std::array<Real, sm_Size>;
        using SignType = std::array<NumericalValueSymbol, sm_Size>;

    private:
        void TriangleLineRelations();

    private:
        DistanceType m_Distance;
        SignType m_Sign;
        int m_Positive;
        int m_Negative;
        int m_Zero;
        Vector2D m_Origin;
        Vector2D m_Direction;
        Triangle2 m_Triangle;
    };
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_H

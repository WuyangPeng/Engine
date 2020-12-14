///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 16:31)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    // 椭圆为(x/a)^2 + (y/b)^2 = 1，
    // 但仅在第一象限中的部分(x >= 0 and y >= 0)近似。
    // 生成numArcs >= 2 的弧构造对应于所述曲率在
    // 椭圆点(a,0) 和 (0,b)的加权平均值中。
    // 返回的输入点数组有numArcs+1个元素和
    // 返回输入圆心和半径每个数组有numArc元素。
    // m_Points[i]和m_Points[i+1]相关联的弧
    // 具有中心m_Center[i]和半径的m_Radius[i]。

    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE EllipseByArcs2Impl final
    {
    public:
        using ClassType = EllipseByArcs2Impl<Real>;
        using Vector2D = Vector2D<Real>;
        using Math = Math<Real>;
        using Arc2 = Arc2<Real>;
        using Circle2 = Circle2<Real>;
        using PointsType = std::vector<Vector2D>;
        using Circle2Container = std::vector<Circle2>;

    public:
        EllipseByArcs2Impl(Real begin, Real end, size_t numArcs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const PointsType GetPoints() const;
        [[nodiscard]] const Circle2Container GetCircle2() const;

        [[nodiscard]] const Arc2 GetArc2(int index) const;
        [[nodiscard]] int getNumArcs() const;

    private:
        void Calculate(Real begin, Real end);

    private:
        PointsType m_Points;
        Circle2Container m_Circle;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_H

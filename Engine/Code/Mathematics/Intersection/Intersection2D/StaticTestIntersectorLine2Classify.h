///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 15:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Classify : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Classify<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        // 线性分量的分类。
        // 线是P0 + s * D0和P1 + s * D1。
        // 当线不相交时，返回值为IntersectionType::Empty，
        // 当线只有唯一的交点时，返回值为IntersectionType::Point，
        // 或当线重叠时，返回值为IntersectionType::Line。
        // 当只有唯一的交点时，点为P0 + s[0] * D0 = P1 + s[1] * D1。
        // 'epsilon'参数是用于测试平行或垂直向量的非负数。
        // 在Test() 和 Find() 函数中使用的值是m_Epsilon。
        // 如果你想知道s[]值，传递isCalculateParameter为'true'。
        // 代码用于射线-射线，直线-直线和线段-线段的相交测试共享。
        StaticTestIntersectorLine2Classify(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin,
                                           const Vector2D& rhsDirection, bool isCalculateParameter = true, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] Real GetParameter0() const noexcept;
        [[nodiscard]] Real GetParameter1() const noexcept;

    private:
        void Test(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin, const Vector2D& rhsDirection, bool isCalculateParameter);

    private:
        Real m_Parameter0;
        Real m_Parameter1;
    };

    using FloatStaticTestIntersectorLine2Classify = StaticTestIntersectorLine2Classify<float>;
    using DoubleStaticTestIntersectorLine2Classify = StaticTestIntersectorLine2Classify<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H

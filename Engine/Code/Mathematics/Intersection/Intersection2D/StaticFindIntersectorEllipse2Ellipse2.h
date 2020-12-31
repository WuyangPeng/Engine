///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 11:22)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ellipse2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorEllipse2Ellipse2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorEllipse2Ellipse2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorEllipse2Ellipse2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorEllipse2Ellipse2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorEllipse2Ellipse2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using StaticFindIntersectorEllipse2Ellipse2Impl = StaticFindIntersectorEllipse2Ellipse2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StaticFindIntersectorEllipse2Ellipse2);

        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Ellipse2 = Ellipse2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorEllipse2Ellipse2(const Ellipse2& ellipse0, const Ellipse2& ellipse1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ellipse2 GetEllipse0() const noexcept;
        [[nodiscard]] const Ellipse2 GetEllipse1() const noexcept;

        /// 用于静态查找相交点查询的交叉点集。 Q满足0 <= Q <= 4。
        /// 当Q > 0时，解释取决于交叉点类型。
        ///   IT_POINT：Q个不同的交点
        ///   IT_OTHER：椭圆是相同的。 GetIntersectionEllipse返回椭圆对象之一。 Q无效。
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Ellipse2 GetIntersectionEllipse() const noexcept;
        [[nodiscard]] bool IsTransverseIntersection(int index) const;

    private:
        using CoeffType = std::array<Real, 6>;
        using RootsType = std::vector<Real>;

    private:
        // 静态交集查询
        void Find();

        //  支持对潜在的相交点进行排序。
        struct Measurement final
        {
        public:
            Measurement() noexcept;
            [[nodiscard]] bool operator<(const Measurement& measure) const noexcept;

            // <x, y, sqrt(Q0(x,y)^2 + Q1(x,y)^2)>
            Vector2D m_Point;
            Real m_Q0;
            Real m_Q1;
            Real m_Norm;
            Real m_Angle0;
            bool m_Transverse;
        };

        [[nodiscard]] static Polynomial<Real> GetQuartic(const Ellipse2& ellipse0, const Ellipse2& ellipse1);

        [[nodiscard]] Measurement RefinePoint(const CoeffType& coeff, const Vector2D& point);

    private:
        IMPL_TYPE_DECLARE(StaticFindIntersectorEllipse2Ellipse2);
    };

    using FloatStaticFindIntersectorEllipse2Ellipse2 = StaticFindIntersectorEllipse2Ellipse2<float>;
    using DoubleStaticFindIntersectorEllipse2Ellipse2 = StaticFindIntersectorEllipse2Ellipse2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H

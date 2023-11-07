///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ellipse2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorEllipse2Ellipse2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorEllipse2Ellipse2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Ellipse2 = Ellipse2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorEllipse2Ellipse2(const Ellipse2& ellipse0, const Ellipse2& ellipse1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ellipse2 GetEllipse0() const noexcept;
        NODISCARD Ellipse2 GetEllipse1() const noexcept;

        /// 用于静态查找相交点查询的交叉点集。 Q满足0 <= Q <= 4。
        /// 当Q > 0时，解释取决于交叉点类型。
        ///   IT_POINT：Q个不同的交点
        ///   IT_OTHER：椭圆是相同的。 GetIntersectionEllipse返回椭圆对象之一。 Q无效。
        NODISCARD int GetQuantity() const;
        NODISCARD Vector2 GetPoint(int index) const;
        NODISCARD Ellipse2 GetIntersectionEllipse() const noexcept;
        NODISCARD bool IsTransverseIntersection(int index) const;

    private:
        using CoeffType = std::array<Real, 6>;
        using RootsType = std::vector<Real>;
        using Intersection = std::vector<Vector2>;
        using TransverseType = std::array<bool, 4>;

    private:
        // 静态交集查询
        void Find();

        //  支持对潜在的相交点进行排序。
        struct Measurement final
        {
        public:
            Measurement() noexcept;
            NODISCARD bool operator<(const Measurement& measure) const noexcept;

            // <x, y, sqrt(Q0(x,y)^2 + Q1(x,y)^2)>
            Vector2 point;
            Real q0;
            Real q1;
            Real norm;
            Real angle0;
            bool transverse;
        };

        NODISCARD static Polynomial<Real> GetQuartic(const Ellipse2& ellipse0, const Ellipse2& ellipse1);

        NODISCARD Measurement RefinePoint(const CoeffType& coeff, const Vector2& vector2);

    private:
        // 要相交的对象。
        Ellipse2 ellipse0;
        Ellipse2 ellipse1;

        // 相交点。
        Intersection point;
        TransverseType transverse;

        // 求根的准确性位数。 默认值为10。
        int digitsAccuracy;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H

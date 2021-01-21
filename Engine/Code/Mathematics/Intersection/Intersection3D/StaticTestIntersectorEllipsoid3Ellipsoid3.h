///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 15:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorEllipsoid3Ellipsoid3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorEllipsoid3Ellipsoid3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Ellipsoid3 = Ellipsoid3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorEllipsoid3Ellipsoid3(const Ellipsoid3& ellipsoid0, const Ellipsoid3& ellipsoid1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ellipsoid3 GetEllipsoid0() const noexcept;
        [[nodiscard]] const Ellipsoid3 GetEllipsoid1() const noexcept;

        // 测试查询的一种形式。 椭球是分开的，相交的（在点或曲线上），椭球0严格包含在椭球1中，或椭球1严格包含在椭球0中。
        enum class Classification
        {
            EllipsoidsSeparated,
            EllipsoidsIntersecting,
            Ellipsoid0ContainsEllipsoid1,
            Ellipsoid1ContainsEllipsoid0
        };

        [[nodiscard]] Classification GetClassification() const;

    private:
        using RootsType = std::vector<Real>;

    private:
        void Test();

        // GetClassification()的支持函数。
        static RootsType GetRoots(Real d0, Real d1, Real c0, Real c1);

        static RootsType GetRoots(Real d0, Real c0);

        static RootsType GetRoots(Real d0, Real d1, Real d2, Real c0, Real c1, Real c2);

        struct ResultType
        {
            Real m_S;
            Real m_F;
        };

        static ResultType BisectF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real fmin, Real smax, Real fmax);

        static ResultType BisectDF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real dfmin, Real smax, Real dfmax);

        static ResultType BisectF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real fmin, Real smax, Real fmax);

        static ResultType BisectDF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real dfmin, Real smax, Real dfmax);

    private:
        Ellipsoid3 m_Ellipsoid0;
        Ellipsoid3 m_Ellipsoid1;
        Classification m_Classification;
    };

    using FloatStaticTestIntersectorEllipsoid3Ellipsoid3 = StaticTestIntersectorEllipsoid3Ellipsoid3<float>;
    using DoubleStaticTestIntersectorEllipsoid3Ellipsoid3 = StaticTestIntersectorEllipsoid3Ellipsoid3<double>;

}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H

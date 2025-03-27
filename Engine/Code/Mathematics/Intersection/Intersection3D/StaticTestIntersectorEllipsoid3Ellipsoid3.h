///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorEllipsoid3Ellipsoid3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorEllipsoid3Ellipsoid3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Ellipsoid3 = Ellipsoid3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        StaticTestIntersectorEllipsoid3Ellipsoid3(const Ellipsoid3& ellipsoid0, const Ellipsoid3& ellipsoid1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ellipsoid3 GetEllipsoid0() const noexcept;
        NODISCARD Ellipsoid3 GetEllipsoid1() const noexcept;

        // ���Բ�ѯ��һ����ʽ�� �����Ƿֿ��ģ��ཻ�ģ��ڵ�������ϣ�������0�ϸ����������1�У�������1�ϸ����������0�С�
        enum class Classification
        {
            EllipsoidsSeparated,
            EllipsoidsIntersecting,
            Ellipsoid0ContainsEllipsoid1,
            Ellipsoid1ContainsEllipsoid0
        };

        NODISCARD Classification GetClassification() const noexcept;

    private:
        using RootsType = std::vector<Real>;

    private:
        void Test();

        // GetClassification()��֧�ֺ�����
        NODISCARD static RootsType GetRoots(Real d0, Real d1, Real c0, Real c1);

        NODISCARD static RootsType GetRoots(Real d0, Real c0);

        NODISCARD static RootsType GetRoots(Real d0, Real d1, Real d2, Real c0, Real c1, Real c2);

        struct ResultType
        {
            Real s;
            Real f;
        };

        NODISCARD static ResultType BisectF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real fmin, Real smax, Real fmax) noexcept;

        NODISCARD static ResultType BisectDF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real dfmin, Real smax, Real dfmax) noexcept;

        NODISCARD static ResultType BisectF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real fmin, Real smax, Real fmax) noexcept;

        NODISCARD static ResultType BisectDF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real dfmin, Real smax, Real dfmax) noexcept;

    private:
        Ellipsoid3 ellipsoid0;
        Ellipsoid3 ellipsoid1;
        Classification classification;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H

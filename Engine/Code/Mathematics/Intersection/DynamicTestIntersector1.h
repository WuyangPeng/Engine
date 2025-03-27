///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 16:04)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersector1 final : public Intersector1<Real>
    {
    public:
        using ClassType = DynamicTestIntersector1<Real>;
        using ParentType = Intersector1<Real>;

        using MathType = typename ParentType::MathType;

    public:
        DynamicTestIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool IsIntersection() const noexcept override;

        // ��̬�ཻ��ѯ���������䴦�ڵ�һ��/���һ�νӴ���ʱ�䡣
        NODISCARD Real GetFirstTime() const;
        NODISCARD Real GetLastTime() const;

    private:
        void Test(Real tMax, Real speedU, Real speedV);

    private:
        // �й��ཻ����Ϣ��
        Real firstTime;
        Real lastTime;

        bool intersection;
    };

    using DynamicTestIntersector1F = DynamicTestIntersector1<float>;
    using DynamicTestIntersector1D = DynamicTestIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H

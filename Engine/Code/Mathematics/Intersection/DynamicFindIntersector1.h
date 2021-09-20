///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 18:27)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersector1Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<DynamicFindIntersector1Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<DynamicFindIntersector1Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<DynamicFindIntersector1Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersector1 final : public Intersector1<Real>
    {
    public:
        using DynamicFindIntersector1Impl = DynamicFindIntersector1Impl<Real>;
         
        TYPE_DECLARE(DynamicFindIntersector1);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ParentType = Intersector1<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] bool IsIntersection() const noexcept final;

        // ��̬�ཻ��ѯ���������䴦�ڵ�һ��/���һ�νӴ���ʱ�䡣
        [[nodiscard]] Real GetFirstTime() const;
        [[nodiscard]] Real GetLastTime() const;

        // �йؽ�������Ϣ��
        // �ཻ��Ϊ0�����䲻�ص�����
        // 1������߽��ཻ����2�������������ཻ����
        [[nodiscard]] int GetNumIntersections() const;
        [[nodiscard]] Real GetIntersection(int index) const;

    private:
        void Find(Real tMax, Real speedU, Real speedV);

    private:
        PackageType impl;
    };

    using FloatDynamicFindIntersector1 = DynamicFindIntersector1<float>;
    using DoubleDynamicFindIntersector1 = DynamicFindIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H

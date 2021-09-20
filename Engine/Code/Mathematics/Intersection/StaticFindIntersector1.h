///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 15:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersector1Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersector1Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersector1Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersector1Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersector1 final : public Intersector1<Real>
    {
    public:
        using StaticFindIntersector1Impl = StaticFindIntersector1Impl<Real>;
 
        TYPE_DECLARE(StaticFindIntersector1);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ParentType = Intersector1<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] bool IsIntersection() const noexcept final;

        // �йؽ�������Ϣ��
        // �ཻ��Ϊ0�����䲻�ص�����
        // 1������߽��ཻ����2�������������ཻ����
        [[nodiscard]] int GetNumIntersections() const;
        [[nodiscard]] Real GetIntersection(int index) const;

    private:
        void Find();

    private:
        PackageType impl;
    };

    using FloatStaticFindIntersector1 = StaticFindIntersector1<float>;
    using DoubleStaticFindIntersector1 = StaticFindIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H

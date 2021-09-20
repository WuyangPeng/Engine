///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/29 10:53)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorBox3Box3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<DynamicFindIntersectorBox3Box3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<DynamicFindIntersectorBox3Box3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<DynamicFindIntersectorBox3Box3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using DynamicFindIntersectorBox3Box3Impl = DynamicFindIntersectorBox3Box3Impl<Real>;
  
        TYPE_DECLARE(DynamicFindIntersectorBox3Box3);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorBox3Box3(
            const Box3& box0,
            const Box3& box1,
            Real tmax,
            const Vector3D& lhsVelocity,
            const Vector3D& rhsVelocity,
            const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box3 GetBox0() const noexcept;
        [[nodiscard]] const Box3 GetBox1() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        // ��̬���ҽ�����ѯ�� �ô����鱻���������
        void Find();

    private:
        PackageType impl;
    };

    using FloatDynamicFindIntersectorBox3Box3 = DynamicFindIntersectorBox3Box3<float>;
    using DoubleDynamicFindIntersectorBox3Box3 = DynamicFindIntersectorBox3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H

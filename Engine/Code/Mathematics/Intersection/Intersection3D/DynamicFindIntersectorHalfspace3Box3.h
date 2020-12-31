///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/31 16:32)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Plane3.h"

/// ��ռ���ƽ�淨��ָ���ƽ������ϵĵ㼯�� ����Ĳ�ѯ��һ�����ӺͰ���ո�Ľ�����
/// �ڶ�̬���Ҳ�ѯ�У�����ÿ��Ѿ������ո��ཻ���򷵻�ֵΪ'false'�� ����뷨��Ѱ�ҵ�һ�νӴ���

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorHalfspace3Box3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicFindIntersectorHalfspace3Box3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicFindIntersectorHalfspace3Box3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicFindIntersectorHalfspace3Box3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorHalfspace3Box3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using DynamicFindIntersectorHalfspace3Box3Impl = DynamicFindIntersectorHalfspace3Box3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(DynamicFindIntersectorHalfspace3Box3);

        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorHalfspace3Box3(const Plane3& halfspace, const Box3& box,
                                             Real tmax, const Vector3D& lhsVelocity,
                                             const Vector3D& rhsVelocity,
                                             const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        // �ཻ�㼯��Ϊ�գ��㣬�߶λ���Ρ� ���� GetQuantity()����0��1��2��4��
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

    private:
        IMPL_TYPE_DECLARE(DynamicFindIntersectorHalfspace3Box3);
    };

    using FloatDynamicFindIntersectorHalfspace3Box3 = DynamicFindIntersectorHalfspace3Box3<float>;
    using DoubleDynamicFindIntersectorHalfspace3Box3 = DynamicFindIntersectorHalfspace3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H

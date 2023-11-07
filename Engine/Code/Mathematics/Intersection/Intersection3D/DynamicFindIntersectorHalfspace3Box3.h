///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:56)

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
    class DynamicFindIntersectorHalfspace3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorHalfspace3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using Container = std::vector<Vector3>;

    public:
        DynamicFindIntersectorHalfspace3Box3(const Plane3& halfSpace,
                                             const Box3& box,
                                             Real tMax,
                                             const Vector3& lhsVelocity,
                                             const Vector3& rhsVelocity,
                                             const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetHalfspace() const noexcept;
        NODISCARD Box3 GetBox() const noexcept;

        // �ཻ�㼯��Ϊ�գ��㣬�߶λ���Ρ� ���� GetQuantity()����0��1��2��4��
        NODISCARD int GetQuantity() const;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Plane3 halfSpace;
        Box3 box;

        // �йؽ�������Ϣ��
        Container point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H

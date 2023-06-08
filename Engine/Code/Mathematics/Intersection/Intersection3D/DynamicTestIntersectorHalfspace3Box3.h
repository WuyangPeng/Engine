///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 19:34)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Plane3.h"

/// ��ռ���ƽ�淨��ָ���ƽ������ϵĵ㼯��
/// ����Ĳ�ѯ��һ�����ӺͰ��ƽ��Ľ�����
/// �ڶ�̬���Ҳ�ѯ�У�����ÿ��Ѿ�����ƽ���ཻ���򷵻�ֵΪ'false'��
/// ����뷨��Ѱ�ҵ�һ�νӴ���

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorHalfspace3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorHalfspace3Box3(const Plane3& halfspace,
                                             const Box3& box,
                                             Real tmax,
                                             const Vector3& lhsVelocity,
                                             const Vector3& rhsVelocity,
                                             const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetHalfspace() const noexcept;
        NODISCARD Box3 GetBox() const noexcept;

    private:
        void Test();

    private:
        Plane3 halfspace;
        Box3 box;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H

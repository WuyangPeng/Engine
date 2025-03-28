///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:02)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

/// ��ռ���ƽ�淨��ָ���ƽ������ϵĵ㼯�� ����Ĳ�ѯ�������κͰ�ռ�Ľ�����
/// �ڶ�̬���Ҳ�ѯ�У�����������Ѿ����ռ��ཻ���򷵻�ֵΪ'false'�� ����뷨��Ѱ�ҵ�һ�νӴ���

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorHalfspace3Triangle3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicTestIntersectorHalfspace3Triangle3(const Plane3& halfspace,
                                                  const Triangle3& triangle,
                                                  Real tmax,
                                                  const Vector3& lhsVelocity,
                                                  const Vector3& rhsVelocity,
                                                  const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetHalfspace() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

    private:
        void Test();

    private:
        Plane3 halfspace;
        Triangle3 triangle;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H

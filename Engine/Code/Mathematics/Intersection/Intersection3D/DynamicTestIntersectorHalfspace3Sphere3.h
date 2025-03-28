///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:02)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Sphere3.h"

/// ��ռ���ƽ�淨��ָ���ƽ������ϵĵ㼯�� ����Ĳ�ѯ������Ͱ�ռ�Ľ�����
/// �ڶ�̬���Ҳ�ѯ�У���������Ѿ����ռ��ཻ���򷵻�ֵΪ�� false����
/// ����뷨���ҵ���һ�νӴ�������������£�ֻ��һ���Ӵ��㡣

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorHalfspace3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Sphere3Type = Sphere3<Real>;
        using Plane3Type = Plane3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicTestIntersectorHalfspace3Sphere3(const Plane3Type& halfspace,
                                                const Sphere3Type& sphere,
                                                Real tMax,
                                                const Vector3Type& lhsVelocity,
                                                const Vector3Type& rhsVelocity,
                                                const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3Type GetHalfspace() const noexcept;
        NODISCARD Sphere3Type GetSphere() const noexcept;

    private:
        void Test();

    private:
        Plane3Type halfspace;
        Sphere3Type sphere;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H

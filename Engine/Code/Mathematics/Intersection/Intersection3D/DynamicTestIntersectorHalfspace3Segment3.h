///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Segment3.h"

/// ��ռ���ƽ�淨��ָ���ƽ������ϵĵ㼯��
/// ����Ĳ�ѯ�����߶κͰ�ǵĽ�����
/// �ڶ�̬���Ҳ�ѯ�У�����߶��Ѿ����ռ��ཻ���򷵻�ֵΪ'false'��
/// ����뷨��Ѱ�ҵ�һ�νӴ���

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorHalfspace3Segment3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Segment3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        DynamicTestIntersectorHalfspace3Segment3(const Plane3& halfspace,
                                                 const Segment3& segment,
                                                 Real tmax,
                                                 const Vector3& lhsVelocity,
                                                 const Vector3& rhsVelocity,
                                                 const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetHalfspace() const noexcept;
        NODISCARD Segment3 GetSegment() const noexcept;

    private:
        void Test();

    private:
        Plane3 halfspace;
        Segment3 segment;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H

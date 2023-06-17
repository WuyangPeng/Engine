///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 08:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorPlane3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Plane3 = Plane3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        // ���Ҫ����ģ��ȷ�����뽫epsilonֵ����Ϊ��С��������
        StaticFindIntersectorPlane3Triangle3(const Plane3& plane, const Triangle3& triangle, Real epsilon = Math::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const Plane3 GetPlane() const noexcept;
        NODISCARD const Triangle3 GetTriangle() const noexcept;

        // �ཻ�������ǿյģ��㣬�߶λ����������Σ�GetQuantity����0��1��2��3��
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD const Vector3 GetPoint(int index) const;

    private:
        void Find();

        Plane3 plane;
        Triangle3 triangle;

        int quantity;
        Vector3 point0;
        Vector3 point1;
        Vector3 point2;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/20 18:23)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorPlane3Triangle3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        // ���Ҫ����ģ��ȷ�����뽫epsilonֵ����Ϊ��С��������
        StaticFindIntersectorPlane3Triangle3(const Plane3& plane, const Triangle3& triangle, Real epsilon = Math::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        // �ཻ�������ǿյģ��㣬�߶λ����������Σ�GetQuantity����0��1��2��3��
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Plane3 m_Plane;
        Triangle3 m_Triangle;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
        Vector3D m_Point2;
    };

    using FloatStaticFindIntersectorPlane3Triangle3 = StaticFindIntersectorPlane3Triangle3<float>;
    using DoubleStaticFindIntersectorPlane3Triangle3 = StaticFindIntersectorPlane3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H

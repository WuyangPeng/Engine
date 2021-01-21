///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/21 11:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cone3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSphere3Cone3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorSphere3Cone3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Cone3 = Cone3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSphere3Cone3(const Sphere3& sphere, const Cone3& cone, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Sphere3 GetSphere() const noexcept;
        [[nodiscard]] const Cone3 GetCone() const noexcept;

        /// �ھ�̬�����ཻ��ѯ�У���������Բ׶��֮�䷢���ཻ������������޼��� �˺���������ӽ�Բ׶����Ľ��㡣
        [[nodiscard]] const Vector3D GetPoint() const noexcept;

    private:
        void Find();

    private:
        Sphere3 m_Sphere;
        Cone3 m_Cone;

        // ��Բ׶����������ཻ�㡣
        Vector3D m_Point;
    };

    using FloatStaticFindIntersectorSphere3Cone3 = StaticFindIntersectorSphere3Cone3<float>;
    using DoubleStaticFindIntersectorSphere3Cone3 = StaticFindIntersectorSphere3Cone3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H

///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/09 19:03)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Box3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Box3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Box3(const Vector3D& point, const Box3& ellipse) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        // ��̬�����ѯ��
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Box3 m_Box;
    };

    using FloatDistancePoint3Box3 = DistancePoint3Box3<float>;
    using DoubleDistancePoint3Box3 = DistancePoint3Box3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_H

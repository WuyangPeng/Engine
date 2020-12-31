///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/09 19:07)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Ellipsoid3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Ellipsoid3<Real>;
        using Vector3D = Vector3D<Real>;
        using Ellipsoid3 = Ellipsoid3<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Ellipsoid3(const Vector3D& point, const Ellipsoid3& ellipsoid) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Ellipsoid3 GetEllipsoid() const noexcept; 

        // ��̬�����ѯ��
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Ellipsoid3 m_Ellipsoid;
    };

    using FloatDistancePoint3Ellipsoid3 = DistancePoint3Ellipsoid3<float>;
    using DoubleDistancePoint3Ellipsoid3 = DistancePoint3Ellipsoid3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/21 15:27)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/MathematicsDll.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Ray3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceRay3Ray3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Ray3 = Ray3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Ray3(const Ray3& lhsRay, const Ray3& rhsRay) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3 GetLhsRay() const noexcept;
        NODISCARD Ray3 GetRhsRay() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine3Line3Tool& tool) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine3Line3Tool& tool) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine3Line3Tool& tool) const;

    private:
        Ray3 lhsRay;
        Ray3 rhsRay;
    };

    using DistanceRay3Ray3F = DistanceRay3Ray3<float>;
    using DistanceRay3Ray3D = DistanceRay3Ray3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H

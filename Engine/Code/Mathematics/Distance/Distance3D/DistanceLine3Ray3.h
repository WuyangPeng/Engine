///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Ray3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Ray3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Line3Type = Line3<Real>;
        using Ray3Type = Ray3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using DistanceLine3Line3ToolType = DistanceLine3Line3Tool<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceLine3Ray3(const Line3Type& line, const Ray3Type& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Ray3Type GetRay() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPoints(const DistanceLine3Line3ToolType& tool) const;

    private:
        Line3Type line;
        Ray3Type ray;
    };

    using DistanceLine3Ray3F = DistanceLine3Ray3<float>;
    using DistanceLine3Ray3D = DistanceLine3Ray3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H

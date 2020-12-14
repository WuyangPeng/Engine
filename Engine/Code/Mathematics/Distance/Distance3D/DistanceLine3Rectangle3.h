///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/11 13:58)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Rectangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceLine3Rectangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Vector2D = Vector2D<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Rectangle3(const Line3& line, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Rectangle3 GetRectangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        [[nodiscard]] Real GetRectangleCoordinate(int index) const;

    private:
        Line3 m_Line;
        Rectangle3 m_Rectangle;

        // �й���ӽ������Ϣ��

        // closest0 = line.origin + param * line.direction
        // closest1 = rect.center + param0 * rect.dir0 + param1 * rect.dir1
        mutable Vector2D m_RectCoord;
    };

    using FloatDistanceLine3Rectangle3 = DistanceLine3Rectangle3<float>;
    using DoubleDistanceLine3Rectangle3 = DistanceLine3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RECTANGLE3_H

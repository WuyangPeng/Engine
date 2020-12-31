///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/07 16:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine2Line2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistanceLine2Line2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Line2 = Line2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine2Line2(const Line2& lhsLine, const Line2& rhsLine) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLhsLine() const noexcept;
        [[nodiscard]] const Line2 GetRhsLine() const noexcept;

        // ��̬�����ѯ��
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        Line2 m_LhsLine;
        Line2 m_RhsLine;
    };

    using FloatDistanceLine2Line2 = DistanceLine2Line2<float>;
    using DoubleDistanceLine2Line2 = DistanceLine2Line2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_H

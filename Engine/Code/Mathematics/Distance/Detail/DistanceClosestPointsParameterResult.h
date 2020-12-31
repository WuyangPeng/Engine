///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 18:43)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceClosestPointsResult.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceClosestPointsParameterResult : public DistanceClosestPointsResult<Real, Vector>
    {
    public:
        using ClassType = DistanceClosestPointsParameterResult<Real, Vector>;
        using ParentType = DistanceClosestPointsResult<Real, Vector>;
        using ImplTypePtr = ParentType::ImplTypePtr;

    public:
        DistanceClosestPointsParameterResult(Real distance, Real contactTime, const Vector& lhsClosestPoint,
                                             const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] Real GetLhsParameter() const override;
        [[nodiscard]] Real GetRhsParameter() const override;

        [[nodiscard]] ImplTypePtr Clone() const override;

    private:
        Real m_LhsParameter;
        Real m_RhsParameter;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H

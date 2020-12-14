///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 18:39)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceInternalFwd.h"

#include <vector>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceResultFactory final
    {
    public:
        using ClassType = DistanceResultFactory<Real, Vector>;
        using DistanceResultImplPtr = std::shared_ptr<DistanceResultImpl<Real, Vector>>;
        using ClosestPoints = std::vector<Vector>;

    public:
        DistanceResultFactory() = delete;

        [[nodiscard]] static DistanceResultImplPtr Create(Real distance);
        [[nodiscard]] static DistanceResultImplPtr Create(Real distance, Real contactTime);
        [[nodiscard]] static DistanceResultImplPtr Create(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint);
        [[nodiscard]] static DistanceResultImplPtr Create(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);
        [[nodiscard]] static DistanceResultImplPtr Create(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter);
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:42)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceInternalFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceResult final
    {
    public:
        using DistanceResultImpl = DistanceResultImpl<Real, Vector>;

        DELAY_COPY_UNSHARED_TYPE_DECLARE(DistanceResult);

        using ClosestPoints = std::vector<Vector>;

    public:
        explicit DistanceResult(Real distance);
        DistanceResult(Real distance, Real contactTime);
        DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint);
        DistanceResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);
        DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetDistance() const noexcept;

        // �����ڶ�̬��ѯ����С�����ʱ�䡣
        NODISCARD Real GetContactTime() const noexcept;

        // �����������������㡣��Щ�ھ�̬��̬��ѯʱ����Ч�ġ�
        // ���������ϵļ��������������һ����ʱ������������£�GetSize��������ֵ����1��
        // GetPoint����֧�ֲ�ѯ�������������顣
        NODISCARD Vector GetLhsClosestPoint() const;
        NODISCARD Vector GetRhsClosestPoint() const;
        NODISCARD Vector GetLhsClosestPoint(int index) const;
        NODISCARD Vector GetRhsClosestPoint(int index) const;
        NODISCARD int GetLhsClosestPointSize() const;
        NODISCARD int GetRhsClosestPointSize() const;

        void SetDistance(Real distance);
        void SetContactTime(Real contactTime);
        void SetSqrtDistance(Real distance);
        void Set(Real distance, Real contactTime);

        NODISCARD Real GetLhsParameter() const;
        NODISCARD Real GetRhsParameter() const;

    private:
        PackageType impl;
    };

    using DistanceResult2F = DistanceResult<float, Vector2F>;
    using DistanceResult3F = DistanceResult<float, Vector3F>;
    using DistanceResult2D = DistanceResult<double, Vector2D>;
    using DistanceResult3D = DistanceResult<double, Vector3D>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_H

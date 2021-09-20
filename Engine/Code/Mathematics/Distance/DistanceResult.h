///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/05 23:49)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ImplStaticAssertHelper.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceResultImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DistanceResultImpl<float, Vector2D<float>>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DistanceResultImpl<double, Vector2D<double>>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DistanceResultImpl<float, Vector3D<float>>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DistanceResultImpl<double, Vector3D<double>>>;

    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DistanceResultImpl<Real, Vector>>;

    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceResult final
    {
    public:
        using DistanceResultImpl = DistanceResultImpl<Real, Vector>;
        void Copy();

    public:
        TYPE_DECLARE(DistanceResult);
        using ClassShareType = CoreTools::DelayCopyUnsharedClasses;

        using ClosestPoints = std::vector<Vector>;

    public:
        explicit DistanceResult(Real distance);
        DistanceResult(Real distance, Real contactTime);
        DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint);
        DistanceResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);
        DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetDistance() const noexcept;

        // 发生在动态查询其最小距离的时间。
        [[nodiscard]] Real GetContactTime() const noexcept;

        // 关于两个对象的最近点。这些在静态或动态查询时是有效的。
        // 单个对象上的集最近点的如果不是一个点时，在这种情况下，GetSize函数返回值大于1。
        // GetPoint可以支持查询整个最近点的数组。
        [[nodiscard]] const Vector GetLhsClosestPoint() const;
        [[nodiscard]] const Vector GetRhsClosestPoint() const;
        [[nodiscard]] const Vector GetLhsClosestPoint(int index) const;
        [[nodiscard]] const Vector GetRhsClosestPoint(int index) const;
        [[nodiscard]] int GetLhsClosestPointSize() const;
        [[nodiscard]] int GetRhsClosestPointSize() const;

        void SetDistance(Real distance);
        void SetContactTime(Real contactTime);
        void SetSqrtDistance();
        void Set(Real distance, Real contactTime);

        [[nodiscard]] Real GetLhsParameter() const;
        [[nodiscard]] Real GetRhsParameter() const;

    private:
        using DistanceResultImplPtr  = std::shared_ptr<ImplType>;

    private:
        DistanceResultImplPtr impl;
    };

    using FloatDistanceResult2 = DistanceResult<float, FloatVector2D>;
    using FloatDistanceResult3 = DistanceResult<float, FloatVector3D>;
    using DoubleDistanceResult2 = DistanceResult<double, DoubleVector2D>;
    using DoubleDistanceResult3 = DistanceResult<double, DoubleVector3D>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_H

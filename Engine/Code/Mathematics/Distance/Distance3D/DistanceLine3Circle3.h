///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 15:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Circle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceLine3Circle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Circle3(const Line3& line, const Circle3& circle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 对象访问。
        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

        /// 静态距离查询。 计算从点P到圆的距离。
        /// 当P在法线C + t * N上，其中C是圆心并且N是包含该圆的平面的法线时，则所有圆点都与P等距。
        /// 在这种情况下，返回点为C + r * U ，其中U是垂直于N的向量。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 动态距离查询的函数计算。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        struct DistanceInfo
        {
            Real m_SqrDistance;
            int m_NumClosestCircle;
            Vector3D m_ClosestCircle;

            DistanceInfo(Real sqrDistance, int numClosestCircle, const Vector3D& closestCircle) noexcept;
        };

        /// mClosestLine[i]是输入。 mClosestCircle[i]是输出。
        /// 返回它们之间的平方距离。 mNumClosest的值设置为1或INT_MAX。 如果是后者，则所有圆点都与mClosestLine[i]等距。
        DistanceInfo SqrDistancePointCircle(const Vector3D& closestLine) const;

        // 将函数F(s) = s + m2b2 - r * m0sqr * s / sqrt(m0sqr * s * s + b1sqr)分成指定间隔[smin，smax]。
        static Real BisectF(Real lineDotDiff, Real radiusMultiplyDot, Real dot, Real diffCrossNormalDot, Real smin, Real smax);

        Line3 m_Line;
        Circle3 m_Circle;       
    };

    using FloatDistanceLine3Circle3 = DistanceLine3Circle3<float>;
    using DoubleDistanceLine3Circle3 = DistanceLine3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/21 14:13)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"

namespace Mathematics
{
    template <typename Real>
    class DistancePoint2Ellipse2Tool final
    {
    public:
        using ClassType = DistancePoint2Ellipse2Tool<Real>;
        using Vector2 = Vector2<Real>;
        using Math = Math<Real>;

    public:
        DistancePoint2Ellipse2Tool(Real extent0, Real extent1, const Vector2& vector, Real zeroThreshold);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetSquaredDistance() const noexcept;
        NODISCARD Vector2 GetOutputVector() const noexcept;

    private:
        // 椭圆是(x0 / e0)^2 + (x1 / e1)^2 = 1且e0 >= e1。
        // 查询点是(y0,y1)与 y0 >= 0 和y1 >= 0
        // 函数返回从查询点到椭圆的平方距离。
        // 它也计算在第一象限最接近(y0,y1)的椭圆点 (x0,x1) 。
        void ComputeSquaredDistance();

        // 椭圆是 (x0 / e0)^2 + (x1 / e1)^2 = 1。
        // 查询点是 (y0,y1)。
        // 函数返回从查询点到椭圆的平方距离。
        // 它也计算最接近(y0,y1)的椭圆点 (x0,x1) 。
        void ComputeSquaredDistanceSpecial(const Vector2& localExtent, const Vector2& queryPoint);

    private:
        Vector2 extent;
        Vector2 inputVector;
        Vector2 outputVector;
        Real squaredDistance;
        Real zeroThreshold;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H

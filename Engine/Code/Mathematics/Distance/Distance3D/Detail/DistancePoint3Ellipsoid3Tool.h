///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class DistancePoint3Ellipsoid3Tool final
    {
    public:
        using ClassType = DistancePoint3Ellipsoid3Tool<Real>;

        using Vector3Type = Vector3<Real>;
        using MathType = Math<Real>;

    public:
        DistancePoint3Ellipsoid3Tool(Real extent0, Real extent1, Real extent2, const Vector3Type& vector, Real zeroThreshold);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetSquaredDistance() const noexcept;
        NODISCARD Vector3Type GetOutputVector() const noexcept;

    private:
        using Container = std::vector<Real>;

    private:
        // 椭圆是(x0 / e0)^2 + (x1 / e1)^2 + (x2 / e2)^2 = 1且e0 >= e1 >= e2。
        // 查询点是(y0,y1,y2)与 y0 >= 0 ,y1 >= 0和y2 >= 0
        // 函数返回从查询点到椭圆的平方距离。
        // 它也计算在第一象限最接近(y0,y1,y2)的椭圆点(x0,x1,x2) 。
        void ComputeSquaredDistance();

        // 椭圆是 (x0 / e0)^2 + (x1 / e1)^2 + (x2 / e2)^2 = 1。
        // 查询点是 (y0,y1,y2)。
        // 函数返回从查询点到椭圆的平方距离。
        // 它也计算最接近(y0,y1,y2)的椭圆点 (x0,x1,x2)  。
        void ComputeSquaredDistanceSpecial(const Vector3Type& extent, const Vector3Type& queryPoint);

        // 该平分算法来寻找F(t)的唯一根。
        NODISCARD Container Bisector(const Container& extent, const Container& queryPoint);

    private:
        Vector3Type toolExtent;
        Vector3Type inputVector;
        Vector3Type outputVector;
        Real squaredDistance;
        Real zeroThreshold;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H

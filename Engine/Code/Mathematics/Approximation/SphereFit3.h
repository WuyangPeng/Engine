///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 11:09)

#ifndef MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
#define MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    // 对一组点的最小二次拟合球。
    // 如果迭代的次数已超过maxIterations，触发一个断言。尝试增加迭代的最大数量。
    // 如果initialCenterIsAverage设置为“真”，
    // 对于球体中心的初始猜测是数据点的平均值。
    // 如果数据点沿一个立体角的群集，SphereFit3是收敛速度很慢。
    // 如果initialCenterIsAverage设置为“假”，
    // 球体中心的初始值猜测使用一个球面二次方程，
    // 表示一个球面的系数的最小二乘法来估算。
    // 这种做法往往会迅速收敛。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SphereFit3 final
    {
    public:
        using ClassType = SphereFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Points = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        SphereFit3(const Points& points, int maxIterations, bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

    private:
        void Calculate(const Points& points, int maxIterations, bool initialCenterIsAverage);
        [[nodiscard]] const Vector3D GetAveragePoint(const Points& points);
        void Iteration(const Points& points, const Vector3D& average);

    private:
        Sphere3 m_Sphere;
    };

    using FloatSphereFit3 = SphereFit3<float>;
    using DoubleSphereFit3 = SphereFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H

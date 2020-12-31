///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 14:51)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // 最小二乘使用距离测量正交拟合了一个大圆到单位长度向量 (x,y,z) （并沿大圆测量）所建议的大圆。
    // 输入points[]是单位长度。返回的值是单位长度，把它叫做N。
    // 拟合的大圆定义为Dot(N,X) = 0，其中X是大圆一个单位长度矢量。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GreatCircleFit3 final
    {
    public:
        using ClassType = GreatCircleFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Points = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        explicit GreatCircleFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetNormal() noexcept;

    private:
        void Calculate(const Points& points);

    private:
        Vector3D m_Normal;
    };

    using FloatGreatCircleFit3 = GreatCircleFit3<float>;
    using DoubleGreatCircleFit3 = GreatCircleFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H

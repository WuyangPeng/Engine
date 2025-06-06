///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:25)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"

#include <vector>

namespace Mathematics
{
    // 高斯分布拟合点。该中心是点的平均值，轴是所述协方差矩阵的特征向量，
    // 而扩展是协方差矩阵的特征值和并以递增的顺序返回。
    // 数量存储在Box2<Real>仅仅有一个单一的容器中。
    template <typename Real>
    class GaussPointsFit2 final
    {
    public:
        using ClassType = GaussPointsFit2<Real>;

        using Vector2Type = Vector2<Real>;
        using Box2Type = Box2<Real>;
        using MathType = Math<Real>;
        using PointsType = std::vector<Vector2Type>;

    public:
        explicit GaussPointsFit2(const PointsType& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Box2Type GetBox2() const noexcept;

    private:
        NODISCARD static Box2Type Calculate(const PointsType& points);

    private:
        Box2Type box;
    };

    using GaussPointsFit2F = GaussPointsFit2<float>;
    using GaussPointsFit2D = GaussPointsFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H

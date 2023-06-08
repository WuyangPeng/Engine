///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:18)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"

#include <vector>

namespace Mathematics
{
    // 高斯分布拟合点。该中心是点的平均值，轴是所述协方差矩阵的特征向量，
    // 而扩展是协方差矩阵的特征值和并以递增的顺序返回。
    // 数量存储在Box3<Real>仅仅有一个单一的容器中。
    template <typename Real>
    class GaussPointsFit3 final
    {
    public:
        using ClassType = GaussPointsFit3<Real>;
        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using PointsType = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        explicit GaussPointsFit3(const PointsType& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Box3 GetBox3() const noexcept;

    private:
        NODISCARD static Box3 Calculate(const PointsType& points);

    private:
        Box3 box;
    };

    using GaussPointsFit3F = GaussPointsFit3<float>;
    using GaussPointsFit3D = GaussPointsFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H

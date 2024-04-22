/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 10:29)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN3_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN3_H

#include "Mathematics/MathematicsDll.h"

#include "ApproximationQuery.h"
#include "Mathematics/Algebra/Vector/Vector3.h"
#include "Mathematics/Primitives/OrientedBox.h"

/// 使用高斯分布拟合点。
/// 中心是点的平均值，轴是协方差矩阵的特征向量，范围是协方差阵的特征值，并按递增顺序返回。
/// 定向框用于存储平均值、轴和范围。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationGaussian3 : public ApproximationQuery<Real, Algebra::Vector3<Real>>
    {
    public:
        using ClassType = ApproximationGaussian3<Real>;
        using ParentType = ApproximationQuery<Real, Algebra::Vector3<Real>>;

        using OrientedBox3 = Algebra::OrientedBox3<Real>;
        using Vector3 = Algebra::Vector3<Real>;
        using ObservationTypeContainer = std::vector<Vector3>;
        using IndicesContainer = std::vector<int>;
        using Math = Math<Real>;

    public:
        ApproximationGaussian3() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 基本拟合算法。有关可以调用的各种 Fit(...)函数，请参见ApproximationQuery.h。
        NODISCARD bool FitIndexed(const ObservationTypeContainer& observations, const IndicesContainer& indices) override;

        /// 获取最适合的参数。
        NODISCARD OrientedBox3 GetParameters() const noexcept;

        NODISCARD int GetMinimumRequired() const noexcept override;

        NODISCARD Real Error(const Vector3& point) const override;

        void CopyParameters(const ParentType& input) override;

    private:
        OrientedBox3 parameters;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN3_H

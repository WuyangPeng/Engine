/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 19:16)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_QUERY_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_QUERY_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

/// 对最小二乘拟合算法和RANSAC算法的基类支持。
namespace Mathematics
{
    template <typename Real, typename ObservationType>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationQuery
    {
    public:
        using ClassType = ApproximationQuery<Real, ObservationType>;

        using ObservationTypeContainer = std::vector<ObservationType>;
        using IndicesContainer = std::vector<int>;

    public:
        ApproximationQuery() noexcept;
        virtual ~ApproximationQuery() noexcept = default;
        ApproximationQuery(const ApproximationQuery& rhs) = default;
        ApproximationQuery& operator=(const ApproximationQuery& rhs) = default;
        ApproximationQuery(ApproximationQuery&& rhs) noexcept = default;
        ApproximationQuery& operator=(ApproximationQuery&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        /// 基类Fit*函数是通用的，但需要为特定的派生类调用索引拟合函数。
        NODISCARD virtual bool FitIndexed(const ObservationTypeContainer& observations, const IndicesContainer& indices) = 0;

        NODISCARD bool ValidIndices(const ObservationTypeContainer& observations, const IndicesContainer& indices) noexcept(!isApproximationQueryValidateIndices);

        /// 估计通过std::vector传入的所有观测值的模型参数。
        NODISCARD bool Fit(const ObservationTypeContainer& observations);

        /// 估计观测值的连续子集的模型参数。
        NODISCARD bool Fit(const ObservationTypeContainer& observations, int iMin, int iMax);

        /// 估计观测值的索引子集的模型参数。
        NODISCARD virtual bool Fit(const ObservationTypeContainer& observations, const IndicesContainer& indices);

        /// 估计由索引和可能小于indices.size()的索引数量指定的观测子集的模型参数。
        NODISCARD bool Fit(const ObservationTypeContainer& observations, const IndicesContainer& indices, int numIndices);

        /// 应用随机抽样一致性算法将模型拟合到观测值。
        /// 该算法需要三个虚拟函数才能由派生类实现。

        /// 拟合模型所需的最小观测次数。
        NODISCARD virtual int GetMinimumRequired() const = 0;

        /// 计算当前模型参数的指定观测值的模型误差。
        NODISCARD virtual Real Error(const ObservationType& observation) const = 0;

        /// 在两个模型之间复制参数。这用于将候选模型参数复制到当前最佳拟合模型。
        virtual void CopyParameters(const ApproximationQuery& input) = 0;

        NODISCARD static bool Ransac(ApproximationQuery& candidateModel,
                                     const ObservationTypeContainer& observations,
                                     int numRequiredForGoodFit,
                                     Real maxErrorForGoodFit,
                                     int numIterations,
                                     IndicesContainer& bestConsensus,
                                     ApproximationQuery& bestModel);
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_QUERY_H

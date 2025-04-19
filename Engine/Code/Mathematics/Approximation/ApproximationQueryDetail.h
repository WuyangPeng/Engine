/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 19:16)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_QUERY_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_QUERY_DETAIL_H

#include "ApproximationQuery.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Time/Timer.h"

#include <algorithm>
#include <numeric>
#include <random>
#include <ranges>

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationQuery<Real, ObservationType>::ApproximationQuery() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationQuery<Real, ObservationType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationQuery<Real, ObservationType>::ValidIndices(const ObservationTypeContainer& observations, const IndicesContainer& indices) noexcept(!isApproximationQueryValidateIndices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#if defined(MATHEMATICS_APPROXIMATION_QUERY_VALIDATE_INDICES)

    const auto numIndices = boost::numeric_cast<int>(indices.size());
    const auto numObservations = boost::numeric_cast<int>(observations.size());
    if (!observations.empty() &&
        !indices.empty() &&
        GetMinimumRequired() <= numIndices &&
        numIndices <= numObservations)
    {
        auto currentIndex = 0;
        for (auto i = 0; i < numIndices; ++i)
        {
            if (indices.at(currentIndex++) >= numObservations)
            {
                return false;
            }
        }
        return true;
    }

    return false;

#else  // !MATHEMATICS_APPROXIMATION_QUERY_VALIDATE_INDICES

    /// 调用者负责传递正确格式的数据。
    System::UnusedFunction(observations, indices);

    return true;

#endif  // MATHEMATICS_APPROXIMATION_QUERY_VALIDATE_INDICES
}

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationQuery<Real, ObservationType>::Fit(const ObservationTypeContainer& observations)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    IndicesContainer indices(observations.size());
    std::iota(indices.begin(), indices.end(), 0);
    return FitIndexed(observations, indices);
}

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationQuery<Real, ObservationType>::Fit(const ObservationTypeContainer& observations, int iMin, int iMax)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (iMin <= iMax)
    {
        const auto numIndices = iMax - iMin + 1;
        IndicesContainer indices(numIndices);
        std::iota(indices.begin(), indices.end(), iMin);
        return FitIndexed(observations, indices);
    }
    else
    {
        return false;
    }
}

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationQuery<Real, ObservationType>::Fit(const ObservationTypeContainer& observations, const IndicesContainer& indices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return FitIndexed(observations, indices);
}

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationQuery<Real, ObservationType>::Fit(const ObservationTypeContainer& observations, const IndicesContainer& indices, int numIndices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto iMax = std::min(numIndices, boost::numeric_cast<int>(indices.size()));
    IndicesContainer localIndices(iMax);
    std::copy_n(indices.begin(), iMax, localIndices.begin());
    return FitIndexed(observations, localIndices);
}

template <typename Real, typename ObservationType>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationQuery<Real, ObservationType>::Ransac(ApproximationQuery& candidateModel, const ObservationTypeContainer& observations, int numRequiredForGoodFit, Real maxErrorForGoodFit, int numIterations, IndicesContainer& bestConsensus, ApproximationQuery& bestModel)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto numObservations = boost::numeric_cast<int>(observations.size());
    const auto minRequired = candidateModel.GetMinimumRequired();
    if (numObservations < minRequired)
    {
        /// 用于模型拟合的观测值太少。
        return false;
    }

    /// 数组的第一部分将存储共识集，该共识集最初填充有与候选内列相对应的最小数量的索引。
    /// 最后一部分将存储剩余的索引。这些点将根据模型进行测试，
    /// 并在它们合适时添加到共识集中。
    /// 所有的索引操作都已到位。
    /// 最初，候选者是身份置换。
    IndicesContainer candidates(numObservations);
    std::iota(candidates.begin(), candidates.end(), 0);

    if (numObservations == minRequired)
    {
        /// 我们有最小数量的观测值来生成模型，因此不能使用Ransac。
        /// 用整套观测值计算模型。
        bestConsensus = candidates;
        return bestModel.Fit(observations);
    }

    auto bestNumFittedObservations = minRequired;

    for (auto i = 0; i < numIterations; ++i)
    {
        /// 随机排列前面的候选，将数组划分为GetMinimumRequired()索引（候选索引）和剩余索引（用于针对模型进行测试的候选索引）。
        const auto timer = CoreTools::Timer::Create();
        std::ranges::shuffle(candidates, std::default_random_engine(boost::numeric_cast<uint32_t>(timer.GetMilliseconds())));

        /// 将模型安装到内侧。
        if (candidateModel.Fit(observations, candidates, minRequired))
        {
            /// 测试每个剩余的观察结果是否符合模型。
            /// 如果是，请将其纳入协商一致意见。
            auto numFittedObservations = minRequired;
            for (auto j = minRequired; j < numObservations; ++j)
            {
                auto error = candidateModel.Error(observations.at(candidates.at(j)));
                if (error <= maxErrorForGoodFit)
                {
                    std::swap(candidates.at(j), candidates.at(numFittedObservations));
                    ++numFittedObservations;
                }
            }

            if (numFittedObservations >= numRequiredForGoodFit)
            {
                /// 我们的观察结果符合模型。使用共识集更新最佳模型。
                std::ignore = candidateModel.Fit(observations, candidates, numFittedObservations);
                if (numFittedObservations > bestNumFittedObservations)
                {
                    /// 共识集比以前的共识集大，因此它的模型成为最佳模型.
                    bestModel.CopyParameters(candidateModel);
                    bestConsensus.resize(numFittedObservations);
                    std::copy(candidates.begin(), candidates.begin() + numFittedObservations, bestConsensus.begin());
                    bestNumFittedObservations = numFittedObservations;
                }
            }
        }
    }

    return bestNumFittedObservations >= numRequiredForGoodFit;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_QUERY_DETAIL_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 09:26)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_HEIGHT_LINE2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_HEIGHT_LINE2_DETAIL_H

#include "ApproximationHeightLine2.h"
#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationHeightLine2<Real>::ApproximationHeightLine2() noexcept
    : ParentType{}, parameters{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationHeightLine2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationHeightLine2<Real>::FitIndexed(const ObservationTypeContainer& observations, const IndicesContainer& indices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto numIndices = boost::numeric_cast<int>(indices.size());

    if (this->ValidIndices(observations, indices))
    {
        /// 计算点的平均值。
        Vector2 mean{};
        auto currentIndex = 0;
        for (auto i = 0; i < numIndices; ++i)
        {
            mean += observations.at(indices.at(currentIndex++));
        }
        mean /= boost::numeric_cast<Real>(numIndices);

        if (std::isfinite(mean[0]) && std::isfinite(mean[1]))
        {
            /// 计算点的协方差矩阵。
            Real covar00{};
            Real covar01{};
            currentIndex = 0;
            for (auto i = 0; i < numIndices; ++i)
            {
                auto diff = observations.at(indices.at(currentIndex++)) - mean;
                covar00 += diff[0] * diff[0];
                covar01 += diff[0] * diff[1];
            }

            /// 分解协方差矩阵。
            if (covar00 > Real{})
            {
                parameters.first = mean;
                parameters.second[0] = covar01 / covar00;
                parameters.second[1] = Math::GetValue(-1);
                return true;
            }
        }
    }

    parameters.first = Vector2::GetZero();
    parameters.second = Vector2::GetZero();

    return false;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationHeightLine2<Real>::ParametersType Mathematics::ApproximationHeightLine2<Real>::GetParameters() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return parameters;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::ApproximationHeightLine2<Real>::GetMinimumRequired() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return 2;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationHeightLine2<Real>::Error(const Vector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto d = Dot(point - parameters.first, parameters.second);
    auto error = d * d;
    return error;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationHeightLine2<Real>::CopyParameters(const ParentType& input)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto source = dynamic_cast<const ApproximationHeightLine2&>(input);

    *this = source;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_HEIGHT_LINE2_DETAIL_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/04 00:06)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN2_DETAIL_H

#include "ApproximationGaussian2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/SymmetricEigensolver2x2.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationGaussian2<Real>::ApproximationGaussian2() noexcept
    : ParentType{}, parameters{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationGaussian2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationGaussian2<Real>::FitIndexed(const ObservationTypeContainer& observations, const IndicesContainer& indices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (this->ValidIndices(observations, indices))
    {
        /// 计算点的平均值。
        Vector2 mean{};
        auto currentIndex = 0;
        for (auto i = 0u; i < indices.size(); ++i)
        {
            mean += observations.at(currentIndex++);
        }
        auto invSize = MathType::GetValue(1) / boost::numeric_cast<Real>(indices.size());
        mean *= invSize;

        if (std::isfinite(mean[0]) && std::isfinite(mean[1]))
        {
            /// 计算点的协方差矩阵。
            Real covar00{};
            Real covar01{};
            Real covar11{};
            currentIndex = 0;
            for (auto i = 0u; i < indices.size(); ++i)
            {
                auto diff = observations.at(currentIndex++) - mean;
                covar00 += diff[0] * diff[0];
                covar01 += diff[0] * diff[1];
                covar11 += diff[1] * diff[1];
            }
            covar00 *= invSize;
            covar01 *= invSize;
            covar11 *= invSize;

            /// 求解特征系统。
            const SymmetricEigensolver2x2<Real> es{};
            std::array<Real, 2> eval{};
            std::array<std::array<Real, 2>, 2> evec{};
            es(covar00, covar01, covar11, +1, eval, evec);
            parameters.SetCenter(mean);
            parameters.SetAxis({ Vector2{ evec.at(0) }, Vector2{ evec.at(1) } });
            parameters.SetExtent(Vector2{ eval });
            return true;
        }
    }

    parameters.SetCenter(Vector2::GetZero());
    parameters.SetAxis({ Vector2::GetZero(), Vector2::GetZero() });
    parameters.SetExtent(Vector2::GetZero());
    return false;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationGaussian2<Real>::OrientedBox2 Mathematics::ApproximationGaussian2<Real>::GetParameters() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return parameters;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::ApproximationGaussian2<Real>::GetMinimumRequired() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return 2;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationGaussian2<Real>::Error(const Vector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto diff = point - parameters.GetCenter();
    Real error{};
    for (auto i = 0; i < 2; ++i)
    {
        if (parameters.GetExtent(i) > Real{})
        {
            auto ratio = Dot(diff, parameters.GetAxis(i)) / parameters.GetExtent(i);
            error += ratio * ratio;
        }
    }
    return error;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationGaussian2<Real>::CopyParameters(const ParentType& input)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto source = dynamic_cast<const ClassType&>(input);

    *this = source;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN2_DETAIL_H

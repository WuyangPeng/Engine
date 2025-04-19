/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 10:29)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN3_DETAIL_H

#include "ApproximationGaussian3.h"
#include "ApproximationQueryDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/SymmetricEigensolver3x3.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationGaussian3<Real>::ApproximationGaussian3() noexcept
    : ParentType{}, parameters{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationGaussian3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationGaussian3<Real>::FitIndexed(const ObservationTypeContainer& observations, const IndicesContainer& indices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (this->ValidIndices(observations, indices))
    {
        /// 计算点的平均值。
        Vector3 mean{};
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
            Real covar02{};
            Real covar11{};
            Real covar12{};
            Real covar22{};
            currentIndex = 0;
            for (auto i = 0u; i < indices.size(); ++i)
            {
                auto diff = observations.at(currentIndex++) - mean;
                covar00 += diff[0] * diff[0];
                covar01 += diff[0] * diff[1];
                covar02 += diff[0] * diff[2];
                covar11 += diff[1] * diff[1];
                covar12 += diff[1] * diff[2];
                covar22 += diff[2] * diff[2];
            }
            covar00 *= invSize;
            covar01 *= invSize;
            covar02 *= invSize;
            covar11 *= invSize;
            covar12 *= invSize;
            covar22 *= invSize;

            /// 求解特征系统。
            const SymmetricEigensolver3x3<Real> es{};
            std::array<Real, 3> eval{};
            std::array<std::array<Real, 3>, 3> evec{};
            es(covar00, covar01, covar02, covar11, covar12, covar22, false, +1, eval, evec);
            parameters.SetCenter(mean);
            parameters.SetAxis({ Vector3{ evec.at(0) }, Vector3{ evec.at(1) }, Vector3{ evec.at(2) } });
            parameters.SetExtent(Vector3{ eval });
            return true;
        }
    }

    parameters.SetCenter(Vector3::GetZero());
    parameters.SetAxis({ Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero() });
    parameters.SetExtent(Vector3::GetZero());
    return false;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationGaussian3<Real>::OrientedBox3 Mathematics::ApproximationGaussian3<Real>::GetParameters() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return parameters;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::ApproximationGaussian3<Real>::GetMinimumRequired() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return 2;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationGaussian3<Real>::Error(const Vector3& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto diff = point - parameters.GetCenter();
    Real error{};
    for (auto i = 0; i < 3; ++i)
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
void Mathematics::ApproximationGaussian3<Real>::CopyParameters(const ParentType& input)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto source = dynamic_cast<const ClassType&>(input);

    *this = source;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_GAUSSIAN3_DETAIL_H

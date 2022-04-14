///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/14 17:44)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_DETAIL_H

#include "BSplineCurveFit.h"
#include "BSplineFitBasisDetail.h"
#include "Mathematics/Algebra/BandedMatrixSolveDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::BSplineCurveFit<Real>::BSplineCurveFit(int dimension, int numSamples, const std::vector<Real>& sampleData, int degree, int numControls)
    : dimension{ dimension },
      numSamples{ numSamples },
      sampleData{ sampleData },
      degree{ degree },
      numControls{ numControls },
      controlData(gsl::narrow_cast<size_t>(dimension) * gsl::narrow_cast<size_t>(numControls)),
      basis{ numControls, degree }
{
    MATHEMATICS_ASSERTION_0(dimension >= 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree < numControls, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numControls <= numSamples, "无效输入。\n");

    BSplineFitBasis<Real> dBasis{ numControls, degree };
    auto tMultiplier = Math::GetValue(1) / static_cast<Real>(gsl::narrow_cast<size_t>(numSamples) - 1);

    BandedMatrixSolve<Real> ataMat{ numControls, degree + 1, degree + 1 };

    for (auto i0 = 0; i0 < numControls; ++i0)
    {
        for (auto i1 = 0; i1 < i0; ++i1)
        {
            ataMat(i0, i1) = ataMat(i1, i0);
        }

        auto i1Max = i0 + degree;
        if (i1Max >= numControls)
        {
            i1Max = numControls - 1;
        }

        for (auto i1 = i0; i1 <= i1Max; ++i1)
        {
            auto value = Math::GetValue(0);
            for (auto i2 = 0; i2 < numSamples; ++i2)
            {
                auto t = tMultiplier * Math::GetValue(i2);
                auto imin = 0;
                auto imax = 0;
                dBasis.Compute(t, imin, imax);
                if (imin <= i0 && i0 <= imax && imin <= i1 && i1 <= imax)
                {
                    auto dB0 = dBasis.GetValue(i0 - imin);
                    auto dB1 = dBasis.GetValue(i1 - imin);
                    value += dB0 * dB1;
                }
            }

            ataMat(i0, i1) = value;
        }
    }

    VariableMatrix<Real> atMat{ numSamples, numControls };

    for (auto i0 = 0; i0 < numControls; ++i0)
    {
        for (auto i1 = 0; i1 < numSamples; ++i1)
        {
            auto t = tMultiplier * Math::GetValue(i1);
            auto imin = 0;
            auto imax = 0;
            dBasis.Compute(t, imin, imax);
            if (imin <= i0 && i0 <= imax)
            {
                atMat[i0][i1] = dBasis.GetValue(i0 - imin);
            }
        }
    }

    atMat = ataMat.SolveSystem(atMat);

    for (auto i0 = 0; i0 < numControls; ++i0)
    {
        for (auto i1 = 0; i1 < numSamples; ++i1)
        {
            auto xValue = atMat[i0][i1];
            for (auto j = 0; j < dimension; ++j)
            {
                const auto controlDataIndex = i0 * dimension + j;
                const auto sampleDataIndex = i1 * dimension + j;
                controlData.at(controlDataIndex) += xValue * sampleData.at(sampleDataIndex);
            }
        }
    }

    auto index = 0;
    for (auto j = 0; j < dimension; j++)
    {
        controlData.at(index) = sampleData.at(index);

        const auto controlDataIndex = index + dimension * (numControls - 1);
        const auto sampleDataIndex = index + dimension * (numSamples - 1);
        controlData.at(controlDataIndex) = sampleData.at(sampleDataIndex);

        ++index;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineCurveFit<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BSplineCurveFit<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return dimension;
}

template <typename Real>
int Mathematics::BSplineCurveFit<Real>::GetSampleQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numSamples;
}

template <typename Real>
std::vector<Real> Mathematics::BSplineCurveFit<Real>::GetSampleData() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sampleData;
}

template <typename Real>
int Mathematics::BSplineCurveFit<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return degree;
}

template <typename Real>
int Mathematics::BSplineCurveFit<Real>::GetControlQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numControls;
}

template <typename Real>
std::vector<Real> Mathematics::BSplineCurveFit<Real>::GetControlData() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return controlData;
}

template <typename Real>
const Mathematics::BSplineFitBasis<Real>& Mathematics::BSplineCurveFit<Real>::GetBasis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis;
}

template <typename Real>
std::vector<Real> Mathematics::BSplineCurveFit<Real>::GetPosition(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    std::vector<Real> position{};

    auto imin = 0;
    auto imax = 0;
    basis.Compute(t, imin, imax);

    auto basisValue = basis.GetValue(0);

    auto index = 0;
    for (auto j = 0; j < dimension; ++j)
    {
        const auto controlDataIndex = dimension * imin + index;
        position.emplace_back(basisValue * controlData.at(controlDataIndex));
        ++index;
    }

    index = 1;
    for (auto i = imin + 1; i <= imax; ++i)
    {
        basisValue = basis.GetValue(index);
        for (auto j = 0; j < dimension; ++j)
        {
            const auto controlDataIndex = dimension * imin + index;
            position.at(j) += basisValue * controlData.at(controlDataIndex);
            ++index;
        }
    }

    return position;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_DETAIL_H
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:49)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_DETAIL_H

#include "BSplineSurfaceFit.h"
#include "Mathematics/Algebra/BandedMatrixSolveDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename Real>
Mathematics::BSplineSurfaceFit<Real>::BSplineSurfaceFit(int degree0, int numControls0, int numSamples0, int degree1, int numControls1, int numSamples1, const std::vector<std::vector<Vector3<Real>>>& samples)
    : numSamples{ numSamples0, numSamples1 },
      samples{ samples },
      degree{ degree0, degree1 },
      numControls{ numControls0, numControls1 },
      controls(numControls0, std::vector<Vector3<Real>>(numControls1)),
      basis{}
{
    MATHEMATICS_ASSERTION_0(1 <= degree0 && degree0 + 1 < numControls0, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numControls0 <= numSamples0, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= degree1 && degree1 + 1 < numControls1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numControls1 <= numSamples1, "无效输入。\n");

    std::array<std::shared_ptr<BSplineFitBasis<Real>>, 2> dBasis{};
    std::array<Real, 2> tMultiplier{};

    for (auto dim = 0; dim < 2; ++dim)
    {
        basis.at(dim) = std::make_shared<BSplineFitBasis<Real>>(numControls.at(dim), degree.at(dim));

        dBasis.at(dim) = std::make_shared<BSplineFitBasis<Real>>(numControls.at(dim), degree.at(dim));

        tMultiplier.at(dim) = Math<Real>::GetValue(1) / Math<Real>::GetValue(numSamples.at(dim) - 1);
    }

    std::array<std::shared_ptr<BandedMatrixSolve<Real>>, 2> ataMat{};
    for (auto dim = 0; dim < 2; ++dim)
    {
        ataMat.at(dim) = std::make_shared<BandedMatrixSolve<Real>>(numControls.at(dim), degree.at(dim) + 1, degree.at(dim) + 1);

        for (auto i0 = 0; i0 < numControls.at(dim); ++i0)
        {
            for (auto i1 = 0; i1 < i0; ++i1)
            {
                (*ataMat.at(dim))(i0, i1) = (*ataMat.at(dim))(i1, i0);
            }

            auto i1Max = i0 + degree.at(dim);
            if (i1Max >= numControls.at(dim))
            {
                i1Max = numControls.at(dim) - 1;
            }

            for (auto i1 = i0; i1 <= i1Max; ++i1)
            {
                Real value{};
                for (auto i2 = 0; i2 < numSamples.at(dim); ++i2)
                {
                    auto t = tMultiplier.at(dim) * Math<Real>::GetValue(i2);
                    auto imin = 0;
                    auto imax = 0;
                    dBasis.at(dim)->Compute(t, imin, imax);
                    if (imin <= i0 && i0 <= imax && imin <= i1 && i1 <= imax)
                    {
                        auto b0 = dBasis.at(dim)->GetValue(i0 - imin);
                        auto b1 = dBasis.at(dim)->GetValue(i1 - imin);
                        value += b0 * b1;
                    }
                }
                (*ataMat.at(dim))(i0, i1) = value;
            }
        }
    }

    std::array<VariableMatrix<Real>, 2> atMat{};
    for (auto dim = 0; dim < 2; dim++)
    {
        atMat.at(dim).SetSize(numSamples.at(dim), numControls.at(dim));

        for (auto i0 = 0; i0 < numControls.at(dim); ++i0)
        {
            for (auto i1 = 0; i1 < numSamples.at(dim); ++i1)
            {
                auto t = tMultiplier.at(dim) * Math<Real>::GetValue(i1);
                auto imin = 0;
                auto imax = 0;
                dBasis.at(dim)->Compute(t, imin, imax);
                if (imin <= i0 && i0 <= imax)
                {
                    atMat.at(dim)(i0, i1) = dBasis.at(dim)->GetValue(i0 - imin);
                }
            }
        }
    }

    for (auto dim = 0; dim < 2; ++dim)
    {
        atMat.at(dim) = ataMat.at(dim)->SolveSystem(atMat.at(dim));
    }

    for (auto i1 = 0; i1 < numControls.at(1); ++i1)
    {
        for (auto i0 = 0; i0 < numControls.at(0); ++i0)
        {
            Vector3<Real> sum{};
            for (auto j1 = 0; j1 < numSamples.at(1); ++j1)
            {
                auto x1Value = atMat.at(1)(i1, j1);
                for (auto j0 = 0; j0 < numSamples.at(0); ++j0)
                {
                    auto x0Value = atMat.at(0)(i0, j0);
                    sum += (x0Value * x1Value) * samples.at(j1).at(j0);
                }
            }
            controls.at(i1).at(i0) = sum;
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineSurfaceFit<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BSplineSurfaceFit<Real>::GetSampleQuantity(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numSamples.at(i);
}

template <typename Real>
std::vector<std::vector<Mathematics::Vector3<Real>>> Mathematics::BSplineSurfaceFit<Real>::GetSamplePoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return samples;
}

template <typename Real>
int Mathematics::BSplineSurfaceFit<Real>::GetDegree(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return degree.at(i);
}

template <typename Real>
int Mathematics::BSplineSurfaceFit<Real>::GetControlQuantity(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numControls.at(i);
}

template <typename Real>
std::vector<std::vector<Mathematics::Vector3<Real>>> Mathematics::BSplineSurfaceFit<Real>::GetControlPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return controls;
}

template <typename Real>
const Mathematics::BSplineFitBasis<Real>& Mathematics::BSplineSurfaceFit<Real>::GetBasis(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *basis.at(i);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineSurfaceFit<Real>::GetPosition(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto iumin = 0;
    auto iumax = 0;
    auto ivmin = 0;
    auto ivmax = 0;
    basis.at(0)->Compute(u, iumin, iumax);
    basis.at(1)->Compute(v, ivmin, ivmax);

    auto pos = Vector3<Real>::GetZero();
    for (auto iv = ivmin, j = 0; iv <= ivmax; ++iv, ++j)
    {
        auto value1 = basis.at(1)->GetValue(j);
        for (auto iu = iumin, i = 0; iu <= iumax; ++iu, ++i)
        {
            auto value0 = basis.at(0)->GetValue(i);
            pos += (value0 * value1) * controls.at(iv).at(iu);
        }
    }
    return pos;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_DETAIL_H
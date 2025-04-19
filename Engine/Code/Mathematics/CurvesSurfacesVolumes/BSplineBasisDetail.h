///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:49)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_DETAIL_H

#include "BSplineBasis.h"

#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <memory>

template <typename Real>
Mathematics::BSplineBasis<Real>::BSplineBasis() noexcept
    : ctrlPointsCount{}, degree{}, knot{}, open{}, uniform{}, bD0{}, bD1{}, bD2{}, bD3{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BSplineBasis<Real>::BSplineBasis(int numCtrlPoints, int degree, bool open)
    : ctrlPointsCount{}, degree{}, knot{}, open{}, uniform{}, bD0{}, bD1{}, bD2{}, bD3{}
{
    Create(numCtrlPoints, degree, open);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::BSplineBasis<Real>::Create(int numCtrlPoints, int newDegree, bool newOpen)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    uniform = true;

    const auto numKnots = Initialize(numCtrlPoints, newDegree, newOpen);
    const auto temp = ctrlPointsCount - degree;
    const auto factor = (MathType::GetValue(1)) / (temp);

    if (open)
    {
        auto i = 0;
        for (; i <= degree; ++i)
        {
            knot.at(i) = MathType::GetValue(0);
        }

        for (; i < ctrlPointsCount; ++i)
        {
            const auto value = i - degree;
            knot.at(i) = value * factor;
        }

        for (; i < numKnots; ++i)
        {
            knot.at(i) = MathType::GetValue(1);
        }
    }
    else
    {
        for (auto i = 0; i < numKnots; ++i)
        {
            const auto value = i - degree;
            knot.at(i) = value * factor;
        }
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>::BSplineBasis(int numCtrlPoints, int degree, const std::vector<Real>& interiorKnot)
    : ctrlPointsCount{}, degree{}, knot{}, open{}, uniform{}, bD0{}, bD1{}, bD2{}, bD3{}
{
    Create(numCtrlPoints, degree, interiorKnot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::BSplineBasis<Real>::Create(int numCtrlPoints, int newDegree, const std::vector<Real>& interiorKnot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    uniform = false;

    const auto numKnots = Initialize(numCtrlPoints, newDegree, true);
    auto i = 0;
    for (; i <= degree; ++i)
    {
        knot.at(i) = MathType::GetValue(0);
    }

    for (auto j = 0; i < ctrlPointsCount; ++i, ++j)
    {
        knot.at(i) = interiorKnot.at(j);
    }

    for (; i < numKnots; ++i)
    {
        knot.at(i) = MathType::GetValue(1);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineBasis<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BSplineBasis<Real>::GetNumCtrlPoints() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ctrlPointsCount;
}

template <typename Real>
int Mathematics::BSplineBasis<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return degree;
}

template <typename Real>
bool Mathematics::BSplineBasis<Real>::IsOpen() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return open;
}

template <typename Real>
bool Mathematics::BSplineBasis<Real>::IsUniform() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return uniform;
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>::GetD0(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bD0.at(degree).at(i);
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>::GetD1(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bD1.at(degree).at(i);
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>::GetD2(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bD2.at(degree).at(i);
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>::GetD3(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bD3.at(degree).at(i);
}

template <typename Real>
std::vector<std::vector<Real>> Mathematics::BSplineBasis<Real>::Allocate() const
{
    const auto numRows = degree + 1;
    const auto numCols = ctrlPointsCount + degree;
    std::vector<std::vector<Real>> data(numRows, std::vector<Real>(numCols));

    return data;
}

template <typename Real>
int Mathematics::BSplineBasis<Real>::Initialize(int numCtrlPoints, int newDegree, bool newOpen)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= newDegree && newDegree <= numCtrlPoints - 1, "无效输入。\n");

    ctrlPointsCount = numCtrlPoints;
    degree = newDegree;
    open = newOpen;

    const int numKnots = ctrlPointsCount + degree + 1;
    knot.resize(numKnots);

    bD0 = Allocate();
    bD1.clear();
    bD2.clear();
    bD3.clear();

    return numKnots;
}

template <typename Real>
void Mathematics::BSplineBasis<Real>::SetKnot(int j, Real value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!uniform)
    {
        const auto i = j + degree + 1;
        if (degree + 1 <= i && i <= ctrlPointsCount)
        {
            knot.at(i) = value;
        }
    }
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>::GetKnot(int j) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto i = j + degree + 1;
    if (degree + 1 <= i && i <= ctrlPointsCount)
    {
        return knot.at(i);
    }

    return MathType::maxReal;
}

template <typename Real>
int Mathematics::BSplineBasis<Real>::GetKey(Real& t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (open)
    {
        if (t <= MathType::GetValue(0))
        {
            t = MathType::GetValue(0);
            return degree;
        }
        else if (t >= MathType::GetValue(1))
        {
            t = MathType::GetValue(1);
            return ctrlPointsCount - 1;
        }
    }
    else
    {
        if (t < MathType::GetValue(0) || t >= MathType::GetValue(1))
        {
            t -= MathType::Floor(t);
        }
    }

    int i = 0;

    if (uniform)
    {
        i = degree + static_cast<int>((ctrlPointsCount - degree) * t);
    }
    else
    {
        for (i = degree + 1; i <= ctrlPointsCount; ++i)
        {
            if (t < knot.at(i))
            {
                break;
            }
        }
        --i;
    }

    return i;
}

template <typename Real>
void Mathematics::BSplineBasis<Real>::Compute(Real t, int order, int& minIndex, int& maxIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(order <= 3, "仅支持三阶导数。\n");

    if (order >= 1)
    {
        if (bD1.empty())
        {
            bD1 = Allocate();
        }

        if (order >= 2)
        {
            if (bD2.empty())
            {
                bD2 = Allocate();
            }

            if (order >= 3)
            {
                if (bD3.empty())
                {
                    bD3 = Allocate();
                }
            }
        }
    }

    auto i = GetKey(t);
    bD0.at(0).at(i) = MathType::GetValue(1);

    if (order >= 1)
    {
        bD1.at(0).at(i) = MathType::GetValue(0);
        if (order >= 2)
        {
            bD2.at(0).at(i) = MathType::GetValue(0);
            if (order >= 3)
            {
                bD3.at(0).at(i) = MathType::GetValue(0);
            }
        }
    }

    const auto nextI = i + 1;
    auto n0 = t - knot.at(i);
    auto n1 = knot.at(nextI) - t;
    Real invD0{};
    Real invD1{};

    for (auto j = 1; j <= degree; j++)
    {
        const auto iAddJ = i + j;
        const auto iReduceJ = i - j;
        const auto nextIReduceJ = iReduceJ + 1;
        const auto previousJ = j - 1;
        invD0 = (MathType::GetValue(1)) / (knot.at(iAddJ) - knot.at(i));
        invD1 = (MathType::GetValue(1)) / (knot.at(nextI) - knot.at(nextIReduceJ));

        bD0.at(j).at(i) = n0 * bD0.at(previousJ).at(i) * invD0;
        bD0.at(j).at(iReduceJ) = n1 * bD0.at(previousJ).at(nextIReduceJ) * invD1;

        if (order >= 1)
        {
            bD1.at(j).at(i) = (n0 * bD1.at(previousJ).at(i) + bD0.at(previousJ).at(i)) * invD0;
            bD1.at(j).at(iReduceJ) = (n1 * bD1.at(previousJ).at(nextIReduceJ) - bD0.at(previousJ).at(nextIReduceJ)) * invD1;

            if (order >= 2)
            {
                bD2.at(j).at(i) = (n0 * bD2.at(previousJ).at(i) + (MathType::GetValue(2))*bD1.at(previousJ).at(i)) * invD0;
                bD2.at(j).at(iReduceJ) = (n1 * bD2.at(previousJ).at(nextIReduceJ) - (MathType::GetValue(2))*bD1.at(previousJ).at(nextIReduceJ)) * invD1;

                if (order >= 3)
                {
                    bD3.at(j).at(i) = (n0 * bD3.at(previousJ).at(i) + MathType::GetValue(3) * bD2.at(previousJ).at(i)) * invD0;
                    bD3.at(j).at(iReduceJ) = (n1 * bD3.at(previousJ).at(nextIReduceJ) - MathType::GetValue(3) * bD2.at(previousJ).at(nextIReduceJ)) * invD1;
                }
            }
        }
    }

    for (auto j = 2; j <= degree; ++j)
    {
        for (int k = i - j + 1; k < i; ++k)
        {
            const auto kAddJ = k + j;
            const auto nextK = k + 1;
            const auto nextKAddJ = kAddJ + 1;
            const auto previousJ = j - 1;

            n0 = t - knot.at(k);
            n1 = knot.at(nextKAddJ) - t;
            invD0 = (MathType::GetValue(1)) / (knot.at(kAddJ) - knot.at(k));
            invD1 = (MathType::GetValue(1)) / (knot.at(nextKAddJ) - knot.at(nextK));

            bD0.at(j).at(k) = n0 * bD0.at(previousJ).at(k) * invD0 + n1 * bD0.at(previousJ).at(nextK) * invD1;

            if (order >= 1)
            {
                bD1.at(j).at(k) = (n0 * bD1.at(previousJ).at(k) + bD0.at(previousJ).at(k)) * invD0 + (n1 * bD1.at(previousJ).at(nextK) - bD0.at(previousJ).at(nextK)) * invD1;

                if (order >= 2)
                {
                    bD2.at(j).at(k) = (n0 * bD2.at(previousJ).at(k) + (MathType::GetValue(2))*bD1.at(previousJ).at(k)) * invD0 + (n1 * bD2.at(previousJ).at(nextK) - (MathType::GetValue(2))*bD1.at(previousJ).at(nextK)) * invD1;

                    if (order >= 3)
                    {
                        bD3.at(j).at(k) = (n0 * bD3.at(previousJ).at(k) + MathType::GetValue(3) * bD2.at(previousJ).at(k)) * invD0 + (n1 * bD3.at(previousJ).at(nextK) - MathType::GetValue(3) * bD2.at(previousJ).at(nextK)) * invD1;
                    }
                }
            }
        }
    }

    minIndex = i - degree;
    maxIndex = i;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_DETAIL_H
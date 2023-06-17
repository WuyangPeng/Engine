///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:50)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_DETAIL_H

#include "BSplineVolume.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::BSplineVolume<Real>::BSplineVolume(int numUCtrlPoints, int numVCtrlPoints, int numWCtrlPoints, int uDegree, int vDegree, int wDegree)
    : ctrlPoint{}, basis{}
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numWCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= wDegree && wDegree <= numWCtrlPoints - 1, "无效输入。\n");

    for (auto i = 0; i < numUCtrlPoints; ++i)
    {
        ctrlPoint.emplace_back(numVCtrlPoints, std::vector<Vector3<Real>>(numWCtrlPoints));
    }

    basis.at(0).Create(numUCtrlPoints, uDegree, true);
    basis.at(1).Create(numVCtrlPoints, vDegree, true);
    basis.at(2).Create(numWCtrlPoints, wDegree, true);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineVolume<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BSplineVolume<Real>::GetNumCtrlPoints(int dim) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).GetNumCtrlPoints();
}

template <typename Real>
int Mathematics::BSplineVolume<Real>::GetDegree(int dim) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).GetDegree();
}

template <typename Real>
void Mathematics::BSplineVolume<Real>::SetControlPoint(int uIndex, int vIndex, int wIndex, const Vector3<Real>& newCtrlPoint)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ctrlPoint.at(uIndex).at(vIndex).at(wIndex) = newCtrlPoint;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineVolume<Real>::GetControlPoint(int uIndex, int vIndex, int wIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ctrlPoint.at(uIndex).at(vIndex).at(wIndex);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineVolume<Real>::GetPosition(Real u, Real v, Real w) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto iumin = 0;
    auto iumax = 0;
    auto ivmin = 0;
    auto ivmax = 0;
    auto iwmin = 0;
    auto iwmax = 0;

    basis.at(0).Compute(u, 0, iumin, iumax);
    basis.at(1).Compute(v, 0, ivmin, ivmax);
    basis.at(2).Compute(w, 0, iwmin, iwmax);

    auto pos = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
        auto tmp0 = basis.at(0).GetD0(iu);
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
            auto tmp1 = basis.at(1).GetD0(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
                auto tmp2 = basis.at(2).GetD0(iw);
                auto prod = tmp0 * tmp1 * tmp2;
                pos += prod * ctrlPoint.at(iu).at(iv).at(iw);
            }
        }
    }

    return pos;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineVolume<Real>::GetDerivativeU(Real u, Real v, Real w) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto iumin = 0;
    auto iumax = 0;
    auto ivmin = 0;
    auto ivmax = 0;
    auto iwmin = 0;
    auto iwmax = 0;
    basis.at(0).Compute(u, 1, iumin, iumax);
    basis.at(1).Compute(v, 0, ivmin, ivmax);
    basis.at(2).Compute(w, 0, iwmin, iwmax);

    auto derU = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
        auto tmp0 = basis.at(0).GetD1(iu);
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
            auto tmp1 = basis.at(1).GetD0(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
                auto tmp2 = basis.at(2).GetD0(iw);
                auto prod = tmp0 * tmp1 * tmp2;
                derU += prod * ctrlPoint.at(iu).at(iv).at(iw);
            }
        }
    }

    return derU;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineVolume<Real>::GetDerivativeV(Real u, Real v, Real w) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto iumin = 0;
    auto iumax = 0;
    auto ivmin = 0;
    auto ivmax = 0;
    auto iwmin = 0;
    auto iwmax = 0;
    basis.at(0).Compute(u, 0, iumin, iumax);
    basis.at(1).Compute(v, 1, ivmin, ivmax);
    basis.at(2).Compute(w, 0, iwmin, iwmax);

    auto derV = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
        auto tmp0 = basis.at(0).GetD0(iu);
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
            auto tmp1 = basis.at(1).GetD1(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
                auto tmp2 = basis.at(2).GetD0(iw);
                auto prod = tmp0 * tmp1 * tmp2;
                derV += prod * ctrlPoint.at(iu).at(iv).at(iw);
            }
        }
    }

    return derV;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineVolume<Real>::GetDerivativeW(Real u, Real v, Real w) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto iumin = 0;
    auto iumax = 0;
    auto ivmin = 0;
    auto ivmax = 0;
    auto iwmin = 0;
    auto iwmax = 0;
    basis.at(0).Compute(u, 0, iumin, iumax);
    basis.at(1).Compute(v, 0, ivmin, ivmax);
    basis.at(2).Compute(w, 1, iwmin, iwmax);

    auto derW = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
        auto tmp0 = basis.at(0).GetD0(iu);
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
            auto tmp1 = basis.at(1).GetD0(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
                auto tmp2 = basis.at(2).GetD1(iw);
                auto prod = tmp0 * tmp1 * tmp2;
                derW += prod * ctrlPoint.at(iu).at(iv).at(iw);
            }
        }
    }

    return derW;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineVolume<Real>::GetPosition(const std::array<Real, 3>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetPosition(pos.at(0), pos.at(1), pos.at(2));
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineVolume<Real>::GetDerivative(int i, const std::array<Real, 3>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (i)
    {
        case 0:
            return GetDerivativeU(pos.at(0), pos.at(1), pos.at(2));
        case 1:
            return GetDerivativeV(pos.at(0), pos.at(1), pos.at(2));
        case 2:
            return GetDerivativeW(pos.at(0), pos.at(1), pos.at(2));
        default:
            break;
    }

    return Vector3<Real>::GetZero();
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_DETAIL_H
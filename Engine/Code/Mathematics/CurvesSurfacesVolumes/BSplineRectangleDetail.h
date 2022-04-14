///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 10:27)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_DETAIL_H

#include "BSplineRectangle.h"
#include "ParametricSurfaceDetail.h"
#include "SurfaceDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen)
    : ParentType{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0), Math::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{ ctrlPoint },
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? (uOpen ? 1 : uDegree) : 0) },
      vReplicate{ (vLoop ? (vOpen ? 1 : vDegree) : 0) }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uOpen);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vOpen);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, Real* vKnot)
    : ParentType{ Math ::GetValue(0), Math::GetValue(1), Math ::GetValue(0), Math::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{ ctrlPoint },
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? (uOpen ? 1 : uDegree) : 0) },
      vReplicate{ (vLoop ? 1 : 0) }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uOpen);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vKnot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, bool vOpen)
    : ParentType{ Math ::GetValue(0), Math::GetValue(1), Math ::GetValue(0), Math::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{ ctrlPoint },
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? 1 : 0) },
      vReplicate{ (vLoop ? (vOpen ? 1 : vDegree) : 0) }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uKnot);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vOpen);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, Real* vKnot)
    : ParentType{ Math ::GetValue(0), Math::GetValue(1), Math ::GetValue(0), Math::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{ ctrlPoint },
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? 1 : 0) },
      vReplicate{ (vLoop ? 1 : 0) }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uKnot);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vKnot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineRectangle<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BSplineRectangle<Real>::GetNumCtrlPoints(int dim) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).GetNumCtrlPoints();
}

template <typename Real>
int Mathematics::BSplineRectangle<Real>::GetDegree(int dim) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).GetDegree();
}

template <typename Real>
bool Mathematics::BSplineRectangle<Real>::IsOpen(int dim) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).IsOpen();
}

template <typename Real>
bool Mathematics::BSplineRectangle<Real>::IsUniform(int dim) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).IsUniform();
}

template <typename Real>
bool Mathematics::BSplineRectangle<Real>::IsLoop(int dim) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return loop.at(dim);
}

template <typename Real>
void Mathematics::BSplineRectangle<Real>::SetControlPoint(int uIndex, int vIndex, const Vector3<Real>& ctrl)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= uIndex && uIndex < numUCtrlPoints && 0 <= vIndex && vIndex < numVCtrlPoints)
    {
        ctrlPoint.at(uIndex).at(vIndex) = ctrl;

        const auto doUReplicate = (uIndex < uReplicate);
        const auto doVReplicate = (vIndex < vReplicate);
        auto iUExt = 0;
        auto iVExt = 0;

        if (doUReplicate)
        {
            iUExt = numUCtrlPoints + uIndex;
            ctrlPoint.at(iUExt).at(vIndex) = ctrl;
        }
        if (doVReplicate)
        {
            iVExt = numVCtrlPoints + vIndex;
            ctrlPoint.at(uIndex).at(iVExt) = ctrl;
        }
        if (doUReplicate && doVReplicate)
        {
            ctrlPoint.at(iUExt).at(iVExt) = ctrl;
        }
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineRectangle<Real>::GetControlPoint(int uIndex, int vIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= uIndex && uIndex < numUCtrlPoints && 0 <= vIndex && vIndex < numVCtrlPoints)
    {
        return ctrlPoint.at(uIndex).at(vIndex);
    }

    return Vector3<Real>{ Math ::maxReal, Math ::maxReal, Math ::maxReal };
}

template <typename Real>
void Mathematics::BSplineRectangle<Real>::SetKnot(int dim, int i, Real knot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= dim && dim <= 1)
    {
        basis.at(dim).SetKnot(i, knot);
    }
}

template <typename Real>
Real Mathematics::BSplineRectangle<Real>::GetKnot(int dim, int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= dim && dim <= 1)
    {
        return basis.at(dim).GetKnot(i);
    }

    return Math ::maxReal;
}

template <typename Real>
void Mathematics::BSplineRectangle<Real>::Get(Real u, Real v, Vector3<Real>* pos, Vector3<Real>* derU, Vector3<Real>* derV, Vector3<Real>* derUU, Vector3<Real>* derUV, Vector3<Real>* derVV) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto iumin = 0;
    auto iumax = 0;
    if (derUU != nullptr)
    {
        basis.at(0).Compute(u, 0, iumin, iumax);
        basis.at(0).Compute(u, 1, iumin, iumax);
        basis.at(0).Compute(u, 2, iumin, iumax);
    }
    else if ((derUV != nullptr) || (derU != nullptr))
    {
        basis.at(0).Compute(u, 0, iumin, iumax);
        basis.at(0).Compute(u, 1, iumin, iumax);
    }
    else
    {
        basis.at(0).Compute(u, 0, iumin, iumax);
    }

    auto ivmin = 0;
    auto ivmax = 0;
    if (derVV != nullptr)
    {
        basis.at(1).Compute(v, 0, ivmin, ivmax);
        basis.at(1).Compute(v, 1, ivmin, ivmax);
        basis.at(1).Compute(v, 2, ivmin, ivmax);
    }
    else if ((derUV != nullptr) || (derV != nullptr))
    {
        basis.at(1).Compute(v, 0, ivmin, ivmax);
        basis.at(1).Compute(v, 1, ivmin, ivmax);
    }
    else
    {
        basis.at(1).Compute(v, 0, ivmin, ivmax);
    }

    if (pos != nullptr)
    {
        *pos = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD0(iu) * basis.at(1).GetD0(iv);
                *pos += tmp * ctrlPoint.at(iu).at(iv);
            }
        }
    }

    if (derU != nullptr)
    {
        *derU = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD1(iu) * basis.at(1).GetD0(iv);
                *derU += tmp * ctrlPoint.at(iu).at(iv);
            }
        }
    }

    if (derV != nullptr)
    {
        *derV = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD0(iu) * basis.at(1).GetD1(iv);
                *derV += tmp * ctrlPoint.at(iu).at(iv);
            }
        }
    }

    if (derUU != nullptr)
    {
        *derUU = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD2(iu) * basis.at(1).GetD0(iv);
                *derUU += tmp * ctrlPoint.at(iu).at(iv);
            }
        }
    }

    if (derUV != nullptr)
    {
        *derUV = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD1(iu) * basis.at(1).GetD1(iv);
                *derUV += tmp * ctrlPoint.at(iu).at(iv);
            }
        }
    }

    if (derVV != nullptr)
    {
        *derVV = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD0(iu) * basis.at(1).GetD2(iv);
                *derVV += tmp * ctrlPoint.at(iu).at(iv);
            }
        }
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineRectangle<Real>::P(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> pos{};
    Get(u, v, &pos, 0, 0, 0, 0, 0);

    return pos;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineRectangle<Real>::PU(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derU{};
    Get(u, v, 0, &derU, 0, 0, 0, 0);

    return derU;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineRectangle<Real>::PV(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derV{};
    Get(u, v, 0, 0, &derV, 0, 0, 0);

    return derV;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineRectangle<Real>::PUU(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derUU{};
    Get(u, v, 0, 0, 0, &derUU, 0, 0);

    return derUU;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineRectangle<Real>::PUV(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derUV{};
    Get(u, v, 0, 0, 0, 0, &derUV, 0);

    return derUV;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineRectangle<Real>::PVV(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derVV{};
    Get(u, v, 0, 0, 0, 0, 0, &derVV);

    return derVV;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_DETAIL_H
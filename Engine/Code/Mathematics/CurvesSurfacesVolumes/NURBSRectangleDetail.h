///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/17 16:12)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_RECTANGLE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_RECTANGLE_DETAIL_H

#include "NURBSRectangle.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Real>
Mathematics::NURBSRectangle<Real>::NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, const std::vector<std::vector<Real>>& ctrlWeight, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen)
    : ParentType{ Math<Real>::GetValue(0), Math<Real>::GetValue(1), Math<Real>::GetValue(0), Math<Real>::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{},
      ctrlWeight{},
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? (uOpen ? 1 : uDegree) : 0) },
      vReplicate{ (vLoop ? (vOpen ? 1 : vDegree) : 0) }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint, ctrlWeight);

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uOpen);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vOpen);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::NURBSRectangle<Real>::NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, const std::vector<std::vector<Real>>& ctrlWeight, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, const std::vector<Real>& vKnot)
    : ParentType{ Math<Real>::GetValue(0), Math<Real>::GetValue(1), Math<Real>::GetValue(0), Math<Real>::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{},
      ctrlWeight{},
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? (uOpen ? 1 : uDegree) : 0) },
      vReplicate{ vLoop ? 1 : 0 }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint, ctrlWeight);

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uOpen);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vKnot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::NURBSRectangle<Real>::NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, const std::vector<std::vector<Real>>& ctrlWeight, int uDegree, int vDegree, bool uLoop, bool vLoop, const std::vector<Real>& uKnot, bool vOpen)
    : ParentType{ Math<Real>::GetValue(0), Math<Real>::GetValue(1), Math<Real>::GetValue(0), Math<Real>::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{},
      ctrlWeight{},
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? 1 : 0) },
      vReplicate{ (vLoop ? (vOpen ? 1 : vDegree) : 0) }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint, ctrlWeight);

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uKnot);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vOpen);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::NURBSRectangle<Real>::NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, const std::vector<std::vector<Real>>& ctrlWeight, int uDegree, int vDegree, bool uLoop, bool vLoop, const std::vector<Real>& uKnot, const std::vector<Real>& vKnot)
    : ParentType{ Math<Real>::GetValue(0), Math<Real>::GetValue(1), Math<Real>::GetValue(0), Math<Real>::GetValue(1), true },
      numUCtrlPoints{ numUCtrlPoints },
      numVCtrlPoints{ numVCtrlPoints },
      ctrlPoint{},
      ctrlWeight{},
      loop{ uLoop, vLoop },
      basis{},
      uReplicate{ (uLoop ? 1 : 0) },
      vReplicate{ (vLoop ? 1 : 0) }
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint, ctrlWeight);

    basis.at(0).Create(numUCtrlPoints + uReplicate, uDegree, uKnot);
    basis.at(1).Create(numVCtrlPoints + vReplicate, vDegree, vKnot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::NURBSRectangle<Real>::CreateControl(const std::vector<std::vector<Vector3<Real>>>& newCtrlPoint, const std::vector<std::vector<Real>>& newCtrlWeight)
{
    const auto newNumUCtrlPoints = numUCtrlPoints + uReplicate;
    const auto newNumVCtrlPoints = numVCtrlPoints + vReplicate;

    ctrlPoint.resize(newNumUCtrlPoints, std::vector<Vector3<Real>>(newNumVCtrlPoints));

    ctrlWeight.resize(newNumUCtrlPoints, std::vector<Real>(newNumVCtrlPoints));

    for (auto i = 1; i < newNumUCtrlPoints; ++i)
    {
        ctrlPoint.at(i) = newCtrlPoint.at(gsl::narrow_cast<size_t>(i) * newNumVCtrlPoints);
        ctrlWeight.at(i) = newCtrlWeight.at(gsl::narrow_cast<size_t>(i) * newNumVCtrlPoints);
    }

    for (auto iu = 0; iu < newNumUCtrlPoints; iu++)
    {
        const auto uOld = iu % numUCtrlPoints;
        for (auto iv = 0; iv < newNumVCtrlPoints; iv++)
        {
            const auto vOld = iv % numVCtrlPoints;
            ctrlPoint.at(iu).at(iv) = newCtrlPoint.at(uOld).at(vOld);
            ctrlWeight.at(iu).at(iv) = newCtrlWeight.at(uOld).at(vOld);
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::NURBSRectangle<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::NURBSRectangle<Real>::GetNumCtrlPoints(int dim) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).GetNumCtrlPoints();
}

template <typename Real>
int Mathematics::NURBSRectangle<Real>::GetDegree(int dim) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).GetDegree();
}

template <typename Real>
bool Mathematics::NURBSRectangle<Real>::IsOpen(int dim) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).IsOpen();
}

template <typename Real>
bool Mathematics::NURBSRectangle<Real>::IsUniform(int dim) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.at(dim).IsUniform();
}

template <typename Real>
bool Mathematics::NURBSRectangle<Real>::IsLoop(int dim) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return loop.at(dim);
}

template <typename Real>
void Mathematics::NURBSRectangle<Real>::SetControlPoint(int uIndex, int vIndex, const Vector3<Real>& ctrl)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= uIndex && uIndex < numUCtrlPoints && 0 <= vIndex && vIndex < numVCtrlPoints)
    {
        ctrlPoint.at(uIndex).at(vIndex) = ctrl;

        const auto doUReplicate = (uIndex < uReplicate);
        const auto doVReplicate = (vIndex < vReplicate);

        auto uExt = 0;
        auto vExt = 0;
        if (doUReplicate)
        {
            uExt = numUCtrlPoints + uIndex;
            ctrlPoint.at(uExt).at(vIndex) = ctrl;
        }

        if (doVReplicate)
        {
            vExt = numVCtrlPoints + vIndex;
            ctrlPoint.at(uIndex).at(vExt) = ctrl;
        }

        if (doUReplicate && doVReplicate)
        {
            ctrlPoint.at(uExt).at(vExt) = ctrl;
        }
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSRectangle<Real>::GetControlPoint(int uIndex, int vIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ctrlPoint.at(uIndex).at(vIndex);
}

template <typename Real>
void Mathematics::NURBSRectangle<Real>::SetControlWeight(int uIndex, int vIndex, Real weight)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= uIndex && uIndex < numUCtrlPoints && 0 <= vIndex && vIndex < numVCtrlPoints)
    {
        ctrlWeight.at(uIndex).at(vIndex) = weight;

        const auto doUReplicate = (uIndex < uReplicate);
        const auto doVReplicate = (vIndex < vReplicate);
        auto uExt = 0;
        auto vExt = 0;

        if (doUReplicate)
        {
            uExt = numUCtrlPoints + uIndex;
            ctrlWeight.at(uExt).at(vIndex) = weight;
        }

        if (doVReplicate)
        {
            vExt = numVCtrlPoints + vIndex;
            ctrlWeight.at(uIndex).at(vExt) = weight;
        }

        if (doUReplicate && doVReplicate)
        {
            ctrlWeight.at(uExt).at(vExt) = weight;
        }
    }
}

template <typename Real>
Real Mathematics::NURBSRectangle<Real>::GetControlWeight(int uIndex, int vIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ctrlWeight.at(uIndex).at(vIndex);
}

template <typename Real>
void Mathematics::NURBSRectangle<Real>::SetKnot(int dim, int i, Real knot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= dim && dim <= 1)
    {
        basis.at(dim).SetKnot(i, knot);
    }
}

template <typename Real>
Real Mathematics::NURBSRectangle<Real>::GetKnot(int dim, int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= dim && dim <= 1)
    {
        return basis.at(dim).GetKnot(i);
    }

    return Math<Real>::maxReal;
}

template <typename Real>
void Mathematics::NURBSRectangle<Real>::Get(Real u, Real v, Vector3<Real>* pos, Vector3<Real>* derU, Vector3<Real>* derV, Vector3<Real>* derUU, Vector3<Real>* derUV, Vector3<Real>* derVV) const
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
    else if (derUV != nullptr || derU != nullptr)
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
    else if (derUV != nullptr || derV != nullptr)
    {
        basis.at(1).Compute(v, 0, ivmin, ivmax);
        basis.at(1).Compute(v, 1, ivmin, ivmax);
    }
    else
    {
        basis.at(1).Compute(v, 0, ivmin, ivmax);
    }

    auto x = Vector3<Real>::GetZero();
    Real w = Math<Real>::GetValue(0);
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
            auto tmp = basis.at(0).GetD0(iu) * basis.at(1).GetD0(iv) * ctrlWeight.at(iu).at(iv);
            x += tmp * ctrlPoint.at(iu).at(iv);
            w += tmp;
        }
    }
    auto invW = (Math<Real>::GetValue(1)) / w;
    auto p = invW * x;
    if (pos != nullptr)
    {
        *pos = p;
    }

    if (derU == nullptr && derV == nullptr && derUU == nullptr && derUV == nullptr && derVV == nullptr)
    {
        return;
    }

    auto wDerU = Math<Real>::GetValue(0);
    auto wDerV = Math<Real>::GetValue(0);
    auto pDerU = Vector3<Real>::GetZero();
    auto pDerV = Vector3<Real>::GetZero();

    if (derU != nullptr || derUU != nullptr || derUV != nullptr)
    {
        auto xDerU = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD1(iu) * basis.at(1).GetD0(iv) * ctrlWeight.at(iu).at(iv);
                xDerU += tmp * ctrlPoint.at(iu).at(iv);
                wDerU += tmp;
            }
        }
        pDerU = invW * (xDerU - wDerU * p);
        if (derU != nullptr)
        {
            *derU = pDerU;
        }
    }

    if (derV != nullptr || derVV != nullptr || derUV != nullptr)
    {
        auto XDerV = Vector3<Real>::GetZero();
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD0(iu) * basis.at(1).GetD1(iv) * ctrlWeight.at(iu).at(iv);
                XDerV += tmp * ctrlPoint.at(iu).at(iv);
                wDerV += tmp;
            }
        }
        pDerV = invW * (XDerV - wDerV * p);
        if (derV != nullptr)
        {
            *derV = pDerV;
        }
    }

    if (derUU == nullptr && derUV == nullptr && derVV == nullptr)
    {
        return;
    }

    if (derUU != nullptr)
    {
        auto xDerUU = Vector3<Real>::GetZero();
        auto wDerUU = Math<Real>::GetValue(0);
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD2(iu) * basis.at(1).GetD0(iv) * ctrlWeight.at(iu).at(iv);
                xDerUU += tmp * ctrlPoint.at(iu).at(iv);
                wDerUU += tmp;
            }
        }
        *derUU = invW * (xDerUU - (Math<Real>::GetValue(2)) * wDerU * pDerU - wDerUU * p);
    }

    if (derUV != nullptr)
    {
        auto xDerUV = Vector3<Real>::GetZero();
        auto wDerUV = Math<Real>::GetValue(0);
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD1(iu) * basis.at(1).GetD1(iv) * ctrlWeight.at(iu).at(iv);
                xDerUV += tmp * ctrlPoint.at(iu).at(iv);
                wDerUV += tmp;
            }
        }
        *derUV = invW * (xDerUV - wDerU * pDerV - wDerV * pDerU - wDerUV * p);
    }

    if (derVV != nullptr)
    {
        auto xDerVV = Vector3<Real>::GetZero();
        auto wDerVV = Math<Real>::GetValue(0);
        for (auto iu = iumin; iu <= iumax; ++iu)
        {
            for (auto iv = ivmin; iv <= ivmax; ++iv)
            {
                auto tmp = basis.at(0).GetD0(iu) * basis.at(1).GetD2(iv) * ctrlWeight.at(iu).at(iv);
                xDerVV += tmp * ctrlPoint.at(iu).at(iv);
                wDerVV += tmp;
            }
        }
        *derVV = invW * (xDerVV - (Math<Real>::GetValue(2)) * wDerV * pDerV - wDerVV * p);
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSRectangle<Real>::P(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> pos{};
    Get(u, v, &pos, 0, 0, 0, 0, 0);

    return pos;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSRectangle<Real>::PU(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derU{};
    Get(u, v, 0, &derU, 0, 0, 0, 0);

    return derU;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSRectangle<Real>::PV(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derV{};
    Get(u, v, 0, 0, &derV, 0, 0, 0);

    return derV;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSRectangle<Real>::PUU(Real u, Real v) const
{
    Vector3<Real> derUU{};
    Get(u, v, 0, 0, 0, &derUU, 0, 0);

    return derUU;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSRectangle<Real>::PUV(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derUV{};
    Get(u, v, 0, 0, 0, 0, &derUV, 0);

    return derUV;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSRectangle<Real>::PVV(Real u, Real v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> derVV{};
    Get(u, v, 0, 0, 0, 0, 0, &derVV);

    return derVV;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_RECTANGLE_DETAIL_H
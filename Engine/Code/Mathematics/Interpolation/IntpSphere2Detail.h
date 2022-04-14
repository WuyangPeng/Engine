///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/21 13:17)

#ifndef MATHEMATICS_INTERPOLATION_INTP_SPHERE2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_SPHERE2_DETAIL_H

#include "IntpSphere2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpSphere2<Real>::IntpSphere2(int quantity, const std::vector<Real>& theta, const std::vector<Real>& phi, const std::vector<Real>& f, QueryType queryType)
    : dt{}, interp{}
{
    const auto threeQuantity = 3 * quantity;
    std::vector<Vector2<Real>> wrapAngles(threeQuantity);
    std::vector<Real> wrapF(threeQuantity);
    for (auto i = 0; i < quantity; ++i)
    {
        wrapAngles.at(i)[0] = theta.at(i);
        wrapAngles.at(i)[1] = phi.at(i);
        wrapF.at(i) = f.at(i);
    }

    for (auto i0 = 0, i1 = quantity, i2 = 2 * quantity; i0 < quantity; ++i0, ++i1, ++i2)
    {
        wrapAngles.at(i1)[0] = wrapAngles.at(i0)[0] + Math<Real>::GetTwoPI();
        wrapAngles.at(i2)[0] = wrapAngles.at(i0)[0] - Math<Real>::GetTwoPI();
        wrapAngles.at(i1)[1] = wrapAngles.at(i0)[1];
        wrapAngles.at(i2)[1] = wrapAngles.at(i0)[1];
        wrapF.at(i1) = wrapF.at(i0);
        wrapF.at(i2) = wrapF.at(i0);
    }

    dt = std::make_shared<Delaunay2<Real>>(wrapAngles, static_cast<Real>(0.001), queryType);
    interp = std::make_shared<IntpQdrNonuniform2<Real>>(*dt, wrapF);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpSphere2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::IntpSphere2<Real>::GetSphericalCoords(Real x, Real y, Real z, Real& theta, Real& phi) noexcept
{
    if (z < Math<Real>::GetValue(1))
    {
        if (z > -Math<Real>::GetValue(1))
        {
            theta = Math<Real>::ATan2(y, x);
            phi = Math<Real>::ACos(z);
        }
        else
        {
            theta = -Math<Real>::GetPI();
            phi = Math<Real>::GetPI();
        }
    }
    else
    {
        theta = -Math<Real>::GetPI();
        phi = Math<Real>::GetValue(0);
    }
}

template <typename Real>
bool Mathematics::IntpSphere2<Real>::Evaluate(Real theta, Real phi, Real& f)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const Vector2<Real> angles{ theta, phi };
    Real thetaDeriv{};
    Real phiDeriv{};
    return interp->Evaluate(angles, f, thetaDeriv, phiDeriv);
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_SPHERE2_DETAIL_H
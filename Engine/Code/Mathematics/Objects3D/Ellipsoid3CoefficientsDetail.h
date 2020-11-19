///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/17 13:06)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H

#include "Ellipsoid3Coefficients.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSOID3_COEFFICIENTS_ACHIEVE)

    #include "Ellipsoid3CoefficientsAchieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSOID3_COEFFICIENTS_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Ellipsoid3Coefficients<Real>& lhs, const Ellipsoid3Coefficients<Real>& rhs, const Real epsilon)
{
    auto lhsCoefficients = lhs.GetCoefficients();
    auto rhsCoefficients = rhs.GetCoefficients();

    constexpr auto coefficientsSize = Ellipsoid3Coefficients<Real>::sm_CoefficientsSize;

    if (lhsCoefficients.size() != coefficientsSize || rhsCoefficients.size() != coefficientsSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetCoefficients���ص������С����"s));
    }

    for (auto i = 0; i < coefficientsSize; ++i)
    {
        if (!Math<Real>::Approximate(lhsCoefficients[i], rhsCoefficients[i], epsilon))
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H

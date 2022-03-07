///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/09 16:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_DETAIL_H

#include "ChebyshevRatio.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
typename Mathematics::ChebyshevRatio<Real>::Tuple Mathematics::ChebyshevRatio<Real>::Get(Real t, Real cosA)
{
    Tuple result{};
    if (cosA < Math::GetValue(1))
    {
        auto a = Math::ACos(cosA);
        auto invSinA = Math::GetValue(1) / Math::Sin(a);
        result[0] = Math::Sin((Math::GetValue(1) - t) * a) * invSinA;
        result[1] = Math::Sin(t * a) * invSinA;
    }
    else
    {
        result[0] = Math::GetValue(1) - t;
        result[1] = t;
    }

    return result;
}

template <typename Real>
template <int N>
typename Mathematics::ChebyshevRatio<Real>::Tuple Mathematics::ChebyshevRatio<Real>::GetEstimate(Real t, Real y)
{
    static_assert(1 <= N && N <= 16, "Invalid degree.");

    using ArrayType = std::array<Real, 16>;

    constexpr ArrayType onePlusMu{ static_cast<Real>(1.62943436108234530),
                                   static_cast<Real>(1.73965850021313961),
                                   static_cast<Real>(1.79701067629566813),
                                   static_cast<Real>(1.83291820510335812),
                                   static_cast<Real>(1.85772477879039977),
                                   static_cast<Real>(1.87596835698904785),
                                   static_cast<Real>(1.88998444919711206),
                                   static_cast<Real>(1.90110745351730037),
                                   static_cast<Real>(1.91015881189952352),
                                   static_cast<Real>(1.91767344933047190),
                                   static_cast<Real>(1.92401541194159076),
                                   static_cast<Real>(1.92944142668012797),
                                   static_cast<Real>(1.93413793373091059),
                                   static_cast<Real>(1.93824371262559758),
                                   static_cast<Real>(1.94186426368404708),
                                   static_cast<Real>(1.94508125972497303) };

    constexpr ArrayType a{ (N != 1 ? Math::GetValue(1) : onePlusMu[0]) / (Math::GetValue(1) * Math::GetValue(3)),
                           (N != 2 ? Math::GetValue(1) : onePlusMu[1]) / (Math::GetValue(2) * Math::GetValue(5)),
                           (N != 3 ? Math::GetValue(1) : onePlusMu[2]) / (Math::GetValue(3) * Math::GetValue(7)),
                           (N != 4 ? Math::GetValue(1) : onePlusMu[3]) / (Math::GetValue(4) * Math::GetValue(9)),
                           (N != 5 ? Math::GetValue(1) : onePlusMu[4]) / (Math::GetValue(5) * Math::GetValue(11)),
                           (N != 6 ? Math::GetValue(1) : onePlusMu[5]) / (Math::GetValue(6) * Math::GetValue(13)),
                           (N != 7 ? Math::GetValue(1) : onePlusMu[6]) / (Math::GetValue(7) * Math::GetValue(15)),
                           (N != 8 ? Math::GetValue(1) : onePlusMu[7]) / (Math::GetValue(8) * Math::GetValue(17)),
                           (N != 9 ? Math::GetValue(1) : onePlusMu[8]) / (Math::GetValue(9) * Math::GetValue(19)),
                           (N != 10 ? Math::GetValue(1) : onePlusMu[9]) / (Math::GetValue(10) * Math::GetValue(21)),
                           (N != 11 ? Math::GetValue(1) : onePlusMu[10]) / (Math::GetValue(11) * Math::GetValue(23)),
                           (N != 12 ? Math::GetValue(1) : onePlusMu[11]) / (Math::GetValue(12) * Math::GetValue(25)),
                           (N != 13 ? Math::GetValue(1) : onePlusMu[12]) / (Math::GetValue(13) * Math::GetValue(27)),
                           (N != 14 ? Math::GetValue(1) : onePlusMu[13]) / (Math::GetValue(14) * Math::GetValue(29)),
                           (N != 15 ? Math::GetValue(1) : onePlusMu[14]) / (Math::GetValue(15) * Math::GetValue(31)),
                           (N != 16 ? Math::GetValue(1) : onePlusMu[15]) / (Math::GetValue(16) * Math::GetValue(33)) };

    constexpr ArrayType b{ (N != 1 ? Math::GetValue(1) : onePlusMu[0]) * Math::GetValue(1) / Math::GetValue(3),
                           (N != 2 ? Math::GetValue(1) : onePlusMu[1]) * Math::GetValue(2) / Math::GetValue(5),
                           (N != 3 ? Math::GetValue(1) : onePlusMu[2]) * Math::GetValue(3) / Math::GetValue(7),
                           (N != 4 ? Math::GetValue(1) : onePlusMu[3]) * Math::GetValue(4) / Math::GetValue(9),
                           (N != 5 ? Math::GetValue(1) : onePlusMu[4]) * Math::GetValue(5) / Math::GetValue(11),
                           (N != 6 ? Math::GetValue(1) : onePlusMu[5]) * Math::GetValue(6) / Math::GetValue(13),
                           (N != 7 ? Math::GetValue(1) : onePlusMu[6]) * Math::GetValue(7) / Math::GetValue(15),
                           (N != 8 ? Math::GetValue(1) : onePlusMu[7]) * Math::GetValue(8) / Math::GetValue(17),
                           (N != 9 ? Math::GetValue(1) : onePlusMu[8]) * Math::GetValue(9) / Math::GetValue(19),
                           (N != 10 ? Math::GetValue(1) : onePlusMu[9]) * Math::GetValue(10) / Math::GetValue(21),
                           (N != 11 ? Math::GetValue(1) : onePlusMu[10]) * Math::GetValue(11) / Math::GetValue(23),
                           (N != 12 ? Math::GetValue(1) : onePlusMu[11]) * Math::GetValue(12) / Math::GetValue(25),
                           (N != 13 ? Math::GetValue(1) : onePlusMu[12]) * Math::GetValue(13) / Math::GetValue(27),
                           (N != 14 ? Math::GetValue(1) : onePlusMu[13]) * Math::GetValue(14) / Math::GetValue(29),
                           (N != 15 ? Math::GetValue(1) : onePlusMu[14]) * Math::GetValue(15) / Math::GetValue(31),
                           (N != 16 ? Math::GetValue(1) : onePlusMu[15]) * Math::GetValue(16) / Math::GetValue(33) };

    auto term0 = Math::GetValue(1) - t;
    auto term1 = t;

    const auto sqr0 = term0 * term0;
    const auto sqr1 = term1 * term1;

    auto f0 = term0;
    auto f1 = term1;
    for (auto i = 0; i < N; ++i)
    {
        term0 *= (b[i] - a[i] * sqr0) * y;
        term1 *= (b[i] - a[i] * sqr1) * y;
        f0 += term0;
        f1 += term1;
    }

    return Tuple{ f0, f1 };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_DETAIL_H
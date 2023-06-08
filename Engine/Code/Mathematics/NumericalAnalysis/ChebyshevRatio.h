///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:41)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Base/BaseFwd.h"

namespace Mathematics
{
    template <typename Real>
    class ChebyshevRatio final
    {
    public:
        using ClassType = ChebyshevRatio<Real>;
        using Math = Math<Real>;
        using Tuple = CoreTools::Tuple<2, Real>;

    public:
        ChebyshevRatio() noexcept = delete;

    public:
        static Tuple Get(Real t, Real cosA);

        template <int N>
        static Tuple GetEstimate(Real t, Real y);

        static Real GetChebyshevRatio(Real t, Real angle);

        static Real ChebyshevRatioUsingCosAngle(Real t, Real cosAngle);

        static std::array<Real, 2> ChebyshevRatios(Real t, Real angle);

        static std::array<Real, 2> ChebyshevRatiosUsingCosAngle(Real t, Real cosAngle);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H
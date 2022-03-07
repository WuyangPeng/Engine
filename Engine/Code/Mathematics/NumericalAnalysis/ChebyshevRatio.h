///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/09 16:39)

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
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H
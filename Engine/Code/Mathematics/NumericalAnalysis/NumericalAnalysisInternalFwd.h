///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/12 21:29)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_INTERNAL_FWD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_INTERNAL_FWD_H

#include "NumericalAnalysisFwd.h"

namespace Mathematics
{
    class EquationImpl;
    class EquationFactory;

    template <typename Real>
    class Bisect2Calculate;

    template <typename Real>
    class Bisect2Node;

    template <typename Real>
    class Bisect2Storage;

    template <typename Real>
    class Bisect3Calculate;

    template <typename Real>
    class Bisect3Node;

    template <typename Real>
    class Bisect3Storage;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_INTERNAL_FWD_H
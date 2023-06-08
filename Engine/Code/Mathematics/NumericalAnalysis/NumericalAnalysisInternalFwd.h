///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:43)

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
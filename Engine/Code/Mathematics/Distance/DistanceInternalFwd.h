///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/19 21:39)

#ifndef MATHEMATICS_DISTANCE_INTERNAL_FWD_H
#define MATHEMATICS_DISTANCE_INTERNAL_FWD_H

#include "DistanceFwd.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceResultImpl;

    template <typename Real, typename Vector>
    class DistanceResultFactory;

    template <typename Real>
    class DistanceLine2Line2Tool;

    template <typename Real>
    class DistanceLine3Line3Tool;
}

#endif  // MATHEMATICS_DISTANCE_INTERNAL_FWD_H
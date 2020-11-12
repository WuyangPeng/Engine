///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 13:18)

#ifndef MATHEMATICS_BASE_FWD_H
#define MATHEMATICS_BASE_FWD_H

#include "CoreTools/DataTypes/DataTypesFwd.h"

namespace Mathematics
{
    class BitHacks;

    template <typename Real>
    class FastTrigonometric;

    template <typename Real>
    class FastNegativeExp;

    template <typename Real>
    class Math;

    template <typename Real>
    class Random;

    enum class NumericalValueSymbol;

    using Float1 = CoreTools::Tuple<1, float>;
    using Float2 = CoreTools::Tuple<2, float>;
    using Float3 = CoreTools::Tuple<3, float>;
    using Float4 = CoreTools::Tuple<4, float>;
}

#endif  // MATHEMATICS_BASE_FWD_H
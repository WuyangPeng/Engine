///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/30 14:01)

#ifndef MATHEMATICS_BASE_FWD_H
#define MATHEMATICS_BASE_FWD_H

#include "CoreTools/DataTypes/DataTypesFwd.h"

namespace Mathematics
{
    class BitHacks;

    template <typename Real>
    requires std::is_floating_point_v<Real>
    class FastTrigonometric;

    template <typename Real>
    requires std::is_floating_point_v<Real>
    class FastNegativeExp;

    template <typename Real>
    class Math;

    template <typename Real>
    requires std::is_floating_point_v<Real>
    class Random;

    enum class NumericalValueSymbol;

    using Float1 = CoreTools::Tuple<1, float>;
    using Float2 = CoreTools::Tuple<2, float>;
    using Float3 = CoreTools::Tuple<3, float>;
    using Float4 = CoreTools::Tuple<4, float>;

    template <bool RowMajor, typename Real, int... Dimensions>
    class LexicoArray2;
}

#endif  // MATHEMATICS_BASE_FWD_H
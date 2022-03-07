///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 22:20)

#include "Mathematics/MathematicsExport.h"

#include "BitHacks.h"
#include "ScaledFloatToInt.h"

int32_t Mathematics::BitHacks::ScaledFloatToInt(float scaledFloat, int power) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(0 <= scaledFloat && scaledFloat <= 1, "value的区间为[0,1]。");
    MATHEMATICS_ASSERTION_3(0 <= power && power <= 24, "power的区间为[0,24]。");

    const Mathematics::ScaledFloatToInt scaledFloatToInt{ scaledFloat, power };

    return scaledFloatToInt.GetScaledResult();
}

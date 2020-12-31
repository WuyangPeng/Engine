///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 10:49)

#include "Mathematics/MathematicsExport.h"

#include "BitHacks.h"
#include "ScaledFloatToInt.h"

int32_t Mathematics::BitHacks::ScaledFloatToInt(float value, int power) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(0 <= value && value <= 1, "value的区间为[0,1]。");
    MATHEMATICS_ASSERTION_3(0 <= power && power <= 24, "power的区间为[0,24]。");

    const Mathematics::ScaledFloatToInt scaledFloatToInt{ value, power };

    return scaledFloatToInt.GetScaledResult();
}

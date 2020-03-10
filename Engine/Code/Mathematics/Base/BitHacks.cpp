// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 19:37)

#include "Mathematics/MathematicsExport.h"

#include "BitHacks.h"
#include "ScaledFloatToInt.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

int Mathematics::BitHacks
	::ScaledFloatToInt (float value, int power)
{
	MATHEMATICS_ASSERTION_3(0 <= value && value <= 1,"value的区间为[0,1]。");
	MATHEMATICS_ASSERTION_3(0 <= power && power <= 24,"power的区间为[0,24]。");

	Mathematics::ScaledFloatToInt scaledFloatToInt{ value,power };

	return scaledFloatToInt.GetScaledResult();
}



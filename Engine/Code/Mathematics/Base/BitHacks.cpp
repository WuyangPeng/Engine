// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 19:37)

#include "Mathematics/MathematicsExport.h"

#include "BitHacks.h"
#include "ScaledFloatToInt.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

int Mathematics::BitHacks
	::ScaledFloatToInt (float value, int power)
{
	MATHEMATICS_ASSERTION_3(0 <= value && value <= 1,"value������Ϊ[0,1]��");
	MATHEMATICS_ASSERTION_3(0 <= power && power <= 24,"power������Ϊ[0,24]��");

	Mathematics::ScaledFloatToInt scaledFloatToInt{ value,power };

	return scaledFloatToInt.GetScaledResult();
}



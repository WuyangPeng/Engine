// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 09:42)

#include "Mathematics/MathematicsExport.h"

#include "BitHacks.h"
#include "ScaledFloatToInt.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

int Mathematics::BitHacks
	::ScaledFloatToInt(float value, int power)
{
	MATHEMATICS_ASSERTION_3(0 <= value && value <= 1, "value������Ϊ[0,1]��");
	MATHEMATICS_ASSERTION_3(0 <= power && power <= 24, "power������Ϊ[0,24]��");

	CoreTools::DoNothing();

	const Mathematics::ScaledFloatToInt scaledFloatToInt{ value,power };

	return scaledFloatToInt.GetScaledResult();
}



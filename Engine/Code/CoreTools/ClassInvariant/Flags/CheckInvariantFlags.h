// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 18:03)

#ifndef CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_FLAGS_H
#define CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
	enum class CheckInvariantConditions
	{
		OnlyPreconditions, // ������ǰ������
		OnlyPostconditions, // �����Ժ�������
		Fully // ��ȫ�಻��ʽ
	};

	enum class TriggerAssertCheck
	{
		Invariant, // ����ʽ
		Assertion, // ����
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_FLAGS_H
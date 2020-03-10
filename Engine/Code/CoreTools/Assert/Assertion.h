// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 18:10)

#ifndef CORE_TOOLS_ASSERT_ASSERTION_H
#define CORE_TOOLS_ASSERT_ASSERTION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/CustomAssertMacro.h"
#include "CoreTools/ClassInvariant/ClassInvariantFwd.h"

// ʹ��CoreTools��Assertion�����ļ�/�и��١�
namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Assertion
	{
	public:
		using ClassType = Assertion;

	public:
		Assertion(bool condition, const FunctionDescribed& functionDescribed, const char* format, ...);

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // CORE_TOOLS_ASSERT_ASSERTION_H

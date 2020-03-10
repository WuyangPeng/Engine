// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 18:10)

#ifndef CORE_TOOLS_ASSERT_ASSERTION_H
#define CORE_TOOLS_ASSERT_ASSERTION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/CustomAssertMacro.h"
#include "CoreTools/ClassInvariant/ClassInvariantFwd.h"

// 使用CoreTools的Assertion用于文件/行跟踪。
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

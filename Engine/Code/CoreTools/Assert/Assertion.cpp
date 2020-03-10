// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:10)

#include "CoreTools/CoreToolsExport.h"

#include "Assertion.h"
#include "CoreTools/ClassInvariant/TriggerAssert.h"
#include "CoreTools/ClassInvariant/ScopeExitDetail.h"
#include "CoreTools/ClassInvariant/Flags/CheckInvariantFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <cstdarg>

CoreTools::Assertion
	::Assertion(bool condition, const FunctionDescribed& functionDescribed, const char* format, ...)
{
	if (!condition)
	{
		va_list arguments{};
		va_start(arguments, format);

		ScopeExit<> onExit{ [&arguments]()
		{
			va_end(arguments);
		} };

		TriggerAssert triggerAssert{ TriggerAssertCheck::Assertion, functionDescribed, format, arguments };
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Assertion)



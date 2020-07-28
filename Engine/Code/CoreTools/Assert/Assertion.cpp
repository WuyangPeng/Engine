// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:10)

#include "CoreTools/CoreToolsExport.h"

#include "Assertion.h"
#include "System/Helper/PragmaWarning.h"
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
		 
#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)

		va_list arguments{};
		va_start(arguments, format);

		#include STSTEM_WARNING_POP

		ScopeExit<> onExit{ [&arguments]()
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26477)

			va_end(arguments);

		#include STSTEM_WARNING_POP
		} };

		const TriggerAssert triggerAssert{ TriggerAssertCheck::Assertion, functionDescribed, format, arguments };
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Assertion)



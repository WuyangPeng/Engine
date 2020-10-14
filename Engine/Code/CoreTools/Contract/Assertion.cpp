//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/10 15:14)

#include "CoreTools/CoreToolsExport.h"

#include "Assertion.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/CheckInvariantFlags.h"
#include "CoreTools/Contract/ScopeExitDetail.h"
#include "CoreTools/Contract/TriggerAssert.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <cstdarg>

CoreTools::Assertion::Assertion(bool condition, const FunctionDescribed& functionDescribed, const char* format, ...)
{
    if (!condition)
    {
        va_list arguments{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)
        va_start(arguments, format);
#include STSTEM_WARNING_POP

        const auto function = [&arguments]() noexcept {
            va_end(arguments);
        };

        ScopeExit<> onExit{ function };

        const TriggerAssert triggerAssert{ TriggerAssertCheck::Assertion, functionDescribed, format, arguments };
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Assertion)

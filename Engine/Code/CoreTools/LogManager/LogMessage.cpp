///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 23:00)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessage.h"
#include "Detail/LogMessageImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::LogMessage::LogMessage(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed)
    : impl{ level, filter, message, functionDescribed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessage)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessage, GetMessageDescribe, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetLogFilterType, CoreTools::LogFilter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessage, GetMessageSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetFunctionDescribed, CoreTools::FunctionDescribed)
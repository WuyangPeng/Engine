// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 11:07)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessage.h"
#include "Detail/LogMessageImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::LogMessage
	::LogMessage(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed)
	:m_Impl{ make_shared<ImplType>(level,filter,message,functionDescribed) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LogMessage)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessage, GetMessageDescribe, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetLogFilterType, CoreTools::LogFilter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessage, GetMessageSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LogMessage, GetFunctionDescribed, CoreTools::FunctionDescribed)
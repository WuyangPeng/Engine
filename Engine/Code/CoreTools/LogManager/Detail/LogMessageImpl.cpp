/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:42)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessageImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogMessageImpl::LogMessageImpl(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept
    : logLevel{ level }, filter{ filter }, message{}, functionDescribed{ functionDescribed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessageImpl)

System::String CoreTools::LogMessageImpl::GetMessageDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return message;
}

CoreTools::LogLevel CoreTools::LogMessageImpl::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return logLevel;
}

CoreTools::LogFilter CoreTools::LogMessageImpl::GetLogFilterType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return filter;
}

int CoreTools::LogMessageImpl::GetMessageSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(message.size());
}

CoreTools::FunctionDescribed CoreTools::LogMessageImpl::GetFunctionDescribed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return functionDescribed;
}

void CoreTools::LogMessageImpl::AddMessage(const String& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    message += value;
}

void CoreTools::LogMessageImpl::SetFunctionDescribed(const FunctionDescribed& aFunctionDescribed) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    functionDescribed = aFunctionDescribed;
}

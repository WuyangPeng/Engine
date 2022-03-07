///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:42)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessageImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogMessageImpl::LogMessageImpl(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed)
    : logLevel{ level }, filter{ filter }, message{ message }, functionDescribed{ functionDescribed }
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

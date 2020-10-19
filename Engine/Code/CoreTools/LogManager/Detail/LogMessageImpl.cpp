//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:45)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessageImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogMessageImpl::LogMessageImpl(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed)
    : m_Level{ level }, m_Filter{ filter }, m_Message{ message }, m_FunctionDescribed{ functionDescribed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessageImpl)

System::String CoreTools::LogMessageImpl::GetMessageDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Message;
}

CoreTools::LogLevel CoreTools::LogMessageImpl::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Level;
}

CoreTools::LogFilter CoreTools::LogMessageImpl::GetLogFilterType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Filter;
}

int CoreTools::LogMessageImpl::GetMessageSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Message.size());
}

CoreTools::FunctionDescribed CoreTools::LogMessageImpl::GetFunctionDescribed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_FunctionDescribed;
}

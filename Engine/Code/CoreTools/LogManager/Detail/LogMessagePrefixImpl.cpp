//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:46)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderPrintFlagsExist.h"
#include "LogMessagePrefixImpl.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/LogLevelManager.h"

using namespace std::literals;

CoreTools::LogMessagePrefixImpl::LogMessagePrefixImpl(AppenderPrint appenderFlags, LogLevel level, LogFilter filter)
    : m_Prefix{}, m_AppenderPrint{ appenderFlags }, m_Level{ level }, m_Filter{ filter }
{
    GeneratePrefix();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::LogMessagePrefixImpl::GeneratePrefix()
{
    if (m_Level != LogLevel::Disabled)
    {
        GenerateTimestampPrefix();
        GenerateLogLevelPrefix();
        GenerateLogFilterPrefix();
    }
}

// private
void CoreTools::LogMessagePrefixImpl::GenerateTimestampPrefix()
{
    if (AppenderPrintFlagsExist::IsExist(m_AppenderPrint, AppenderPrint::PrefixTimestamp))
    {
        auto nowTime = boost::posix_time::second_clock::local_time();

        m_Prefix += (SYSTEM_TEXT("【"s) + boost::posix_time::to_simple_string_type<System::TChar>(nowTime) + SYSTEM_TEXT("】"s));
    }
}

// private
void CoreTools::LogMessagePrefixImpl::GenerateLogLevelPrefix()
{
    if (AppenderPrintFlagsExist::IsExist(m_AppenderPrint, AppenderPrint::PrefixLogLevel))
    {
        m_Prefix += (SYSTEM_TEXT("【"s) + LogLevelManager::GetLogLevelDescribe(m_Level) + SYSTEM_TEXT("】"s));
    }
}

// private
void CoreTools::LogMessagePrefixImpl::GenerateLogFilterPrefix()
{
    if (AppenderPrintFlagsExist::IsExist(m_AppenderPrint, AppenderPrint::PrefixLogFilterType))
    {
        m_Prefix += (SYSTEM_TEXT("【"s) + LogFilterManager::GetLogFilterDescribe(m_Filter) + SYSTEM_TEXT("】"s));
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePrefixImpl)

System::String CoreTools::LogMessagePrefixImpl::GetPrefix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Prefix;
}

int CoreTools::LogMessagePrefixImpl::GetPrefixSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Prefix.size());
}

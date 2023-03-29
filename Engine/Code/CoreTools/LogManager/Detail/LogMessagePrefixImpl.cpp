///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:02)

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
    : prefix{}, appenderPrint{ appenderFlags }, level{ level }, filter{ filter }
{
    GeneratePrefix();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::LogMessagePrefixImpl::GeneratePrefix()
{
    if (level != LogLevel::Disabled)
    {
        GenerateTimestampPrefix();
        GenerateLogLevelPrefix();
        GenerateLogFilterPrefix();
    }
}

void CoreTools::LogMessagePrefixImpl::GenerateTimestampPrefix()
{
    if (AppenderPrintFlagsExist::IsExist(appenderPrint, AppenderPrint::PrefixTimestamp))
    {
        const auto nowTime = boost::posix_time::second_clock::local_time();

        prefix += (SYSTEM_TEXT("【"s) + boost::posix_time::to_simple_string_type<System::TChar>(nowTime) + SYSTEM_TEXT("】"s));
    }
}

void CoreTools::LogMessagePrefixImpl::GenerateLogLevelPrefix()
{
    if (AppenderPrintFlagsExist::IsExist(appenderPrint, AppenderPrint::PrefixLogLevel))
    {
        prefix += (SYSTEM_TEXT("【"s) + LogLevelManager::GetLogLevelDescribe(level) + SYSTEM_TEXT("】"s));
    }
}

void CoreTools::LogMessagePrefixImpl::GenerateLogFilterPrefix()
{
    if (AppenderPrintFlagsExist::IsExist(appenderPrint, AppenderPrint::PrefixLogFilterType))
    {
        prefix += (SYSTEM_TEXT("【"s) + LogFilterManager::GetLogFilterDescribe(filter) + SYSTEM_TEXT("】"s));
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePrefixImpl)

System::String CoreTools::LogMessagePrefixImpl::GetPrefix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return prefix;
}

int CoreTools::LogMessagePrefixImpl::GetPrefixSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(prefix.size());
}

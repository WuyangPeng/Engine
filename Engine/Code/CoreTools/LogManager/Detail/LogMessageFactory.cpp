///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 15:25)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessageFactory.h"
#include "NullLogMessage.h"
#include "PrintFileNameLogMessage.h"
#include "PrintLogMessage.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/Log.h"

CoreTools::LogMessageFactory::LogMessageImplSharedPtr CoreTools::LogMessageFactory::Create(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed)
{
    if (const auto minLogLevel = LOG_SINGLETON.GetMinLogLevelType(filter);
        minLogLevel == LogLevel::Disabled || level < minLogLevel)
    {
        return std::make_shared<NullLogMessage>(level, filter, functionDescribed);
    }
    else
    {
        return std::make_shared<PrintLogMessage>(level, filter, functionDescribed);
    }
}

CoreTools::LogMessageFactory::LogMessageImplSharedPtr CoreTools::LogMessageFactory::Create(const LogFileName& fileName, LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed)
{
    if (const auto minLogLevel = LOG_SINGLETON.GetMinLogLevelType(filter);
        minLogLevel == LogLevel::Disabled || level < minLogLevel)
    {
        return std::make_shared<NullLogMessage>(level, filter, functionDescribed);
    }
    else
    {
        return std::make_shared<PrintFileNameLogMessage>(fileName, level, filter, functionDescribed);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessageFactory)
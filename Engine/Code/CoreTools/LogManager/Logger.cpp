///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 10:01)

#include "CoreTools/CoreToolsExport.h"

#include "Logger.h"
#include "Detail/LoggerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, Logger)

CoreTools::Logger::Logger(LogFilter logFilter, LogLevel logLevel)
    : impl{ logFilter, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Logger)

CoreTools::LogFilter CoreTools::Logger::GetLogFilterType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetLogFilterType();
}

CoreTools::LogLevel CoreTools::Logger::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetLogLevel();
}

void CoreTools::Logger::SetLogLevel(LogLevel level)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetLogLevel(level);
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:12)

#include "CoreTools/CoreToolsExport.h"

#include "Logger.h"
#include "Detail/LoggerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::Logger::Logger(LogFilter logFilter, LogLevel logLevel)
    : impl{ logFilter, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Logger)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Logger, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Logger, GetLogFilterType, CoreTools::LogFilter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Logger, SetLogLevel, LogLevel, void)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, Logger)
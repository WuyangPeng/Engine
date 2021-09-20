//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 19:00)

#include "CoreTools/CoreToolsExport.h"

#include "Logger.h"
#include "Detail/LoggerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::Logger::Logger(LogFilter logFilter, LogLevel logLevel)
    : impl{ logFilter, logLevel  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Logger)

 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Logger, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Logger, GetLogFilterType, CoreTools::LogFilter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Logger, SetLogLevel, LogLevel, void)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, Logger)
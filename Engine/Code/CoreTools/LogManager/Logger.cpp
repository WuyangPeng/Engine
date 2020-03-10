// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 11:03)

#include "CoreTools/CoreToolsExport.h"

#include "Logger.h"
#include "Detail/LoggerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::Logger
	::Logger(LogFilter logFilter, LogLevel logLevel)
	:m_Impl{ make_shared<ImplType>(logFilter,logLevel) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Logger)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, Logger)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Logger, GetLogLevel, CoreTools::LogLevel)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Logger, GetLogFilterType, CoreTools::LogFilter)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Logger, SetLogLevel, LogLevel, void)

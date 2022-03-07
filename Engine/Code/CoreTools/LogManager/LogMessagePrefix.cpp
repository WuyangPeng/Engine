///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 23:01)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessagePrefix.h"
#include "Detail/LogMessagePrefixImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::LogMessagePrefix::LogMessagePrefix(AppenderPrint appenderFlags, LogLevel level, LogFilter filter)
    : impl{ appenderFlags, level, filter }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePrefix)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessagePrefix, GetPrefix, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessagePrefix, GetPrefixSize, int)

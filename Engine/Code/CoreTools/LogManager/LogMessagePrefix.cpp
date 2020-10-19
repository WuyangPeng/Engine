//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 19:01)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessagePrefix.h"
#include "Detail/LogMessagePrefixImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::LogMessagePrefix::LogMessagePrefix(AppenderPrint appenderFlags, LogLevel level, LogFilter filter)
    : m_Impl{ make_shared<ImplType>(appenderFlags, level, filter) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LogMessagePrefix)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessagePrefix, GetPrefix, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessagePrefix, GetPrefixSize, int)

//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 19:01)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessagePostfix.h"
#include "Detail/LogMessagePostfixImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::LogMessagePostfix::LogMessagePostfix(AppenderPrint appenderFlags, LogLevel level, const FunctionDescribed& functionDescribed)
    : impl{  appenderFlags, level, functionDescribed  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePostfix)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessagePostfix, GetPostfix, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, LogMessagePostfix, GetPostfixSize, int)

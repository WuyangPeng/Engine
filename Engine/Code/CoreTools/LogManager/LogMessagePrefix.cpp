/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 14:07)

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

CoreTools::LogMessagePrefix::String CoreTools::LogMessagePrefix::GetPrefix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPrefix();
}

int CoreTools::LogMessagePrefix::GetPrefixSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPrefixSize();
}

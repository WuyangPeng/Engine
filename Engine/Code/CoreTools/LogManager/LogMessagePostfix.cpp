/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:07)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessagePostfix.h"
#include "Detail/LogMessagePostfixImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogMessagePostfix::LogMessagePostfix(AppenderPrint appenderFlags, LogLevel level, const FunctionDescribed& functionDescribed)
    : impl{ appenderFlags, level, functionDescribed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePostfix)

CoreTools::LogMessagePostfix::String CoreTools::LogMessagePostfix::GetPostfix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPostfix();
}

int CoreTools::LogMessagePostfix::GetPostfixSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPostfixSize();
}

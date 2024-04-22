/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:53)

#include "CoreTools/CoreToolsExport.h"

#include "Error.h"
#include "LastError.h"
#include "Detail/ErrorFactory.h"
#include "Detail/ErrorImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::Error::Error(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message)
    : impl{ ImplCreateUseFactory::Default, functionDescribed, lastError, message }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Error::Error(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
    : impl{ ImplCreateUseFactory::Default, functionDescribed, lastError, message }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Error)

CoreTools::Error::String CoreTools::Error::GetError() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetError();
}

const char* CoreTools::Error::GetCurrentFunction() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCurrentFunction();
}

const char* CoreTools::Error::GetFileName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileName();
}

int CoreTools::Error::GetLine() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetLine();
}

const CoreTools::FunctionDescribed& CoreTools::Error::GetFunctionDescribed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFunctionDescribed();
}

void CoreTools::Error::ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
{
    throw Error{ functionDescribed, lastError, message };
}

void CoreTools::Error::ThrowError(const FunctionDescribed& functionDescribed, const String& message)
{
    const LastError lastError{};

    throw Error{ functionDescribed, lastError, message };
}

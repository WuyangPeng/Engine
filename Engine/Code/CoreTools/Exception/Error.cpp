///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:03)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Error, GetError, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetCurrentFunction, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetFileName, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetLine, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetFunctionDescribed, const CoreTools::FunctionDescribed&)

void CoreTools::Error::ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
{
    throw ClassType{ functionDescribed, lastError, message };
}

void CoreTools::Error::ThrowError(const FunctionDescribed& functionDescribed, const String& message)
{
    const LastError lastError{};

    throw ClassType{ functionDescribed, lastError, message };
}

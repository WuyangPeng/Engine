//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:28)

#include "CoreTools/CoreToolsExport.h"

#include "Error.h"
#include "LastError.h"
#include "Detail/ErrorFactory.h"
#include "Detail/ErrorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::Error::Error(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message)
    : m_Impl{ ErrorFactory::CreateError(functionDescribed, lastError, message) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Error::Error(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
    : m_Impl{ ErrorFactory::CreateError(functionDescribed, lastError, message) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Error)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Error, GetError, const System::String)
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
    LastError lastError{};

    throw ClassType{ functionDescribed, lastError, message };
}

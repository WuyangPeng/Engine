/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:53)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ErrorImpl::ErrorImpl(const FunctionDescribed& functionDescribed, String message) noexcept
    : functionDescribed{ static_cast<FunctionDescribed>(functionDescribed) },
      errorMessage{ std::move(message) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ErrorImpl::~ErrorImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ErrorImpl)

System::String CoreTools::ErrorImpl::GetError() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return errorMessage;
}

const char* CoreTools::ErrorImpl::GetCurrentFunction() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return functionDescribed.GetCurrentFunction();
}

const char* CoreTools::ErrorImpl::GetFileName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return functionDescribed.GetFileName();
}

int CoreTools::ErrorImpl::GetLine() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return functionDescribed.GetLine();
}

const CoreTools::FunctionDescribed& CoreTools::ErrorImpl::GetFunctionDescribed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return functionDescribed;
}

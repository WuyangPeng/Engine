//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:27)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::ErrorImpl::ErrorImpl(const FunctionDescribed& functionDescribed, const String& message)
    : m_FunctionDescribed{ functionDescribed }, m_ErrorMessage{ message }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ErrorImpl::~ErrorImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ErrorImpl)

const System::String CoreTools::ErrorImpl::GetError() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_ErrorMessage;
}

const char* CoreTools::ErrorImpl::GetCurrentFunction() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_FunctionDescribed.GetCurrentFunction();
}

const char* CoreTools::ErrorImpl::GetFileName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_FunctionDescribed.GetFileName();
}

int CoreTools::ErrorImpl::GetLine() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_FunctionDescribed.GetLine();
}

const CoreTools::FunctionDescribed& CoreTools::ErrorImpl::GetFunctionDescribed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_FunctionDescribed;
}

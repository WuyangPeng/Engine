///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/30 15:14)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::ErrorImpl::ErrorImpl(const FunctionDescribed& functionDescribed, const String& message)
    : functionDescribed{ functionDescribed }, errorMessage{ message }
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

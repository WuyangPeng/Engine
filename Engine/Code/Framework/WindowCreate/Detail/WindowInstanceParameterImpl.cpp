///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:11)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

Framework::WindowInstanceParameterImpl::WindowInstanceParameterImpl(WindowsHInstance instance, const String& className)
    : hInstance{ instance }, className{ className }
{
    if (instance == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口实例不存在。"s));
    }

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowInstanceParameterImpl::IsValid() const noexcept
{
    if (hInstance != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::WindowInstanceParameterImpl::WindowsHInstance Framework::WindowInstanceParameterImpl::GetHInstance() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return hInstance;
}

System::String Framework::WindowInstanceParameterImpl::GetWindowClassName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return className;
}

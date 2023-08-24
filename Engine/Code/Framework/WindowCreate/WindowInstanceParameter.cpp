///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 15:16)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameter.h"
#include "Detail/WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowInstanceParameter::WindowInstanceParameter(WindowsHInstance instance, const String& className)
    : impl{ instance, className }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowInstanceParameter)

Framework::WindowInstanceParameter::WindowsHInstance Framework::WindowInstanceParameter::GetHInstance() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetHInstance();
}

Framework::WindowInstanceParameter::String Framework::WindowInstanceParameter::GetWindowClassName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowClassName();
}

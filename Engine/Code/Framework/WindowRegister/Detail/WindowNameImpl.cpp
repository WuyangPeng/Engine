/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:12)

#include "Framework/FrameworkExport.h"

#include "WindowNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::WindowNameImpl::WindowNameImpl(String className, String menuName)
    : className{ std::move(className) }, menuName{ std::move(menuName) }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("className为空。"s))
    }

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

bool Framework::WindowNameImpl::IsValid() const noexcept
{
    if (!className.empty())
        return true;
    else
        return false;
}

System::String Framework::WindowNameImpl::GetWindowClassName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return className;
}

System::String Framework::WindowNameImpl::GetWindowMenuName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return menuName;
}

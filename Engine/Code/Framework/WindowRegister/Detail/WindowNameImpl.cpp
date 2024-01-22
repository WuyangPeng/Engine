/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:12)

#include "Framework/FrameworkExport.h"

#include "WindowNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::WindowNameImpl::WindowNameImpl(String className, String menuName)
    : className{ std::move(className) }, menuName{ std::move(menuName) }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("classNameΪ�ա�"s))
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

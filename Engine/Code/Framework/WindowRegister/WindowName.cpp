/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:13)

#include "Framework/FrameworkExport.h"

#include "WindowName.h"
#include "Detail/WindowNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowName::WindowName(const String& className, const String& menuName)
    : impl{ className, menuName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowName)

System::String Framework::WindowName::GetWindowClassName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowClassName();
}

System::String Framework::WindowName::GetWindowMenuName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowMenuName();
}

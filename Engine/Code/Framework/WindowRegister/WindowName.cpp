///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:02)

#include "Framework/FrameworkExport.h"

#include "WindowName.h"
#include "Detail/WindowNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::WindowName::WindowName(const String& className, const String& menuName)
    : impl{ className, menuName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowName, GetWindowClassName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowName, GetWindowMenuName, System::String)

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:09)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoop.h"
#include "Detail/WindowMessageLoopImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::WindowMessageLoop::WindowMessageLoop(Display function)
    : impl{ function }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageLoop)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, WindowMessageLoop, EnterMessageLoop, HWnd, System::WindowsWParam)

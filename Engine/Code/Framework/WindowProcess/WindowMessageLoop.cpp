///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 16:46)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoop.h"
#include "Detail/WindowMessageLoopImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_unique;
using std::move;

Framework::WindowMessageLoop::WindowMessageLoop(Display function)
    : impl{ function }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageLoop)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, WindowMessageLoop, EnterMessageLoop, HWnd, System::WindowsWParam)

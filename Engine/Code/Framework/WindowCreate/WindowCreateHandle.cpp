///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 16:12)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandle.h"
#include "Detail/WindowCreateHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::move;

Framework::WindowCreateHandle::WindowCreateHandle(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size)
    : impl{ windowInstanceParameter, windowCreateParameter, size }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowCreateHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateHandle, GetHwnd, Framework::WindowCreateHandle::WindowsHWnd)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowCreateHandle, SetMainWindow, void)

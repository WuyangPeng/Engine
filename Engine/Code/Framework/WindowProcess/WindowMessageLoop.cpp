///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 11:07)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoop.h"
#include "Detail/WindowMessageLoopImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowMessageLoop::WindowMessageLoop(DisplayFunction function)
    : impl{ function }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageLoop)

System::WindowsWParam Framework::WindowMessageLoop::EnterMessageLoop(WindowsHWnd hWnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->EnterMessageLoop(hWnd);
}

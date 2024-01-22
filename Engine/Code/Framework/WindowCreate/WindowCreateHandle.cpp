/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:33)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandle.h"
#include "Detail/WindowCreateHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowCreateHandle::WindowCreateHandle(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size)
    : impl{ windowInstanceParameter, windowCreateParameter, size }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowCreateHandle)

Framework::WindowCreateHandle::WindowsHWnd Framework::WindowCreateHandle::GetHWnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetHWnd();
}

void Framework::WindowCreateHandle::SetMainWindow()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMainWindow();
}

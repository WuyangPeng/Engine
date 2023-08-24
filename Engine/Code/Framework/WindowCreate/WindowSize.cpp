///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 15:15)

#include "Framework/FrameworkExport.h"

#include "WindowSize.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

using namespace std::literals;

Framework::WindowSize::WindowSize() noexcept
    : windowWidth{ 0 }, windowHeight{ 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowSize::WindowSize(int width, int height)
    : windowWidth{ width }, windowHeight{ height }
{
    if (windowWidth < 0 || windowHeight < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("WindowSize传入的大小为负数！"s))
    }

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowSize::WindowSize(WindowsLParam lParam)
    : WindowSize{ System::GetLowWord(lParam), System::GetHighWord(lParam) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowSize::IsValid() const noexcept
{
    if (0 <= windowWidth && 0 <= windowHeight)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Framework::WindowSize::SetWindowSize(int width, int height)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (width < 0 || height < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置的新大小为负数！"s))
    }

    windowWidth = width;
    windowHeight = height;
}

int Framework::WindowSize::GetWindowWidth() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowWidth;
}

int Framework::WindowSize::GetWindowHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowHeight;
}

bool Framework::operator==(const WindowSize& lhs, const WindowSize& rhs) noexcept
{
    return lhs.GetWindowHeight() == rhs.GetWindowHeight() && lhs.GetWindowWidth() == rhs.GetWindowWidth();
}

std::ostream& Framework::operator<<(std::ostream& os, const WindowSize& size)
{
    os << "width = "
       << size.GetWindowWidth()
       << " height = "
       << size.GetWindowHeight();

    return os;
}
